#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "great mushroom", "��֥" );
	add("id",({"mushroom"}) );
	set_short("��֥" );
	set_long(
		"�����֥��������ҩ����, ����ֱ������, ��������Գ���(taste)����ζ����\n"
	);
	set( "ident", "GREAT_MUSHROOM" );
	set( "unit", "��" );
        set( "weight", 2 );
	set( "savour","bitter");
	set( "value", ({ 120, "silver" }) );
}
