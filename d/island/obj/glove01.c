#include <../island.h>

inherit ARMOR;
void create()
{
	set_name( "Titan Gauntlets","�ѺϽ���" );
	add( "id", ({ "gauntlets","gloves" }) );
	set_short( "�ѺϽ���" );
	set_long(@LONG
	ʥ��ʿר�õĻ��֣�����һ�����صĽ��������
	�ɵġ���Ȼ�ǽ������ʣ�����ȴ����һ�������
	�᱿�ء�
LONG
           );
	set( "unit","˫" );
	set( "weight",20 );
	set( "type","hands" );
	set( "material","heavy_metal" );
	set( "armor_class",5 );
	set( "defense_bonus",5 );
	set( "special_defense",([ "fire":10 ]) );
	set( "value",({ 2890,"silver" }) );
}
