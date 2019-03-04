#include "../asterism.h"

inherit ARMOR;

void create()
{
        set_name("obsidian gloves", "黑曜石手套");
        add( "id", ({ "gloves" }) );
        set_short( "黑曜石手套");
        set_long(
                "这是一双由珍贵的黑曜石制成的手套。\n"
        );
        set("unit","双");
        set( "type", "hands" );
        set("material","element") ;
	set( "armor_class", 5 );
        set( "defense_bonus", 3 );
        set( "weight", 65 );
        set( "value", ({ 150, "gold" }) );
}






