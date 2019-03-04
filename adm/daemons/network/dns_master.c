//#pragma save_binary


/* File     : /adm/daemons/network/network_master.c
 * Created  : 93-08-09
 * By       : Grendel@tmi-2

 * History  : Huthar@Portals wrote the original name server
 *          : Pinkfish@Discworld wrote a port of the CD udp server.  The
 *              udp comms and the database code are based on that port.

 * This is the daemon that runs the DNS

 * What does it do?
 * -> maintains the database of known muds
 * -> handles udp communication
 * -> maintains a list of which services are avaible at which muds
 * -> maintains an indexed list of outstanding requests to network services
 */

#include <config.h>
#include <net/config.h>
#include <net/daemons.h>
#include <net/dns.h>
#include <net/socket.h>
#include <net/services.h>
#include <net/macros.h>

#define DEBUG 1

#define STD_SERVICE ({ "mail_q", "rwho_q", "locate_q", \
  "gwizmsg", "gtell", \
	"gfinger_q", "rftp", "gchannel" })
#define STD_SERVICE_SIZE	8

// used by the log() function
#define MY_LOG_FILE "network/dns_master"

/* global vars */
// the udp port number of the mud, and the socket id of the udp socket
 int my_port, socket_id;

// The mapping containing the general mud info.
 mapping muds;
 string *unknown;

// This mapping has an entry for every mud in the dns, and holds
// information about the protocols supported for the services
 mapping mud_svc;

// Info about ourselves
 mapping this_host;

// the server where we get our mudlist from, and the number of tries
// we have had to contact it.
 mixed * bootsrv;

// used for sequencing the requests to the network services
 int seq_ctr;
 mapping seq_entries;

// Used for debugging
#ifdef DEBUG
# define debug( x ) if( monitor ) message( "diagnostic", ( x ), monitor )
static object monitor = 0;
#else
# define debug( x )
#endif

#ifdef KEEP_STATS
static mapping host_info = ([]);
static mapping type_info = ([]);
#endif

/* prototypes */
// udp communication functions
int startup_udp();
void send_udp( string host, int port, string msg );
void read_callback( int sock, string msg, string addr );
string start_message();

// mud database functions
void init_database();
void refresh_database();
varargs void do_pings( string mud );
void set_mud_info( string name, mapping junk );
void zap_mud_info( string name, mapping junk );
void support_q_callback( mapping info );

// name serving functions
int query_services( string mud );
int query_service_method( string mud, string service );
mapping query_mud_info( string name );
string get_host_name( string alias );
int get_mudresource( string mud, string resource );
int dns_mudp( string name );
mapping query_muds();
mapping query_svc();

// sequencing functions
varargs int idx_request( function f );
void sequence_clean_up();

#ifdef DEBUG
// debugging functions
mixed * query_bootsrv();
void dump_sequencer();
void set_monitor( object ob );
object query_monitor();
#endif

// misc functions
 void restore_euid();
void aux_log( string file, string entry );
void aux_warning( string warning );
 void log( string entry );
void resolve_callback( string address, string my_ip, int key );

/*
 * The udp network functions
 */

// this function binds our listening socket, and requests a mudlist
int startup_udp() {
  if( socket_id )
    return 0;
  
  socket_id = socket_create( DATAGRAM, "read_callback", "close_callback" );
  if( socket_id < 0 )  {
    log( "Failed to acquire socket.\n" );
    return 0;
  }
  if( socket_bind( socket_id, my_port ) <= 0 )  {
    log( "Failed to bind socket socket.\n" );
    socket_close( socket_id );
    return 0;
  }
  return 1;
}

// this is the function used by the udp slave daemons to send packets
void send_udp( string host, int port, string msg ) {
  int sock;
  
  if( !port || undefinedp( port ) ) return;
//  if( port == "0" ) return;

	if( !previous_object()) return ;
  if( !ACCESS_CHECK( previous_object() )
    && file_name( previous_object() )[0..strlen( SERVICES_PATH ) - 1] 
                      != SERVICES_PATH )
    return;
  
  debug( "DNS: Sending " + msg );
  sock = socket_create( DATAGRAM, "read_callback", "close_callback" );
  
  if( sock <= 0 ) {
    log( "Failed to open socket to " + host + " " + port + "\n" );
    return;
  }

#ifdef KEEP_STATS
    host_info[host]+= strlen(msg);
#endif
  if( socket_write( sock, msg, host + " " + port ) == EESENDTO ) ;
  socket_close( sock );
}

