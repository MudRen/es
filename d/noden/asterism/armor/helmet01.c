#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("halfling helmet", "������ͷ��");
        add( "id", ({ "helmet" }) );
        set_short( "������ͷ��");
        set_long(
                "���ǰ���������ר�õ�ͷ�� \n"
        );
        set("unit","��");
        set( "type", "head" );
        set("material","light_metal") ;
        set( "armor_class", 5 );
        set( "defense_bonus", 0 );
        set( "weight", 70 );
        set( "value", ({ 135, "gold" }) );
}



