//#pragma save_binary

//  Intermud Tell Server

//  File	: /adm/daemons/network/ts.c (was: /adm/daemons/ts.c)
//  Creator	: Huthar@portals
//  Updated	: Blackthorn@Genocide  (10/29/92)
//		: Pallando@tmi-2  (12/12/92)
//		: Tzar@WizMud  (03/27/93)  Printed out and completely recoded
//		: Watcher@TMI  (04/03/93)  Added ghost status notification
//		: Inspiral@TMI  (05/11/93)  Channel security reinstated
//		: Zak  (07/09/93)  Added 'Replies' code patch
//		: Karathan  (08/14/93)  Updated to work with dns
//		: Inspiral (somewhere93) Added idle msessage
//		: Leto@Earth (02/27/94)  Reinstated old ignore code
//			 : Inspiral@TMI-2 (03/17/94)  Added UDP emote gtell support.

#include <uid.h>
#include <daemons.h>
#include <net/daemons.h>
#include <net/services.h>
#include <net/config.h>
#include <net/dns.h>
#include <net/macros.h>

#include <channels.h>
#include <config.h>
#include <net/socket.h>

#define log(x) log_file("TS", x)
#define IT 60
//  If you change this IT define, please change it also in /cmds/std/_tell.c
#define NH "%s is not on this mud.\n"
#define C_NH "%s��û�������ϡ�\n"

#define CHANNEL_FILE      "/adm/etc/intermud_channels"
#define CHANNEL_INTERMUDS "/adm/etc/channel_intermuds"

string *cm;
mapping channels;
mapping requests;

//  The interface to the mudlib
void remote_channel(object source, string channel, string msg, int *next);
void tcp_channel(object source,string channel,string mud,string msg,int *next);
varargs string remote_tell(object source, string user,
	string mud, string msg, int emote);
varargs  string udp_tell(object source, string user,
	string mud, string msg, int emote);
 string tcp_tell(object source, string user, string mud, string msg);

// The inetd functions
void service_request(int id, mixed *parms);
void service_callback(int id);
void read_callback(int id, string msg);
void close_callback(int id);
void timeout(int id, int t);

//  Internal functions
void close_connection(mixed id);
varargs	string tell_user(string who_from, string mud_from,
	string who_to, string msg, int emote );
void get_cms();
void get_channels();
int check_mud(string m);
mixed check_channel(string str);

void create()
{
	seteuid(ROOT_UID);
	cm = ({});
	requests = ([]);
	channels = ([]);
	get_cms();
	get_channels();
}

//  This is called by the channels command. It will call the remote tell
//  command for each mud in the list.
void remote_channel(object source, string channel, string msg, int *next)
{
	int i, s;
	mapping svc;
	if (!previous_object()) return;
	if( geteuid(previous_object()) != ROOT_UID ) return;

	channel = lower_case(channel);
	if( !next ) {
		tell_object(source, sprintf("Beginning %s sending.\n",channel));
		next = ({ 0, 0, 0, time() });
	}
	s = sizeof(cm);
	if( next[0] >= s ) {
		tell_object(source, sprintf(
			"%s sending completed. %d sites contacted out of %d in %d seconds.\n",
			capitalize(channel), next[1], next[2], (time()-next[3])));
		return;
	}
	svc = (mapping)DNS_MASTER->query_svc();
	for( i = next[0]; i < s && (lower_case(cm[i]) == mud_nname() ||
		!undefinedp(svc[htonn(cm[i])])); i++ ) ;
	if( i < s ) {
		next[0] = i+1;
		next[2]++;
		call_out("tcp_channel", 0, source, channel, lower_case(cm[i]),
			msg, next);
	} else
		tell_object(source, sprintf(
			"%s sending completed. %d sites contacted out of %d in %d seconds.\n",
			capitalize(channel), next[1], next[2], (time()-next[3])));
}

