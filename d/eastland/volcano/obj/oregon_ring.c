#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "oregon ring", "���ոԵĽ�ָ" );
	add( "id", ({ "ring" }) );
	set_short( "���ոԵĽ�ָ" );
	set_long(
		"���Ƕ��ոԵĽ�ָ��\n"
	);
	set( "no_sale", 1 );
	set( "unit", "ֻ" );
	set( "weight", 3 );
	set( "value", ({ 1, "silver" }) );
}
