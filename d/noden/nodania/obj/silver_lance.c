#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "silver lance", "��ǹ" );
	add( "id", ({ "lance" }) );
	set_short( "��ǹ" );
	set_long(@CLONG
����һ����������ɫ��ǹ���󲿷����ʹ�ô�������������ʿ�Ƕ�ϲ��
������������
CLONG
	);
	set( "unit", "��" );
	set( "type", "thrusting" );
	set( "weapon_class", 30 );
	set( "min_damage", 17 );
	set( "max_damage", 37 );
	set( "weight", 150 );
	set( "value", ({ 1500, "silver" }) );
}
