#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("gold crown", "�Ͻ��");
        add( "id", ({ "crown" }) );
        set_short("�Ͻ��");
        set_long(
                "���������ʹ�˴���֮����Ī�����ҫ��\n"
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "element");
        set( "armor_class", 8 );
        set( "defense_bonus", 0 );
        set( "special_defense",
               ([ "energy":5 ]) );
        set( "weight", 120 );
        set( "value", ({ 230, "gold" }) );
        set( "no_sell",1);
}






