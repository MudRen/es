#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "sweet herb", "�ʲ�" );
       set("no_sale",1);
	add("id",({"herb"}));
	set_short( "�ʲ�" );
	set_long(
		"�ʲ�ҩ���º�, ��ĳЩҩ�����ǲ���ȱ��ҩ��������Գ���(taste)����\n"
	);
	set( "ident", "SWEET_HERB" );
	set( "unit", "��" );
        set( "weight", 2);
	set( "savour","sweet");
         set( "value",({50, "silver" }) );
}
