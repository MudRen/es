#include <../island.h>

inherit ARMOR;
void create()
{
	set_name( "Titan Helmet","�ѺϽ���" );
	add( "id", ({ "helmet" }) );
	set_short( "�ѺϽ���" );
	set_long(@LONG
	ʥ��ʿר�õ�ͷ��������һ�����صĽ��������
	�ɵġ���Ȼ�ǽ������ʣ�����ȴ����һ�������
	�᱿�ء�
LONG
           );
	set( "unit","��" );
	set( "weight",50 );
	set( "type","head" );
	set( "material","heavy_metal" );
	set( "armor_class",10 );
	set( "defense_bonus",1 );
	set( "special_defense",([ "fire":5 ]) );
	set( "value",({ 1370,"silver" }) );
}
