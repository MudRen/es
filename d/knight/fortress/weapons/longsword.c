#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name("long sword", "����");
	add( "id", ({ "sword" }) );
	set_short( "��������" );
	set_long(
		"���ָֽ���ŵ�����������ӵ���ʽ������\n"
	);
	set( "unit", "��" );
	set( "weight", 70 );
	set( "weapon_class", 18 );
	set( "type", "longblade" );
	set( "min_damage", 8 );
	set( "max_damage", 19 );
	set( "value", ({ 480, "silver" }) );
}
