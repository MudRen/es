#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "iron key", "����Կ��" );
	add( "id", ({ "key" }) );
	set_short( "an iron key", "����Կ��" );
	set_long(
		"An ivory key with a large ruby on its handle.\n",
		"һ���ø����������ɵ�Կ�ס�\n"
	);
	set( "unit", "��" );
	set( "to_lock", "WINEROOM_DOOR" );
	set( "weight", 3 );
	set( "value", ({ 40, "silver" }) );
	set( "no_sale", 1 );
}
