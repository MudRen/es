// grid_server.c
// The virtual room server for TMI-2. The virtual room concept was implemented
// into the MudOS driver and mudlib by Whiplash@TMI and Truilkan@TMI (and
// possibly several others). This room is a rather direct copy of Truilkan's
// example ocean room. Two main differences are: 1) it is two-dimensional
// rather than three and 2) It has an attached terrain map which controls
// the room descriptions, causing it to have only finite size but more
// interesting rooms. These two differences were implemented by Mobydick@TMI
// in July 1992.
// In August 1992 an exits map was added by Mobydick@TMI which permits
// virtual rooms to have less than the normal four exits.

#include <config.h>

inherit "/std/room" ;
inherit "/std/virtual/compile";

#define BASE "/d/grid/rooms/"
#define SUFFIX ".grid"
#define TERRAIN_DAEMON "/adm/daemons/virtual/terrain_daemon.c"

void initialize(string arg)
{
    int x, y, i ;
    string north, south, east, west ;

	room::create() ;
    sscanf(arg,"%d,%d",x,y) ;
    south = BASE + (x + 1) +  "," + y       + SUFFIX ;
    east = BASE + x       +  "," + (y + 1) + SUFFIX;
    north  = BASE + (x - 1) +  "," + y       + SUFFIX;
    west = BASE + x       +  "," + (y - 1) + SUFFIX;
    set_outside("Fooland");
    set ("short", TERRAIN_DAEMON->get_short(x,y)) ;
    set ("c_short", TERRAIN_DAEMON->get_c_short(x,y)) ;
    set ("long", TERRAIN_DAEMON->get_long(x,y)) ;
    set ("c_long", TERRAIN_DAEMON->get_c_long(x,y)) ;
    set ("exits", ([]) ) ;
    i = (int)TERRAIN_DAEMON->get_exits(x,y) ;
    if (!(i%2)) add ("exits", ([ "west" : west ]) ) ;
    if (!((i/2)%2)) add ("exits", ([ "east" : east ]) ) ;
    if (!((i/4)%2)) add ("exits", ([ "south" : south ]) ) ;
    if (!((i/8)%2)) add ("exits", ([ "north" : north ]) ) ;
}
