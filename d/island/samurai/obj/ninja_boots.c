#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Ninja Boots ", "����ѥ ");
        add( "id", ({ "boots" }) );
        set_short("Ninja Boots", "����ѥ ");
        set_long(@AAA
һ�������Ǵ��ķ���ѥ����������Ь�ӱ�����Ҫ��Ķ࣬����ȥ
��о�������������һЩ
AAA
     );
        set( "unit", "��"); 
        set( "type", "feet" );
        set( "armor_class", 5 );
        set( "defense_bonus", 2 );
        set("material","leather");
        set( "weight", 30 );
        set( "value", ({ 600, "silver" }) );
}
