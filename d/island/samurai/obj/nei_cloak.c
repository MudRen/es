#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Thunder Cloak", "�׵�����");
        add( "id", ({ "thunder","cloak" }) );
        set_short("Thunder Cloak", "�׵�����");
        set_long(@AAA
����һ�������׵羫������������
AAA
        );
        set( "unit", "��"); 
        set( "type", "cloak" );
        set( "armor_class", 7 );
        set( "defense_bonus", 5 );
        set("material","cloth");
        set("special_defense",(["eletric":7]));
        set( "weight", 30 );
        set( "value", ({ 700, "silver" }) );
}
