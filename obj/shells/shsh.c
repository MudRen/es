 
/***
 ***	  Shadow Shell Display System  [Version 4.5]
 ***	  - Created by Glenn Ferguson  ( Watcher@TMI, GateWay )
 ***
 ***	      Copyright (1993)  -  All Rights Reserved.
 ***
 ***		      TMI DISTRIBUTION VERSION
 ***
 ***	  You must have an ANSI compatible terminal to use the window
 ***	  portions of the shadow shell system.
 ***
 ***	  You are free to use any portion of this file as you wish, but 
 ***      please maintain my name in the header.  If you have a bug fix or 
 ***      a better way of doing part of the shell, please let me know. :)
 ***
 ***	  Refer to the shell man page for detailed information on
 ***	  specific shell functions and commands.
 ***
 ***	  Last Updated  :  04/30/1993
 ***/
 
#include <mudlib.h>
#include <net/daemons.h>
#include <config.h>
#include <net/socket.h>

inherit OBJECT ;
 
#define ESC	""
#define CSI	ESC + "["
#define BEEP	""
 
#define WHOM 	environment(this_object())
#define NAME	capitalize((string)this_player()->query("name"))
#define TIME	extract(ctime(time() + (time_mod * 60)), 4, 15)
#define HISTORY	(string *)environment()->query_history()
 
#define NULL		({ })		/** Null empty building array **/
#define SVERSION		"4.5"		/** Shadow Shell version number **/
#define COMMCHAR	"/"		/** Precharacter for commands **/
#define RCFILE		".ssrc"		/** RC save file name **/
#define	RCDEF		0		/** Default toggle of RCFILE save **/
#define MAX_ALARM	5		/** Default maximum allowed alarms **/
#define MAX_buffer1	100		/** Maximum lines stored in buffer1 **/
#define MAXSOCKET	2		/** Max number of open connections **/
 
#define ALLOW		1		/** Insert Shell Security here **/
 
#define COLOUR	({ ({ "default","red","green","yellow","blue","magenta", \
		      "cyan","white","light red","light green","light yellow",\
		      "light blue","light magenta","high white" }), \
		    ({ "-","31","32","33","34","35","36","37","1;31","1;32",\
		       "1;33","1;34","1;35","1;36","1;37" }) })
 
//	Function prototypes
 
static string define_user_path();
static string query_socket_error(int err);
static int restore_array(string array);
static int add_buffer1(string mesg);
static int display_alarms();
static void init_divider();
static set_main_window();
static int send_mesg(string str, int win);
static int file_completion(string str);
static new_window_size(string size);
static int shell_help(string str);
static int setup_screen();
static int stop_shell();
static int mark_text(string str);
static int unmark_text(string str);
static int display_assign();
static int display_text_list(string str);
static int save_rcfile();
static mixed *process_choice(string str);
static mixed *process_users();
static string comm_catch(string mess);
static int conduct_history(int num);
nomask int socket_permission();
string save_array();
string process_dir(string str);
static int vis_ck();
static int busy_ck();
 
//	Global shell variables - Saved in RCFILE file
 
mixed *window, *GAG, *HILITE, *ASSIGN, *ALARM, *PAGE;
string *cursor1, *divider, *hilight, *snoop, *buffer1;
int MAX, time_mod, rcflag, fcflag;
 
//	Static global shell variables - Not retained in save file
 
static object old_room;
static mixed *sweep, *socket, *buff_pos;
static string prompt, time, dir, *buffer1, *TMP_buffer1;
static int Status, scheck, vis, busy, HOME, help;
 
create() {
 
	set("id", ({"shadow shell", "shell", "shsh"}) );
	set_name( "shell", "shell" );
	set_short( "Shadow shell", "Shadow shell" );
	set_long( "This is Watcher's Shadow Shell System [Version " +
		SVERSION + "]\nType \"help shell\" for shell commands.\n");
	set("prevent_drop", 1);
 
        MAX = 24;                        /** Default Screen Length **/
        HOME = 1;                        /** Default Home Window **/
	GAG = NULL;			 /** Setup GAG array **/
	HILITE = NULL;			 /** Setup HILITE array **/
	PAGE = NULL;			 /** Setup PAGE array **/
	ASSIGN = ({ NULL, NULL });	 /** Setup Assignment array **/
	ALARM = NULL;			 /** Setup Alarm array **/
	buffer1 = NULL;			 /** Setup buffer1 holding array **/
	socket = ({ NULL, NULL, NULL }); /** Setup socket system **/
	rcflag = RCDEF;			 /** Set rcflag as default **/
	buff_pos = ({ 0, 0 });		 /** buffer1 parameter setup **/
	window = ({ 0,0,0,0,0,0 });	 /** Window array framework **/
	seteuid(getuid(this_object()));  /** Set object permissions **/
 
	cursor1 = ({ "default", "-" });	 /** Setup default colour **/
	divider = ({ "default", "-" });
	hilight = ({ "default", "-" });
	snoop = ({ "red", "0;31" });
	buffer1 = ({ "yellow", "1;33" });
}
 
/**
 **	Override Simul_efun message rerouting
 **	  - Necessary to maintain shell as previous_object() in
 **	    message rerouting in /std/user.c's receive_message()
 **/
 
#include "/adm/simul_efun/write.c"
#include "/adm/simul_efun/say.c"
#include "/adm/simul_efun/tell_object.c"
 
/**
 **	Shell's user command function
 **/
 
int command_user(string what) {
 
   this_player()->force_me(what);

return 1; }
 
 
/**
 **	Shell autoloading routines
 **/
 
string query_auto_load() {
   string par1;  int par2;
 
   sscanf(file_name(this_object()),"%s#%d", par1, par2);
 
   if(save_rcfile())  return par1 + ":";
 
return par1 + ":" + HOME + "||" + save_array(); }
 
static int save_rcfile() {
   string where;
 
   if(WHOM && rcflag && (where = define_user_path()) != "") {
   save_object(where); return 1; }
 
return 0; }
 
init_arg(string arg) {
   string saved;
 
   if(!arg || arg == "")  return;
 
   sscanf(arg,"%d||%s", HOME, saved);
   restore_array(saved);
   MAX = window[ sizeof(window)-1 ];
 
return; }
 
int clean_up() {  return 1;  }		// Prevent inadvertant clean_up
 
//	Locate the user's RCFILE save directory
 
static string get_home_path() {
   string name;
 
   name = (string) WHOM->query("name");

return "/u/" + extract(name,0,0) + "/" + name + "/"; }
 
//	Locate path to user's ssrc save file
 
static string define_user_path() {
 
   if(file_size(get_home_path()) != -2) {
   tell_object(WHOM,"\nShsh: Error in locating user home directory.\n       "+
	"Reverting to autoload save format.\n");
   rcflag = 0;
   return ""; }
 
return get_home_path() + RCFILE; }
 
//	Restore saved shell attributes
 
static int restore_attr_file() {
   string where;
 
   where = get_home_path();
   if((!rcflag && window[0] != 0) || file_size(where) != -2 ||
      file_size(where + RCFILE + SAVE_EXTENSION) < 0) return 1;
 
   restore_object(where + RCFILE);
 
return 1; }
 
string save_array() {    /** Converts numeric array to a savable string **/
   string array, temp;
   int loop;
 
   for(array="",loop=0; loop<sizeof(window); loop++)
   array += ( window[loop] + "," );
   array += "X";                        /** End point mark **/
 
return array; }
 
/*** Converts loaded strings back into numeric array ***/
 
