#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("cook hat", "��ʦñ");
        add( "id", ({ "hat" }) );
        set_short( "cook hat", "��ʦñ");
        set_long(
                "A hat .\n",
                "����һ����ʦר�õ�ñ�ӣ�����մ���͹�\n"
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "cloth");
        set( "armor_class", 4 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "fire":4,"mental":1 ]) );
        set( "weight", 60 );
        set( "value", ({ 12, "gold" }) );
}



