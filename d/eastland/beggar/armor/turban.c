#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name("white turban", "���ڽ�");
        add( "id", ({ "turban" }) );
        set_short( "���ڽ�");
        set_long(@C_LONG
���ڽ���һ������������ϲ�������ͷ���ˡ� 
C_LONG
        );
        set("unit","��");
        set( "type", "head" );
        set("material","cloth") ;
        set( "armor_class", 7 );
        set( "defense_bonus", 3 );
        set( "weight", 30 );
        set( "value", ({ 60, "gold" }) );
}



