#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "dang guei", "����" );
           set("no_sale",1);
	add("id", ({"dang","guei"}) );
	set_short( "����" );
	set_long(
		"����һ��������ҩ�ĵĵ��顣����Գ���(taste)����ζ����\n"
	);
	set( "ident", "DANG_GUEI" );
	set( "unit", "��" );
        set( "weight", 2);
	set( "savour","bitter");
	set( "value", ({ 100, "silver" }) );
}
