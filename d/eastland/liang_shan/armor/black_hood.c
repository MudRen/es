#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("black hood", "���");
        add( "id", ({ "hood","black" }) );
        set_short( "a black hood", "���");
        set_long(
                "A black hood .\n",
                "����һ���������õĺ�ͷ��ͨ����ûʲ����ݵ�λ���˴��� \n"
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "cloth");
        set( "armor_class", 3 );
        set( "defense_bonus", 1 );
        set( "weight", 50 );
        set( "value", ({ 10, "gold" }) );
}



