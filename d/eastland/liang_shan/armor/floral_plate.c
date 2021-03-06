#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("floral platemail","梅花榆叶甲");
    add("id",({"plate","platemail"}) );
    set_short( "iron platemail","梅花榆叶甲");
	set_long(
		"This is a plate called floral platemail....\n",
		"这是用许多细密的铁叶所组合成的战甲，与其说它是防具不如称它\n"
		"为艺术品，在铁叶间，点缀著许多梅花型的饰品．\n"
	);
    set( "no_sale",1);
	set( "unit", "件" );
	set( "weight", 170 );
	set( "type", "body" );
	set( "armor_class", 36 );
        set("material","light_metal");
	set( "defense_bonus", 7 );
	set( "value", ({ 253, "gold" }) );
}
