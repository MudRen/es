#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        ::create();
        set_short( "天堂别墅" );
        set_long("     这是全以能的神--全能创世者的别墅，来到这里你感
        到周身通泰，别墅里的东西你从来没见过,留心一点找找可能\n
        会有大收获!\n");
        set( "light",1 );
        set( "exits", ([
      "guild" : "/d/wiz/wiz_hall",
       ]) );
}
