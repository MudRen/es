#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("halfling magician cape", "������ħ��ʦ����");
        add( "id", ({ "cape" }) );
        set_short( "������ħ��ʦ����");
        set_long(
                "���ǰ�����ħ��ʦר�õ����� \n"
        );
        set("unit","��");
        set( "type", "cloak" );
        set("material","cloth") ;
        set( "armor_class", 5 );
        set( "defense_bonus", 3 );
        set( "weight", 70 );
        set( "value", ({ 155, "gold" }) );
}



