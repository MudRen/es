#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name("doctor amulet", "ҽ�߻���");
        add( "id", ({ "amulet" }) );
        set_short( "ҽ�߻���");
        set_long(@C_LONG
����һ������ͨ�Ļ���,��������һ�Ѽ�Ҫ����ҽ������, ����˵��һ���ֵ仹��
��ǡ����
C_LONG               
               );
        set("unit","��");
        set("material","element");
        set( "type", "misc" );
        set( "armor_class", 0 );
        set( "defense_bonus", 6 );
        set( "weight", 5 );
        set( "value", ({ 110, "gold" }) );
}