void tcp_channel(object source, string channel, string mud, string msg,
	int *next)
{
	int id, t;

	if( previous_object() && geteuid(previous_object()) != ROOT_UID ) return;

	id = INETD->open_service(mud, "tell", ({ channel }));
	if( id < 0 ) return remote_channel(source, channel, msg, next);
	t = time();
	requests[id] = ({ source, channel, mud, msg, t, next });
	call_out("timeout", SERVICE_TIMEOUT, id, t);
}

// This is called by the tell command. It works out which type of protocol
// to use, then acts appropriately
varargs string remote_tell(object source, string user, string mud,
	string msg, int emote)
{
	mapping minfo;
	int msvc;

	if( !DNS_MASTER->query_mud_info(mud) )
		return ("Telld: no mud with that name presently active.\n");

	msvc = (int)DNS_MASTER->query_service_method(mud, "tell");

	return udp_tell(source, user, mud, msg, emote);
}

varargs  string udp_tell(object source, string user,
	string mud, string msg, int emote)
{
	if( !DNS_MASTER->query_mud_info(mud) )
	// this is bad, you had to have a service entry to get here
	return ("Telld: error: unknown mud has service entry\n");
	GTELL->send_gtell(mud, user, source, msg, emote);
	return "Tell on its way. May take some time.\n";
}

 string tcp_tell(object source, string user, string mud, string msg)
{
	int id, t;

	id = INETD->open_service(mud, "tell", ({ user }));
	if( id < 0 ) return ("Remote mud does not exist.\n");
	t = time();
	requests[id] = ({ source, user, mud, msg, t });
	call_out("timeout", SERVICE_TIMEOUT, id, t);
	return "";
}

//  This is called by the inet daemon when it receives an incoming tell request
void read_callback(int id, string str)
{
	string org, mud, to, msg;
	mixed *ss;
	object ob;
	int l;

	if( geteuid(previous_object()) != ROOT_UID ) return;
	if( !str || str == "" || str == "\n" )
		return close_connection( ({ id }) );
	l = strlen(str) - 1;
	if( str[l..l] == "\n" ) str = str[0..(l-1)];
	if( sscanf(str, "%s@%s tells %s: %s", org, mud, to, msg) != 4 &&
		sscanf(str, "%s@%s replies %s: %s", org, mud, to, msg) != 4 )
		return close_connection( ({ id }) );
	if( msg == "Cannot find Interwiz here." ||
		msg == "Cannot find Intermud here" )
		return close_connection( ({ id }) );
	to = lower_case(to);
	if( org == "TS" || org == "Game Driver" ) {
		if( ob = find_player(to) )
			tell_object(ob, sprintf("Message from %s's Tell server:\n%s\n",
				nntoh(mud), wrap(msg)) );
	} else {
		if( ss = check_channel(to) )
			INTER_CHAN_D->incoming_channel(all_caps(to), capitalize(org),
				nntoh(mud), msg, 0);
		else
			INETD->write_socket(id, sprintf("TS@%s tells %s: %s.\n",
				THIS_MUD, lower_case(org), tell_user(org, mud, to, msg)));
	}
	close_connection( ({ id }) );
}

//  This is called by the remote mud via the inet daemon when a connection
//  is requested
void service_callback(int id)
{
	string name;

	if( geteuid(previous_object()) != ROOT_UID ) return;
	if( !requests[id] ) return;
	if( objectp(requests[id][0]) )
		name = requests[id][0]->query("name");
	else if( stringp(requests[id][0]) )
		name = requests[id][0];
	else
		return close_connection(id);
	INETD->write_socket(id, sprintf("%s@%s tells %s: %s.\n",
		name, THIS_MUD, requests[id][1], requests[id][3]));
	if( sizeof(requests[id]) > 5 ) {
		requests[id][5][1]++;
		remote_channel(requests[id][0], requests[id][1], requests[id][3],
			requests[id][5]);
		requests[id] -= requests[id][5];
	}
	else if( objectp(requests[id][0]) )
		tell_object(requests[id][0], "Remote tell was sent.\n");
	close_connection(id);
}

