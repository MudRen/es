#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name("wind ring","���ƽ�ָ");
        add( "id", ({ "ring" }) );
        set_short( "���ƽ�ָ");
        set_long(@C_LONG
���ƽ�ָ����˷��������ӵĶ���֮��,��˵,��˷������ָ����һЩ�ھ���
C_LONG
        );
        set("unit","ֻ");
        set( "type", "finger" );
        set("material","element");
        set( "armor_class", 0 );
        set( "defense_bonus", 3 );
        set( "weight", 10 );
        set( "value", ({ 147, "gold" }) );
}