static int restore_array(string array) {
   int number;
 
   window = ({ });
   while(sscanf(array,"%d,%s",number,array)==2) 
   window += ({ number });
 
return 1; }
 
 
void init() {
 
	//  If the environment isn't a user ... remove the shell.
 
	if(environment() && !interactive(environment())) {
	  remove();  return;  }
 
	//  Check user's permissions to use the shell
 
        if(!ALLOW || this_player() != environment())  return;
 
	//  Set the shell's euid to that of the user
 
	seteuid(getuid(this_player()));
 
	add_action("player_quit",	"quit");
	add_action("command_catch",	"", 1);
        add_action("system_config",	"configure");
	add_action("toggle_shell",	"shsh");
        add_action("clean_screen",	"cls");
        add_action("shell_help",	"help");
        add_action("add_window",	"add");
        add_action("rem_window",	"remove");
        add_action("refresh_shell",	"refresh");
        add_action("change_window",	"change");
 
	add_action("assign_comm", 	COMMCHAR + "assign");
	add_action("unassign_comm", 	COMMCHAR + "unassign");
	add_action("change_time", 	COMMCHAR + "time");
	add_action("add_alarm", 	COMMCHAR + "alarm");
	add_action("rem_alarm", 	COMMCHAR + "unalarm");
	add_action("switch_window", 	COMMCHAR + "goto");
	add_action("beep_other", 	COMMCHAR + "beep");
	add_action("mark_text", 	COMMCHAR + "gag");
	add_action("unmark_text", 	COMMCHAR + "ungag");
	add_action("mark_text", 	COMMCHAR + "hilite");
	add_action("unmark_text", 	COMMCHAR + "unhilite");
	add_action("mark_text", 	COMMCHAR + "page");
	add_action("unmark_text", 	COMMCHAR + "unpage");
	add_action("shell_status", 	COMMCHAR + "status");
	add_action("display_text_list", COMMCHAR + "history");
	add_action("open_buffer1", 	COMMCHAR + "buffer1");
	add_action("completion_mode", 	COMMCHAR + "fc");
	add_action("conduct_history", 	COMMCHAR + "do");
 
	if(socket_permission()) {
        add_action("connect_window", 	COMMCHAR + "open");
        add_action("disconnect_window", COMMCHAR + "close");
	}
 
	restore_attr_file();	/**  Restore saved attributes  **/
}
 
//	Designation of shadow shell version
 
string query_version() { return SVERSION; }
 
//	Indicates shell activity status
//	   - Returns 1 if shell is active, 0 if shell is inactive
 
int query_status() { return Status; }
 
//	Function used by status window for maintaining status display
 
static int status_check() {
   int scheck;
 
   if(vis_ck() != vis) { vis = vis_ck(); scheck = 1; }
   if(busy_ck() != busy) {  busy = busy_ck();  scheck = 1; }
 
return scheck; }
 
/** Status Function checks **/
 
static vis_ck() { return (int)WHOM->query("invisible");  }
static busy_ck() { return (int)WHOM->query("busy");  }
 
 
/**
 **	ANSI Function/Window Library processing calls
 **/
 
static void Talk(string str) {  tell_object(WHOM, str);  }
 
static void clear_window(int top, int bottom) {
   Talk(CSI + top + "H" + CSI + (bottom - top) + "M"); }
 
static void win_size(int top, int bottom) {  Talk(CSI+top+";"+bottom+"r"); }
 
static void save_position() { Talk(ESC+"7"); } 
 
static void restore_position() { Talk(ESC+"8"); }
 
static void new_pos(int pos) { Talk(CSI+pos+"H"); }
 
static string invert(string mess) {
   if(hilight[1] != "-")				// Add colour
	return (CSI + "7m" + CSI + hilight[1] + "m" + mess + CSI + "0m" +
		(cursor1[1] != "-" ? CSI + cursor1[1] + "m" : ""));
   else return (CSI + "7m" + mess + CSI + "0m" +
		(cursor1[1] != "-" ? CSI + cursor1[1] + "m" : ""));  }
 
static void erase_line(int pos) { Talk(CSI + pos + "H" + CSI + "2K"); }
 
static void form_line(int pos, int wind) {
   save_position();
   new_pos(pos);
 
   if(divider[1] != "-")  Talk(CSI + divider[1] + "m");   /* Colour */
 
   if(wind == -1)
   Talk("==[Communication]==================================================" +
  	"=============");
   else if(wind)
   Talk("==[Window " + wind + "]============================================" +
	"========================");
   else
   Talk("===================================================================" +
	"============");
 
   if(divider[1] != "-")  Talk(CSI + "0m");	/* Turn colour off */
   if(cursor1[1] != "-")   Talk(CSI + cursor1[1] + "m");  /* cursor1 colour */
 
   restore_position();
 
}
 
//	Place a description label on window separation divider
 
static void label_line(string mesg, int win) {
 
   if(!mesg || mesg == "") {
   form_line(window[(HOME*2)+2]-1, HOME);
   return;  }
 
   save_position();
   new_pos(window[(win*2)+2]-1);
 
   Talk(CSI + "15C" + "[" + mesg + "]");
 
   restore_position();

}
 
 
 /***
  ***     Return to main HOME window
  ***     - The main window can be changed by changing the HOME 
  ***       variable to the new window number
  ***/
 
static int main_screen() {
   string tmp;
   int position;
 
   position = (HOME + 1) * 2;
 
   if(position > sizeof(window)-1) {
   write("Error:  Set home window is out of array bounds.\n");
   return 0; }
 
   win_size(window[position],window[position+1]);
   
   if(member_array(query_verb(), ({ "shsh", "refresh" })) == -1)
	new_pos(window[position + 1]);
   else new_pos(window[position]);
 
   tmp = "" + (window[position + 1] - window[position]) + "";
 
   environment()->setenv("LINES", tmp);	  /* Adjust pager to window size */
   environment()->do_new();
 
return 1; }
 
 
 /**	 Write a message to a specific shell window
  **
  **     - Window 0 is to the Communication window
  **     - Window 1 is to the main interactive window
  **	 - Window X is to the Xth open window (Window 0 if X is nonexistent)
  **
  **	 Ex:  write_window(0,"Watcher begins to glow.", "tell_object");
  **          will write that message to the communication window.
  **/
 
void write_window(int num, string mess, string type) {
   string *tmp;
   int position, where;
  
   mess = comm_catch(mess);	// Adjustment to message via gag/hilite/etc
   if(!mess || mess == "")  return;
 
   if(previous_object() != this_object())	// Store message to buffer1
	add_buffer1(mess);
 
   //	Label incoming snoop communication with optional colour
 
   if(type == "snoop" && snoop[0] != "default")
	mess = CSI + snoop[1] + "m" + mess + CSI + "0m";
 
   //	If the user is in a socket window, block any prompts from host mud
 
   if(mess == prompt && member_array(HOME, socket[1]) != -1)  return;
 
   //	If message is a standard write message, dump straight to screen
 
   if(type == "write") {  Talk( mess );  return;  }
 
   tmp = explode(mess, "\n");   mess = implode(tmp, "\n");
 
   if(!Status)  mess += "\n";
 
   //	Reroute to window 1 if comm isn't present and 
   //	active window is 2 or greater.
 
   if(!num && !window[2] && HOME > 1)  num = 1;
 
   if((!num && !window[2]) || !Status) {
   Talk( mess );				// Relay incoming message
   if(mess == prompt)  Talk("\n");
   return; }
 
   where = member_array(type, ASSIGN[0]);    /* Check for reassignment */
   if(where != -1)  num = ASSIGN[1][where];
 
   if(num == -1)  return 0;	/* Communication redirected to nul */
 
   //	Located requested window access point
 
   position = (num + 1) * 2;
   if(position > sizeof(window)-1 || position < 2)  position = 2;
 
   //	Write incoming message to specified window
 
   save_position();
   win_size(window[position], window[position+1]);
   new_pos(window[position+1]);
   mess = "\n" + mess;                        /** Scroll window up **/
   Talk(mess);
   main_screen();
   restore_position();
 
return; }
 
/**
 **	Mudlib Message communication relay
 **	 - Called from receive_message() in user object
 **/
 
receive_message(string class1, string msg) {
  return write_window(0, msg, class1);  }
 
//	Cycling refresh system for updating status window
 
