#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Phenix Robe","��˳���" );
	add( "id",({ "robe" }) );
	set_short( "��˳���" );
	set_long(@LONG
	�ɲ������޷�˵ĳ������֯�ĳ��ۡ�
LONG
           );
	set( "unit","��" );
	set( "weight",50 );
	set( "type","body" );
	set( "material","leather" );
	set( "armor_class",28 );
	set( "defense_bonus",8 );
	set( "special_defense",([ "fire":30,"evil":20 ]) );
	set( "value",({ 5720,"silver" }) );
}