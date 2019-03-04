#include <mudlib.h>

inherit HERB;

void create()
{
	herb::create();
#include <compress_obj.h>
	set_name( "spicy plaster", "天香断续膏" );
	add( "id", ({ "plaster" }) );
	set_short( "天香断续膏" );
	set_long(@C_LONG
这是一盒著名的外伤灵药「天香断续膏」，采用了超过一百种产自翰烟山
的稀有药草熬制而成，如果敷(apply)在伤处，有恢复神效。
C_LONG
	);
	set( "unit", "盒" );
	set( "heal_apply", 7 );
	set( "duration", 30 );
        set( "weight", 15 );
	set( "value", ({ 25, "gold" }) );
}
