#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "fruit", "��ʵ" );
	add("id",({"fruit"}) );
	set_short("��ʵ" );
	set_long(
		"��Ź�ʵ����������ƻ��, ���Ǳ��沼��ϸϸ����ë������Գ���(taste)����ζ����\n"
	);
	set( "ident", "NO_NAME_FRUIT" );
	set( "unit", "��" );
        set( "weight", 2 );
	set( "savour","sweet");
	set( "effect","simple_poison");
	set( "duration",4);
	set( "damange",6);
	set( "no_sale",1);
}

