#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "ginseng", "�˲�" );
	set_short( "a ginseng", "�˲�" );
	set_long(
		"You see a ginseng which are used as reagents the most.\n",
		"����һ��������ҩ�ĵ��˲Ρ�����Գ���(taste)����ζ����\n"
	);
	set( "ident", "GINSENG" );
         set("no_sale",1);
	set( "unit", "��" );
        set( "weight", 2 );
	set( "savour","bitter");

	set( "value", ({ 100, "silver" }) );
}
