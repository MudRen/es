#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "altar key", "��̳Կ��" );
	add( "id", ({ "key" }) );
	set_short( "an altar key", "��̳Կ��" );
	set_long(
		"A long iron key.\n",
		"������������ͨ����̳���ŵ�Կ�ס�\n"
	);
	set( "unit", "��" );
	set( "to_lock", "HAWK_ALTAR_ENTRANCE" );
	set( "weight", 3 );
	set( "value", ({ 40, "silver" }) );
	set( "no_sale", 1 );
}
