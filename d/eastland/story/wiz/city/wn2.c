#include "../../story.h"
#include "../../magic.c"
#include <conditions.h>
inherit ROOM;

void create()
{
        ::create();
	set_short("北大街");
	set_long( @LONG
你走正走在「巫咸城」内北大街上，大街往东边方向延伸，南边则是西大街。
西大街由这里一转已变成为地处偏僻的北大街，往来无尘嚣，街旁树木稀稀落落於
房子间，空气清新，显的格外幽雅脱俗，街道内相当安静，是为居住之地。路旁另
有一口枯井和一棵大榕树约七、八抱宽，其分枝繁叶已延伸达二十四尺直径方圆，
老幼皆喜来此乘凉嬉戏，为北大街另添一殊。
LONG
	);
        set("light",1);
	set( "exits", ([ 
           "south" : SCITY"wn1",
            "east" : SCITY"nw2",
        ]) );
        set("objects", ([
            "boy#1" : SWMOB"boy2",
            "boy#2" : SWMOB"boy2",
            "girl1" : SWMOB"girl2",
            "girl2" : SWMOB"girl2",
            "older" : SWMOB"older1",
        ]) );
	reset();
}
void init()
{
   add_action("do_search","search");
   add_action("do_jump","jump");
}
int do_search(string arg)
{
    write(@LONG
你发现了一口枯井(well)，深不见底，你最好不要□试跳下去(jump)，以免
发生危险。  
LONG
   );    
   return 1;
}
int do_jump(string arg)
{
   object player;
   if ( !arg || arg!="well" ) {
      write("Snytax:<jump well>。\n");
      return 1;
   }
   player=this_player();
   tell_object(player,"你冲动地往井里跳下去！\n\n\n\n\n\n\n");
   player->move_player(SCITY"well1",({
            "%s不顾一切地往井里一跳！\n",
            "%s从上面跳下来。\n"}),"");
   tell_object(player,"唉呀，你不小心地被井边墙壁突出的石块给割伤，流血不止！\n");                     
   (CONDITION_PREFIX + "bleeding")->apply_effect(player,20,2 );
   return 1;           
}