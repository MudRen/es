#include "../echobomber.h"

inherit OBJECT;

void create()
{
	set_name( "green crystal", "��ɫħˮ��" );
	add( "id", ({ "crystal" }) );
	set_short( "green mystic crystal", "��ɫħˮ��" );
	set_long(
	    "The green mystic crystal shinning terrible lights.\n",
	    "��ҫ��а����ɫ��â�����ص�ˮ��ʯ.\n"
	);
	set( "no_sale", 1 );
	set( "unit", "��" );
	set( "echo_crystal",3);
	set( "weight", 10 );
	set( "value", ({ 1, "silver" }) );
}
