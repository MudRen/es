#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "swamp moss", "����̦" );
        set("no_sale",1);
	add( "id", ({"moss"}) );
	set_short( "some swamp moss", "����̦" );
	set_long(
		"You see some green moss with dark spots.\n",
		"����һ�����������������̦�࣬������һЩ��ɫ�ߵ㡣����Գ���(taste)����\n"
	);
	set( "unit", "��" );
	set( "ident", "SWAMP_MOSS" );
	set( "effect","slow");
	set( "frequency",3);
	set( "difference",2);
        set( "weight", 2 );
	set( "value", ({ 20, "silver" }) );
}
