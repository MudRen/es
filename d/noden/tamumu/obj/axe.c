#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "grand axe", "�޸�" );
	add( "id", ({ "tamumu grand axe", "axe" }) );
	set_short( "��ķķ�޸�" );
	set_long("��Ѿ޸��ĸ��кܿ������൱�������ܶԵ�������Ĵ��ɱ������\n"
	);
	set( "unit", "��" );
	set( "type", "axe" );
	set( "weapon_class", 25 );
	set( "min_damage", 20 );
	set( "max_damage", 30 );
	set( "nosecond", 1 );
	set( "weight", 200 );
	set( "value", ({ 480, "silver" }) );
}
