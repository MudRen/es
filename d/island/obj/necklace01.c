#include <../island.h>

inherit ARMOR;
void create()
{
	set_name( "Sapphire Necklace","����ʯ����" );
	add( "id", ({ "necklace" }) );
	set_short( "����ʯ����" );
	set_long(@LONG
	ʥ��ʿר�õ�����������һ������ʯ׹�ӣ����Գ�
	���ĸ߹�
LONG
           );
	set( "unit","��" );
	set( "weight",5 );
	set( "type","misc" );
	set( "material","element" );
	set( "defense_bonus",10 );
	set( "special_defense",([ "fire":10,"electric":10 ]) );
	set( "value",({ 2620,"silver" }) );
}
