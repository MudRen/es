#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "chuan chiung", "��ܺ" );
           set("no_sale",1);
	add("id", ({"chuan","chiung"}) );
	set_short( "��ܺ" );
	set_long(
		"����һ��������ҩ�Ĵ�ܺ������Գ���(taste)����ζ����\n"
	);
	set( "ident", "CHUAN_CHIUNG" );
	set( "unit", "��" );
        set( "weight", 1 );
	set( "savour","acrimony");
	set( "effect","simple_poison");
	set( "duration",2);
	set( "damage",2);
	set( "value", ({ 50, "silver" }) );
}
