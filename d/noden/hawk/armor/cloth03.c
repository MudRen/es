#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "Hell Blessed suit","��ڤ֮��" );
        add( "id", ({ "suit","cloth" }) );
        set_short( "��ڤ֮��" );
        set_long(
                "�㿴�������������д�˼�����: �ڵ�˹��Ʒ��Ʒ�ʱ�֤��\n"
        );
        set( "unit", "��" );
        set("material","cloth");
        set( "type", "body" );
        set( "armor_class", 33 );
        set( "defense_bonus", 5 );
        set( "weight", 70 );
        set( "value", ({ 1700, "silver" }) );
}
