#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "ivory key", "����Կ��" );
	add( "id", ({ "key" }) );
	set_short( "an ivory key", "����Կ��" );
	set_long(
		"An ivory key with a large ruby on its handle.\n",
		"һ����������̳ɵ�Կ�ף���Կ�׵ı���������һ���챦ʯ��\n"
	);
	set( "unit", "��" );
	set( "to_lock", "KING_YARAMON_XI_LIBRARY" );
	set( "weight", 3 );
	set( "value", ({ 40, "silver" }) );
	set( "no_sale", 1 );
}
