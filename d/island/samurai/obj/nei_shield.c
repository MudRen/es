#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Thunder Shield", "�׵����");
        add( "id", ({ "thunder","shield" }) );
        set_short("Thunder Shield", "�׵����");
        set_long(@AAA
����һ�������׵羫�������Ķ���
AAA
        );
        set( "unit", "��"); 
        set( "type", "shield" );
        set( "armor_class", 8 );
        set( "defense_bonus", 6 );
        set("material","element");
        set("special_defense",(["eletric":6]));
        set( "weight", 100 );
        set( "value", ({ 1200, "silver" }) );
}
