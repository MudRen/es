#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "club", "������" );
	add( "id", ({ "spiked club" }) );
	set_short( "������" );
	set_long(
   "������������������������̣��������Ǽ����ص�սʿ��������\n"
	);
	set( "unit", "��" );
	set( "type", "blunt" );
	set( "weapon_class", 18 );
	set( "min_damage", 7 );
	set( "max_damage", 24 );
	set( "weight", 170 );
	set( "value", ({ 230, "silver" }) );
}