// this is called when we receive a udp packet.  We determine which
// service the packet is for, and send it to the auxiliary daemon of
// that name
static void read_callback( int sock, string msg, string addr ) {
  string func, rest, *bits, name, arg;
  mapping args;
  int i;
  
  debug( "DNS: Got " + msg );
  
// get the function from the packet
  if( !sscanf( msg, "@@@%s||%s@@@%*s", func, rest ) ) {
    if( !sscanf( msg, "@@@%s@@@%*s", func ) )
      return;
    rest = "";
  }
// get the address(remove port number)
  sscanf( addr, "%s %*s", addr );
  
// get the arguments to the function
// these are in the form "<arg>:<value>" and are put into a mapping
// like that
  if( !stringp( rest ) || !strlen( rest ) ) return;
  // === added by kenny ===
  rest = replace_string(rest, "|||CHANNEL", "| ||CHANNEL");
  rest = replace_string(rest, "|||MSG", "| ||MSG");
  // === end ===
  bits = explode( rest, "||" );
  args = allocate_mapping( i = sizeof( bits ) );
  
  while( i-- )
    if( bits[i] && sscanf( bits[i], "%s:%s", name, arg ) == 2 )
      args[name] = arg;
  args["HOSTADDRESS"] = addr;
  
// some muds don't send their name out in a network friendly form
  if( args["NAME"] ) {
    name = htonn( args["NAME"] );
    args["ALIAS"] = nntoh( args["NAME"] );
    
// we have received a message from someone, so we clear their
// no contact count
    if( mapp( muds[name] ) ) {
      muds[name]["TIME"] = time();
      map_delete( muds[name], DNS_NO_CONTACT );
    }
  }
  
// we now execute the function we have received
  debug( "DNS: Parse " + SERVICES_PATH + func + ".c\n" );
  func = SERVICES_PATH + func + ".c";
  
  if( file_exists( func ) )
    func -> incoming_request( args );
  else {
    sscanf( func, SERVICES_PATH + "%s.c", func );
    if( member_array( func, unknown ) < 0 )
        unknown += ({ func });
  }
  // Finally, get a services update.
  query_services( name );
}

// used to inform the slave daemons of the udp port
int query_udp_port() {
  return my_port;
}

string *query_mud_names() {
  return keys( muds );
}

// this is called when we want to shut the mud down
void send_shutdown() {
  string *mud_names;
  int i;
  
// check the permission
        if( !previous_object()) return ;
  if( geteuid( previous_object() ) != ROOT_UID )
    return;
  
// run through the muds and send a shutdown message
  mud_names = keys( muds );
  i = sizeof( mud_names );
  
  while( i-- )
    SHUTDOWN -> send_shutdown( muds[mud_names[i]]["HOSTADDRESS"],
      muds[mud_names[i]]["PORTUDP"] );
}

string start_message() {
  return sprintf( "||NAME:%s||VERSION:%s||MUDLIB:%s||HOST:%s||PORT:%d"
    "||DRIVER:%s||PORTUDP:%d||", Mud_name(),
    "1.0", "Eastern Stories", query_host_name(),
    mud_port(), version(), my_port );
}

/* --------------------------
 * Network database functions
 */

// Sends a startup message to our server mud, then requests a mudlist.
void init_database() {
  int i;
  string message, *list;
  
// if we have received any muds then we stop starting up.
  if( ( SERVICES_PATH + DNS_MUDLIST_A ) -> query_db_flag() ) {
// start call outs - note we do the sequence clean up
// a bit early because of the number of muds we query
// when we first start up.
    call_out( "refresh_database", REFRESH_INTERVAL );
    call_out( "sequence_clean_up", 4 * SERVICE_TIMEOUT );
    do_pings();
    return;
  }
  
  message = sprintf( "@@@%s%s@@@\n", DNS_STARTUP, start_message() );
  
// send a startup and request a mudlist
  list = values( LISTNODES );
  i = sizeof( list );
  
  while( i-- ) {
    sscanf( list[i], "%s %d", bootsrv[0], bootsrv[1] );
    send_udp( bootsrv[0], bootsrv[1], message );
    MUDLIST_Q -> send_mudlist_q( bootsrv[0], bootsrv[1] );
  }
  
  call_out( "init_database", 60 );
  return;
}

