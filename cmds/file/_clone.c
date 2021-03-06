//#pragma save_binary
 
/*
// This file is part of the TMI distribution mudlib.
// Please include this header if you use this code.
// Written by Sulam(12-19-91)
// Help() added 1/27/92 Brian
// Qixx@Hero Added "cwf" stuff.
// Watcher@TMI (3/24/93) Cleaned up and file existence check.
// Watcher@TMI (4/3/93) Improved the message handling.
*/

#include <mudlib.h>
#include <move.h>
#include <uid.h>
#include <logs.h>

inherit DAEMON ;

#define SYNTAX	"Syntax: clone [filename]\n"
 
int cmd_clone(string str)
{
	object ob, *players;
	mixed res;
	string new_str;
	int i;
 
	notify_fail( SYNTAX );

	if(!str)  str = (string)this_player()->query("cwf");
	if(!str || str == "")  return 0;
 
	if( getuid(this_object()) != ROOT_UID) {
		notify_fail("Resetting uid of clone command.\n");
		this_player()->force_me("clone " + str );
		destruct(this_object());
		return 0;
	}
 
	seteuid( getuid(this_player()) );

	str = resolv_path("cwd", str);

	if(extract(str, strlen(str)-2, strlen(str)-1) != ".c")
		str += ".c";

	if(!file_exists(str)) {
		for ( i = sizeof(str)-1; str[i] != '/' ; i -- );
		new_str = str[0..i]+"_"+str[i+1..sizeof(str)-1];
		
        if( file_size(new_str) <= 0 ) {
			write("Clone: " + str + " does not exist.\n");
			return 1;
		}
		str = str[0..sizeof(str)-3];
	}

	write("Cloning: " + str );

	if(res=catch(ob=new(str)))
		write("\nError: " + res + "\n");

	if( !ob ) return 1;
	
	players = filter_array(all_inventory(environment(this_player())),
		"is_a_player", this_object() );
	for( i=0; i<sizeof(players); i++ )
	  if( (this_player() != players[i]) && visible(this_player(), players[i]) )
		tell_object( players[i],
			(string)this_player()->query_c_mclone(ob)+"\n"
		);
 
	if( (ob->move(this_player())!=MOVE_OK || (int)ob->get()) || (int)ob->query("npc")) {
//	if( ob->move(this_player())!=MOVE_OK ) {
		ob->move(environment(this_player()));
		write(" to " + file_name(environment(this_player())) + ".\n");
	}
	else write(" to " + file_name(this_player()) + ".\n");

	this_player()->set("cwf",str);
	
#ifdef WIZ_CLONE_LOG
	seteuid(ROOT_UID);
	if(!member_group(geteuid(this_player()), "admin"))
		log_file(WIZ_CLONE_LOG, "************\n" +
			extract(ctime(time()), 4, 15) +
			" [" + geteuid(this_player()) + "] clone "+str+" at "+
			file_name(environment(this_player())) + ".\n"
		);
#endif
	
	return 1;
}

int is_a_player(object player)
{
	if( userp(player) ) return 1;
	return 0;
}

int help()
{
   write( SYNTAX + "\n" +
        "This command creates an object from the file which\n"+
        "is passed to the command.  The object is cloned into\n"+
        "your environment if it cannot be carried, otherwise\n"+
        "it is cloned into your inventory.\n"+
	"If the object is not loaded, this command will force it to load.\n"+
	"The object's create() function will be called in the clone. It is\n"+
	"almost always better to clone an object than to use the master\n"+
	"copy of it. Rooms are the major exception to this rule.\n") ;
  return 1;
}
 
/* EOF */
 
