#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("mithril boots", "������սѥ");
        add( "id", ({ "boots" }) );
        set_short( "������սѥ");
        set_long(
                "һ˫�������������ɵ�սѥ.\n"
        );
        set("unit","˫");
        set( "type", "feet" );
        set("material","light_metal") ;
        set( "armor_class", 5 );
        set( "defense_bonus", 2 );
        set( "weight", 100 );
        set( "value", ({ 145, "gold" }) );
}