void service_request(int id, mixed *parms)
{
	if( geteuid(previous_object()) != ROOT_UID ) return;
	if( !parms || !sizeof(parms) || !parms[0] || !stringp(parms[0]) ) return;
	tell_object(requests[id][0], parms[0]);
}

void close_callback(int id)
{
	if( geteuid(previous_object()) != ROOT_UID ) return;
	if( sizeof(requests[id]) > 5 )
		remote_channel(requests[id][0], requests[id][1], requests[id][3],
			requests[id][5]);
	map_delete(requests, id);
}   

void timeout(int id, int t)
{
	if( previous_object() && geteuid(previous_object()) != ROOT_UID ) return;
	if( !requests[id] || requests[id][4] != t ) return;
	if( sizeof(requests[id]) > 5 )
		remote_channel(requests[id][0], requests[id][1], requests[id][3],
			requests[id][5]);
	else if( objectp(requests[id][0]) )
		tell_object(requests[id][0], "Remote tell connection timed out.\n");
	INETD->close_socket(id);
	map_delete(requests, id);
}

//  This function is called by service functions to close the conenction
void close_connection(mixed id)
{
	if( geteuid(previous_object()) != ROOT_UID ) return;
	if( intp(id) ) {
		INETD->close_socket(id);
		map_delete(requests, id);
	} else
		INETD->close_socket(id[0]);
}

