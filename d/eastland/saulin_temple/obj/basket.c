#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_name( "basket", "藤篮" );
	set_short( "藤篮" );
	set_c_open_long(@C_LONG
这是江南最有名的藤器店--王记 出品的藤篮，篮子本身编得相当精巧，
看来十分耐用, 而且应该能装不少东西, 是进香客常携带装供品的东西。
C_LONG
 	);
	set( "weight", 15 );
    set( "weight_apply", 60);
	set( "max_load", 300);
	set( "value", ({ 413, "silver" }) );
    set( "prevent_insert",1);
}
