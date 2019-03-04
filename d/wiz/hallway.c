#include <mudlib.h>
inherit "std/room";
void create() {
::create();
set("light", 1);
set("short","Hallway of Domains");
set("long","You are in a large circular room. It looks as if this\n"
"room has never been set foot in. There is a huge black\n"
"orb hovering in the center of the room. It is the mark\n"
"of a wise and all-knowing wizard once known as Kee.\n"
"As you look around, you see many doors to the great and\n"
"powerful domains of the land. You feel as if you belong\n"
"to one of these. A pulpit stands below the orb.\n");
set("item_desc",(["orb":"The blackness of this orb makes\n"+
" you feel the power that is held within. It is quite large.\n",
"pulpit":"There is a plaque on it, look at it.\n",
"plaque":"It reads: Feel thy fury if thou shalt enter the false door!\n"]));
set("exits",(["cloud":"/d/wiz/cloud.c","moorth":"/d/wiz/moorth.c",
"ocean":"/d/wiz/ocean.c","abyss":"/d/wiz/abyss.c","eastland":
"/d/wiz/eastland.c","noden":"/d/wiz/noden.c",
"std":"/d/wiz/std.c"]));

call_other( "/d/wiz/mboard1.c","frog");
}
