#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "moon ring","�½�");
        add( "id", ({"ring"}) );
        set_short("�½�");
        set_long(@C_LONG
һֻ�����������¹ⱦʯ�������Ľ�ָ����ָ����ҫ������Ͼ�Ĺ�â�����˲�����
����һ����
C_LONG
        );
        set( "unit", "ֻ" );
        set( "type", "finger" );
        set( "material", "element" );
        set( "weight",1);
        set( "defense_bonus", 7 );
        set( "value", ({ 1000, "silver" }) );
}
