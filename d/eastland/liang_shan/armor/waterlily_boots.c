#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("waterlily boots", "ź˿������");
        add( "id", ({ "boots" }) );
        set_short("ź˿������");
        set_long(
                "��������ź����ά���Ƴɵ�Ь�ӣ��������ʮ�����ã�\n"
        );
        set( "no_sale",1);
        set( "unit", "˫");
        set( "type", "feet" );
        set( "material", "element");
        set( "armor_class", 7 );
        set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "evil":8, "divine":-8,"poison":2 ]) );
        set( "weight", 70 );
        set( "value", ({ 2740, "silver" }) );
}
