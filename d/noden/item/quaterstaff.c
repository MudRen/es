#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "oak quaterstaff", "��ľ��" );
	add( "id", ({ "quaterstaff", "staff" }) );
   set_short( "��ľ��" );
	set_long(
		"һ���ü�Ӳ����ľ���ɵ�ľ�ȣ����ļ�˰���һ��������\n"
	);
	set( "unit", "��" );
	setup_weapon( "blunt", 15, 3, 10 );
	set( "weight", 65 );
	set( "value", ({ 120, "silver" }) );
}
