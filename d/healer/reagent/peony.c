#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "peony", "��ҩ" );
set("no_sale",1);
	set_short( "��ҩ" );
	set_long(
		"��������ҩ��Ҷ��ɹǬ�Ƴɵ�ҩ�ġ�����Գ���(taste)����ζ����\n"
	);
	set( "ident", "PEONY" );
	set( "unit", "��" );
        set( "weight", 2 );
	set( "savour","acidity");
	set( "effect","weak");
	set( "frequency",1);
	set( "difference",3);
	set( "value", ({ 40, "silver" }) );
}
