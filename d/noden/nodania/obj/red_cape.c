#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "red cape", "红披风" );
	add( "id", ({ "cape" }) );
	set_short( "红色披风" );
	set_long(@CLONG
一件用东方的丝绸精心缝制的红色披风，上面绣著耶拉曼王家的标志:
狮鹫兽。这件披风看起来不但昂贵，而且质地细密，穿在身上一点也不
会妨碍行动。
CLONG
	);
	set( "unit", "件" );
	set( "weight", 50 );
	set( "type", "cloak" );
	set( "material", "knight" );
	set( "armor_class", 10 );
	set( "defense_bonus", 8 );
	set( "special_defense", ([ "energy":10, "mental":-10 ]) );
	set( "no_sale",1 );
	set( "value", ({ 310, "gold" }) );
}
