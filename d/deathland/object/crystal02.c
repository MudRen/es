#include "../echobomber.h"

inherit OBJECT;

void create()
{
	set_name( "black crystal", "��ɫħˮ��" );
	add( "id", ({ "crystal" }) );
	set_short( "black mystic crystal", "��ɫħˮ��" );
	set_long(
	    "The black mystic crystal shinning terrible lights.\n",
	    "��ҫ�������ĺ�ɫ��â�����ص�ˮ��ʯ.\n"
	);
	set( "no_sale", 1 );
	set( "unit", "��" );
	set( "echo_crystal",2);
	set( "weight", 10 );
	set( "value", ({ 1, "silver" }) );
}
