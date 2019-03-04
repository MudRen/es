#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("iron platemail","铁叶铠甲");
    add("id",({"plate","platemail"}) );
    set_short( "iron platemail","铁叶铠甲");
	set_long(
		"This is a plate called iron platemail....\n",
		"这是用许多细密的铁叶所组合成的战甲，与其说它是防具不如称它\n"
		"为艺术品，穿上它你整个人感觉奂然一新\n"
	);
    set( "no_sale",1);
	set( "unit", "件" );
	set( "weight", 170 );
	set( "type", "body" );
	set( "armor_class", 35 );
        set("material","heavy_metal");
	set( "defense_bonus", 6 );
	set( "value", ({ 251, "gold" }) );
}
