#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("iron helmet", "��˪ҫ��������");
        add( "id", ({ "helmet" }) );
        set_short( "iron helmet", "��˪ҫ��������");
        set_long(
                "A iron helmet .\n",
                "�������������ɵĿ�������Ľ���������һ�ɺ��⣮ \n"
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "heavy_metal");
        set( "armor_class", 9 );
        set( "defense_bonus", 4 );
        set( "special_defense",
               ([ "fire":5, "cold":-2, ]) );
        set( "weight", 80 );
        set( "value", ({ 280, "gold" }) );
}



