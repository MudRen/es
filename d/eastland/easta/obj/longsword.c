#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "highsteel longsword", "����" );
	add( "id", ({ "longsword", "sword" }) );
	set_short( "��ֳ���" );
	set_long("����һ���ʵؼ�Ӳ��������ɵĳ�����\n");
	set( "unit", "��" );
	set( "weight", 90 );
	setup_weapon( "longblade", 22, 9, 20 );
	set( "bleeding", 5 );
	set( "value", ({ 520, "silver" }) );
}

