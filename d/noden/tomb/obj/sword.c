#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "rusty longsword", "�⽣" );
	add( "id", ({ "longsword", "sword" }) );
  set_short( "���ⳤ��" );
	set_long(
		"��ѳ����Ѿ��������⣬�����������ƺ����ܵ���������\n"
	);
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "weight", 80 );
	set( "weapon_class", 9 );
	set( "min_damage", 5 );
	set( "max_damage", 13 );
	set( "value", ({ 105, "silver" }) );
}