refresh_status() {
   int size;
 
   remove_call_out("refresh_status");
   call_out("refresh_status",0);
 
   //	Updated records of present user prompt
 
   prompt = (string)environment()->write_prompt(1);
 
   if(status_check()) {
   save_position();
   new_pos(window[0] + 1);
 
   Talk("Status: ");
   if(vis_ck()) Talk("You are invisible   ");
   else Talk("You are visible     ");
 
   Talk("Busy flag: ");
   if(busy) Talk("Active       ");  else Talk("Inactive     ");
 
   Talk("Time: " + TIME );  
   time = TIME;
 
   restore_position(); }
 
   if(time != TIME) {
   save_position();
   Talk(CSI + "2;53HTime: " + TIME );
   time = TIME;
   restore_position();  }
 
   if(environment(WHOM) == old_room &&
      (string)environment()->query("cwd") == dir)  return;
   old_room = environment(WHOM);
   dir = (string)environment()->query("cwd");
 
   save_position();
   new_pos(window[0]);
   erase_line(window[0]);
   Talk("["+file_name(environment(WHOM))+"]  ");
   Talk(invert((string)environment(WHOM)->query("short")));
   size = strlen(" [Cwd: " + process_dir(dir) + "] ");
   Talk(CSI + "0;" + (81-size) + "H [Cwd: " + process_dir(dir) + "] ");
   restore_position();
 
}
 
//	Setup outline and preliminary status of status window
 
static create_status() {
 
   old_room = 0;   vis = -1;
   if(window[1] == MAX)  form_line(MAX - 3, 1);
   else if(window[2])  form_line(window[1], -1);
   else form_line(window[1], 1);
   refresh_status();
 
return 1; }
 
//	Command function for activating/deactivating shell system
 
int toggle_shell(string str) {
 
   if(Status)	notify_fail("Your Shadow shell is presently active.\n" +
			    "Usage: shsh [on/off]\n");
   else		notify_fail("Your Shadow shell is presently inactive.\n" +
			    "Usage: shsh [on/off]\n");

   if(str == "on") 		return setup_screen();
   else if(str == "off")	return stop_shell();

return 0; }
 
//	Draw window divisions and setup initial shell systems
 
static setup_screen() {
 
   if(!window[0] && !window[2] && !window[4]) {
   write("Your shell system has not been configured.\n");
   return 1; }
 
   if(Status) { 
   write("Your shell system is already active.\n");
   return 1; }
 
   Talk(CSI + "2J");			//  Clears user string
   Talk(CSI + "0m");			//  Reset Screen colours
 
   if(cursor1[1] != "-")  	
     Talk(CSI + cursor1[1] + "m");	//  cursor11 colour
 
   if(window[0])   create_status();
   init_divider();
   main_screen();
   Status = 1;
 
   if(query_verb() == "shsh")  
	Talk("Shadow Shell enabled.\n");
 
return 1; }
 
//   Creates divider lines for each created window
 
static void init_divider() {
   int loop, pos;
 
   if(!window[2]) pos = 6;    else pos = 4;
   for(loop=pos; loop<sizeof(window); loop += 2)
   form_line(window[loop - 1]+1, loop/2-1);
}
 
 
 /**
  **    Shell System User configuration
  **/
 
static system_config(string str) {
   notify_fail("Usage: configure shell\n");
 
   if(!id(str)) return 0;
 
   //	Clear previous window setup designations
 
   HOME = 1;
   window = ({ 0,0,0,0,0,0 });
   remove_call_out("refresh_status");
 
   write("Shadow Shell Configuration\n\n");
   write("  Input your screen length [Default 24] : ");
   input_to("screen_length");
 
return 1; }
 
static screen_length(string length) {
   int temp;
 
   if(!length || length == "") {
   write("  Default screen length maintained.\n");
   MAX = 24; }
 
   else {
   temp = atoi(length);
 
     if(!intp(temp) || temp < 1) {
     write("\n  Invalid shell screen length.\n");
     write("  Input your screen length [Default 24] : ");
     input_to("screen_length");
     return 1; }
 
   MAX = temp; }
 
   write("\n  Change default screen colours [yes/no] : ");
   input_to("change_colour");
 
return 1; }
 
static change_colour(string str) {
   string hold;
   int loop;

   if(!str || member_array(lower_case(str),({"yes","y","no","n"})) == -1) {
   write("  Change default screen colours [yes/no] : ");
   input_to("change_colour");
   return 1;  }
 
   if(member_array(lower_case(str), ({ "no", "n" })) != -1) {
   write("\n  Initiate status window [yes/no] : ");
   input_to("status_set");
   return 1; }
 
   hold = "\nAvailable colours: ";
   
   for(loop=0; loop<sizeof(COLOUR[0]); loop++) {
	hold += COLOUR[0][loop];
	if(loop < sizeof(COLOUR[0])-1) hold += ", ";
	if(loop == sizeof(COLOUR[0])-2) hold += "and ";  }
 
   write(wrap(hold + ".") + "\n");
   write("  [Please Note:  Not all terminals support all above colours]\n\n");
 
   write("  cursor1 [" + cursor1[0] + "] : ");
   input_to("cursor1_colour");
 
return 1; }
 
static cursor1_colour(string str) {
   int pos;
 
   if(!str || str == "") {
   write("  Colour unchanged.\n\n  Dividers [" + divider[0] + "] : ");
   input_to("divider_colour");
   return 1; }
 
   pos = member_array(lower_case(str), COLOUR[0]);
 
   if(pos == -1) {
   write("  cursor1 [" + cursor1[0] + "] : ");
   input_to("cursor1_colour");
   return 1; }
 
   write("  Colour changed.\n");
   cursor1[0] = COLOUR[0][pos];   cursor1[1] = COLOUR[1][pos];

   write("\n  Dividers [" + divider[0] + "] : ");
   input_to("divider_colour");
 
return 1; }
 
static divider_colour(string str) {
   int pos;
 
   if(!str || str == "") {
   write("  Colour unchanged.\n\n  Snooping [" + snoop[0] + "] : ");
   input_to("snoop_colour");
   return 1; }
 
   pos = member_array(lower_case(str), COLOUR[0]);
 
   if(pos == -1) {
   write("  Dividers [" + divider[0] + "] : ");
   input_to("divider_colour");
   return 1; }
 
   write("  Colour changed.\n");
   divider[0] = COLOUR[0][pos];   divider[1] = COLOUR[1][pos];
 
   write("\n  Snooping [" + snoop[0] + "] : ");
   input_to("snoop_colour");
 
return 1; }
 
static snoop_colour(string str) {
   int pos;
 
   if(!str || str == "") {
   write("  Colour unchanged.\n\n  buffer1 [" + buffer1[0] + "] : ");
   input_to("buffer1_colour");
   return 1; }
 
   pos = member_array(lower_case(str), COLOUR[0]);
 
   if(pos == -1) {
   write("  Snooping [" + snoop[0] + "] : ");
   input_to("snoop_colour");
   return 1; }
 
   write("  Colour changed.\n");
   snoop[0] = COLOUR[0][pos];   snoop[1] = COLOUR[1][pos];
 
   write("\n  Hilights [" + hilight[0] + "] : ");
   input_to("hilight_colour");
 
return 1; }
 
static buffer1_colour(string str) {
   int pos;
 
   if(!str || str == "") {
   write("  Colour unchanged.\n\n  Hilights [" + hilight[0] + "] : ");
   input_to("hilight_colour");
   return 1; }
 
   pos = member_array(lower_case(str), COLOUR[0]);
 
   if(pos == -1) {
   write("  buffer1 [ " + buffer1[0] + "] : ");
   input_to("buffer1_colour");
   return 1; }
 
   write("  Colour changed.\n");
   buffer1[0] = COLOUR[0][pos];   buffer1[1] = COLOUR[1][pos];
 
   write("\n  Hilights [" + hilight[0] + "] : ");
   input_to("hilight_colour");
 
return 1; }
 
static hilight_colour(string str) {
   int pos;
 
   if(!str || str == "") {
   write("  Colour unchanged.\n\n  Initiate status window [yes/no] : ");
   input_to("status_set");
   return 1; }
 
   pos = member_array(lower_case(str), COLOUR[0]);
 
   if(pos == -1) {
   write("  Hilights [" + hilight[0] + "] : ");
   input_to("hilight_colour");
   return 1; }
 
   write("  Colour changed.\n");
   hilight[0] = COLOUR[0][pos];   hilight[1] = COLOUR[1][pos];
   
   write("\n  Initiate status window [yes/no] : ");
   input_to("status_set");
 
return 1; }
 
