#include "../oldcat.h"

inherit ARMOR;

void create()
{
	set_name( "warrior's cloak", "武者斗蓬" );
	add( "id", ({ "cloak" }) );
	set_short( "武者斗蓬" );
	set_long( 
    @LONG
这是一件古代武者所穿著的斗蓬，跟著主人南征北讨，沾满了敌人的血迹。
LONG
	);
	set( "unit", "件" );
	set( "type", "cloak" );
	set( "material", "cloth");
	set( "armor_class", 8 );
	set( "defense_bonus", 0 );
	set( "special_defense", ([
	  "energy" : 10, "electric" : -5 ])
    );
	set( "weight", 50 );
	set( "value", ({ 1500, "silver" }) );
}
