#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "jail key", "����Կ��" );
	add( "id", ({ "key" }) );
	set_short( "����Կ��" );
	set_long(
		"������ķķ������Կ�ף�����մ����Ѫ����\n"
	);
	set( "to_lock", "TAMUMU_JAIL1" );
	set( "weight", 3 );
	set( "value", ({ 15, "silver" }) );
	set( "no_sale", 1 );
}
