#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "highsteel shortsword", "���ֶ̽�" );
	add( "id", ({ "shortsword", "sword" }) );
	set_short( "a highsteel shortsword", "���ֶ̽�" );
	set_long(
		"You see an excellent shortsword made of highsteel.\n",
		"����һ��ǧ���١������ֶͳɵĶ̽����Ǳ���®�ľ�Ʒ��\n"
	);
	set( "unit", "��" );
	set( "weight", 90 );
	setup_weapon( "shortblade", 25, 11, 22 );
//	set( "bleeding", 5 );
	set( "value", ({ 420, "silver" }) );
}
