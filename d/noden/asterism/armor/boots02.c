#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("Obsidian boots", "����ʯ��ѥ");
        add( "id", ({ "boots" }) );
        set_short( "����ʯ��ѥ");
        set_long(
                "����һ˫����ʯ��ѥ.\n"
        );
        set("unit","˫");
        set( "type", "feet" );
        set("material","element") ;
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set( "weight", 130 );
        set( "value", ({ 70, "gold" }) );
}






