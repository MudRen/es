#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "cellar key", "�ƽ�Կ��" );
	add( "id", ({ "key" }) );
   set_short( "�ƽ�Կ��" );
	set_long(
		"һ�ѻ�ͭ���ɵ�Կ�ף����湳��һ��������\n"
	);
	set( "unit", "��" );
	set( "to_lock", "GHOST_HAROLD_CELLAR" );
	set( "weight", 3 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
}
