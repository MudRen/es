#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "chai hu", "���" );
          set("no_sale",1);
	add("id",({"chai","hu"}) );
	set_short( "���" );
	set_long(
		"����һ֧������ҩ�Ĳ��������Գ���(taste)����ζ����\n"
	);
	set( "ident", "CHAI_HU" );
	set( "unit", "֧" );
        set( "weight", 2 );
	set( "savour","bitter");
	set( "effect","slow");
	set( "frequency",2);
	set( "difference",2);
	set( "value", ({ 50, "silver" }) );
}