// This periodic function queries the boot server for its current list
// of muds
void refresh_database() {
  int i;
  string *list;
  
  while( remove_call_out( "refresh_database" ) != -1 );
  
  call_out( "refresh_database", REFRESH_INTERVAL );
  list = values( LISTNODES );
  i = sizeof( list );
  
  while( i-- ) {
    sscanf( list[i], "%s %d", bootsrv[0], bootsrv[1] );
    MUDLIST_Q -> send_mudlist_q( bootsrv[0], bootsrv[1] );
  }
}

// this periodic function pings all the muds on our list.  It keeps them
// alive in our database, and keeps us alive in theirs
varargs
void do_pings( string mud ) {
   int i, current_time;
  string *mud_names;

        if( !previous_object()) return ;  
	if( !ACCESS_CHECK( previous_object() ) ) return;
  while( remove_call_out( "do_pings" ) != -1 );
  
   current_time = time();

  call_out( "do_pings", PING_INTERVAL );
  
  mud_names = keys( muds );
  if( mud && mud != "" ) {
    if( !muds[mud] )
      return;
    else mud_names = ({ mud });
  }
  
  i = sizeof( mud_names );
  while( i-- ) {
// increment the no contact count - this will be zerod if a reply
// is received, if it reaches a threshold the mud is removed
/*
    muds[mud_names[i]] [DNS_NO_CONTACT]++;
    map_delete( muds[mud_names[i]], DNS_CONTACT );
*/
    
// ping the mud
    PING_Q -> send_ping_q( muds[mud_names[i]]["HOSTADDRESS"],
      muds[mud_names[i]]["PORTUDP"] );
    
// delete it if is hasn 't answered recently enough
/*
    if( muds[mud_names[i]][DNS_NO_CONTACT] >= MAX_RETRYS )
*/
   if( current_time - muds[mud_names[i]]["TIME"] > MAX_NO_CONTACT )
      zap_mud_info( mud_names[i], 0 );
  }
}

// adds a mud to the 'muds' mapping.  if it is a new entry then it may
// also query the muds services
void set_mud_info( string name, mapping junk ) {
  name = htonn( name );
  
        if( !previous_object()) return ;
  if( !( ACCESS_CHECK( previous_object() ) )
    && file_name( previous_object() )[0..strlen( SERVICES_PATH ) - 1] 
          != SERVICES_PATH )
    return;
  
// already know about ourselves
  if( name == mud_nname() )
    return;
  
  junk["ALIAS"] = nntoh( junk["NAME"] );
  junk["TIME"] = time();
  muds[name] = junk;
}

// deletes an entry for a mud
void zap_mud_info( string name, mapping junk ) {
// check permissions

        if( !previous_object()) return ;
  if( !ACCESS_CHECK( previous_object() )
    && file_name( previous_object() )[0..strlen( SERVICES_PATH ) - 1] 
                    != SERVICES_PATH )
    return;
  
// delete the entry
  map_delete( muds, name );
  
// wipe the service information
  map_delete( mud_svc, name );
}

// This is called when we get a service response from the other end
void support_q_callback( mapping info ) {
  int i;
  string mud;
  
// check permission
        if( !previous_object()) return ;
  if( !ACCESS_CHECK( previous_object() ) )
    return;
  
// check the reply is valid - note that if info is 0 it is possible
// this is the result of a tiemout, but as muds are only queried
// once, and the default is unknown, we dont have a problem.
  if( !info || !info["CMD"] || !info["NAME"] || !strlen( info["CMD"] )
    || !strlen( info["NAME"] ) )  {
    return;
  }
  
  mud = htonn( info["NAME"] );
  
  if( undefinedp( muds[mud] ) )
    return;
  
  if( undefinedp( mud_svc[mud] ) )
    mud_svc += ([  mud : allocate( sizeof( STD_SERVICE ) ) ]);
  
  if( !info["SUPPORTED"] && !info["NOTSUPPORTED"] )
    return; // mesed up packet
  
  i = member_array( info["CMD"], STD_SERVICE );
  mud_svc[mud][i] = ( info["SUPPORTED"] ? 1 : -1 );
  return;
}


/*
 * Name server functions
 */
// this is used by the internet communication front ends.  It return
// flags representing whether a service is supported or not.
int query_service_method( string mud, string service )
{
  int i;
  
  mud = htonn( mud );
  
// do we know about the mud
  if( undefinedp( muds[mud] ) )
    return SVC_UNKNOWN;
  
  return SVC_UDP;
}