static status_set(string str) {
 
   if(str == "yes" || str == "y") {
   window[0] = 1;  window[1] = 3; }
 
   else if(str == "no" || str == "n") {
   window[0] = 0;  window[1] = 0; }
 
   else {
   write("  Initiate status window [yes/no] : ");
   input_to("status_set");
   return 1; }
 
   write("\n  Initiate communication window [yes/no] : ");
   input_to("comm_set");
 
return 1; }
 
static comm_set(string str) {
 
   if(str == "yes" || str == "y") {
   write("\n  Communication window size [Default 5] : ");
   input_to("set_comm_size");
   return 1; }
 
   else if(str == "no" || str == "n") {
   window[2] = 0;  window[3] = 0; }
 
   else {
   write("  Initiate communication window [yes/no] : ");
   input_to("comm_set");
   return 1; }
 
   set_main_window();
 
   write("\n  Save attributes in a record file? [Default: ");
   if(rcflag) write("yes] ");  else write("no] ");
   input_to("rcfile_choice");
 
return 1; }
 
static set_comm_size(string size) {
   int temp;
 
   if(!size || size == "") {
   write("  Default communication window size maintained.\n");
   temp = 5; }
 
   else {
   temp = atoi(size);
 
     if(!intp(temp) || temp < 1) {
     write("\n  Invalid communication window size.\n");
     write("  Communication window size [Default 5] : ");
     input_to("set_comm_size");
     return 1; }
 
   }
 
   if(!window[0])  window[2] = 1;
   else window[2] = 4;
   window[3] = window[2] + temp;
 
   set_main_window();
 
   write("\n  Save attributes in a record file? [Default: ");
   if(rcflag) write("yes] ");  else write("no] ");
   input_to("rcfile_choice");
 
return 1; }
 
static rcfile_choice(string str) {
   string where;
 
   if(str!="" && !(member_array(lower_case(str),({"yes","y","no","n"}))+1)) {
   write("\n  Invalid choice responce (yes/no)\n  Save attributes in a " +
	 "record file? [Default: ");
   if(rcflag) write("yes] ");  else write("no] ");
   input_to("rcfile_choice");
   return 1; }
 
   if(str == "yes" || str == "y" || str == "Y") rcflag = 1;
   else if(str == "no" || str == "n" || str == "N") rcflag = 0;
 
   if(rcflag && (where = define_user_path()) != "") {
   if(file_size(where + SAVE_EXTENSION) > -1)
     write("  Updating shell \"" + RCFILE + "\" file.\n");
   else write("  Creating shell \"" + RCFILE + "\" file.\n");
   save_rcfile(); }
 
   write("\nShell configuration complete.\n");
   if(Status) write("Type \"refresh shell\" to update screen setup.\n");
 
return 1; }
 
static set_main_window() {
 
   if(!window[0] && !window[2]) {
   window[4] = 1;  window[5] = MAX;
   return 1; }
 
   if(window[2]) {
   window[4] = window[3] + 2;
   window[5] = MAX;
   return 1; }
 
   window[4] = window[1] + 1;
   window[5] = MAX;
 
return 1; }
 
//	Modify time display according to user's timezone position
 
static int change_time() {

   write("Present Mud time\t:  " + extract(ctime(time()), 4, 15) + "\n" +
	 "Present Shell time\t:  " + TIME + "\n\n" +
	 "Shell time zone modification [" + time_mod + " minutes] : ");
   input_to("modify_time");
 
return 1; }
 
static int modify_time(string str) {
   int num;

   if(!str || str == "") {
   write("Time zone modification unchanged.\n");
   return 1; }
 
   if(str == "none")  str = "0";

   if(sscanf(str, "%d", num) != 1)  {
   write("Illegal modification.  Value unchanged.\n");
   return 1; }

   write("Time modification changed.\n");
   time_mod = num;
   save_rcfile();
 
return 1; }
 
//	Terminate and clear shell screen system
 
static stop_shell() {
   int loop;
 
   remove_call_out("refresh_status");
 
   //	Remove shell LINES designation size and replace any
   //	previous line environmental setup.
 
   this_player()->remove_env("LINES");
   this_player()->do_new();
 
   if(!Status) {
   write("Your shell system is not active.\n");
   return 1; }
 
   //	Close and clear any open shell terminal sockets
 
   for(loop=0; loop<sizeof(socket[0]); loop++) 
   socket_close(socket[0][loop]);
 
   socket = ({ NULL, NULL, NULL });
 
   //	Clear and reset screen and cursor1
 
   write(CSI + "0r");
   write(CSI + "H" + CSI + "J");
   write(CSI + "0m");			/** Reset cursor1 colour **/
 
   //	Save present shell designations before terminating activity
 
   if(rcflag)  save_rcfile();
   Status = 0;
 
   write("Shadow Shell disabled.\n");
 
return 1; }
 
//	Command used to clear screen or specified windows
 
int clean_screen(string str) {
   int temp;
 
   notify_fail("Usage: cls || cls comm || cls [window]\n");
 
   //	If shell isn't active, clear entire screen
 
   if(!Status) {
   write(CSI + "0r");
   write(CSI + "H" + CSI + "J");
   write("Screen cleared.\n");
   return 1; }
 
   //	If no window is specified, clear active window
 
   if(!str || str == "") {
   clear_window(window[(HOME*2)+2], window[(HOME*2)+3]);
   new_pos(window[(HOME*2)+2]);
   return 1; }
 
   if(str == "comm" || str == "communication") {
   save_position();
   win_size(window[2], window[3]);
   clear_window(window[2], window[3]+1);
   win_size(window[4], window[5]);
   restore_position();
   return 1; }
 
   if(sscanf(str,"%d",temp)!=1 || temp < 0) return 0;
   if(!temp) return clean_screen("comm");
   if(temp == 1) return clean_screen("");
 
   if((temp*2)+3 > sizeof(window)) {
   write("There is no such window open.\n");
   return 1; }
 
   save_position();
   win_size(window[(temp*2)+2], window[(temp*2)+3] + 1);
   clear_window(window[(temp*2)+2], window[(temp*2)+3] + 2);
   win_size(window[(HOME*2)+2], window[(HOME*2)+3]);
   restore_position();
 
return 1; }
 
//	Command used to add an additional window to active set
 
static add_window(string str) {
   int num;
 
   notify_fail("Usage: add window\n");
   if(str != "window" && sscanf(str,"window %d", num) != 1)  return 0;
 
   if(!Status) {
   write("You must be in shell mode to add a new window.\n");
   return 1; }
 
   if(num)  return new_window_size("" + num + "");
 
   write("Input size of new window : ");
   input_to("new_window_size");
 
return 1; }
 
static new_window_size(string size) {
   int temp, last;
 
   if(!size || size == "") {
   write("New window initiation aborted.\n");
   return 1; }
 
   if(sscanf(size,"%d",temp)!=1 || temp < 1) {
   write("Illegal new window size. Initiation aborted.\n");
   return 1; }
 
   //	Check to see if new window size is possible 
 
   last = sizeof(window) - 2;
   if(temp >= (window[last+1] - window[last])) {
   write("New window length is too large for present configuration.\n");
   return 1; }
 
   //	Clear lowest window, and add new window at requested size
 
   clear_window(window[last], MAX - 1);
   window[last + 1] -= (temp + 2);
   window += ({ (window[last + 1] +2) });
   window += ({ MAX });
   form_line(window[last + 1]+1, sizeof(window)/2-2);
   main_screen();
 
return 1; }
 
static refresh_shell(string str) {
 
   notify_fail("Usage: refresh shell\n");
   if(!id(str)) return 0;
 
   if(!Status) {
   write("Your shell system is not active.\n");
   return 1; }
 
   Status = 0;
   time = 0;		/* force status screen rewrite */
 
return setup_screen(); }
 
