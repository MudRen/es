#include "../../layuter.h"
inherit ARMOR;

void create()
{
        set_name("jade shield", "������");
        add( "id", ({ "shield" }) );
        set_short("������");
        set_long(
                "����һ���������Ķ���\n"
        );
        set("unit","��");
        set( "type", "shield" );
        set( "material", "element" );
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set( "special_defense", ([ "electric":3 ]) );
        set( "weight", 100 );
        set( "value", ({ 300, "gold" }) );
}