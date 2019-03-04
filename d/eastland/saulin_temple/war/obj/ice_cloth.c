
#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("iceworm cloth","冰蚕衣");
        add("id",({"cloth"}) );
         set_short("冰蚕衣");
        set_long(@C_LONG
这是一件用北极冰蚕丝做成的衣服，除了有冰蚕丝强韧的弹力外，更
受过阴魔的加持，防御力非同小可。
C_LONG
        );
        set( "unit", "件" );
        set( "weight", 150 );
        set( "type", "body" );
        set( "material", "cloth" );
        set( "armor_class", 25 );
	set( "defense_bonus", 6 );
        set( "special_defense", ([ "ice" :8, "divine":-10 ]) );
        set( "value", ({ 318, "gold" }) );
}
