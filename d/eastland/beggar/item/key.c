#include <mudlib.h>

inherit OBJECT;

void create()
{
   set_name( "copper key", "ͭԿ��" );
	add( "id", ({ "key" }) );
   set_short( "ͭԿ��" );
   set_long(
            "һ�������ͭԿ�ס�\n" );
   set( "unit", "��" );
   set( "to_lock", "DBEGGAR_JAIL1" );
	set( "weight", 3 );
	set( "value", ({ 1, "silver" }) );
	set( "no_sale", 1 );
}
