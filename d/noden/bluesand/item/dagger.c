#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "long dagger", "����ذ��" );
	add( "id", ({ "dagger" }) );
   set_short( "����ذ��" );
	set_long(
		"һ�ѳ���������ذ�ף�����Ϊ�˷���Ӷ����ӳ���\n"
	);
	set( "unit", "��" );
	set( "type", "dagger" );
	set( "weapon_class", 11 );
	set( "min_damage", 4 );
	set( "max_damage", 9 );
	set( "bleeding", 5 );
	set( "weight", 35 );
	set( "value", ({ 170, "silver" }) );
}
