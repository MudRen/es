#include <mudlib.h>
#include <conditions.h>

inherit MEDICINE;

void create()
{
	medicine::create();
	set_name("strong pill", "养生主" );
	add( "id", ({"pill"}) );
	set_short("养生主");
	set_long(
		"这是由刑老爹研发出来的补药,对身体虚弱的人有很好的疗效。\n"
		"如果你觉得力不从心,吃(eat)下它保证让你四十岁还像一尾活龙!\n"
	);
	set( "can_eat", 1 );
	set( "unit", "粒" );
	set( "weight", 15 );
	set( "value", ({ 50, "silver" }) );
        set( "medication", 50 );
}

void eat(object player)
{
    int stat;
    
	if( !player->query("conditions/weak") ) return;
	tell_object( player, can_read_chinese(player)?
		"你觉得全身又充满精力！\n": "You recover from poison!\n" );
	stat = (int) player->query("weak");
	player->modify_stat("str",stat);	
	"/std/conditions/weak"->remove_effect(player);
}
