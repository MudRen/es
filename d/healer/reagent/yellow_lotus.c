#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "yellow lotus", "����" );
         set("no_sale",1);
	add( "id", ({"lotus"}) );
	set_short( "����" );
	set_long(
		"����һЩ��������ɹǬ�Ƴɵ�ҩ�ġ�����Գ���(taste)����ζ����\n"
	);
	set( "unit","��");
	set( "ident", "YELLOW_LOTUS" );
	set( "savour","bitter");
	set( "effect","slow");
	set( "frequency",2);
	set( "difference",2);
        set( "weight", 2 );
	set( "value", ({ 10, "silver" }) );
}
