#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("Copper shield", "ͭ��");
        add( "id", ({ "shield" }) );
        set_short( "ͭ��" );
        set_long(
@C_LONG
����ͭ�ƵĶ��ƣ�������ʵ���ء�
C_LONG
        );
        set( "unit", "��");
        set( "type", "shield" );
        set( "material", "heavy_metal" );
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 140 );
        set( "value", ({ 380, "silver" }) );
}
