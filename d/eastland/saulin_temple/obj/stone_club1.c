#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "massive bo", "��ʯ��" );
	add( "id", ({ "bo" }) );
	set_short( "��ʯ��" );
	set_long(
		"����һ�����صĴ�ʯ������Ұ����սʿ���õ�������\n"
	);
	set( "unit", "��" );
	setup_weapon( "bo", 30, 15, 35 );
	set( "nosecond", 1 );
	set( "weight", 250 );
	set( "value", ({ 80, "silver" }) );
}
