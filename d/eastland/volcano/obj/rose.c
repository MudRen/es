#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "blue rose", "��õ��" );
	set_short( "��õ��" );
        add ( "id" , ({"rose"}) );
	set_long(
	  "����һ�����Ϻ��е���ɫõ�廨��\n"
	);
	set( "no_sale", 1 );
	set( "unit", "��" );
	set( "weight", 2 );
	set( "value", ({ 1, "gold" }) );
}
