#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "rhinoceros horn", "Ϭţ��" );
              set("no_sale",1);
	add( "id", ({ "horn" }) );
	set_short( "a rhinoceros horn", "Ϭţ��" );
	set_long(
		"You see a horn of rhinoceros, used to be a kind of reagent.\n",
		"����Ϭţͷ�ϵĽǣ���ǰ������������������������ҩ�ġ�����Գ���(taste)����\n"
	);
	set( "ident", "RHINOCEROS_HORN" );
	set( "unit", "֦" );
        set( "weight", 4 );
	set( "effect","weak");
	set( "frequency",3);
	set( "difference",3);
	set( "value", ({ 680, "silver" }) );
}
