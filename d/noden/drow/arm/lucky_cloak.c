#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("lucky cloak", "幸运斗蓬");
        add( "id", ({ "cloak" }) );
        set_short( "幸运斗蓬" );
        set_long(
@C_LONG
这件白色的斗蓬据说是毕老爹在离开黑暗精灵村时，送给神官萨林
的离别纪念品，上面缝有小刀的图案，也是小偷工会的标记，能在
战斗时为您带来好运。
C_LONG
        );
        set( "unit", "领");
        set( "type", "cloak" );
   set( "material", "thief" );
   set( "armor_class", 7 );
   set( "defense_bonus", 10 );
        set( "special_defense",
               ([ "fire": -10 ]) );
   set("extra_skills", ([ "dodge" : 10 ]) );
   set( "weight", 55 );
        set( "value", ({ 2650, "silver" }) );
        set( "no_sale", 1);
}
