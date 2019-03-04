#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("holy ring","爱染明王戒指");
    add("id",({"ring"}) );
    set_short( "爱染明王戒指");
	set_long(@C_LONG
这是五大明王之一 — 爱染明王使用过的戒指,如果你是善良
正义之士, 它将以明王之名加护你的。
C_LONG
       	        );
	set( "unit", "个" );
	set( "weight", 12 );
	set( "type", "finger" );
	set( "material","stone");
	set( "armor_class", 0 );
	set( "defense_bonus", 7 );
	set( "value", ({ 300, "gold" }) );
}
