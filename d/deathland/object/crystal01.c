#include "../echobomber.h"

inherit OBJECT;

void create()
{
	set_name( "purple crystal", "��ɫħˮ��" );
	add( "id", ({ "crystal" }) );
	set_short( "purple mystic crystal", "��ɫħˮ��" );
	set_long(
	    "The purple mystic crystal shinning terrible lights.\n",
	    "��ҫ��������ɫ��â�����ص�ˮ��ʯ.\n"
	);
	set( "no_sale", 1 );
	set( "unit", "��" );
	set( "echo_crystal",1);
	set( "weight", 10 );
	set( "value", ({ 1, "silver" }) );
}
