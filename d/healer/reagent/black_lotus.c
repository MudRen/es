#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "black lotus", "��������" );
	add( "id", ({"lotus"}) );
	set_short( "��������" );
	set_long(
		"������������һ�������������е�������ɹǬ�Ƴɵġ�ɫ�ʵ��ۺ�,\n"
		"��Щ�������㡣����Գ���(taste)����ζ����\n"
	);
	set( "unit","��");
	set( "ident", "BLACK_LOTUS" );
	set( "savour","bitter");
	set( "effect","slow");
	set( "frequency",4);
	set( "difference",3);
        set( "weight", 1 );
	set( "value", ({ 15, "silver" }) );
}

