#include <mudlib.h>
#include <stats.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "old toaist", "老道士" );
	add( "id", ({ "toaist" }) );
	set_short( "老道士" );
	set_long(
		"这位道士是这间道观的主持，听说法力高强已经降伏无数的妖怪。\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set_natural_weapon( 20, 11, 15 );
	set_natural_armor( 40, 10 );
	set_perm_stat( "dex", 15 );
	set_perm_stat( "kar", 15 );
	set_skill( "dodge", 20 );
	set( "wealth/gold", 20 );
	set( "inquiry", ([
		"paper" : 
	"想要符啊!只要添点(put coins)香油就可以得到一张收妖符。"
	]) );
#include <replace_mob.h>
}

