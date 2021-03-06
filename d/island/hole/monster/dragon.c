#include <mudlib.h>
#include <races.h>

inherit RACE_DRAGON;
inherit MOUNT;

void create()
{
	::create();
	set_level(17);
	set_name( "Fire Dragon","火龙" );
	add( "id", ({ "dragon" }) );
	set_short( "火龙" );
	set_long(@LONG
这是一头喷火巨龙，听说只要能驯服它便可以将他变成坐骑。
LONG
		);
	set( "unit","头" );
	set( "race","dragon" );
	set_perm_stat( "str",30 );
	set_perm_stat( "dex",20 );
	set_perm_stat( "int",15 );
	set_natural_weapon( 45,40,60 );
	set_natural_armor( 80,40 );
	set( "alignment",300 );
	set( "extra_look","$N正骑著一头巨大的火龙，看起来犹如天神一般。\n" );
//	set( "mountable",1 );
	set( "max_load", 2600 );
}

void init()
{
	mount::init();
}
