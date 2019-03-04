#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "blacksteel large shield", "���" );
	add( "id", ({ "large shield", "shield", "blacksteel shield" }) );
	set_short( "a blacksteel large shield", "�������" );
	set_long(
		"You see a blacksteel large shield.\n",
		"һ���ü�Ӳ���������ɵĴ�ܡ�\n"
	);
	set( "unit", "��" );
	set( "type", "shield" );
	set( "armor_class", 8 );
	set( "defense_bonus", 2 );
	set( "weight", 160 );
	set( "value", ({ 690, "silver" }) );
	set( "no_sale", 1 );
}
