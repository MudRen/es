#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("bronze leggings", "��ͭ�ּ�");
        add( "id", ({ "leggings" }) );
        set_short("��ͭ�ּ�");
        set_long(
                "����һ˫��ͭ�ּ�.\n"
        );
        set("unit","˫");
        set( "type", "legs" );
        set("material","light_metal") ;
        set( "armor_class", 7 );
        set( "defense_bonus", 0 );
        set( "weight", 100 );
        set( "value", ({ 180, "gold" }) );
}






