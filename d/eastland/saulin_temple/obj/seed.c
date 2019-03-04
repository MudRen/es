#include <mudlib.h>

inherit PILL;

void create()
{
	pill::create();
	set_name( "puty seed", "如意菩提子" );
	add( "id", ({ "seed" }) );
	set_short( "如意菩提子" );
	set_long(@C_LONG
这是一颗千年菩提子，它吸收日月精华并受佛祖祝福过, 
服用它可以恢复大量体力。
C_LONG
	);
	set_healing( 120 );
	set( "no_sale", 1 );
	set( "weight", 8 );
	set( "value", ({ 10, "gold" }) );
}
