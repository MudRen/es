#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("golden shield","�ƽ��");
        add( "id", ({ "shield" }) );
        set_short( "�ƽ��");
        set_long(@C_LONG
һ����18K�����ɵĶ��ƣ���ֻ�С����̹������˲��õ�����������Ķ��ơ�
C_LONG
        );
        set( "unit","��");
        set( "type", "shield" );
        set( "material","heavy_metal");
        set( "armor_class",10 );
        set( "defense_bonus", 1 );
        set( "weight", 150 );
        set( "value", ({ 3000, "silver" }) );
}



