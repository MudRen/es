#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Ninja gloves", "��������");
        add( "id", ({ "ninja","gloves"}) );
        set_short("Ninja Vest", "��������");
        set_long(@AAA
һ��������ʹ�õ����ף���˵�з����Ĺ���
AAA
        );
        set( "unit", "��"); 
        set( "type", "hands" );
        set( "armor_class", 3 );
        set( "defense_bonus", 2 );
        set( "specail_defense",([ "poison" : 30 ]));
        set("material","leather");
        set( "weight", 20 );
        set( "value", ({ 1160, "silver" }) );
}
