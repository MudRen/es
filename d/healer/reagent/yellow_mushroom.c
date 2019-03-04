#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "yellow mushroom", "��Ģ��" );
        set("no_sale",1);
	add( "id", ({"mushroom"}) );
	set_short( "a yellow mushroom", "��Ģ��" );
	set_long(
		"You see a yellow mushroom with small white mushroom.\n",
		"����һ��������ɫަ���Ͱ�ɫС�ߵ��Ģ��������Գ���(taste)����ζ����\n"
	);
        set( "unit", "��");
	set( "ident", "YELLOW_MUSHROOM" );
	set( "savour","acidity");
	set( "effect","simple_poison");
	set( "duration",5);
	set( "damage",3);
        set( "weight", 2 );
	set( "value", ({ 10, "silver" }) );
}
