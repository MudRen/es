#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "chrysanthemum marks", "���μһ�");
        add( "id", ({ "marks","marks" }) );
        set_short("chrysanthemum marks", "���μһ�");
        set_long(@AAA
һ�����μһ�,��������ʿ�ӳ�Լ�޼ҵļһ�
AAA
        );
        set( "unit", "��"); 
        set( "type", "misc" );
        set( "armor_class", 0 );
        set( "defense_bonus", 6 );
        set("material","element");
        set( "weight", 30 );
        set( "special_defense",(["fire":20]));
        set( "value", ({ 800, "silver"
                }) );
        
}
