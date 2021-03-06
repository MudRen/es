#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("cloud boots", "天帝云鞋");
        add( "id", ({ "boots","boot" }) );
        set_short("a pair of cloud boots", "天帝云鞋");
        set_long(
"A pair of boots made of clouds  .\n",
"云游僧穿之鞋子称为云鞋, 即僧鞋也。\n"
"这是玉皇大帝赐给太上老君的鞋子, 相传它虽然重但防御力惊人。\n"
        );
        set("material","cloth");
        set( "unit", "双");
        set( "type", "feet" );
        set( "armor_class", 8 );
        set( "defense_bonus", 4 );
        set( "weight", 120 );
        set( "value", ({ 2450, "silver" }) );
        set( "no_sale", 1 );
}
