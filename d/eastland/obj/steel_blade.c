#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "steel blade", "�ֵ�" );
	add( "id", ({ "blade" }) );
   set_short( "�ֵ�" );
	set_long(
		"��Ѹֵ�������ʮ��Ѱ���������У��������֡�\n"
	);
	set( "unit", "��" );
	set( "weight", 120 );
	setup_weapon( "longblade", 15, 10, 17 );
	set( "bleeding", 5 );
	set( "value", ({ 43, "gold" }) );
}
