#include <../hole.h>

inherit WEAPON;
void create()
{
	set_name( "Bulansido Sword","����ϣ�ལ" );
	add( "id",({ "sword" }) );
	set_short( "����ϣ�ལ" );
	set_long(@LONG
	��ѽ���������������Ⱥ���������ϵ�Ȩ����
	ֻҪ˭ӵ����������Գ�Ϊ�����˵����䡣��
	�Ǵ�˵�����������ؽ��ʥ������˵�����
	ʤ������ҫ��
LONG
	);
	set( "unit","��" );
	set( "type","longblade" );
	set( "weapon_class",35 );
	set( "min_damage",20 );
	set( "max_damage",40 );
	set( "weight",150 );
	set( "value",({ 5600,"silver" }) );
//	set( "no_sale",1 );
//	set( "nosecond",1 );
}