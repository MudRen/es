#include "../dony.h"

inherit ARMOR;

void create()
{
        set_name("tan ring","������ָ");
        add( "id", ({ "ring" }) );
        set_short( "������ָ");
        set_long(@C_LONG
������ָ������������������ǧ�꺮���Ƴ�,����ȥ����һ���������⡣
C_LONG
        );
        set("unit","ֻ");
        set( "type", "finger" );
        set("material","element");
        set( "armor_class", 0 );
        set( "defense_bonus", 5 );
        set( "weight", 5 );
        set( "value", ({ 47, "gold" }) );
}