static rem_window(string str) {
   int last, pos;
 
   notify_fail("Usage: remove window\n");
   if(str != "window") return 0;
 
   if(!Status) {
   write("Your shell system is not active.\n");
   return 1; }
 
   last = sizeof(window) - 1;
 
   if(last == 5) {
   write("You do not have any extra windows open.\n");
   return 1; }
 
   pos = member_array((last/2 - 1), socket[1]);
 
   if(pos != -1) {		/* Close socket if one is present */
   socket[0] = exclude_array(socket[0], pos);
   socket[1] = exclude_array(socket[1], pos);
   }
 
   if(HOME == (last/2 -1)) HOME--;
   last = last -2;
   window[last] = MAX;
 
   /**  Wipe contents of the old window  **/
 
   save_position();
   win_size(window[last - 1], window[last]);
   clean_screen("" + (last/2-1));
   restore_position();
   main_screen();
 
   window = window[0..last];
 
return 1; }
 
/**
 **	Send a beep signal to another player
 **/
 
static beep_other(string str) {
   object target;
 
   notify_fail("Usage: " + query_verb() + " [player]\n");
   if(!str || str == "")  return 0;
 
   target = find_player(str);
   if(!target) {  write("No such player is active.\n");  return 1; }
 
   tell_object(target, BEEP + NAME + " signals you.\n");
   write("You signal " + capitalize(str) + ".\n");
 
return 1; }
 
int shell_help(string str) {
 
   if(str == "window" || str == "windows") {
   write("\nWindow Message-Output Information\n" +
         "---------------------------------\n\n" +
   "If you wish a certain output to be placed into a particular window\n"+
   "of the active shadow shell, simply use the following patch to the shell\n"+
    "in the target's inventory:\n\n"+
   "    present(\"shell\",target)->write_window(window #, message, " +
   "class);\n\n" +
   "If you want a message patched to the communication window, then the\n" +
   "window number is 0, with windows increasing in number from there. If\n" +
   "the window doesn't exist, the shell will relay to the communication\n" +
   "window. Adding a class designation is optional, and allows the shell\n" +
   "to further adjust the input according to preset window assignments.\n\n");
   return 1; }
 
   if(str == "shsh long" || str == "shell long") {
    help = 1; write("\n"); command_user("help shsh"); help = 0;
   return 1; }
 
   if(!id(str) || help)  return 0;
 
   write("\nWatcher's Shadow Shell  [Version " + SVERSION + "]\n" +
	 "----------------------\n\n");
   write("  Window Commands:\n");
   write("  - shsh [on/off], configure shell, refresh shell\n");
   write("  - add window, remove window, change window, " + COMMCHAR +
	 "go [num], cls [comm/window]\n\n");
   write("  Message Manipulation Commands:\n");
   write("  - " + COMMCHAR + "gag [string], " + COMMCHAR + "ungag [string/#]" +
	 ", " + COMMCHAR + "hilite [string], " + COMMCHAR + 
	 "unhilite [string/#]\n");
   write("  - " + COMMCHAR + "page [string], " + COMMCHAR + 
	 "unpage [string/#]\n");
   write("  - " + COMMCHAR + "assign [class] to [window], " +
	 COMMCHAR + "unassign [class]\n\n");
 
   if(socket_permission()) {
   write("  Socket Control Commands:\n");
   write("  - " + COMMCHAR + "open [ip number], " + COMMCHAR + "close\n\n"); 
   }
 
   write("  Miscellaneous Shell Commands:\n");
   write("  - " + COMMCHAR + "time, " + COMMCHAR + "beep [player], " +
    	 COMMCHAR + "fc, " + COMMCHAR + "status, " + COMMCHAR + "history, " +
	 COMMCHAR + "do, " + COMMCHAR + "buffer1\n");
   write("  - " + COMMCHAR + "alarm [time in minutes] [optional message], " +
         COMMCHAR + "unalarm [alarm number]\n");
 
   write("\nType \"help shsh long\" for the shadow shell's man page.\n" +
	 "You must have an ANSI terminal to use the shell window " +
	 "functions.\n\n");
 
return 1; }
 
//	If the user quits the mud...deactivate shell, then complete quit
 
int player_quit() {
   if(Status)  stop_shell();
return 0; }
 
static change_window(string str) {
   notify_fail("Usage: change window\n");
   if(str != "window") return 0;
 
   write("Input new home window : ");
   input_to("switch_window");
return 1; }
 
switch_window(string str) {
   int num;
 
   if(!str || sscanf(str,"%d",num)!=1 || !intp(num) || num < 0) {
   notify_fail("Invalid new window selection.\n");
   return 0; }
 
   if(!num) { 
   notify_fail("You cannot select the communication window as your HOME" +
	       " window.\n");
   return 0; }
 
   if(num == HOME) {
   notify_fail("You are already active in that window.\n");
   return 0; }
 
   if( (num*2 + 2) > sizeof(window)-1) {
   notify_fail("There is no such window presently open.\n");
   return 0; }
 
   HOME = num;
   main_screen();
 
   if(member_array(HOME, socket[1]) != -1)
	input_to("socket_catch", 0);
 
return 1; }
 
//	Check incoming communication for gag/hilite/etc content
//	and manipulate as required
 
static string comm_catch(string mess) {
   string tmp1, tmp2;
   int loop;
 
   for(loop=0; loop<sizeof(GAG); loop++)
   if(sscanf(" " + mess + " ", "%s" + GAG[loop] + "%s",tmp1,tmp2) == 2)
     return 0;
 
   for(loop=0; loop<sizeof(HILITE); loop++)
   if(sscanf(" " + mess + " ", "%s" + HILITE[loop] + "%s",tmp1,tmp2) == 2)
   mess = invert(mess);
 
   for(loop=0; loop<sizeof(PAGE); loop++)
   if(sscanf(" " + mess + " ", "%s" + PAGE[loop] + "%s",tmp1,tmp2) == 2)
   	Talk(BEEP);
 
return mess; }
 
static int mark_text(string str) {
   mixed *tmp;
   string verb;
   int loop;
 
   sscanf(query_verb(), COMMCHAR + "%s", verb);
   notify_fail("Usage: " + query_verb() + " [string]\n");
 
   if(verb == "gag")		tmp = GAG;
   else if(verb == "hilite")	tmp = HILITE;
   else if(verb == "page")	tmp = PAGE;

   if(!str || str == "") {
 
   if(tmp == NULL) {
   write("You have no " + verb + " strings stored.\n");
   return 0; }
 
   display_text_list(verb);
   return 0; }
 
   if(member_array(str, tmp) > -1) {
   write("You have already placed a " + verb + " on that string.\n");
   return 1; }
 
   if(verb == "gag")		GAG += ({ str });
   else if(verb == "hilite")	HILITE += ({ str });
   else				PAGE += ({ str });
 
   write("You place a " + verb + " on the string : \"" + str + "\".\n");
   save_rcfile();
 
return 1; }
 
static int unmark_text(string str) {
   mixed *fill;
   string verb;
   int tmp;
 
   sscanf(query_verb(), COMMCHAR + "%s", verb);
   notify_fail("There is no such " + verb + " string entry.\n");
 
   if(verb == "ungag")		fill = GAG;
   else if(verb == "unhilite")	fill = HILITE;
   else				fill = PAGE;
 
   if(!str || str == "") {
   display_text_list(verb);
   write("\nUsage: " + query_verb() + " [string / #]\n");
   return 1; }

   if(member_array(str, fill) > -1) {
 
   if(verb == "ungag")		GAG -= ({ str });
   else if(verb == "unhilite")	HILITE -= ({ str });
   else				PAGE -= ({ str });
 
   write("You remove the " + verb + " on the string : \"" + str + "\".\n");
   save_rcfile();
   return 1; }
 
   if(sscanf(str, "%d", tmp) == 1) {
   if(tmp > sizeof(fill))  return 0;
   write("You remove the " + verb + " on the string : \"" + 
	  fill[tmp - 1] + "\".\n");
 
   if(verb == "ungag")		GAG -= ({ GAG[tmp - 1] });
   else if(verb == "unhilite")	HILITE -= ({ HILITE[tmp - 1] });
   else				PAGE -= ({ PAGE[tmp - 1] });
 
   save_rcfile();
   return 1; }
 
return 0; }
 
