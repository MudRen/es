#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "thin blade", "��Ҷ��" );
	add( "id", ({ "blade" }) );
   set_short( "��Ҷ��" );
	set_long(
		"����һ�ֽ�����������Ҷ�Ķ̽���ʹ�����������\n"
	);
	set( "unit", "��" );
	set( "weight", 60 );
	setup_weapon( "shortblade", 17, 6, 14 );
	set( "bleeding", 5 );
	set( "value", ({ 44, "gold" }) );
}
