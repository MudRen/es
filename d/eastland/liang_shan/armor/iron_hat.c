#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("iron hat", "��������ķ���ñ");
        add( "id", ({ "hat" }) );
        set_short( "iron hat", "��������ķ���ñ");
        set_long(
                "A iron helmet .\n",
                "�������������ɵķ�ñ������ٺ�һ��ͺ����ҵ�����õ����֣� \n"
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "light_metal");
        set( "armor_class", 5 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "none":5 ]) );
        set( "weight", 65 );
        set( "value", ({ 100, "gold" }) );
}



