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
        set( "armor_class",5 );
        set( "weight", 100 );
        set( "value", ({ 1000, "silver" }) );
}



