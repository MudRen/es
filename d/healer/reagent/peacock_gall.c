#include <mudlib.h>
inherit "/std/reagent.c";


void create()
{
	set_name( "peacock's gall", "��ȸ��" );
	add( "id", ({"gall"}) );
	set_short( "��ȸ��" );
	set_long(
		"����һ����ɫ�Ŀ�ȸ��,����ǿ�ҵĶ��ԡ�\n"
		"����㲻�����Ļ�,���Գ���(taste)����\n"
	);
           set("no_sale",1);
	set( "unit", "��" );
	set( "ident", "PEACOCK_GALL" );
        set( "weight", 2 );
	set( "value", ({ 20, "silver" }) );
        set ( "effect","simple_poison");
        set ( "duration",2);
        set ( "damage",40);
}

