#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "karate_clothes", "���ֵ���");
        add( "id", ({ "cloth","clothes" }) );
        set_short("karate_clothes", "���ֵ��� ");
        set_long(@AAA
һ�������ֵ��������ĵ���
AAA
       );
        set( "unit", "��"); 
        set( "type", "body" );
        set( "armor_class", 10 );
        set( "defense_bonus", 1 );
        set("material","cloth");
        set( "weight", 100 );
        set( "value", ({ 300, "silver" }) );
}
