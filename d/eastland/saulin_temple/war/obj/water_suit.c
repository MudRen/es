
#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("fish-scale suit","鱼皮战甲");
        add("id",({"suit"}) );
         set_short("鱼皮战甲");
        set_long(
"这是一套由特殊处理过的鱼皮制成的紧身战甲，有良好的防御力。\n"
        );
        set( "unit", "套" );
        set( "weight", 220 );
        set( "type", "body" );
        set( "material", "leather" );
	set( "armor_class", 20 );
	set( "defense_bonus", 0 );
        set( "value", ({ 87, "gold" }) );
}
