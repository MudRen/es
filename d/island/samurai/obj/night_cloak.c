#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "night_shadow_cloak", "ҹӰ����");
        add( "id", ({ "cloak" }) );
        set_short("night_shadow_cloak", "ҹӰ����");
        set_long(@AAA
����һ������ɫ������,����������ҹ��ʱ,���׶�ز����˷���
AAA
        );
        set( "unit", "��"); 
        set( "type", "cloak" );
        set( "armor_class", 5 );
        set( "defense_bonus", 4 );
        set("material","leather");
        set("special_defense",(["cold": 10 ,"mental": 10 ]));
        set( "weight", 70 );
        set( "value", ({ 1200, "silver"
         }) );
}

