#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Ninja Vest", "��������");
        add( "id", ({ "ninja","vest"}) );
        set_short("Ninja Vest", "��������");
        set_long(@AAA
һ�����������еķ����£��ǽ�ϸ�Ľ�����֯����״���ȱ���
���������׵ķ�����������������������������߲����еķ�
����
AAA
        );
        set( "unit", "��"); 
        set( "type", "body" );
        set( "armor_class", 30 );
        set( "defense_bonus", 3 );
        set("material","element");
        set( "weight", 100 );
        set( "value", ({ 1160, "silver" }) );
}
