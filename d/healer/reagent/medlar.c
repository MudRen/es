#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "medlar", "�����" );
         set("no_sale",1);
	set_short( "a medlar fruit", "�����" );
	set_long(
		"You see a medlar fruit which are used as reagents the most.\n",
		"����һ��������ҩ�ĵ�����ӡ�����Գ���(taste)����\n"
	);
	set( "ident", "MEDLAR" );
	set( "unit", "��" );
        set( "weight", 2 );
	set( "savour","sweet");
        set("value", ({40,"silver" }) );
}
