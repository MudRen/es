#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("Dwarvern mithril full plate","矮人米苏理铠甲");
        add("id",({"plate","platemail"}) );
         set_short( "a dwarvern mithril full plate","矮人米苏理铠甲");
	set_long(
"This is a suit of full plate made of mithril meterial,which can  \n"
"protect your body against opponent's attacks.\n",
"这是一副由米苏理金属造的铠甲,可以保护你抵抗敌人的攻击\n"
	);
	set( "unit", "件" );
	set( "weight", 350 );
	set( "type", "body" );
	set( "material", "light_metal" );
	set( "armor_class", 32 );
	set( "defense_bonus", 0 );
	set( "value", ({ 220, "gold" }) );
}
