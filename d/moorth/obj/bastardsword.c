#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "bastardsword", "�޽�" );
	add( "id", ({ "bastard sword", "sword" }) );
	set_short( "an alloyed bastardsword", "�Ͻ�޽�" );
	set_long(
		"You see a bastard sword made of some unknown alloyed metal.\n",
		"����һ����ĳ�ֺϽ����ɵ����ͽ�������Ϊ����ɫ������ɫ����\n"
	);
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "weight", 160 );
	set( "nosecond", 1 );
	set( "weapon_class", 29 );
	set( "min_damage", 11 );
	set( "max_damage", 26 );
	set( "value", ({ 750, "silver" }) );
}
