#include <../island.h>

inherit ARMOR;
void create()
{
	set_name( "Titan Shield","�ѺϽ��" );
	add( "id", ({ "shield" }) );
	set_short( "�ѺϽ��" );
	set_long(@LONG
	ʥ��ʿר�õĶ��ƣ�����һ�����صĽ��������
	�ɵġ���Ȼ�ǽ������ʣ�����ȴ����һ�������
	�᱿�ء�
LONG
           );
	set( "unit","��" );
	set( "weight",60 );
	set( "type","shield" );
	set( "material","heavy_metal" );
	set( "armor_class",10 );
	set( "defense_bonus",5 );
	set( "special_defense",([ "fire":10 ]) );
	set( "value",({ 3125,"silver" }) );
}
