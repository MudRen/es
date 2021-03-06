//#pragma save_binary
// _say.c
// The ghost's say command. It won't actually give his message, but it will
// at least indicate to live players that he's around and unhappy. Clever
// ghosts will manage to communicate using this. ("One gust for yes, two
// gusts for no. Is your corpse north of here?")
// Written by Mobydick, 11-14-92. Loosely based on the existing player _say
// command.

#include <mudlib.h>

inherit DAEMON ;

int cmd_say (string str)
{
	write( 
		"你纵然有千言万语想说，但是对其他阳世间的人而言只是一阵阴风惨惨而已。\n",
	);
	tell_room( environment(this_player()), 
		"你感到一阵阴森的凉意，似乎听到什麽声音。\n",
		this_player() );
	return 1;
}
