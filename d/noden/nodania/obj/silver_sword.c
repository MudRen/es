#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "bastardsword", "����" );
	set_short( "��ɫ����" );
	set_long(@CLONG
����һ�Ѿ޴���������ɫ��������������������������ֻ�о�ͨ������
����ǿ������ܼ�Ԧ������������
CLONG
	);
	set( "unit", "��" );
	set( "weapon_class", 32 );
	set( "type", "longblade" );
	set( "min_damage", 17 );
	set( "max_damage", 38 );
	set( "nosecond", 1 );
	set( "weight", 180 );
	set( "value", ({ 1400, "silver" }) );
}
