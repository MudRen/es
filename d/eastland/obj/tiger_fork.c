#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "tiger fork", "����" );
	add( "id", ({ "fork" }) );
   set_short( "����" );
	set_long(
		"����һ���ֳ����صĻ��棬�����ּ��ڹ��������λε�ɱ�����ڡ�\n"
	);
	set( "unit", "��" );
	set( "weight", 190 );
	setup_weapon( "thrusting", 23, 9, 27 );
	set( "nosecond", 1 );
        set( "bleeding", 10 );
	set( "value", ({ 89, "gold" }) );
}
