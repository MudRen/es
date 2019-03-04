#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "shortsword", "�̽�" );
	add( "id", ({ "short sword", "sword" }) );
	set_short( "an alloyed shortsword", "�Ͻ�̽�" );
	set_long(
		"You see a short sword made of some unknown alloyed metal.\n",
		"����һ����ĳ�ֺϽ����ɵĶ̽�������Ϊ����ɫ������ɫ����\n"
	);
	set( "unit", "��" );
	set( "type", "shortblade" );
	set( "weight", 50 );
	set( "weapon_class", 15 );
	set( "min_damage", 6 );
	set( "max_damage", 13 );
	set( "value", ({ 290, "silver" }) );
}
