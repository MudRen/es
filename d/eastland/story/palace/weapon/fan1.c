#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "fan", "����" );
	set_short( "����" );
	set_long(@LONG
һ���������ɵĻ��ȣ��������������ĺ�����
LONG
	);
	set( "unit","��");
	set( "type", "blunt" );
	set( "weapon_class", 20 );
	set( "min_damage", 15 );
	set( "max_damage", 22 );
	set( "weight", 50 );
}
