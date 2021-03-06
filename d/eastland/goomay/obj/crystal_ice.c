#include <../goomay.h>

inherit OBJECT;

void create()
{
	set_name( "crystal of ice", "万年冰晶" );
	add( "id", ({ "crystal","ice" }) );
	set_short( "万年冰晶" );
	set_long(
		"这是一颗罕见的万年冰晶，是火焰精灵的克星，要使用它\n"
		"，用 ice <someone>。\n"
	);
	set( "unit", "颗" );
	set( "weight", 5 );
	set( "value", ({ 100, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
	add_action( "do_ice", "ice" );
}

int do_ice(string arg)
{
	object obj;

	if( !arg || arg=="" || !(obj= present(arg, environment(this_player()))) )
		return notify_fail( "要对谁使用冰晶？\n" );
	if( base_name(obj) != Mob"fire_beast" ) {
		write(
			"你拿出冰晶打在" + obj->query("short") + "的身上，不过对方似乎不受影响。\n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name")+ "拿出一颗小石头打在"+obj->query("short")+"身上。\n",
			this_player() );
		return 1;
	} else {
		write( 
			"你拿出冰晶打在" + obj->query("short") + "身上 .... \n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name")+ "拿出一颗冰晶打在"+obj->query("short")+"身上。\n",
			this_player() );
		obj->iced();
		write( 
			"你的冰晶飞了出去，紧紧贴在" + obj->query("short") + "身上！\n");
		remove();
		return 1;
	}
}
