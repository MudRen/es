#include <../island.h>

inherit ARMOR;
void create()
{
	set_name( "Titan Boots","�ѺϽ�սѥ" );
	add( "id", ({ "boots" }) );
	set_short( "�ѺϽ�սѥ" );
	set_long(@LONG
	ʥ��ʿר�õ�սѥ������һ�����صĽ��������
	�ɵġ���Ȼ�ǽ������ʣ�����ȴ����һ�������
	�᱿�ء�
LONG
           );
	set( "unit","˫" );
	set( "weight",30 );
	set( "type","feet" );
	set( "material","heavy_metal" );
	set( "armor_class",10 );
	set( "defense_bonus",2 );
	set( "special_defense",([ "fire":10 ]) );
	set( "value",({ 2780,"silver" }) );
}
