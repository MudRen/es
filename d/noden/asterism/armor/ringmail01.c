#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("halfling ringmail", "�����˻���");
        add( "id", ({ "ringmail","mail" }) );
        set_short("�����˻���");
        set_long(
                "���ǰ�����������ר�õĻ��ס�\n"
        );
        set("unit","��");
        set( "type", "body" );
        set("material","light_metal");
        set( "armor_class", 25 );
        set( "defense_bonus", 2 );
        set( "weight", 250 );
        set( "value", ({ 200, "gold" }) );
}






