#include <../island.h>

inherit ARMOR;
void create()
{
	set_name( "Titan Armbands","�ѺϽ�ۻ�" );
	add( "id", ({ "arm","armbands" }) );
	set_short( "�ѺϽ�ۻ�" );
	set_long(@LONG
	ʥ��ʿר�õıۻ�������һ�����صĽ��������
	�ɵġ���Ȼ�ǽ������ʣ�����ȴ����һ�������
	�᱿�ء�
LONG
           );
	set( "unit","��" );
	set( "weight",45 );
	set( "type","arms" );
	set( "material","heavy_metal" );
	set( "armor_class",6 );
	set( "defense_bonus",3 );
	set( "special_defense",([ "fire":10 ]) );
	set( "value",({ 1175,"silver" }) );
}
