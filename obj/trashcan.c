// A trashcan
// By Annihilator@Eastern.Stories

#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_name( "trashcan", "垃圾桶" );
	set_short( "垃圾桶" );
	set_c_open_long( "一个造型新潮的垃圾桶，上面写著「资源回收，大家一起来」。\n"
		"你可以用 toss 指令将不用的物品丢进垃圾桶。\n" );
	set( "prevent_get", 1 );
	set( "max_load", 200000 );
}

void init()
{
	add_action( "do_toss", "toss" );
}

int do_toss(string arg)
{
	object dest;

	if( !arg || !(dest = present(arg, this_player())) )
		return notify_fail("你要把什麽东西丢进垃圾桶？\n");
	if( dest->query("prevent_drop") || dest->query("secure") )
		return notify_fail("你不能丢掉这样东西。\n");
	write("你将" + dest->query("short") + "丢进垃圾桶。\n");
	tell_room( environment(), 
		this_player()->query("c_name") + "把" + dest->query("short") + "丢进垃圾桶。\n",
		this_player() );
	call_out( "reward", 5 );
	dest->remove();
	return 1;
}

void reward()
{
	object coin;
	tell_room( environment(), 
		"你听到垃圾桶里传来一阵可怕的笑声。\n" );
	coin = new("/std/coins");
	coin->set_type( "silver" );
	coin->set_number(1);
	coin->move( environment() );
}