//  This is used by remote users to output tells to local users and to
//  determine the response sent back to the remote sender.
//	Updated to support Chinese by Annihilator@ES
varargs string tell_user(string who_from, string mud_from, string who_to,
	string msg, int emote)
{
	object rcvr, sndr;
	string pre_ret, ret, tmp, c_who_from, c_who_to, *ignore;
	int ps, pr, sndr_chinese, rcvr_chinese;

	if( geteuid(previous_object()) != ROOT_UID ) return 0;

	if( who_to == "subscribe-to-channels" ) {
		if( THIS_MUD != "tmi-2" )
			return ("Sorry, you can only Subscribe to the channels from TMI-2.\n");
		if( check_mud(mud_from) )
			return ("You are already in the list.\n");
		write_file(CHANNEL_INTERMUDS, sprintf("%s\n", mud_from));
		get_cms();
		return ("You've been added. Please get the newest version of the files from TMI-2.\n");
	}

	sndr = find_player(who_from);
	if( sndr && !mud_from ) {
		sndr_chinese = can_read_chinese(sndr);
		c_who_from = sndr->query("c_name");
	} else
		c_who_from = who_from;

	rcvr = find_player(who_to);
	if( !rcvr ) rcvr = find_living(who_to);
	if( !rcvr ) rcvr = find_object(who_to);
	// No cheat to see invis wizzes ;)
	// Difficulty to determine who_from's chinese mode... Annihilator.
	if( !rcvr ) return ( sndr_chinese ?
		sprintf(C_NH, capitalize(who_to)):
		sprintf(C_NH, capitalize(who_to)) );
	if( rcvr ) c_who_to = rcvr->query("c_name");
	if( !c_who_to ) c_who_to = who_to;
	rcvr_chinese = can_read_chinese(rcvr);

	if( !who_from || !who_to || !msg )
		return (sndr_chinese ?
			"�﷨: tell <ĳ��> <ѶϢ>":"Syntax: tell <who> <msg>");

	if( who_to == "" )
		return (sndr_chinese?"��Ҫ��˭˵����":"Who do you want to tell?");

	who_to = lower_case(who_to);

	if( sndr && !mud_from && member_group(who_from, "admin") ) ps = 2;
	else if( sndr && !mud_from && wizardp(sndr) ) ps = 1;
	else ps = 0;

	if( member_group(who_to, "admin") ) pr = 2;
	else if( wizardp(rcvr) ) pr = 1;
	else pr = 0;

	if( rcvr->query("invisible") > ps )
		return ( sndr_chinese ?
			sprintf(C_NH, capitalize(who_to)):
			sprintf(C_NH, capitalize(who_to)) );  // no cheat'n ;)

	if( !interactive(rcvr) )
		return ( sndr_chinese ?
			sprintf("%s(%s) �����������С�\n", c_who_to, capitalize(who_to)):
			sprintf("%s is presently net-dead.\n", capitalize(who_to)) );

	ignore = rcvr->query("ignore");
	if( pointerp( ignore ) ) {
		if( !mud_from ) {
			if( !member_group(lower_case(who_from),"admin") ) {
				if( -1 != member_array(lower_case(who_from), ignore) )
					return ( sndr_chinese ?
						sprintf("%s(%s) ��������˵����\n", c_who_to,
							capitalize(who_to)):
						sprintf("%s is ignoring you.\n", capitalize(who_to)) );
			}
		} else {
			if( - 1 != member_array( sprintf("@%s", lower_case(mud_from)), ignore ) ) {
				return ( sndr_chinese ?
						sprintf("%s(%s) �������κδ�%s���Ļ���\n", c_who_to,
							capitalize(who_to), capitalize(mud_from)):
						sprintf("%s is ignoring everyone@%s.\n",
							capitalize(who_to), capitalize(mud_from)) );
			} else {
				if( -1 != member_array(sprintf("%s@%s",
					lower_case(who_from), lower_case(mud_from)), ignore) )
					return ( sndr_chinese ?
						sprintf("%s(%s) ��������˵����\n", c_who_to,
							capitalize(who_to)):
						sprintf("%s is ignoring you.\n", capitalize(who_to)) );
			}
		}
	}

	if( ps != 2 && rcvr->query("busy") )
		return ( sndr_chinese ?
			sprintf("%s(%s) ���ں�æ����ʲ�Ự�������˵��\n", c_who_to,
				capitalize(who_to)):
			sprintf("%s is busy right now, try again later.\n",
				capitalize(who_to)) );

	// If we got here, try to send the message to receiver.
	// Check invisible first.
	if( sndr && (int)sndr->query("invisible") > pr )
		who_from = rcvr_chinese? "ĳ��" : "someone";

	if( !mud_from ) {
		if( rcvr_chinese )
			tell_object( rcvr, set_color((emote?
				sprintf("[����]%s(%s): %s\n", c_who_from, who_from, msg):
				sprintf("%s(%s)������: %s\n", c_who_from, capitalize(who_from), msg)), "HIC", rcvr));
		else
			tell_object( rcvr, set_color((emote?
				sprintf("[Tell]%s %s\n", capitalize(who_from), msg):
				sprintf("%s tells you: %s\n", capitalize(who_from), msg)), "HIC", rcvr));
	} else {
		if( rcvr_chinese )
			tell_object( rcvr, set_color((emote?
				sprintf("[����]%s(%s)@%s: %s\n", c_who_from, who_from, mud_from, msg):
				sprintf("%s(%s)@%s������: %s\n", c_who_from, who_from, mud_from, msg)), "HIC", rcvr));
		else
			tell_object( rcvr, set_color((emote?
				sprintf("[Tell]%s@s %s\n", capitalize(who_from), mud_from, msg):
				sprintf("%s@%s tells you: %s\n", capitalize(who_from), mud_from, msg)), "HIC", rcvr));
	}

	// Ok. we got to tell sender how about receiver here.
	// Information about the status of the receiver.
	if( rcvr->query("ghost") ) {
		pre_ret = ( sndr_chinese?
			sprintf("%s(%s) �����ǹ����޷��ش��㡡\n", c_who_to, capitalize(who_to)):
			sprintf("%s is a ghost and can't answer.\n", capitalize(who_to)) );
	} else if( rcvr->query("inactive") )
		pre_ret = ( sndr_chinese?
			sprintf("%s(%s) ����ֹͣ��С�\n", c_who_to, capitalize(who_to)):
			sprintf("%s is presently inactive.\n", capitalize(who_to)) );
	else if( rcvr->query_temp("block_message") )
		pre_ret = sprintf("%s(%s) �����޷�������Ļ���\n", c_who_to, capitalize(who_to));
	else if( query_idle(rcvr) > IT ) {
		tmp = (string)rcvr->getenv("idlemsg");
		pre_ret = ( sndr_chinese?
			sprintf("%s(%s) ���� %s δ���ƶ��ˡ�\n", c_who_to,
				capitalize(who_to), format_c_time(query_idle(rcvr), 1)):
			sprintf("%s has been idle for %s.\n", capitalize(who_to),
				format_time(query_idle(rcvr))) ) +
			( (tmp && tmp != "")? sprintf("Idle Message: %s\n", tmp):"" );
	} else pre_ret = "";

	// Ok, add the tell message.
	if( !mud_from ) {
		// Set reply variable;
		rcvr->set("reply", who_from);

		// Extra information for local users
		if( in_edit(rcvr) )
			pre_ret = ( sndr_chinese?
				sprintf("%s%s(%s) ���ڱ༭������\n", pre_ret, c_who_to, capitalize(who_to)):
				sprintf("%s%s is editing a file.\n", pre_ret, capitalize(who_to)) );
		else if( in_input(rcvr) )
			pre_ret = ( sndr_chinese?
				sprintf("%s%s(%s) ���ڴ������ģʽ��\n", pre_ret, c_who_to, capitalize(who_to)):
				sprintf("%s%s is in input mode.\n", pre_ret, capitalize(who_to)) );

		ret = ( sndr_chinese?
			iwrap(sprintf("�����%s(%s): %s\n", c_who_to, capitalize(who_to), msg)):
			iwrap(sprintf("You tell %s: %s\n", capitalize(who_to), msg)) );
	} else {
		rcvr->set("reply", sprintf("%s@%s", who_from, mud_from));
		ret = ( sndr_chinese?
			sprintf("%s(%s) �յ����ѶϢ�ˡ�\n", c_who_to, capitalize(who_to)):
			sprintf("%s received your message.\n", capitalize(who_to)) );
	}
	return sprintf("%s%s", pre_ret, ret);
}

