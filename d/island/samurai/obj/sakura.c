#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Sakura Clothes", "ӣ֮��");
        add( "id", ({ "clothes"}) );
        set_short("Sakura Clothes", "ӣ֮��");
        set_long(@AAA
����һ������ӣ��ͼ���ĳ���
AAA
        );
        set( "unit", "��"); 
        set( "type", "body" );
        set( "armor_class", 31 );
        set( "defense_bonus", 2 );
        set("material","cloth");
        set( "weight", 110 );
        set( "value", ({ 1160, "silver" }) );
}
