#include "../ekravia.h"
inherit WEAPON;

void	create()
{
	set_name("staff", "����");
	add( "id", ({ "staff" }) );
	set_short("����");
	set_long(
		"һ����ͨ�ġ���\n"
	);
	set( "unit", "��" );
	set( "weight", 30 );
	set( "type", "blunt" );
	set( "weapon_class", 10 );
	set( "min_damage", 5 );
	set( "max_damage", 10 );
	set( "value", ({ 50, "silver" }) );
}
