#include <../island.h>

inherit ARMOR;
void create()
{
	set_name( "Titan Tail","�ѺϽ�β��" );
	add( "id", ({ "tail" }) );
	set_short( "�ѺϽ�β��" );
	set_long(@LONG
	ʥ��ʿר�õ�β�ף�����һ�����صĽ��������
	�ɵġ���Ȼ�ǽ������ʣ�����ȴ����һ�������
	�᱿�ء�
LONG
           );
	set( "unit","��" );
	set( "weight",50 );
	set( "type","tail" );
	set( "material","heavy_metal" );
	set( "armor_class",10 );
	set( "defense_bonus",2 );
	set( "special_defense",([ "fire":10,"electric":10 ]) );
	set( "value",({ 3125,"silver" }) );
}