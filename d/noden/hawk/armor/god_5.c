#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "Spark Leggings","�ŵ��������ּ�" );
        add( "id", ({ "leggings","spark leggings" }) );
        set_short( "�ŵ��������ּ�" );
        set_long(
                "ϣ��ս���ŵ�����ϲ�����ּף��������⣬�����ƺ�����\n"
        );
        set( "unit", "ֻ" );
        set("material","knight");
        set( "type", "legs" );
        set( "armor_class", 1 );
        set( "defense_bonus", 1 );
        set( "weight", 50 );
        set( "value", ({ 4700, "silver" }) );
}
