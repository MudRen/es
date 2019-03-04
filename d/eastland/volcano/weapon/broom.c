#include "../oldcat.h"

inherit WEAPON;

void create()
{
     set_name("broom","扫把");
     set_short("扫把");
     set_long(
      "一把普通的扫把.你可以拿著它去扫扫灰尘.\n"
      );
     set( "unit", "把");
     set( "type","blunt");
     set("weight",35);
     set("value", ({ 20, "silver" }));
     set("weapon_class",10);
     set("min_damage",5);
     set("max_damage",15);
}
