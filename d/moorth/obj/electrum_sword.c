#include <mudlib.h>

inherit WEAPON;

void create()
{
   set_name( "electrum sword", "电光剑" );
	add( "id", ({ "short sword", "sword" }) );
   set_short( "电光剑" );
	set_long(
             "这是一把用默尔斯最新铸剑术打造而成的短刃, 黑色的刀身中隐隐\n"
             "透出几丝闪黄的光芒。\n"
	);
	set( "unit", "把" );
	set( "type", "shortblade" );
   set( "weight", 72 );
   set( "second", 1 );
   set( "weapon_class", 35 );
   set( "min_damage", 19 );
   set( "max_damage", 30 );
   set( "value", ({ 999, "silver" }) );
}
