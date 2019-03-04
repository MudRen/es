#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "highsteel longsword", "����" );
	add( "id", ({ "longsword", "sword" }) );
	set_short( "a highsteel longsword", "��ֳ���" );
	set_long(
		"You see an excellent longsword made of highsteel.\n",
		"����һ���ʵؼ�Ӳ��������ɵĳ�����\n"
	);
	set( "unit", "��" );
	set( "weight", 90 );
	setup_weapon( "longblade", 22, 9, 20 );
//	set( "bleeding", 5 );
	set( "value", ({ 520, "silver" }) );
}
