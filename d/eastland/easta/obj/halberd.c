#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "highsteel halberd", "����" );
	add( "id", ({ "halberd" }) );
	set_short( "��ֳ���" );
	set_long("����һ���ʵؼ�Ӳ��������ɵĳ��ꡣ\n");
	set( "unit", "��" );
	set( "weight", 190 );
	setup_weapon( "polearm", 30, 17, 34 );
	set( "bleeding", 10 );
	set( "nosecond", 1 );
	set( "value", ({ 1420, "silver" }) );
}
