#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("King ring","����֮��");
        add( "id", ({ "ring" }) );
        set_short( "����֮��");
        set_long(@C_LONG
һֻ��Ө��͸�Ľ�ָ�����������������˸���߲ʹ�â��
C_LONG
        );
        set( "unit","ֻ");
        set( "type", "finger" );
        set( "material","element");
        set( "defense_bonus", 5 );
        set( "weight", 10 );
        set( "value", ({ 3500, "silver" }) );
}



