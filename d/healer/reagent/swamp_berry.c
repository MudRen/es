#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "swamp berry", "����ݮ��" );
        set("no_sale",1);
	add( "id", ({"berry"}) );
	set_short( "����ݮ��" );
	set_long(
		"����һ���������ų�ζ�ĺ�ɫ����ݮ��������Գ���(taste)����\n"
	);
	set( "ident", "SWAMP_BERRY" );
set("unit","��");
	set( "savour","acrimony");
	set( "effect","simple_poison");
	set( "duration",3);
	set( "damage",2);
        set( "weight", 2 );
	set( "value", ({ 10, "silver" }) );
}
