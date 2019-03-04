#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "Moraz blade", "Ĭ���ȳ���" );
	add( "id", ({ "blade", "sword" }) );
	set_short( "Moraz Blade", "Ĭ���ȳ���" );
	set_long(
		"You see a long sword with a long crane. The sword is well balanced\n"
		"for those mastering usage of swords and lance.\n",
		"����һ�����ͺ���ǹ�ĳ��������ĵ����ܳ������Ҹ����������ƽ�⣬ʹ��\n"
		"���ʹ�ó�����ǹ������������ʮ�ֿ��ٵػӶ���ѵ���\n"
	);
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "weight", 110 );
	set( "nosecond", 1 );
	set( "bleeding", 10 );
	set( "weapon_class", 33 );
	set( "min_damage", 13 );
	set( "max_damage", 30 );
	set( "value", ({ 1340, "silver" }) );
	set( "no_sale", 1 );
}
