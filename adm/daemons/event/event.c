//#pragma save_binary

//	File	:   /adm/daemons/event.c
//	Creator	:   Glenn Ferguson (Watcher@TMI)   12/12/92
//
//	System time manager
//	- Allows events to be triggered at preset time settings

#include <mudlib.h>
#include <uid.h>
#include <daemons.h>
#include <reboot.h>

inherit DAEMON;

#define SAVE_FILE	"/data/adm/daemons/event"	// Save data file
#define ERR_FILE	"/log/event_err"		// Error output file

#define INTERVAL	60			// Time check interval in sec.
#define IGNORE		900			// Remove event after X seconds
#define HOUR_DIFF	3600			// Seconds in an hour
#define DAY_DIFF	(24 * HOUR_DIFF)	// Seconds in a day
#define WEEK_DIFF	(7 * DAY_DIFF )		// Seconds in a week
#define SETUP_ARRAY	({ })			// Base storage array

protected void load_events();
protected void save_events();
protected void ERROR(string mesg, string err);
protected int check_once();
protected int check_hourly();
protected int check_daily();
protected int check_weekly();
protected int perform_event(string access, string file, string func, string arg);
protected int sort_stack(mixed *event1, mixed *event2);
int add_event(string type, mixed  *event);
protected int initiate_sweep();
protected int init_user_list();

int user_online;
string user_name_list;
mixed *HOURLY, *DAILY, *WEEKLY, *ONCE;

create()
{
	seteuid(getuid(this_object()));		// Setup save permissions

	HOURLY = SETUP_ARRAY;
	DAILY = SETUP_ARRAY;			// Setup event arrays
	WEEKLY = SETUP_ARRAY;
	ONCE = SETUP_ARRAY;

	load_events();				// Load previous saved events
	initiate_sweep();			// Start time check loop

	call_out( "auto_save",1800 );
	call_out( "auto_reclaim", FIRST_RECLAIM_DELAY );
	call_out( "auto_reboot", REBOOT_DELAY-uptime() );
	init_user_list();
}
int check_player(object ob)
{
	if (userp(ob) && !wizardp(ob) && ob->query_level())
		return 1;
}
int init_user_list()
{
	object *usr;
	int i;
	usr = users()+ all_inventory(find_object_or_load("/d/std/rooms/netdead"));
	usr = filter_array(usr,"check_player",this_object());
	user_online = sizeof(usr);
	user_name_list = "";
	for ( i = user_online-1 ; i >= 0 ; i-- ) {
		user_name_list += capitalize((string)usr[i]->query("name"))+", " ;
	}
	return 1;
}
int add_online_user(int login,string who)
{
	string *tmp;
	int i;
	if (login) {
		user_online++;
		user_name_list = who+", "+( user_name_list ? user_name_list : "");
	} else {
		user_online--;
		tmp = explode(user_name_list,who+", ");
		if ( sizeof(tmp) ) {
			user_name_list = "";
			for ( i = 0; i < sizeof(tmp) ; i ++ )
				user_name_list += tmp[i] ;
		}
//		if (sscanf(user_name_list,"%s"+who+", "+"%s",tmp1,tmp2)==2)
//			user_name_list = tmp1 + tmp2;
	}
	return 1;
}

int user_online()
{
	return user_online;
}
string show_users()
{
	return (user_online ? user_name_list : "");
}
void auto_reboot()
{
	// Auto Reboot after 30 mins.
	SHUTDOWN_D->start_shutdown(0, 30);
}
void save_user(object *usr)
{
//	object ob;
	if ( !sizeof(usr) ) {
		call_out("auto_save",1800 );
		return ;
	}
	if ( objectp(usr[0]) && !nullp(usr[0]) && usr[0]->link_data("name")
		&& !usr[0]->query_linkdead()) {
//	if ( ob = find_player("ruby") )
//		tell_object(ob,(string)usr[0]->link_data("name")+sizeof(usr)+"  \n");
		usr[0]->save_me();
		usr[0]->quick_message("�Զ����� ... ��ϡ�\n");
	}
	usr -= ({ usr[0] }) ;
	call_out("save_user",10,usr);
	return ;
}
void auto_save()
{
	object *usr ;
	usr = users() ;
	call_out("save_user",1,usr );
}
void reclaims()
{
	reclaim_objects();
	call_out( "reclaims",RECLAIM_DELAY+random(600) );
}
void auto_reclaim()
{
	call_out( "reclaims",RECLAIM_DELAY+random(600) );
}

