#include <../island.h>

inherit ARMOR;
void create()
{
	set_name( "Titan Chainmail","�ѺϽ�����" );
	add( "id", ({ "chainmail","mail" }) );
	set_short( "�ѺϽ�����" );
	set_long(@LONG
	ʥ��ʿר�õ����ף�����һ�����صĽ��������
	�ɵġ���Ȼ�ǽ������ʣ�����ȴ����һ�������
	�᱿�ء�
LONG
           );
	set( "unit","��" );
	set( "weight",100 );
	set( "type","body" );
	set( "material","heavy_metal" );
	set( "armor_class",40 );
	set( "defense_bonus",5 );
	set( "special_defence",([ "fire":10 ]) );
	set( "value",({ 2670,"silver" }) );
}
