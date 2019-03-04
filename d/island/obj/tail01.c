#include <../island.h>

inherit ARMOR;
void create()
{
	set_name( "Titan Tail","钛合金尾甲" );
	add( "id", ({ "tail" }) );
	set_short( "钛合金尾甲" );
	set_long(@LONG
	圣骑士专用的尾甲，是用一种奇特的金属打造而
	成的。虽然是金属材质，但是却不像一般金属那
	麽笨重。
LONG
           );
	set( "unit","套" );
	set( "weight",50 );
	set( "type","tail" );
	set( "material","heavy_metal" );
	set( "armor_class",10 );
	set( "defense_bonus",2 );
	set( "special_defense",([ "fire":10,"electric":10 ]) );
	set( "value",({ 3125,"silver" }) );
}