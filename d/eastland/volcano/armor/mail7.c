#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "snow platemail", "雪盔" );
	add( "id", ({ "plate", "platemail" }) );
	set_short(  "雪盔" );
	set_long( 
             @LONG
这件盔甲是在极北之地以冰雪之精加上精钢□成，据说完全不惧寒冷或是冰雪攻击。
LONG
	);
	set( "unit", "套" );
	set( "type", "body" );
	set( "material", "heavy_metal");
	set( "armor_class", 28 );
	set( "defense_bonus", 5);
	set( "special_defense",
	     ([ "cold":20, "fire":-5 ]) );
	set( "weight", 300 );
	set( "no_sale", 1);
	set( "value", ({ 5000, "silver" }) );
}
