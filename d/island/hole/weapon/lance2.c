#include <../hole.h>

inherit WEAPON;
void create()
{
	set_name( "Ebony Lance","��̴ľ����ǹ" );
	add( "id",({ "lance" }) );
	set_short( "��̴ľ����ǹ" );
	set_long(@LONG
	���������˽�����ר�õĳ�ǹ���ձ��Ĳ�������
	��̴ľ���ģ������������һ�ָ߼�Ʒ��
LONG
		);
	set( "unit","��" );
	set( "type","jousting" );
	set( "weapon_class",35 );
	set( "min_damage",20 );
	set( "max_damage",40 );
	set( "weight",140 );
	set( "value",({ 2330,"silver" }) );
}