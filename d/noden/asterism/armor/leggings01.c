#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("brass leggings", "��ͭ�ּ�");
        add( "id", ({ "leggings" }) );
        set_short("��ͭ�ּ�");
        set_long(
                "����һ˫��ͭ�ּ�.\n"
        );
        set("unit","˫");
        set( "type", "legs" );
        set("material","light_metal") ;
        set( "armor_class", 6 );
        set( "defense_bonus", 0 );
        set( "weight", 110 );
        set( "value", ({ 70, "gold" }) );
}