mapping query_svc_entry( string mud ) {

        if( !previous_object()) return copy( mud_svc[mud]);
  if( ACCESS_CHECK( previous_object() ) )
    return mud_svc[mud];
  
  return copy( mud_svc[mud] );
}

int query_named_service( string mud, string x_serv ) {
  int x, y;

   if( mud && mud != "" && x_serv || strlen( x_serv ) ) {
      mud = htonn( mud );
      x = member_array( x_serv, STD_SERVICE );

      if( x > -1 && mud_svc[mud] )
         y = mud_svc[mud][x];
      else y = 0;
   }
   return y;
}


string get_host_name( string name ) {
  name = htonn( name );
  
  if( name == mud_nname() )
    return this_host["HOSTADDRESS"];
  if( undefinedp( muds[name] ) )
    return 0;
  return muds[name]["HOSTADDRESS"];
}

int
get_mudresource( string mud, string resource ) {
  mud = htonn( mud );
  
// if it is our own mud
  if( mud == mud_nname() )
    switch( resource )    {
// these two are still using the old system
      case "cd-udp":
      return SRVC_PORT_UDP( mud_port() );
      case "port":
      case "DEFAULT":
      return mud_port();
    }
  
// check if it is in the DB
  if( !undefinedp( muds[mud] ) )
    switch( resource )    {
      case "cd-udp":
      return to_int( muds[mud]["PORTUDP"] );
      case "DEFAULT":
      return to_int( muds[mud]["PORT"] );
    }
  
   return 0;
}

mapping query_mud_info( string name ) {
  mapping m;
  string str;
  
  name = htonn( name );
  if( name == mud_nname() )
    return this_host + ([  "TIME" : ( time() ) ]);
  
  return copy( muds[name] );
}

// this returns '1' if the mud is in the dns, or if it is us
int dns_mudp( string name ) {
  name = htonn( name );
  if( name == mud_nname() ) return 1;
  if( muds[name] )
     if( muds[name]["TCP"] == TCP_ONLY )
         return 0;
  return 1;
}

// returns all the muds in the databases
mapping
query_muds() {
        if( !previous_object()) return  copy( muds ) + ([  mud_nname():this_host +([  "TIME":ctime( time() ) ]) ]);
  if( ACCESS_CHECK( previous_object() ) )
    return muds + ([  mud_nname():this_host + ([  "TIME":ctime( time() ) ]) ]);
  
  return copy( muds ) + ([  mud_nname():this_host + ([  "TIME":ctime( time() ) ]) ]);
}

// returns the mud alias
string query_alias( string mudname ) {
  mapping safemuds;
  
  if( !mudname ) return 0;
  mudname = htonn( mudname );
  safemuds = muds + ([  mud_nname():this_host + ([  "TIME":ctime( time() ) ]) ]);
  
  if( !safemuds[mudname] ) return 0;
  return safemuds[mudname]["ALIAS"];
}

// returns the services mapping
mapping query_svc() {
        if( !previous_object()) copy( mud_svc ) ;
  if( ACCESS_CHECK( previous_object() ) )
    return mud_svc;
  
  return copy( mud_svc );
}

/*
 * service sequencing functions

 * this is a potential security nightmare, be careful what euid the object
 * has when it calls the function
 */
// register a function in the sequencer
varargs int idx_request( function f ) {
        if( !previous_object()) return 0;
  if( file_name( previous_object() )[0..strlen( SERVICES_PATH ) - 1] 
               != SERVICES_PATH )
    return 0;
  
  seq_ctr++;

  seq_entries[seq_ctr] = ({ geteuid( previous_object() ), f, time() });
  return seq_ctr;
}

// call a function in the sequencer
void idx_callback( int idx, mixed param ) {
  mixed *entry;
  
        if( !previous_object()) return ;
  if( !ACCESS_CHECK( previous_object() ) )
    return;
  
  if( undefinedp( seq_entries[idx] ) )
    return;
  
  entry = seq_entries[idx];
  map_delete( seq_entries, idx );
  
  seteuid( entry[0] );
  ( *entry[1] )( param );
  restore_euid();
}

