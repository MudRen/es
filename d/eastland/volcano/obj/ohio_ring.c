#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "ohio ring", "����Ľ�ָ" );
	add( "id", ({ "ohio ring","ring" }) );
	set_short("����Ľ�ָ" );
	set_long(
		"���Ƕ���Ľ�ָ��\n"
	);
	set( "no_sale", 1 );
	set( "unit", "ֻ" );
	set( "weight", 3 );
	set( "value", ({ 0, "silver" }) );
}
