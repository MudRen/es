#include "../dony.h"

inherit WEAPON;

void create()
{
     set_name("dog blunt","竹棒");
     add( "id",({"blunt"}) );
     set_short("竹棒");
     set_long(@C_LONG
一把普普通通的棒子, 用来打狗最好。
C_LONG
      );
     set( "unit", "把");
     set("weight",30);
     set("value", ({ 25, "silver" }));
     setup_weapon( "blunt", 20, 12, 20 );
}
