#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "shopkeeper", "商店主人" );
	add( "id", ({ "keeper", "shop keeper" }) );
   set_short( "商店主人" );
	set_long(
		"这位老板是个年纪大约五、六十岁的诺顿人，由於他年轻的时候\n"
		"曾经到过许多地方游历，因此会说各种语言。\n"
	);
	set( "no_attack", 1 );
#include <replace_mob.h>
}
