#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Cloak","ս������" );
	add( "id",({ "cloak" }) );
	set_short( "ս������" );
	set_long(@LONG
	����ս�������䱸�е����硣
LONG
           );
	set( "unit","��" );
	set( "weight",50 );
	set( "type","cloak" );
	set( "material","leather" );
	set( "armor_class",8 );
	set( "defense_bonus",4 );
	set( "special_defense",([ "fire":25,"cold":10,"none":15 ]) );
	set( "value",({ 5700,"silver" }) );
//	set( "no_sale",1 );
}
