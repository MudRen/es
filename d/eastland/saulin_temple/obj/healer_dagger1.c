#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "thin dagger","������");
	add( "id", ({ "dagger" }) );
	set_short( "������" );
	set_long(
		"����һ�Ѽ�����խ��ذ��, �������, ȴ�ַ����Ľ���\n" 
	);
	set( "unit", "��" );
	set( "type", "dagger" );
	set( "weight", 40 );
	set( "weapon_class", 30 );
	set( "min_damage", 13 );
	set( "max_damage", 26 );
	set( "value", ({ 1500, "silver" }) );
}
