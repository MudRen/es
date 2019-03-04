#include <../island.h>

inherit ARMOR;
void create()
{
	set_name( "Titan Chainmail","钛合金铠甲" );
	add( "id", ({ "chainmail","mail" }) );
	set_short( "钛合金铠甲" );
	set_long(@LONG
	圣骑士专用的铠甲，是用一种奇特的金属打造而
	成的。虽然是金属材质，但是却不像一般金属那
	麽笨重。
LONG
           );
	set( "unit","件" );
	set( "weight",100 );
	set( "type","body" );
	set( "material","heavy_metal" );
	set( "armor_class",40 );
	set( "defense_bonus",5 );
	set( "special_defence",([ "fire":10 ]) );
	set( "value",({ 2670,"silver" }) );
}
