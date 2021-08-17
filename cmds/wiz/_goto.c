//#pragma save_binary

//	File	:  /cmds/xtra/_goto.c
//	Creator	:  Watcher@TMI-2  (4/14/93)
//
// Mobydick added the -c flag, 6-3-93. This defeats the check that the
// file exists for moves to rooms. Use it if you want to go to a virtual
// room.
//	The standard wizard goto command.


#include <move.h>
#include <mudlib.h>

inherit DAEMON ;

protected int goto_location(object where);

#define SYNTAX	"Syntax: goto [-c] [location | living object]\n"

int cmd_goto(string str)
{
	object ob;
	string tmp,flag ;
	int err;

	notify_fail( SYNTAX );

	if(!str || str == "")  return 0;

	if( sscanf(str,"%s %s",flag,tmp) == 2 ) {
		if( flag!="-c" )
			return notify_fail( flag+": unknown flag.\n" );
		str = tmp;
	}

	if( ob = find_living(lower_case(str)) )
		if( visible(ob, this_player()) )
			return goto_location( environment(ob) );
		else
 			return notify_fail("No such living object found!\n");

	str = resolv_path("cwd", str);

	flag = "-c";
	if( !flag || flag!="-c" ) {
		if(extract(str, strlen(str)-2, strlen(str)-1) != ".c")	str += ".c";

		if(!file_exists(str)) {
			write("Goto: No such location or living object found.\n");
			return 1;
		}
	}
	err = catch( call_other(str, "???") );		// Load up the room

	if( !ob = find_object(str) ) {
		write("Goto: Could not load " + str + "\n");
		if(err) write("		" + err );
		return 1;
	}

	goto_location( ob );

	return 1;
}

protected int goto_location(object where)
{
	object old;
	int res;

	if( !where | !objectp(where) ) return 0;

	old = environment( this_player() );

	if(old == where) {
		write("����ԭ����������\n");
		say((string)this_player()->query("c_name") + "��ԭ����������\n",
			({ this_player() }));
		return 1;
	}

	res = this_player()->move_player( where, "" );

	if( res )
		write("Goto: Could not move to " + identify(where) + ".\n");

	return 1;
}

int help()
{
	write( SYNTAX + "\n" +
		"This command moves a wizard to the desired location, either the\n" +
		"environment of a living object, or the room matching the inputted\n" +
		"filename (ie: goto fred  or  goto /d/Fooland/shop).\n"+
		"In the latter case, it checks to see if the file exists before\n"+
		"attempting the move. You can use the -c flag to defeat this\n"+
		"check if you want to move to a virtual room.\n") ;

	return 1;
}
