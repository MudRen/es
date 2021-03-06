#include <mudlib.h>

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(7);
	set_name( "ammunt", "亚曼特兽" );
	add ("id", ({ "ammunt", "beast" }) );
	set_short( "凶猛的亚曼特兽" );
	set("aggressive", 1);
	set("killer", 1);
	set("pursuing", 1);
	set_long(@CLONG
    这是一只有介於鳄鱼、河马、狮子之间的奇怪野兽。对於比人还小的
动物, 它可以连下巴都不必动就能一口吞下。
CLONG
	);
	
	set( "alignment", -500 );
	set( "unit", "只" );
	set_perm_stat( "dex", 9 );
	set_perm_stat( "str", 12 );
	set_perm_stat( "int", 3 );
	set_perm_stat( "piety", 3 );
	set("special_defense", ([ "all":20 ]) );
	set("aim_difficulty", ([ "critical":10, "vascular":30, ]) );
	set_natural_weapon( 9, 6, 10);
	set_natural_armor( 35, 7);
	
	set_c_limbs( ({ "的身体", "的头", "的脚", "的尾巴"}) );
	set_c_verbs( ({ "%s狠狠地向%s一口咬下", "%s向%s飞身一扑",
		 "%s用尾巴重重地横扫%s",}) ); 
}
