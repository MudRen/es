#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Fire Shield","×ÆÈÈ¶Ü" );
	add( "id", ({ "shield" }) );
	set_short( "×ÆÈÈ¶Ü" );
	set_long(@LONG
	ÄÜ¹»·â±Õ»ğÑæµÄ¶Ü¡£
LONG
		);
	set( "unit","Ãæ" );
	set( "weight",120 );
	set( "type","shield" );
	set( "material","light_metal" );
	set( "armor_class",8 );
	set( "defense_bonus",3 );
	set( "special_defense",([ "fire":30,"cold":-15 ]) );
	set( "value",({ 2150,"silver" }) );
}
