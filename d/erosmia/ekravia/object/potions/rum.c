#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "rum", "莱姆酒" );
	add( "id", ({ "rum" }) );
	set_short( "莱姆酒" );
	set_long( @LONG
这是一种常见的甜酒, 虽然甜, 可是很容易醉喔。
LONG
	);
	set( "no_sale", 1 );
	set( "unit", "瓶" );
	set( "weight", 15 );
	set( "value", ({ 100, "silver" }) );
}
