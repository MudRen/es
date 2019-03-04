//#pragma save_binary

// File : /std/body.c
//
// This file contains the code common to all player bodies. It is inherited
// by ghost.c, the ghost body, and living.c, which is the file containing
// the code common to the monster body and the player body.
// This file was created 3-10-93 by Mobydick@TMI-2, in conjunction with
// Watcher@TMI-2 as part of creating the new bodies system, which in turn
// was made possible by the work on login.c done by Buddha@TMI-2 in
// January 1993.
//
// All of the functions in this file were in the original user.c found
// at TMI-2 before the bodies project was launched. Its documentation is
// as follows:
// Original Authors: Sulam and Buddha @ The Mud Institute
// Many other people have added to this as well.
// This file has a long revision history dating back to the
// hideous mudlib.n and is now probably not at all the same.
//
// This file is a part of the TMI-2 distribution mudlib.
// Please keep this header with any code within.

#include <config.h>
#include <mudlib.h>
#include <daemons.h>
#include <net/daemons.h>
#include <body.h>
#include <logs.h>
#include <priv.h>
#include <uid.h>
#include <move.h>
#include <commands.h>

inherit "/std/body/attack.c";
inherit "/std/body/more.c";
inherit "/std/body/alias.c";
 
static object link;

// Prototypes. The important one is the user/nonuser recognition function.

void save_data();
void basic_commands();
mixed query_env (string env);
static void init_commands();

// Connection link support functions

object query_link()
{
	return link;
}

void set_link(object ob)
{
	if (geteuid(previous_object()) != ROOT_UID && 
	    base_name(previous_object()) != CONNECTION)  return;
	link = ob;
}

mixed link_data(string what)
{
	if( !link ) return 0;
	return (mixed)link->query(what);
}

//  User debug function 
/*
void debug(string mess)
{
#ifdef DEBUG
   write( mess );
#endif
}
*/
 
//  This function switchs the user from its present body to
//  that of a ghost when they "die".
static object create_ghost()
{
	object ghost, old;
	string name;
	mixed tmp;
	//	First confirm the body has a link
	if(!link)  return 0;
 
	ghost = new(GHOST);
	old = environment();
 
	link->set("dead", 1);
	link->set("tmp_body", ghost);

	if(!link->switch_body()) {
		write("Error in the ghost body transfer.  Please inform an Admin.\n");
		return 0;
	}
	if (!name = query("c_name")) name = link_data("c_name");
	
	ghost->set("name", link_data("name") );
	ghost->set("c_name", name );
	ghost->set("chinese", 1 );
	ghost->set("level", this_object()->query_level() );
	ghost->init_setup();
	ghost->setup_ghost();
	link = 0;

#ifdef GHOST_START_LOCATION
//	if(tmp=catch(call_other(GHOST_START_LOCATION, "???")) ||
//		tmp=catch(ghost->move(GHOST_START_LOCATION) != MOVE_OK))
		  ghost->move(START);
#else
	ghost->move(environment());
#endif

	tell_room( old, 
		"�㿴��һ��\��ɫ��Ӱ�Ӵ�"+(string)ghost->query("c_name") + "�ġ�����Ʈ��\n" 
	);

	if(environment(ghost) != old) {
		tell_room( old, 
			"��Ӱ����Ʈ����գ�Ȼ����ʧ�ˡ�\n"
		);

		tell_room(environment(ghost), 
			"�㿴��һ��\��ɫ��Ӱ�Ӵӿ����г��֡�\n" ,
			ghost );
	}
 
	return ghost;
}
 
// The force hook.

int force_me(string cmd)
{
	string tmp, verb, *verbs;
	int res;
 
	tmp = geteuid(previous_object());
 
	if(tmp != ROOT_UID && tmp != geteuid(this_object()))
		return 0;

	//  Process command for aliases/nicknames/etc

	if(interactive(this_object()))
		cmd = (string)this_object()->parse_arg(cmd);

	verbs = explode(cmd, " ");
	if( sizeof(verbs) > 0 ) verb = verbs[0];
	else return 0;
	
	//	Check to make sure the force is not an illegal force. If so,
	//	block it and notify all the parties of the foul deed.
// mark it by Ruby@ES for not need to check ... save time
/*
	if(BAD_FORCE_VERBS && member_array(verb, BAD_FORCE_VERBS) != -1) {
		tell_object(this_object(), (string)this_player()->query("cap_name") + 
			 " using " + identify(previous_object()) + " tried to force you to " +
			 cmd + ".\n");
		write("Illegal force attempt blocked and noted.\n");

#ifdef BAD_FORCE
		log_file(BAD_FORCE, wrap((string)this_player()->query("cap_name") +
			" using " + identify(previous_object()) + " tried to force " +
			(string)this_object()->query("cap_name") + " to " + cmd + " [" +
			extract(ctime(time()),4,15) + "]\n"));
#endif

		return 0;
	}
*/
	res = command(cmd);
	return res;
}
 
//  This function initializes the body shell prior to transfer
//  of the user connection.
 
