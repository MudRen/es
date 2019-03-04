//#pragma save_binary

// living.c
// Part of the new bodies project, which was launched by Watcher@TMI-2 and
// Mobydick@TMI-2.
// Based on the login code written by Buddha@TMI-2 in January 1993.
// This file was started 3-11-93 by Mobydick. All of the code that it
// inherits was pre-existing, and the appropriate headers in those files
// have been retained.

#include <mudlib.h>
 
inherit "/std/body_npc.c" ;
 
#include "/std/living/stats_npc.c"

// This procedure returns the total number of coins the player is carrying.
// Mobydick, 10-13-92.

int query_vision()
{
	return 1;
}
 