static int display_text_list(string str) {
   mixed *tmp;
   int loop;
 
   if(query_verb() == COMMCHAR + "history") {
   str = "history";  tmp = HISTORY;  }
 
   else if(str == "gag")	tmp = GAG;
   else if(str == "hilite")	tmp = HILITE;
   else				tmp = PAGE;
 
   if(str == "history") {
   write("Present Stored History list:\n");
   for(loop=sizeof(tmp)-1; loop>-1; loop--)
   write(" " + (loop + 1) + "] " + tmp[loop] + "\n");
   write("\n");
   return 1; }
 
   if((str == "ungag" && GAG == NULL) ||
      (str == "unhilite" && HILITE == NULL) ||
      (str == "unpage" && PAGE == NULL)) {
   write("There are presently no stored " + capitalize(str) + " strings.");
   return 0; }
 
   write("Present Stored " + capitalize(str) + " Strings:\n");
   for(loop=0; loop<sizeof(tmp); loop++)
   write(" " + (loop + 1) + "] " + tmp[loop] + "\n");
   write("\n");
 
return 1; }
 
//	Assign rerouting message functions
 
static int display_assign() {
   int loop;

   if(!ASSIGN[0] || ASSIGN[0] ==({ })) {
   write("You have no assigned communication classes.\n");
   return 1; }
 
   write("\nPresently reassigned communication classes:\n");
 
   for(loop=0; loop<sizeof(ASSIGN[0]); loop++) 
   if(ASSIGN[1][loop] == -1)
   write(" " + (loop + 1) + "] " + ASSIGN[0][loop] + " to nul\n");
   else if(!ASSIGN[1][loop])
   write(" " + (loop + 1) + "] " + ASSIGN[0][loop] + " to " +
	 "communication window.\n");
   else write(" " + (loop + 1) + "] " + ASSIGN[0][loop] + " to window " +
	 ASSIGN[1][loop] + "\n");
   write("\n");
 
return 1; }
 
static int assign_comm(string str) {
   string class1;
   int where, num;

   notify_fail("Usage: " + query_verb() + " [class] to [window]\n");
   if(!str || str == "") {  display_assign();  return 0;  }
 
   if(sscanf(str,"%s to nul", class1) == 1)  where = -1;
   else if(sscanf(str,"%s to comm", class1) == 1)  where = 0;
   else if(sscanf(str,"%s to %d", class1, where) != 2)  return 0;
 
   if(where > sizeof(window)/2-2 || where < -1) {
   write("Illegal window assignment. Must be an open window.\n");
   return 1; }
 
   num = member_array(class1, ASSIGN[0]);
 
   if(num == -1) {
 
	if(where > 0)
	write("Class " + class1 + " communication assigned to window " + 
	      where + ".\n");
	else if(!where)
	write("Class " + class1 + " communication assigned to " +
	      "communication window.\n");
	else write("Class " + class1 + " communication ignored.\n");

   ASSIGN[0] += ({ class1 });  ASSIGN[1] += ({ where });
   save_rcfile();
   return 1; }
 
   if(where == -1)
   write("Class " + class1 + " communication ignored.\n");
   else if(!where)
   write("Class " + class1 + " communication reassigned to " +
	 "communication window.\n");
   else write("Class " + class1 + " communication reassigned to window " +
	 where + ".\n");

   ASSIGN[1][num] = where;
   save_rcfile();

return 1; }
 
static int unassign_comm(string str) {
   int num;

   notify_fail("Usage: " + query_verb() + " [communication class]\n");
   if(!str || str == "")  return 0;

   num = member_array(str, ASSIGN[0]);

   if(num == -1) {
   write("You have not assigned " + str + " class to a particular window.\n");
   return 1; }
 
   ASSIGN[0] = exclude_array(ASSIGN[0], num);
   ASSIGN[1] = exclude_array(ASSIGN[1], num);
 
   write("You remove the " + str + " class window assignment.\n");
   save_rcfile();
 
return 1; }
 
//	Shell status output display
 
static int shell_status() {
 
   write("\nShadow Shell Status\n===================\n");
 
   write("\n  File Completion :  ");
   if(fcflag) write("[active]\n");  else write("[inactive]\n");
 
   write("\n  Save Method :  ");
   if(rcflag)  write(define_user_path() + ".o file recall\n");
   else write("Autoload recall\n");
 
   write("\n");
 
   display_alarms();
 
   if(GAG != NULL)	display_text_list("gag");
   else write("You have no active gag strings.\n");
 
   if(HILITE != NULL)	display_text_list("hilite");
   else write("You have no active hilite strings.\n");
 
   if(PAGE != NULL)	display_text_list("page");
   else write("You have no active page strings.\n");
 
   display_assign();
   write("\n");
 
return 1; }
 
command_catch(string str) {
   mixed *tmp;
   string action, what;
   int num, pos;
 
   //	Complete full verb with action
 
   if(!str)  action = query_verb();
   else action = query_verb() + " " + str;
 
   //	Parse for window redirecting of action
 
   if(sscanf(action,"/%d %s", num, what) == 2)  
     return send_mesg(what, num);
 
   // 	Check for file completion request in action
 
   if(file_completion(action))  return 1;

   //	Check for history request via keyboard arrow keys
   //	This option will not work if mudlib has ANSI set define off
 
   if(member_array(query_verb(),({ CSI+"A", CSI+"B", CSI+"C", CSI+"D" })) != -1)
     return conduct_history(1);
 
   tmp = explode(query_verb(), CSI);
   if(sizeof(tmp) > 1)  return conduct_history(sizeof(tmp));
 
return 0; }
 
//	Conduct action history request...
//	The shell accesses the player's history list via tsh
 
static int conduct_history(int num) {
   string *tmp, what;
 
   if(num && stringp(num))  sscanf(num, "%d", num);
 
   if(!num || num < 1 || num > sizeof(HISTORY)) {
   write("Shsh: History request outside of set bounds.\n");
   return 1; }
 
   if(query_verb() != COMMCHAR + "do") num--;
   tmp = HISTORY;   what = tmp[num];
 
   write("Doing: " + what + "\n");
   command_user(what);
 
return 1; }
 
//	This function allows file path completion of sorts.
//	If the last character in the file path is a *, then the
//	shell will try to complete the path as best it can.
 
static int file_completion(string str) {
   mixed *tmp, *result;
   string command;
 
   //	If file completion is off or last char isn't a *, then ignore
 
   if(!fcflag || str[strlen(str)-1] != '*')  return 0;
 
   //	Break command into its word subsets and process last word
 
   tmp = explode(str, " ");
   result = process_choice(tmp[sizeof(tmp)-1]);
 
   //	Indicate shell's ability to complete the file path
 
   if(!result || !sizeof(result))
   write("Shsh: Unable to complete designated filename [" + 
	 tmp[sizeof(tmp)-1] + "]\n");
   else if(sizeof(result) > 1)
   write("Shsh: Multiple possible filename completions [" +
	 tmp[sizeof(tmp)-1] + "]\n");
 
   //	Otherwise complete and initiate the command
 
   else { 
   tmp[sizeof(tmp)-1] = result[0];
   command = implode(tmp, " ");
   command_user(command);  }
 
return 1; }
 
//	The function does the directory searches in an attempt
//	to complete the requested command's file path.
 
static mixed *process_choice(string str) {
   mixed *dir, *tmp, *hold;
   string file, where, patt, dump;
   int loop;
 
   //	Obtain user's present active directory
 
   file = resolv_path("cwd", str);
 
   //	Obtain the requested file's root path
 
   tmp = explode(file, "/");
   where = "/" + implode(tmp[0..(sizeof(tmp)-2)], "/") + "/";
 
   //	Form file search pattern
 
   if(sscanf(tmp[sizeof(tmp)-1],"%s\*",patt) == 1) patt += "%s";
 
   //	Get requested directory contents
 
   dir = get_dir(where);
 
   //	Get all possible filenames that would match requested pattern
 
   for(hold = ({}),loop=0; loop<sizeof(dir); loop++)
   if(sscanf(dir[loop], patt, dump) == 1)
   hold += ({ (where + dir[loop]) });
 
return hold; }
 
