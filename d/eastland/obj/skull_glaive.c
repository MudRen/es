#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "skull glaive", "��ͷ��" );
	add( "id", ({ "glaive" }) );
   set_short( "��ͷ��" );
	set_long(
		"����һ�����صĴ󵶣������Ͽ���һ���׶������Ĺ�ͷ��\n"
	);
	set( "unit", "��" );
	set( "weight", 150 );
	setup_weapon( "longblade", 26, 11, 29 );
	set( "bleeding", 5 );
	set( "value", ({ 72, "gold" }) );
}
