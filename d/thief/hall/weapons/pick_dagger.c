#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("lucky dagger", "����ذ��");
	add( "id", ({ "dagger" }) );
	set_short("����ذ��");
	set_long(
		"����һ�ѵ�������Ů��ľ���ذ�ף���������Ϸ��Ŀɰ����Ϲ⡣\n"
	);
	set( "unit", "��" );
	set( "type", "dagger" );
	set( "weapon_class", 30 );
	set( "min_damage", 15 );
	set( "max_damage", 25 );
	set( "weight", 40 );
	set( "value", ({ 430, "silver" }) );
}
