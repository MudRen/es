#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "rum", "��ķ��" );
	add( "id", ({ "rum" }) );
	set_short( "��ķ��" );
	set_long( @LONG
����һ�ֳ��������, ��Ȼ��, ���Ǻ�������ม�
LONG
	);
	set( "no_sale", 1 );
	set( "unit", "ƿ" );
	set( "weight", 15 );
	set( "value", ({ 100, "silver" }) );
}
