#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(2);
	set_name( "carter", "车夫" );
	set_short( "车夫" );
	set_long(
		"他们是一些脚夫兼车夫，专门帮镖局赶车运镳，现在他们正围成一堆\n"+
		 "闲聊磕牙，一面等著生意上门。\n"
	);
	set( "unit", "名" );
	set_perm_stat( "str", 6 );
	set_perm_stat( "dex", 6 );
	set_skill( "dodge", 20 );
	set( "gender", "male" );
	set( "alignment", 100 );
	set_natural_armor( 10, 4 );
	set_natural_weapon( 1, 2, 5 );
	set( "wealth/gold", 2 );
#include <replace_mob.h>
}
