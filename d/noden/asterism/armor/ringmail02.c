#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("bronze ringmail", "��ͭ����");
        add( "id", ({ "ringmail","mail" }) );
        set_short( "��ͭ����");
        set_long(
                "����һ����ͭ�ƵĻ��ס�\n"
        );
        set("unit","��");
        set( "type", "body" );
        set("material","light_metal");
        set( "armor_class", 26 );
        set( "defense_bonus", 0 );
        set( "weight", 300 );
        set( "value", ({ 210, "gold" }) );
}






