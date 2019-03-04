#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "blacksteel longsword", "����" );
	add( "id", ({ "longsword", "sword" }) );
	set_short( "a blacksteel longsword", "��������" );
	set_long(
		"You see a blacksteel longsword.\n",
		"һ���ü�Ӳ���������ɵĳ�����\n"
	);
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "weapon_class", 30 );
	set( "min_damage", 14 );
	set( "max_damage", 27 );
	set( "weight", 140 );
	set( "value", ({ 620, "silver" }) );
	set( "no_sale", 1 );
}
