#include "../dony.h"

inherit ARMOR;

void create()
{
        set_name("broken cloth","鸠衣");
        add("id",({"cloth"}) );
        set_short("鸠衣");
	set_long(@C_LONG
这是一件破跛烂烂的衣服, 在这件衣服上面的结不下几千个,又有一股汗臭传了过
来, 真是一件标准的乞丐装束。
C_LONG	         );
	set( "unit", "件" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 10 );
	set( "defense_bonus", 3 );
	set("special_defense",
	     (["fire":-10]) );
	set( "value", ({ 500, "silver" }) );
}
