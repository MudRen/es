#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "longsword", "����" );
	add( "id", ({ "long sword", "sword" }) );
	set_short( "an alloyed longsword", "�Ͻ𳤽�" );
	set_long(
		"You see a long sword made of some unknown alloyed metal.\n",
		"����һ����ĳ�ֺϽ����ɵĳ���������Ϊ����ɫ������ɫ����\n"
	);
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "weight", 80 );
	set( "weapon_class", 21 );
	set( "min_damage", 9 );
	set( "max_damage", 19 );
	set( "value", ({ 470, "silver" }) );
}
