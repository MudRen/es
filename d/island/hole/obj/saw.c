#include <../hole.h>

inherit OBJECT;
void create()
{
	set_name( "A Saw","一把锯子" );
	add( "id",({ "saw" }) );
	set_short( "锯子" );
	set_long(@LONG
	一把锋利的锯子。
LONG
		);
	set( "weight",5 );
	set( "unit","把");
}           
