#include <takeda.h>

inherit WEAPON;

void create()
{
	set_name("smooth dagger", "��ˮ��ü��");
	add("id",({"dagger"}));
	set_short("smooth dagger", "��ˮ��ü��");
	set_long(
		"This is a sharp thin dagger\n",
		"����һ�ѷ�����ذ�ף�ϸ���ĵ����ƺ������ж�ˮ����\n"
	);
	set( "unit", "��" );
	set( "weight", 90 );
	set( "type", "dagger" );
	set( "second",1);
	set( "weapon_class", 18 );
	set( "min_damage", 9 );
	set( "max_damage", 18 );
	set( "value", ({ 610, "silver" }) );
}
