#include <mudlib.h>

inherit OBJECT;

void create()
{
   set_name( "wooden key", "ľԿ��" );
	add( "id", ({ "key" }) );
   set_short( "ľԿ��" );
	set_long(
            "һ���Ͼɵ����ڳ�ľ��ɵ�Կ�ס�\n" );
	set( "unit", "��" );
   set( "to_lock", "IANYEU_LIANG_HOME" );
	set( "weight", 3 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
}
