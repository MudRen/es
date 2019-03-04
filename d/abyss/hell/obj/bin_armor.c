#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "blacksteel armor", "ս��" );
	add( "id", ({ "armor" }) );
	set_short( "a suit of blacksteel armor", "����ս��" );
	set_long(
		"You see a suit of blacksteel armor.\n",
		"һ���ü�Ӳ���������ɵ�ս�ס�\n"
	);
	set( "unit", "��" );
	set( "type", "body" );
	set( "armor_class", 25 );
	set( "defense_bonus", 5 );
	set( "weight", 300 );
	set( "value", ({ 830, "silver" }) );
	set( "no_sale", 1 );
}
