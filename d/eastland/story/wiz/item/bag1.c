#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_c_open_long("无底袋是「巫咸国」的特产之一，可以装无数的东西。\n");
	set_name("bag", "无底袋");
	set_short("无底袋");
	set( "weight", 20);
 	set( "weight_apply", 50 );
        set( "max_load", 230 );
	set( "value", ({ 150, "silver" }));
	set( "prevent_insert",1 );
	set( "prevent_put_money", 1);
}
