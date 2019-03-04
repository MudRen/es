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
// #include <daemons.h>
// #include <net/daemons.h>
// #include <body.h>
// #include <logs.h>
// #include <priv.h>
#include <uid.h>
// #include <move.h>
#include <commands.h>

//inherit OBJECT;
inherit "/std/body/attack.c";
//	inherit "/std/body/alias.c";
//	inherit "/std/body/wild_card.c";
//	inherit "/std/body/more.c";
 
// Prototypes. The important one is the user/nonuser recognition function.

void save_data();
void basic_commands();
static int init_commands();

int force_me(string cmd)
{
	int res;
	string *verbs, verb;
 
	//  Process command for aliases/nicknames/etc
	if(interactive(this_object()))
		cmd = (string)this_object()->process_input(cmd);

	verbs = explode(cmd, " ");
	if( sizeof(verbs) > 0 ) verb = verbs[0];
	else return 0;
	
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

	//	Start this user's heartbeat
	set_heart_beat(1);

	//	Enable basic user commands defined in specific body
	basic_commands();

	//	Initialize body's standard command catch
	init_commands();

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

void receive_message(string class1, string msg)
{

	// Invisibility screen. This should catch all tells and says and so forth,
	// and all soul commands, and most command messages.

	if((int)this_player()->query("invisible") )
		return;
	if ((int)this_player()->query("player_invisible"))
		return;

	//  If this_object() is a monster, pass the message so
	//  aggressive monsters can react to certain messages.
	this_object()->relay_message(class1, msg);

	receive(msg);
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

varargs int more(mixed str, int flag, int mask)
{
	return "/adm/daemons/more_d"->more(this_object(),str, flag, mask );
}