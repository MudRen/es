#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Thunder Vest", "�׵�ս��");
        add( "id", ({ "thunder","vest" }) );
        set_short("Thunder Vest", "�׵�ս��");
        set_long(@AAA
����һ�������׵羫�����������ף�������սʱ�����ķ��ߣ�����
ǰ�滹����һ���羫�鷨ӡ����
AAA
        );
        set( "unit", "��"); 
        set( "type", "body" );
        set( "armor_class", 37 );
        set( "defense_bonus", 6 );
        set("material","element");
        set("special_defense",(["eletric":10]));
        set( "weight", 110 );
        set( "value", ({ 1700, "silver" }) );
}