// remove timed out entries
void sequence_clean_up() {
  int i, now;
  int *indices;
  
  while( remove_call_out( "sequence_clean_up" ) != -1 );
  
  indices = keys( seq_entries );
  now = time();
  i = sizeof( indices );

  // Reset the counter if the queue is empty.
  if( !i ) 
     seq_ctr = 0;

  while( i-- ) {
    if( (now - seq_entries[indices[i]][2]) > SERVICE_TIMEOUT ) {
      seteuid( seq_entries[indices[i]][0] );
      ( *seq_entries[indices[i]][1] )( 0 );
      restore_euid();
      map_delete( seq_entries, indices[i] );
    }
  }
  if( !sizeof( seq_entries ) )
      seq_ctr = 0;

  call_out( "sequence_clean_up", SEQ_CLEAN_INTERVAL );
}

/*
 * general debugging stuff
 */
#ifdef DEBUG
mixed *query_bootsrv() {
  return copy( bootsrv );
}

void dump_sequencer() {
  printf( "counter: %d\n\n%d\n", seq_ctr, sizeof( seq_entries ) );
}

void dump_svc() {
  write( identify( mud_svc ) + "\n" );
}

void dump_mud_keys() {
  write( identify( keys( muds ) ) + "\n" );
}

void dump_svc_keys() {
  write( identify( keys( mud_svc ) ) + "\n" );
}

void dump_unknown() {
  printf( "%O\n", unknown );
}

void set_monitor( object ob ) {
  string euid;
        if( !previous_object()) return ;
  euid = geteuid( previous_object() );
  
  if( !euid || !member_group( euid, "admin" ) && !member_group( euid, "socket" ) )
    return;
  monitor = ob;
}

object query_monitor() {
  return monitor;
}
#endif // DEBUG

/*
 * some misc functions
 */
// Not really used yet
 void restore_euid() {
  seteuid( ROOT_UID );
}

// Logging functions
// This one is for log entries from the auxiliaries
void aux_log( string file, string entry ) {
  return;
        if( !previous_object()) return ;
  if( !ACCESS_CHECK( previous_object() ) )
    return;
  log_file( file, entry + "\n" );
}

// This one is for warnings from the auxiliaries
void aux_warning( string warning ) {
        if( !previous_object()) return ;
  if( !ACCESS_CHECK( previous_object() ) )
    return;
  log( "dns_warning: " + warning );
}

// This is for internal use
 void log( string entry ) {
  string temp;
  return;
  log_file( MY_LOG_FILE, entry + "\n" );
}

// Used to find the ip number of the host we are on
void resolve_callback( string address, string my_ip, int key ) {
  this_host["HOSTADDRESS"] = my_ip;
}

//

// This starts us all off
void create() {
  restore_euid();
  bootsrv = allocate( 2 );
  
   unknown = ({ });
// find out which port we are on
  my_port = SRVC_PORT_UDP( mud_port() );
  
// initialise global mud info variables
  muds = allocate_mapping( MUDS_ALLOC );
  mud_svc = allocate_mapping( MUDS_ALLOC );
  
// initialise the sequencing variables
  seq_ctr = 0;
  seq_entries = ([  ]);
  
// tell the mudlist_a daemon that we have cleared the database
  ( SERVICES_PATH + "mudlist_a" ) -> clear_db_flag();
  
// set up our own info
  this_host = ([
    "NAME" : Mud_name(),
    "DRIVER" : version(),
    "MUDLIB" : MUDLIB_NAME,
    "VERSION" : MUDLIB_VERSION,
    "HOST" : query_host_name(),
    "ALIAS"	: "ES",
    "HOSTADDRESS" : query_host_name(), // set in resolve_callback()
    "PORT" : "" + mud_port(),
    "PORTUDP" : "" + my_port,
    "TIME" : ( time() ),
    "TCP" : TCP_SERVICE_LEVEL,
  ]);
  
  resolve( query_host_name(), "resolve_callback" );
  
// initialise the udp socket, if successful start the database system
  if( startup_udp() )
    init_database();
}

int query_services( string name ) {
  string tcp;
  int i, cnt;
  
  if( !name || name == "" ) return -1;
  if( !muds[name] ) return -2;
  if( undefinedp( tcp = muds[name]["TCP"] ) )
      tcp = "none";

  if( tcp && tcp == "only" )
      return -3;

// determines whether or not we send the service queries out
// to the new mud
  i = STD_SERVICE_SIZE;
  
  while( i-- ) {
    if( mud_svc[name] && mud_svc[name][i] ) continue;
    else {
      SUPPORT_Q -> send_support_q( muds[name]["HOSTADDRESS"],
		 muds[name]["PORTUDP"], STD_SERVICE[i] );
      cnt++;
    }
  }
  
  return cnt;
}

string *query_service_list() {
  return STD_SERVICE;
}

/* EOF */
