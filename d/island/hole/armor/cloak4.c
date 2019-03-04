#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Oath Cloak","誓言披风" );
	add( "id",({ "cloak" }) );
	set_short( "誓言披风" );
	set_long(@LONG
	发誓成为圣者时，做为信物赠与的礼物。
LONG
           );
	set( "unit","袭" );
	set( "weight",40 );
	set( "type","cloak" );
	set( "material","cloth" );
	set( "armor_class",6 );
	set( "defense_bonus",4 );
	set( "special_defense",([ "evil":20 ]) );
	set( "value",({ 1170,"silver" }) );
}
