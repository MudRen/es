#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "looter's dagger", "ذ��" );
	add( "id", ({ "dagger" }) );
	set_short( "��Ĺ��ذ��" );
	set_long(
		"����һ�ѳ���������ذ�ף��ڱ���ĩ�˻�����๳�ӣ���Ĺ��ͨ��������\n"
		"ذ����ȡʯ�׻�����ϵı�ʯ��\n"
	);
	set( "unit", "��" );
	set( "type", "dagger" );
	set( "weight", 40 );
	set( "weapon_class", 14 );
	set( "min_damage", 6 );
	set( "max_damage", 11 );
	set( "second", 1 );
	set( "value", ({ 420, "silver" }) );
}
