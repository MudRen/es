#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("white lead ringmail", "��Ǧ����");
        add( "id", ({ "ringmail","mail" }) );
        set_short( "��Ǧ����");
        set_long(
                "����һ���ɰ�Ǧ�ƵĻ��ס�\n"
        );
        set("unit","��");
        set( "type", "body" );
        set("material","light_metal"); 
        set( "armor_class", 28 );
        set( "defense_bonus", 3 );
        set( "weight", 270 );
        set( "value", ({ 150, "gold" }) );
}






