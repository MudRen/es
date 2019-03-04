#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Silvery Shield","银色刺盾" );
	add( "id", ({ "shield" }) );
	set_short( "银色刺盾" );
	set_long(@LONG
	一面闪耀著银色光芒的盾。
LONG
           );
	set( "unit","面" );
	set( "weight",120 );
	set( "type","shield" );
	set( "material","light_metal" );
	set( "armor_class",5 );
	set( "defense_bonus",2 );
	set( "special_defense",([ "fire":30,"cold":-15 ]) );
	set( "value",({ 1110,"silver" }) );
}
