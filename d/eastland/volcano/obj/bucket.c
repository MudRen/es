#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "bucket", "��ˮͰ" );
	set_short( "��ˮͰ" );
	set_long(
		"������������������õĴ�ˮͰ���ǳ��������˿����������档\n"
	);
	set( "no_sale", 1 );
	set( "unit", "ֻ" );
	set( "weight", 3 );
	set( "value", ({ 1, "silver" }) );
}
