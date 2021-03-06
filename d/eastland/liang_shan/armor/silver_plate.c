#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("Dragon plate","火神龙银甲");
    add("id",({"plate","dragon"}) );
    set_short( "dragon plate","火神龙银甲");
	set_long(
		"This is a suit of mail made of iron meterial.\n",
		"这是一件金光闪闪的巨型战甲，其上有一巨大的龙纹，似乎有\n"
		"古火神龙力量保护，一层寒气笼罩，对於炎热似乎有特殊防护。\n"
	);
	set( "unit", "件" );
	set( "weight", 666 );
	set( "type", "body" );
	set( "armor_class", 35 );
        set("material","heavy_metal");
	set( "defense_bonus", 10 );
	set( "value", ({ 666, "gold" }) );
        set( "special_defense",(["ire":15,"evil":10]));
                                    
}
