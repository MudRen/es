#include <../hole.h>

inherit WEAPON;
void create()
{
	set_name( "Silvery Lance","��ɫ��ǹ" );
	add( "id",({ "lance" }) );
	set_short( "��ɫ��ǹ" );
	set_long(@LONG
	���ǰ�Ϊ��������ʿ���Ƶĳ�ǹ������ǹ��һ��
	���εģ���ȫû�нӷ죬���ĵ�λ��Ҳǡ���ô�
	���ǰѺ�˳�ֵı�����
LONG
		);
	set( "unit","��" );
	set( "type","jousting" );
	set( "weapon_class",35 );
	set( "min_damage",20 );
	set( "max_damage",38 );
	set( "weight",200 );
	set( "value",({ 1370,"silver" }) );
//	set( "no_sale",1 );
}