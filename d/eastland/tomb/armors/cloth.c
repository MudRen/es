#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("Sky Cloth","天衣");
        add("id",({"cloth"}) );
        set_short( "@@title");
        set_long(
"传说中天衣是无缝的，如今你看到的这件衣服真的找不到接缝，不知道
是如何制成的。\n"
        );
        set( "unit", "件" );
        set( "weight", 120 );
        set( "type", "body" );
        set( "light", 1);
        set( "material", "cloth");
        set( "armor_class", 32 );
        set( "defense_bonus", 8 );
        set( "value", ({ 199, "gold" }) );
        set( "special_defense", ([ "fire":10,"cold":10,"evil":10 ]) );
        set("no_sale",1);
}

string title()
{
	return set_color("天衣","HIW");
}