#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("general hood", "һ�ֽ�");
        add( "id", ({ "hood","general" }) );
        set_short( "a general hood", "һ�ֽ�");
        set_long(
                "A general hood .\n",
                "����һ����ͨͷ���ƺ�ûʲ�������... \n"
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "cloth");
        set( "armor_class", 4 );
        set( "defense_bonus", 1 );
        set( "weight", 50 );
        set( "value", ({ 83, "gold" }) );
}



