#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Angel Wing","��ʹ���" );
	add( "id", ({ "wing" }) );
	set_short( "��ʹ���" );
	set_long(@LONG
	�ɷ�����ʥ��������ʹ�����ʹ��͸�����
	����������
LONG
		);
	set( "unit","��" );
	set( "weight",5 );
	set( "type","misc" );
	set( "material","element" );
	set( "defense_bonus",6 );
	set( "special_defense",([ "evil":20,"fire":20 ]) );
	set( "value",({ 1900,"silver" }) );
}
