#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "Spirit robe","����֮��" );
        add( "id", ({ "robe","cloth" }) );
        set_short( "����֮��" );
        set_long(
                "һ���������������õ����ӣ���ȴ�����൱����ķ�������\n"
        );
        set( "unit", "��" );
        set("material","cloth");
        set( "type", "body" );
        set( "armor_class", 26 );
        set( "defense_bonus", 4 );
        set( "weight", 90 );
        set( "value", ({ 410, "silver" }) );
}
