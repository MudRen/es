#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("ivory dagger", "����ذ��");
	add( "id", ({ "dagger" }) );
	set_short("����ذ��");
	set_long(
		"һ�Ѿ��ɵ�������ذ�ף�����������౦ʯ��\n"
	);
	set( "unit", "��" );
	set( "weight", 50 );
	set( "type", "dagger" );
	set( "weapon_class", 30 );
	set( "min_damage", 10 );
	set( "max_damage", 22 );
	set( "second", 1 );
	set( "value", ({ 165, "gold" }) );
}
