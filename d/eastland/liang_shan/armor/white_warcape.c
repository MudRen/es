#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("white robe","白缎子征衫");
    add("id",({"robe"}) );
    set_short( "white robe","白缎子征衫");
	set_long(
		"This is a white silk robe for warriors. \n",
		"征衫是战士们出征时所穿的衣物，能穿到这种衣服代表武艺已达到\n"
		"一定的水准．这是用白缎子织成的征衣，虽经清洗，仍看出血迹斑斑．\n"
	);
	set( "unit", "件" );
	set( "weight", 70 );
	set( "type", "body" );
	set( "armor_class", 18 );
        set("material","cloth");
	set( "defense_bonus", 5 );
	set( "value", ({ 63, "gold" }) );
        set( "special_defense",(["none":5,"poison":1]));
}
