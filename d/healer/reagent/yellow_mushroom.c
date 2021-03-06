#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "yellow mushroom", "黄蘑菇" );
        set("no_sale",1);
	add( "id", ({"mushroom"}) );
	set_short( "a yellow mushroom", "黄蘑菇" );
	set_long(
		"You see a yellow mushroom with small white mushroom.\n",
		"这是一种有著黄色蕈顶和白色小斑点的蘑菇。你可以尝尝(taste)他的味道。\n"
	);
        set( "unit", "颗");
	set( "ident", "YELLOW_MUSHROOM" );
	set( "savour","acidity");
	set( "effect","simple_poison");
	set( "duration",5);
	set( "damage",3);
        set( "weight", 2 );
	set( "value", ({ 10, "silver" }) );
}
