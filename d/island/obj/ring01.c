#include <../island.h>

inherit ARMOR;
void create()
{
	set_name( "Sapphire Ring","����ʯ��ָ" );
	add( "id", ({ "ring" }) );
	set_short( "����ʯ��ָ" );
	set_long(@LONG
	ʥ��ʿר�õĽ�ָ�����滹����һ������ʯ�����Գ�
	���ĸ߹�
LONG
           );
	set( "unit","ֻ" );
	set( "weight",5 );
	set( "type","finger" );
	set( "material","element" );
	set( "defense_bonus",10 );
	set( "soecial_defense",([ "fire":10,"electric":10 ]) );
	set( "value",({ 2620,"silver" }) );
}
