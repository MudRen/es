#include "../almuhara.h"

inherit OBJECT;

void create()
{
	set_name( "golden dragon orb", "������" );
	add( "id", ({ "key","orb" }) );
	set_short( "������" );
	set_long(
		"����һ�Ž�ɫ�����ӣ���������������Ĺ�â��\n"
	);
	set( "unit", "��" );
	set( "to_lock", "TOMBKEY_1" );
	set( "weight", 5 );
	set( "value", ({ 10, "copper" }) );
	set( "no_sale", 1 );
}
