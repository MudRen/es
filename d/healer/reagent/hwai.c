#include <mudlib.h>
inherit OBJECT;

void create()
{
	set_name( "Hwai", "��ľ" );
	add("id",({"plant","tree","hwai"}) );
	set_short("��ľ");
	set_long( "����һ�λ�ľ����֦��\n");
	set( "ident", "HWAI" );
	set( "unit", "��" );
        set( "weight", 4 );
	set( "value", ({ 10, "silver" }) );
}

