#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "moraz dagger", "Ī����ذ��" );
	add( "id", ({ "dagger" }) );
	set_short( "a moraz dagger", "Ī����ذ��" );
	set_long(
		"This is a sharp moraz dagger.\n",
		"����һ���������ص�ذ�ף������������ܵļ�����ƽ�⣬ʹ������\n"
		"�������Ҳ���������ذ�����׵����ϵ��˵ı��С�\n"
	);
	set( "unit", "��" );
	set( "type", "dagger" );
	set( "weight", 30 );
	set( "weapon_class", 34 );
	set( "min_damage", 13 );
	set( "max_damage", 20 );
	set( "value", ({ 1270, "silver" }) );
	set( "no_sale", 1 );
}
