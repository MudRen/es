#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "bone blade", "�ǵ�" );
	add( "id", ({ "blade" }) );
	set_short( "a bone blade", "�ǵ�" );
	set_long(
		"��ѹǵ�������ʮ��Ѱ��������һ�����ļ�׵�����ɵġ�\n"
	);
	set( "unit", "��" );
	set( "weight", 120 );
	setup_weapon( "longblade", 8, 6, 9);
//	set( "bleeding", 6 );
	set( "value", ({ 45, "gold" }) );
}
