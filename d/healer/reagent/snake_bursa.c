#include <mudlib.h>
inherit "/std/reagent.c";


void create()
{
	set_name( "snake bursa", "���߶���" );
        set("no_sale",1);
	add( "id", ({"bursa"}) );
	set_short( "���߶���" );
	set_long(
		"����һ�Ŷ��ߵĶ���, ����ϲ���������ݾ�,��˵�������ġ�\n"
		"����㲻�����Ļ�,���Գ���(taste)����\n"
	);
	set( "unit", "��" );
	set( "ident", "SNAKE_BURSA" );
        set( "weight", 2 );
	set( "value", ({ 40, "silver" }) );
        set ( "effect","simple_poison");
        set ( "duration",2);
        set ( "damage",2);
        set ( "savour","sweet");
}

