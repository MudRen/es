#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("iron cap", "�������ͷ��");
        add( "id", ({ "cap" }) );
        set_short( "iron cap", "�������ͷ��");
        set_long(
                "A iron cap .\n",
                "һ������ֵĽ�����ñ�ӣ���������һ����죮\n"
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "adventurer");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 70 );
        set( "value", ({ 300, "gold" }) );
        set("extra_skills",(["whip":10]));
}



