#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        ::create();
 set_short( ""+HIW"天堂别墅"+NOR"" );
        set_long("这是全能的"+HIR"神"+NOR"--全能创世者的别墅，来到这里你感
     到周身通泰，别墅里的东西你从来没见过,留心一点找找可能会有大收获!\n");
        set( "light",1 );
        set( "exits", ([
"pray" : "/d/noden/farwind/charch",
"mage" : "d/mage/tower/mage_guild",
"knight" : "d/knight/fortress/knight_guild",
      "guild" : "/d/wiz/wiz_hall",
       ]) );
}
