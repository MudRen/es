#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "samurai_boots ", "��ʿ��ѥ ");
        add( "id", ({ "boots" }) );
        set_short("samurai_boots", "��ʿ��ѥ ");
        set_long(@AAA
һ����ʿ����ʽ���ĳ�ѥ
AAA
        );
        set( "unit", "��"); 
        set( "type", "feet" );
        set( "armor_class", 7 );
        set( "defense_bonus", 3 );
        set("material","leather");
        set( "weight", 100 );
        set( "value", ({ 600, "silver"
         }) );
}