void init_setup()
{
	//  Set object's living name for hash table
	set_living_name( query("name") );

	//	Set user's euid permissions
	seteuid( getuid(this_object()) );
	//	Initialize the tsh system here so all bodies get it
	call_out("initialize_tsh", 0);

	//	Start this user's heartbeat
	set_heart_beat(1);

	//	Set user object's id and ip properties
	set( "id", ({ query("name") }) );
	set( "ip", query_ip_name(this_object()) );

	//	Enable wizard status if user fulfills prerequisites
	if((int)query_link()->query("wizard")) {
		set("wizard", 1, MASTER_ONLY);
		enable_wizard();
	}
	else set("wizard", 0, MASTER_ONLY);

	//	Enable basic user commands defined in specific body
	basic_commands();

	//	Initialize body's standard command catch
	init_commands();

	//	Setup important body system presents.
	(int)this_object()->fix_load();

	//	Reset the weapon and armor defaults
	set ("weapon1",0);
	set ("weapon2",0);
	set ("armor", ([]) );

	//	Retrieve autoload requests
	this_object()->load_autoload_obj();
 

	//	Setup the message buffer system ... make sure its OWNER_ONLY
	set("message_buffer", "", OWNER_ONLY);
	set("buffer_flag", 0, READ_ONLY);
}
 
void enable_me()
{
	if (geteuid(previous_object()) != ROOT_UID) return;
	enable_wizard();
}

nomask void disable_me()
{
	if (previous_object() == find_object(CMD_DEWIZ))
		disable_wizard();
}
void quick_message(string msg)
{
	receive(msg);
}
void receive_message(string mclass, string msg)
{
	object shell;
	string foo ;
	int htime;

	if( this_object()->query_temp("block_message")
	&& mclass!="illusion" && mclass!="broadcast" ) return;

	// Invisibility screen. This should catch all tells and says and so forth,
	// and all soul commands, and most command messages.

	if( this_player() && this_object() != this_player() ) {
		if((int)this_player()->query("invisible") == 1 &&
			!wizardp(this_object()))
		 return;
		if((int)this_player()->query("invisible") == 2 &&
			!member_group(geteuid(this_object()), "admin"))
		return;
	}

	//  If this_object() is a monster, pass the message so
	//  aggressive monsters can react to certain messages.
	if( (int)query("npc") )
		this_object()->relay_message(mclass, msg);

	//  If the player is being harassed, then the "harass" flag will be
	//  set by the "harass" command, and everything will be logged to a
	//  file until the flag is disabled.
// Mark by Ruby@ES for never use it ... save some ..
/*
	if( (htime = (int)query("harass")) && htime > 0 ) {
		if (htime < time()) {
			  set("harass", 0);
			  receive_message("write",
				  "What you see is no longer being logged.\n");
			  log_file("harass/" + geteuid(),
				  "Harass Log stopped: " + ctime(time()) +
			  "\n========================================\n");
		}
		else log_file("harass/" + geteuid(), msg); 
	}
*/
	//  Message buffering system when user is busy (ie: writing notes)
	//  We are applying the message directly to the mapping because we
	//  want all messages to be stored there (regardless of source),
	//  which would normally be blocked by the OWNER_ONLY security.
 
#ifdef MESSAGE_BUFFER
	if(query_env("enable_buffer") && query("buffer_flag") && mclass != "write") {
		ob_data["message_buffer"] = ob_data["message_buffer"] + msg;
		return;
	}
#endif
 
	//  Mudlib support for user environment shell
	shell = present("shell", this_object());

	if( this_object()->getenv("DISPLAY_MSG_CLASS") ) {
		receive( sprintf("[%s]\t%s", mclass, msg) );
		return;
	}
		
	if( shell && previous_object() != shell &&
		base_name(shell) + ".c" == (string) this_object()->query("shell") )
		  shell->receive_message(mclass, msg);
	else receive(msg);
}

// This function dumps the contents of the MESSAGE_BUFFER to the user's
// more pager for output.
#ifdef MESSAGE_BUFFER

int dump_buffer()
{
	string *dump, output;

	if(geteuid(previous_object()) != geteuid(this_object()))  return 0;
 
	output = query("message_buffer");
	set("buffer_flag", 0);
 
	if(!output || output == "") return 0;

	dump = ({ "\n" +"[Queued message buffer output]" }) +
	  explode(output, "\n");

	this_object()->more(dump);
	set("message_buffer", "");

	return 1; 
}
#endif 


// This is a new apply in MudOS 0.9.16.18. If a wizard is snooping a
// player, then the snooped messages are passed to this function.
// We either pass it off to a mudlib shell, or receive it as normal.
void receive_snoop (string str)
{
	object shell;
 
	//  Mudlib support for user environment shell
	shell = present("shell", this_object());

	if(shell && previous_object() != shell &&
		base_name(shell) + ".c" == (string) this_object()->query("shell"))
 	shell->receive_message("snoop", bold("% ") + str[0..strlen(str)-2]);
 
	else receive( bold("% ",this_object()) + str);
}

void restart_heart()
{
	say(query("cap_name")+" has reconnected.\n");
	write("Reconnected.\n");
	ANNOUNCE->announce_user(this_object(), 2);
	set_heart_beat(1);
}

string local_commands()
{
	mixed *cmds;
	int i;
	string result;
 
	if(geteuid(previous_object()) != ROOT_UID &&
		!member_group(geteuid(previous_object()), "admin"))
		return "You aren't authorized to check this information.\n";
 
	cmds = commands();
 	if (!sizeof(cmds)) return "No commands available";
 
	result = "";
	while (i < sizeof(cmds)) {
		result += (cmds[i][0] + " ");
		i++;
	}
 
	return result + "\n";
}

mixed *user_commands() { return commands(); }
/*
varargs int more(mixed str, int flag, int mask)
{
	return "/adm/daemons/more_d"->more(this_object(),str,flag,mask);
}
*/
