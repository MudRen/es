#include <../goomay.h>

inherit OBJECT;

void create()
{
	set_name( "The statue of Goddess", "������" );
	add( "id", ({ "statue" }) );
	set_short( "������" );
	set_long(
		"����һ����񾫵��Ů����\n"
	);
	set( "unit", "��" );
	set( "weight", 5 );
	set( "value", ({ 100, "silver" }) );
	set( "no_sale", 1 );
}

