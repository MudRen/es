#include "../echobomber.h"

inherit OBJECT;

void create()
{
	set_name( "grey key", "��ɫԿ��" );
	add( "id", ({ "key" }) );
	set_short( "a grey key", "��ɫԿ��" );
	set_long(
		"A grey key.\n",
		"����һ�ѻ�ɫԿ��,���\��\��δʹ������ԭ�еĹ�����ȫ������\n"
	);
	set( "unit", "��" );
	set( "to_lock", "ECHO_VILLAGE_ARCHDOOR" );
	set( "weight", 5 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
}
