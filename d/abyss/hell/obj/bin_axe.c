#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "blacksteel grand axe", "����" );
	add( "id", ({ "axe", "grand axe", "blacksteel axe" }) );
	set_short( "a blacksteel grand axe", "��������" );
	set_long(
		"You see a blacksteel grand axe.\n",
		"һ���ü�Ӳ���������ɵ�������\n"
	);
	set( "unit", "��" );
	set( "type", "axe" );
	set( "weapon_class", 30 );
	set( "min_damage", 22 );
	set( "max_damage", 36 );
	set( "weight", 340 );
	set( "value", ({ 730, "silver" }) );
	set( "nosecond", 1 );
	set( "no_sale", 1 );
}
