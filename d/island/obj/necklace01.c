#include <../island.h>

inherit ARMOR;
void create()
{
	set_name( "Sapphire Necklace","蓝宝石项链" );
	add( "id", ({ "necklace" }) );
	set_short( "蓝宝石项链" );
	set_long(@LONG
	圣骑士专用的项链。还有一个蓝宝石坠子，更显出
	它的高贵。
LONG
           );
	set( "unit","串" );
	set( "weight",5 );
	set( "type","misc" );
	set( "material","element" );
	set( "defense_bonus",10 );
	set( "special_defense",([ "fire":10,"electric":10 ]) );
	set( "value",({ 2620,"silver" }) );
}
