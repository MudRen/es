#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Shield","ս���" );
	add( "id", ({ "shield" }) );
	set_short( "ս���" );
	set_long(@LONG
	����ս������װ����֮ս��ܡ�
LONG
           );
	set( "unit","��" );
	set( "weight",100 );
	set( "type","shield" );
	set( "material","heavy_metal" );
	set( "armor_class",8 );
	set( "defense_bonus",8 );
	set( "special_defense",([ "fire":10,"cold":10 ]) );
	set( "value",({ 2710,"silver" }) );
//	set( "no_sale",1 );
}