static int completion_mode(string str) {
 
   if(fcflag)
   notify_fail("Shell file completion is presently active.\n" +
 	       "Usage: " + query_verb() + " [on/off]\n");
   else 
   notify_fail("Shell file completion is presently inactive.\n" +
	       "Usage: " + query_verb() + " [on/off]\n");
   if(str != "on" && str != "off")  return 0;
 
   if(str == "on") {

	if(fcflag)  write("Shell file completion is already active.\n");
	else {
	write("Shell file completion is now active.\n");
	fcflag = 1;  }
 
   return 1;  }
 
	if(!fcflag)  write("Shell file completion is already inactive.\n");
	else {
	write("Shell file completion is now inactive.\n");
	fcflag = 0;  }
 
return 1; }
 
/***
 ***	Alarm processing subroutines
 ***/
 
static mixed *process_alarm_calls() {
   mixed *calls;
   int loop;
 
   //	Get list of active alarms in the queue
 
   calls = call_out_info();
 
   for(loop=sizeof(calls)-1; loop>-1; loop--)
   if(calls[loop][1] != "initiate_alarm")
	calls = exclude_array(calls, loop);
 
return calls; }
 
static int display_alarms() {
   mixed *calls;
   int loop, remainder;
 
   calls = process_alarm_calls();
   if(sizeof(calls) < 1)  return 1;		//  No alarm calls in queue
 
   write("Alarm calls presently in the queue:\n");

   for(loop=0; loop<sizeof(calls); loop++) {
   remainder = (calls[loop][2]%60);
   write((loop + 1) + "] " + ALARM[loop] + "\n   Time remaining: " +
	 (calls[loop][2]/60) + " minutes, " + remainder + " seconds.\n");
   }
 
   write("\n");

return 1; }
 
static int add_alarm(string str) {
   string mesg;
   int num;
 
   notify_fail("Usage: " + query_verb() + " [time in minutes] " +
               "[optional description]\n");
 
   if(!str || str == "") { display_alarms();  return 0;  }
 
   if(sizeof(ALARM) > MAX_ALARM-1) {
   write("You can only have a maximum of " + MAX_ALARM + " alarms.\n");
   return 1; }
 
   if(sscanf(str, "%d %s", num, mesg) != 2 && sscanf(str, "%d", num) != 1)
	return 0;
 
   if(num < 1)  return 0;
   else num = num * 60;			// Convert to minute format
 
   if(!mesg || mesg == "")	mesg = "none";		// Set no mesg string
 
   ALARM += ({ mesg });
   call_out("initiate_alarm", num);
 
   write("You set the \"" + mesg + "\" alarm to sound in " + (num/60) + 
	 " minutes.\n");
 
return 1; }
 
static int rem_alarm(string str) {
   mixed *calls;
   int num, loop;
 
   notify_fail("Usage: " + query_verb() + " [alarm number]\n");
   if(!str || str == "" || sscanf(str, "%d", num) != 1)  return 0;
 
   calls = process_alarm_calls();
 
   if(num < 1 || num > sizeof(calls)) {
   notify_fail("There is no such alarm sequence set.\n");
   return 0; }
  
   while(find_call_out("initiate_alarm") != -1)
	remove_call_out("initiate_alarm");	    // Clear the queue
 
   for(loop=0; loop<sizeof(calls); loop++) {	    // Replace the queue
   if(loop == num-1)  continue;			    // minus removed alarm
   call_out("initiate_alarm", calls[loop][2]); }
 
   write("You remove \"" + ALARM[num-1] + "\" from alarm queue.\n");
 
   ALARM = exclude_array(ALARM, num-1);

return 1; }
 
//  Give the beep on the alarm call
 
static int call_alarm() {
   int loop;
 
   for(loop=0; loop<40; loop++)	 tell_object(WHOM, BEEP);

return 1; }
 
static void initiate_alarm() {

   tell_object(WHOM,"Alarm: " + ALARM[0] + "\n");
   call_alarm();
   ALARM = exclude_array(ALARM, 0);		// Remove message from stack
 
return; }
 
 
//	Shadow Shell Window socket systems
//
//	This shell has an imbedded window-socket system which allows
//	a user to open a window to another mud. While this is a very
//	useful shell ability, an admin should be careful as to how open
//	they leave the permissions to this system.  Such window socket
//	telneting basically leaves the user anonymous to the remote
//	sites (ie: they will have your host system's ip number). Various
//	schemes are being worked on to allow passing of the user's ip
//	address to the remote system, but at this release time, no
//	such system is available. 
//
//	It should be noted that much of the shell's socket system was
//	based upon the excellent work of Jacques@TMI (Dwayne Fontenot).
//	Without his socket system within the driver and related mudlib
//	support, many of our excellent intermud systems would not exist.
//	Many thanks Jacques!!
 
//	Insert shell socket use permissions here
//	 - Returns 1 to allow, returns 0 to disallow
 
nomask int socket_permission() {

   //	Place your socket restrictions here...if you wish to restrict it. :)
 
return 1; }
 
/***
 ***	Window socket handling routines
 ***/
 
int connect_window(string str) {
   mapping mudlist;
   string mudname;
   int ret, pos;
 
   notify_fail("What numeric address do you wish to connect to?\n" +
	       "Usage: " + query_verb() + " [numeric address] [port]\n");

   if(!Status) {
   notify_fail("You cannot open a connection without an active window.\n");
   return 0; }
 
   if(!str || str == "")  return 0;
 
   if(sizeof(socket[0]) == MAXSOCKET) {
   write("This shell can only accept " + MAXSOCKET + " linked windows.\n");
   return 1; }
 
   if(member_array(HOME, socket[1]) != -1) {
   write("This window already has an open connection.\n");
   return 1; }
 
   //	Open socket and link it to present window
 
   socket[0] += ({ socket_create(STREAM, "socket_shutdown") });
   socket[1] += ({ HOME });
 
   pos = sizeof(socket[0]) - 1;
 
   //	Check for mud name match in host name server
 
   mudlist = DNS_MASTER->query_mud_info(str);
 
   if(mudlist && mudlist["HOST"] && mudlist["PORT"]) {
	mudname = capitalize(str);
	str = mudlist["HOST"] + " " + mudlist["PORT"];
   }
 
   write("Trying : " + str + "\n");
 
   //	Try to connect window to requested ip address
 
   ret = socket_connect(socket[0][pos], str, "receive_data", "write_data");
 
   //	If unable to open connection, remove link from window
 
   if(ret != EESUCCESS) {
   printf("Unable to connect: %s.\n", query_socket_error(ret));
   socket[0] = exclude_array(socket[0], sizeof(socket[0])-1);
   socket[1] = exclude_array(socket[1], sizeof(socket[1])-1);
   return 1; }

   label_line("Open : " + (mudname ? mudname + "  -  " : "") + str, HOME);
   write("[Connection is now open]\n");
   socket[2] += ({ str });
 
   input_to("socket_catch", 0);
 
return 1; }
 
int disconnect_window(string str) {
   int ret, pos, num;
 
   if(!Status) {
   notify_fail("You do not have a connected window open.\n");
   return 0; }
 
   //	Locate requested window for socket closure
 
   if(!str || str == "")  num = HOME;
   else if(sscanf(str, "window %d", num) != 1)  sscanf(str,"%d", num);
 
   pos = member_array(num, socket[1]);
 
   if(pos == -1) {
   write("This window does not have an open connection.\n");
   return 1; }

   //	Attempt to close open socket
 
   ret = socket_close(socket[0][pos]);
 
   if(ret != EESUCCESS) {
   printf("Unable to disconnect: %s.\n", query_socket_error(ret));
   return 1; }

   //	Remove socket designation from window system
 
   socket[0] = exclude_array(socket[0], pos, pos);
   socket[1] = exclude_array(socket[1], pos, pos);
   socket[2] = exclude_array(socket[2], pos, pos);
 
   label_line(0, num);
   write_window(num,"[Connection is now closed]\n\n", "telnet");
 
return 1; }
 
//	Catch all outgoing commands in socket window
 
static int socket_catch(string str) {
   string tmp;
   int num;

   if(member_array(HOME, socket[1]) == -1)
	return command_user(str);
 
   if(str == "cls" || sscanf(str, "cls %s", tmp) == 1 ||
      sscanf(str, COMMCHAR + "%d %s", tmp, num) == 2) {
   command_user(str);
   input_to("socket_catch", 0);
   return 1; }
 
   if(str == COMMCHAR + "close" ||
      sscanf(str,  COMMCHAR + "close %s", tmp) == 1)
	return disconnect_window(tmp);
 
   if(sscanf(str, COMMCHAR + "goto %s", tmp) == 1) {
 
	if(!switch_window(tmp)) {
	input_to("socket_catch", 0);
	return 0; }

   return 1; }
 
   send_mesg(str, 0);
 
   input_to("socket_catch", 0);
 
return 1; }
 
