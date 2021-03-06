#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("fish skin","鱼皮水靠");
    add("id",({"fish","skin"}) );
    set_short( "fish skin","鱼皮水靠");
	set_long(
		"This is a cloth made of skin of fish\n",
		"这是一大块鱼皮作成的衣服，滑溜溜，黏搭搭，摸起来颇为\n"
		"恶心，但在水中穿著却可可以活动自如．\n"
	);
	set( "unit", "件" );
	set( "weight", 90 );
	set( "type", "body" );
	set( "armor_class", 19 );
        set("material","leather");
	set( "defense_bonus", 2 );
	set( "value", ({ 45, "gold" }) );
        set( "special_defense",(["none":4,"acid":-5]));
        set( "extra_skills",(["swimming":20]));
}
