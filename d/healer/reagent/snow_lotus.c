#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "snow lotus", "ѩ��" );
        set("no_sale",1);
	add( "id", ({"lotus"}) );
	set_short( "ѩ��" );
	set_long(
		"��!������ѩ������ɹǬ�Ƴɵ�ҩ��, ��˵�����ѵ�һ��!!����Գ���(taste)����ζ����\n"
	);
	set( "unit","��");
	set( "ident", "SNOW_LOTUS" );
	set( "savour","sweet");
	set( "effect","weak");
	set( "frequency",2);
	set( "difference",2);
        set( "weight", 2 );
	set( "value", ({ 1000, "silver" }) );
}