//	Send a specific action to a specified window
 
static int send_mesg(string str, int win) {
  int ret, pos;
 
   if(win)  pos = member_array(win, socket[1]);
   else     pos = member_array(HOME, socket[1]);
 
   if(pos == -1) {  command_user(str);  return 1;  }
 
   ret = socket_write(socket[0][pos], str + "\n");
 
   if(ret != EESUCCESS) 
   printf("Unable to send command: %s.\n", query_socket_error(ret));
 
return 1; }
 
void receive_data(int where, string mess) {
   int pos;
 
   pos = member_array(where, socket[0]);
 
   if(pos == -1) {
   write("Error: Incoming message could not be routed to a window.\n");
   return; }
 
   if(socket[1][pos] == HOME)   Talk( mess );
   else write_window(socket[1][pos], mess, "telnet");

return; }
 
void socket_shutdown(int where) {
   int ret, pos;
 
   pos = member_array(where, socket[0]);
   if(pos == -1) return;
 
   ret = socket_close(socket[0][pos]);
 
   if(ret != EESUCCESS)
   printf("Unable to close socket: %s.\n", query_socket_error(ret));
 
   label_line(0, socket[1][pos]);
   write_window(socket[1][pos], "[Connection is now closed]\n\n", "telnet");

   socket[0] = exclude_array(socket[0], pos, pos);
   socket[1] = exclude_array(socket[1], pos, pos);
   socket[2] = exclude_array(socket[2], pos, pos);

return; }
 
mixed *query_socket() {  return socket;  }
 
//   This function returns a string description of
//   socket error returned by the driver
 
static string query_socket_error(int err) {
 
   //	These errors are designated in /include/socket_errors.h
 
   switch(err) {

	case EESOCKET		:
	case EESETSOCKOPT	:   return "Could not create socket link";
	case EENONBLOCK		:   return "Could not set non-blocking mode";
	case EENOSOCKS		:   return "No more available socket links";
	case EEFDRANGE		:   return "Descriptor out of range";
	case EEBADF		:   return "Descriptor is invalid";
	case EESECURITY		:   return "Security violation attempt";
	case EEISBOUND		:   return "Accessed socket is already bound";
	case EEADDRINUSE	:   return "Requested address already in use";
	case EEBIND		:   return "Problem with socket binding";
	case EEGETSOCKNAME	:   return "Problem locating requested address";
	case EEMODENOTSUPP	:   return "Socket mode is not supported";
	case EENOADDR		:   return "Socket not bound to an address";
	case EEISCONN		:   return "Set socket is already connected";
	case EELISTEN		:   return "Problem with socket listen";
	case EENOTLISTN		:   return "Set socket is not listening";
	case EEWOULDBLOCK	:   return "Requested operation would block";
	case EEINTR		:   return "Interrupted system call";
	case EEACCEPT		:   return "Problem with socket accept";
	case EEISLISTEN		:   return "Socket is already listening";
	case EEBADADDR		:   return "Invalid internet address format";
	case EEALREADY		:   return "Operation is already in progress";
	case EECONNREFUSED	:   return "Connection refused";
	case EECONNECT		:   return "Problem with socket connection";
	case EENOTCONN		:   return "Socket is not connected";
	case EETYPENOTSUPP	:   return "Object type not supported";
	case EESENDTO		:   return "Problem with sendto functions";
	case EESEND		:   return "Problem with send functions";
	case EECALLBACK		:   return "Wait for socket callback";
	case EESOCKRLSD		:   return "Socket link is already released";
	case EESOCKNOTRLSD	:   return "Socket link not released";
	}
 
return ("Socket error #" + err); }
 
 
//	Shell's message storage buffer1 system functions
 
static int add_buffer1(string mesg) {
   string *tmp;
   int loop;

   //	Do not save prompt outputs in buffer1
 
   if(mesg == prompt)  return 1; 

   //	Divide incoming message into individual lines
 
   tmp = explode(mesg, "\n");

   //	Add individual lines to buffer1
 
   for(loop=0; loop<sizeof(tmp); loop++) {

   if(sizeof(buffer1) > MAX_buffer1)
        buffer1 = buffer1[1..MAX_buffer1];

   buffer1 += ({ tmp[loop] + "\n" });   }

return 1;  }
 
//	Outputs buffer1 to screen in colour or non-colour
//	depending on user's setting.
 
static int print_buffer1(string str) {

   if(buffer1[0] == "default")  write(str + CSI + "10Z");
   else write(CSI + buffer1[1] + "m" + str + CSI + "0m" + CSI + "10Z");
 
return 1; }
 
static int open_buffer1() {
   int loop, win_size, base;
 
   if(!Status) {
   write("The buffer1 recall can only be used when the shell is active.\n");
   return 1; }
 
   //	Clean present screen and setup buffer1 output
 
   clean_screen("");
   win_size = window[(HOME*2)+3] - window[(HOME*2)+2];
   label_line("buffer1 view open -- Up : \"u\"  Down : \"d\"  Quit : " +
	      "\"q\"", HOME);
 
   //	Load present buffer1 into a temporary buffer1.  This is necessary
   //	so the main buffer1 can continue to be added to while the user is
   //   viewing the old buffer1 contents.
 
   TMP_buffer1 = buffer1;
   TMP_buffer1 = ({ "[Top of buffer1]\n" }) + TMP_buffer1 +
		({ "[End of buffer1]" });
 
   //	Determine output buffer1 contents and window size
 
   base = sizeof(TMP_buffer1) - win_size - 2;
 
   if(base < 0) {
   buff_pos[1] = window[(HOME*2)+3] + base;   base = 0;  }
   
   else buff_pos[1] = window[(HOME*2)+3];
 
   for(loop=base; loop<sizeof(TMP_buffer1); loop++)
	print_buffer1(TMP_buffer1[loop]);
 
   //	Save present buffer1 line position
 
   buff_pos[0] = sizeof(TMP_buffer1) - 1;
   get_char("process_buffer1", 1);
 
return 1; }
 
static int process_buffer1(string str) {

   if(str == "q" || str == "Q" || str == ESC) {
   label_line(0, HOME);
   new_pos(window[(HOME*2)+3]);
   write("\n[buffer1 view closed]\n");
   return 1; }
 
   if(str == "d") {
 
   //  	If buffer1 request is beyond the end...ignore and beep
 
   if(buff_pos[0] > sizeof(TMP_buffer1)-2)  	write(BEEP);
 
   //	Otherwise move cursor1 down...if at bottom of the window,
   //	scroll screen down and display next buffer1 line.
 
   else {
   buff_pos[0]++;
   if(buff_pos[1] != window[(HOME*2)+3]) {
   buff_pos[1]++;  write(CSI + "B");  }
   else print_buffer1(TMP_buffer1[buff_pos[0]]);
   }
 
   }
 
   if(str == "u") {
   
   //	If request is above the top of the buffer1, ignore and beep
 
   if(buff_pos[0] == 0)  write(BEEP);
 
   //	Otherwise move cursor1 up...If at the top of the window,
   //	scroll window down and output above buffer1 line.
 
   else {
   buff_pos[0]--;
 
   if(buff_pos[1] != window[(HOME*2)+2]-1) {
   write(CSI + "A");   buff_pos[1]--;  }
   
   else {
   write(ESC + "M");
   print_buffer1(TMP_buffer1[buff_pos[0]]);  
   write(CSI + "A");  }
 
   }
   }
 
   get_char("process_buffer1", 1);
 
return 1; }
 
//  This function is used to strip user dir pre-name 
//  and substitute a ~ in the displayed path.
 
string process_dir(string str) {
   string tmp1, tmp2;
 
   if(sscanf(str, HOME_DIRS + "%s/%s", tmp1, tmp2) == 2)
	return "~" + tmp2 + "/";
 
return str + "/"; }
 