// Load preset event stacks from save file
protected void load_events()
{
   string err;

   err = catch( restore_object(SAVE_FILE) );
   if(err) {  ERROR("Could not load data file", err);  return;  }
}

// Save present event stacks into save file
protected void save_events()
{
   string err;

   err = catch ( save_object(SAVE_FILE) );
   if(err) {  ERROR("Could not save data file", err);  return;  }
}

// Stack accessing error output to error file with time stamp
protected void ERROR(string mesg, string err)
{
   write_file(ERR_FILE, mesg + "\t[" + extract(ctime(time()),4,15) + "]\n");
   if(err && err != "")
   write_file(ERR_FILE, " " + err + "\n\n");
   else write_file(ERR_FILE, "\n");
   return;
}

// Cycling stack check function at INTERVAL intervals
protected int initiate_sweep()
{
   remove_call_out("initiate_sweep");
   call_out("initiate_sweep", INTERVAL);	// Set next time check

   check_once();				// Perform once stack check
   check_hourly();				// Perform hourly stack check
   check_daily();				// Perform daily stack check
   check_weekly();				// Perform weekly stack check

   return 1;
}

//  Event stack processing functions - Called by initiate_sweep()
protected int check_daily()
{
   mixed *tmp;
   int loop;

   if(DAILY == SETUP_ARRAY)  return 1;		// No events stored
   while( DAILY[loop] ) {
     tmp = DAILY[loop];				// Temp. store event data
     if(time() < DAILY[loop][0])  return 1;	// Check again next interval
     if(time() - DAILY[loop][0] <= IGNORE)
       perform_event(DAILY[loop][4], DAILY[loop][1], DAILY[loop][2],
		    DAILY[loop][3]);

     // Remove present event, then reschedule it in the stack
     // in a day's time with same parameters.
     DAILY = exclude_array(DAILY, loop);
     add_event("daily", ({ tmp[0]+DAY_DIFF, tmp[1], tmp[2], tmp[3], tmp[4] }) );
     save_events();

     if(DAILY == SETUP_ARRAY) break;
   }
   return 1;
}

protected int check_hourly()
{
   mixed *tmp;
   int loop;

   if(HOURLY == SETUP_ARRAY)  return 1;		// No events stored
   while( HOURLY[loop] ) {
     tmp = HOURLY[loop];
     if(time() < HOURLY[loop][0])  return 1;	// Check again next interval
     if(time() - HOURLY[loop][0] <= IGNORE)
       perform_event(HOURLY[loop][4], HOURLY[loop][1], HOURLY[loop][2],
		    HOURLY[loop][3]);

     // Remove present event, then reschedule it in the stack
     HOURLY = exclude_array(HOURLY, loop);
     add_event("hourly", ({ tmp[0]+HOUR_DIFF, tmp[1], tmp[2], tmp[3], tmp[4] }));
     save_events();

     if(HOURLY == SETUP_ARRAY) break;
   }
   return 1;
}

protected int check_weekly()
{
   mixed *tmp;
   int loop;

   if(WEEKLY == SETUP_ARRAY)  return 1;		// No events stored

   while( WEEKLY[loop] ) {
     tmp = WEEKLY[loop];
     if(time() < WEEKLY[loop][0])  return 1;	// Check again next interval
     if(time() - WEEKLY[loop][0] <= IGNORE)
       perform_event(WEEKLY[loop][4], WEEKLY[loop][1], WEEKLY[loop][2],
		    WEEKLY[loop][3]);

     // Remove present event, then reschedule it in the stack
     // in a week's time with same parameters.
     WEEKLY = exclude_array(WEEKLY, loop);
     add_event("weekly", ({ tmp[0]+WEEK_DIFF, tmp[1], tmp[2], tmp[3], tmp[4] }));
     save_events();

     if(WEEKLY == SETUP_ARRAY) break;
   }
   return 1;
}

