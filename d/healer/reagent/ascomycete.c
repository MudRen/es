#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "ascomycete", "���Ӿ�" );
	add( "id", ({"reagent"}) );
	set_short("���Ӿ�" );
	set_long(
		"��Ѹ��Ӿ�����ɺ�ɫ, ����˸��һЩ�۹⡣����Գ���(taste)����ζ����\n"
	);
	set( "ident", "ASCOMYCETE" );
	set( "unit", "��" );
        set( "weight", 1 );
	set( "effect","slow");
	set( "frequency",5);
	set( "difference",4);
	set( "value", ({ 50, "silver" }) );
}