int check_mud(string m)
{
	int i;

	for( i=sizeof(cm)-1; i>=0; i-- )
		if( cm[i] == m ) return 1;
	return 0;
}

mixed check_channel(string str)
{
	if( channels[str] )
	return channels[str];
}

void get_channels()
{
	string line, file, channel, msg;
	int chan, i;

	file = CHANNEL_FILE;

	for( i=1; ; i++ ) {
		line = read_file(file, i, 1);
		if( !line || line == "" ) return;
		if( sscanf(line, "%s:%s:%d\n", channel, msg, chan) != 3 ) continue;
		channels[lower_case(channel)] = ({ msg, chan }); 
	}
}

void query_channels()
{
	string *c;
	int i;
	mixed *ss;

	c = keys(channels);
	for( i= sizeof(c)-1; i>=0; i-- )
		for( i=sizeof(channels)-1; i>=0; i-- ) {
			ss = channels[c[i]];
			write(sprintf("msg = %s   ---   chan = \n", ss[0], ss[1]));
		}
}

void get_cms()
{
	string file, mud;
	int i, j;

	file = CHANNEL_INTERMUDS;
	for( i=1; ; i++ ) {
		mud = read_file(file, i);
		if( !mud ) return;
		if( mud == "" || mud[0] == '#' ) continue;
		for( j=0; j<strlen(mud); j++ )
			if(mud[j] != ' ') break;
		if( mud[j] == '\n' ) continue;
		sscanf(mud, "%s\n", mud);
		cm += ({ mud });
	}
}

void write_cms()
{
	int i;

	for( i=0; i<sizeof(cm); i++ )
		write(sprintf("%s\n", cm[i]));
}
