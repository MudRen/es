#include <takeda.h>

inherit WEAPON;

void create()
{
	set_name("iron hammer", "���ϡ�");
	add("id",({"hammer"}));
	set_short("���ϡ�");
	set_long(
		"��������ص����ɹϵ���״��ʹ��ʱ������ܽ�С��\n"
	);
	set( "unit", "��" );
	set( "weight", 130 );
	set( "type", "blunt" );
	set( "weapon_class", 18 );
	set( "min_damage", 10 );
	set( "max_damage", 20 );
	set( "value", ({ 530, "silver" }) );
}
