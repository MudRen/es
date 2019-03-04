//#pragma save_binary
// File  :  /cmds/adm/_makewiz.c
//
// User to promote a player to wizard status. Alters their path to give
// them wizard commands and set their wizard property to 1. Can only be used
// by admins.
// Written by Mobydick@TMI, 11-25-92. Copied most of it from the changepath
// command.
// 93-02-11 Pallando changed WIZPATH to use <config.h>
// 93-02-28 Watcher changed wizard flag set from body to connection
//  	    and allowing promotion when target is not online.
// 93-07-22 Pallando moved the define of NEW_WIZ_PATH to config.h
// 94-09-12 Kyoko move NEW_WIZ_PATH to NEW_NEWBIE_PATH for apprentices.

#include <uid.h>
#include <mudlib.h>
#include <config.h>
#include <daemons.h>

inherit DAEMON;
 
#define SYNTAX	"Syntax: makewiz [player]\n"
 
int cmd_makewiz(string str)
{
	object act_ob, player, link;
	int i, add_path;

	act_ob = previous_object();
	seteuid(ROOT_UID);

	notify_fail( SYNTAX );
	if( !str || str == "" )  return 0;

	//	Check for admin permissions in user
        if( !member_group(geteuid(this_player()),"admin") ) {
		write("Makewiz: Only admin may promote a player to wizard level.\n");
		return 1;
	}

	str = lower_case(str);

	//	Check to see if the target user actually exists
	if(!user_exists(str)) {
		write("Makewiz: No such player.\n");
		return 1;
	}
 
	//	Check to see if the user is presently online
	player = find_player(str) ;
	if( player )  link = player->query_link();
 
	//	Otherwise create the user's connection object 
	if( !link )
		link = FINGER_D->restore_data(str);

	//	Check to see if the user is already a wizard
	if( link->query("wizard") ) {
		write("Makewiz: " + capitalize((string)link->query("name")) +
		" is already a wizard.\n");
		return 1;
	}
	
	//	If user isn't online, restore body to update path
	if( !player ) {
		link->restore_body();
		player = link->query("body_ob");
	}
 
	//	Activate wizard flag
	link->set("wizard", 1);
 
	//	Update users path to include wizard command pathways
	player->set("PATH", NEW_NEWBIE_PATH);
	player->enable_me();
 
 	// Reset access right.
 	PROMOTION_D->add_wiz_list(str);
 	PROMOTION_D->reset_access(link);
 	
	//	Save updated user and connection data
	player->save_data();
	link->save_data();
 
	write("You have promoted " + capitalize(str) + " to wizard level.\n");
//	write("Path now set to:\n	" + player->query("PATH") + "\n");
 
	tell_object(player, 
		"You have been promoted to wizard by " + 
		(string)previous_object()->query("name") + ".\n");

	if(!interactive(player))
	player->remove();
 
	return 1;
}

int help()
{
	write( SYNTAX + "\n" +
"This commands promotes the named player to wizard. It sets their wizard\n"+
"property, calls enable_wizard on their current incarnation, and changes\n"+
"their path to the default wizard path. This command can only be used by\n"+
"admins, and the player need not be online to be promoted. It does not add\n" +
"the player into a guild, or provide a directory. The sponsor command is\n"+
"used for that purpose.\n" +
"\nSee also: sponsor, demote, guilds, path\n") ;
 
	return 1;
}
 