protected int check_once()
{
   int loop;

   if(ONCE == SETUP_ARRAY)  return 1;		// No events stored
   while( ONCE[loop] ) {
     if(time() < ONCE[loop][0])  return 1;	// Check again next interval
     if(time() - ONCE[loop][0] <= IGNORE)
       perform_event(ONCE[loop][4], ONCE[loop][1], ONCE[loop][2], ONCE[loop][3]);

	 // Remove event from the stack and procede to next event
     ONCE = exclude_array(ONCE, loop);
     save_events();

     if(ONCE == SETUP_ARRAY) break;
   }
   return 1;
}

// Perform preset event on remote object
protected int perform_event(string access, string file, string func, string arg)
{
   object what;
   string permis, err;

   // Attempt to locate requested target file
   err = catch( call_other(file, "???") );
   if( !err )  what = find_object(file);
   if( err || !what ) {
     ERROR("Event error:  Could not load " + file, err);
     return 1;
   }

   // Get user's command permission string
   permis = geteuid(what);

   // If attempting to access ROOT object without ROOT permissions,
   // block and log illegal access attempt
   if(permis == ROOT_UID && access != ROOT_UID &&
      !member_group(access, "admin") ) {
      ERROR("Event error:  Illegal root access attempt by " + access,
	        "  " + func + "(" + arg + ")  on  " + file);
      return 1;
   }

   // Perform stored function call on specified object
   seteuid(ROOT_UID);
   err = catch( call_other(what, func, arg) );

   if(err)
   	 ERROR("Event error: ("+identify(what)+") "+file+"->"+func+"(\""+arg+"\")", err);

   return 1;
}

//  Add new event to a specified event stack
int add_event(string type, mixed *event) {
   mixed *tmp;
   int loop, flag;

   // Check accessing permissions ... ensure root command

   if(geteuid(previous_object()) != ROOT_UID &&
      previous_object() != this_object())	return 0;

   if(sizeof(event) != 5)  return 0;		// Invalid event array

   // Store specific stack into a temporary array

   if(type == "once")		    tmp = ONCE;
   else if(type == "hourly")	tmp = HOURLY;
   else if(type == "daily")	    tmp = DAILY;
   else if(type == "weekly")	tmp = WEEKLY;
   else return 0;				// Invalid type format

   //  Add new event to stack, then sort events in increasing time

   tmp += ({ event });
   tmp = sort_array(tmp, "sort_stack", this_object());

   // Replace updated event arrays from tmp

   if(type == "once")		    ONCE = tmp;
   else if(type == "hourly")	HOURLY = tmp;
   else if(type == "daily")	    DAILY = tmp;
   else if(type == "weekly")	WEEKLY = tmp;

   save_events();				// Save updated event stack
   return 1;
}

//  Event stack sorting routine
protected int sort_stack(mixed *event1, mixed *event2)
{
	return ( event1[0] - event2[0] );
}


//  Event removal from specific event stack
int remove_event(string type, mixed *event)
{
   mixed *tmp;
   int pos;

   // Check accessing permissions ... ensure root command
   if(geteuid(previous_object()) != ROOT_UID)	return 0;

   // Store stack array into temporary array
   if(type == "once")		    tmp = ONCE;
   else if(type == "hourly")	tmp = HOURLY;
   else if(type == "daily")	    tmp = DAILY;
   else if(type == "weekly")	tmp = WEEKLY;
   else return 0;

   pos = member_array(event, tmp);
   if(pos == -1)  return 0;			// No such event found

   tmp -= ({ event });

   // Replace updated array back into stack
   if(type == "once")		    ONCE = tmp;
   else if(type == "hourly")	HOURLY = tmp;
   else if(type == "daily")	    DAILY = tmp;
   else if(type == "weekly")	WEEKLY = tmp;

   save_events();

   return 1;
}

// External stack request query for event command
mixed *query_stack(string type)
{
   if(type == "once")		    return ONCE;
   else if(type == "hourly")	return HOURLY;
   else if(type == "daily")	    return DAILY;
   else if(type == "weekly")	return WEEKLY;
   else if(type == "all")
	 return ({ ONCE, HOURLY, DAILY, WEEKLY });

   return 0;
}
