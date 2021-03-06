#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "fire cloak", "火披风" );
	add( "id", ({ "fire","cloak" }) );
	set_short( "fire cloak", "火披风" );
	set_long(@C_LONG
	一件非常奇特的披风，若有似无，还散发出阵阵的热气，对於寒冷系
	的攻击有特殊的防御能力．
C_LONG
	);
	set( "unit", "件" );
	set( "type", "cloak" );
	set( "material", "cloth");
	set( "armor_class", 6 );
	set( "defense_bonus", 7 );
	set( "special_defense",
          ([ "cold":10 ]) ) ;
	set( "weight", 70 );
	set( "value", ({ 2000, "silver" }) );
}
