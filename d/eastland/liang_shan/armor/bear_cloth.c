#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("bear fur cloth","熊皮乌油甲");
    add("id",({"fur","cloth"}) );
    set_short( "熊皮乌油甲");
	set_long(
		"这是用熊皮制成的战甲，胸前有一块巨大的月牙斑纹，其它地方黑\n"
		"油油的不带一丝杂毛，你想这只熊生前一定很可怕．\n"
	);
	set( "unit", "件" );
	set( "weight", 180 );
	set( "type", "body" );
	set( "armor_class", 26 );
        set("material","leather");
	set( "defense_bonus", 4 );
	set( "value", ({ 175, "gold" }) );
}
