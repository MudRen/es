#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "steel hook", "�ֹ�" );
	add( "id", ({ "hook" }) );
   set_short( "�ֹ�" );
	set_long(
		"����ֹ�����һ�������ֲ������ף���֪��Ϊʲ�ả����ϲ��������������\n"
	);
	set( "unit", "��" );
	setup_weapon( "unarmed", 21, 9, 28 );
	set( "weight", 50 );
	set( "value", ({ 940, "silver" }) );
}
