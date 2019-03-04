#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Cloak","战神披风" );
	add( "id",({ "cloak" }) );
	set_short( "战神披风" );
	set_long(@LONG
	这是战神五种配备中的披风。
LONG
           );
	set( "unit","件" );
	set( "weight",50 );
	set( "type","cloak" );
	set( "material","leather" );
	set( "armor_class",8 );
	set( "defense_bonus",4 );
	set( "special_defense",([ "fire":25,"cold":10,"none":15 ]) );
	set( "value",({ 5700,"silver" }) );
//	set( "no_sale",1 );
}
