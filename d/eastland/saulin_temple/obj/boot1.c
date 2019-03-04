#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("cloud boots", "天帝云鞋");
        add( "id", ({ "boots","boot" }) );
        set_short("天帝云鞋");
        set_long(@C_LONG
云游僧穿之鞋子称为云鞋, 即僧鞋也。
这是玉皇大帝赐给太上老君的鞋子, 相传它虽然重但防御力惊人。
C_LONG
        );
        set("material","cloth");
        set( "unit", "双");
        set( "type", "feet" );
        set( "armor_class", 8 );
        set( "defense_bonus", 2 );
        set( "weight", 120 );
        set( "value", ({ 2450, "silver" }) );
        set( "no_sale", 1 );
}
