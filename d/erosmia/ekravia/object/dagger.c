#include "../ekravia.h"
inherit WEAPON;

void	create()
{
	set_name("dagger", "ذ��");
	add( "id", ({ "dagger" }) );
	set_short("ذ��");
	set_long(
		"һ����ͨ��ذ�ס�\n"
	);
	set( "unit", "��" );
	set( "weight", 30 );
	set( "type", "dagger" );
	set( "weapon_class", 20 );
	set( "min_damage", 8 );
	set( "max_damage", 16 );
	set( "second", 1 );
	set( "value", ({ 300, "silver" }) );
}
