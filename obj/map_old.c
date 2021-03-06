
inherit "std/map";

void create()
{
	seteuid( getuid() );
	set_name( "map", "地图" );
	set_short( "a magical map", "魔法地图" );
	set_long(
		"This is a magical map of the realms of Noden Kingdom. You can either\n"
		"\"read map\" to see the map or \"read legend\" to see what the symbol\n"
		"on the map means.\n",
		"这是一张魔法地图，你可以 read map 看地图内容，或用\n"
		"read legend 看地图上符号所代表的意义。\n"
	);
	set_size( 7, 7 );
	set( "virtual_server", "/d/noden/virtual/noden_server" );
	set( "weight", 5 );
	set( "value", ({ 20, "silver" }) );
}
