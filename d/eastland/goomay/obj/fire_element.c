#include <../goomay.h>

inherit OBJECT;

void create()
{
	set_name( "fire element", "��֮��" );
	add( "id", ({ "element","fire" }) );
	set_short( "a fire element", "��֮��" );
	set_long(
		"You see a element of fire . \n",
		"����һ�ź����Ļ��澫����\n"
	);
	set( "unit", "��" );
	set( "weight", 5 );
	set( "value", ({ 100, "silver" }) );
	set( "no_sale", 1 );
}

