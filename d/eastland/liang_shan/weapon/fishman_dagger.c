#include <takeda.h>

inherit WEAPON;

void create()
{
	set_name("fishman's shortblade", "��ʦ�̵�");
	add("id",({"shortblade"}));
	set_short("��ʦ�̵�");
	set_long(
		"����һ�ѷ����Ķ̵�����������������������\n"
	);
	set( "unit", "��" );
	set( "weight", 95 );
	set( "type", "shortblade" );
	set( "second",1);
	set( "weapon_class", 17 );
	set( "min_damage", 8 );
	set( "max_damage", 16 );
	set( "value", ({ 415, "silver" }) );
}
