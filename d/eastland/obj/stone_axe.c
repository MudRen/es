#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "stone axe", "ʯ�師" );
	add( "id", ({ "axe" }) );
   set_short( "ʯ�師" );
	set_long(
		"����һ���ü�Ӳ�Ļ�������ɵ�ʯ�師������һ����ľ����������\n"
	);
	set( "unit", "��" );
	set( "weight", 100 );
	setup_weapon( "axe", 10, 5, 13 );
	set( "value", ({ 165, "silver" }) );
}
