#include <mudlib.h>

inherit MONSTER;

void create()
{
	object obj1;

	::create();
	set_level(4);
	set_name( "Jeff", "杰夫" );
	set( "id", ({ "jeff", "sailor" }) );
   set_short( "老水手杰夫" );
	set_long(
		"老杰夫年轻的时候曾经是一名强壮勇敢的水手，但是现在他已经又老又\n"
		"病，再也没有办法出海了。\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 250 );

	set_perm_stat( "str", 6 );
	set( "wealth/silver", 20 );
	set( "max_hp", 150 );
	set( "hit_points", 150 );
	set( "wimpy", 80 );
	set( "tactic", "flank" );
	
	set_skill("dodge",30);
	set_skill("tactic",30);

	set_natural_armor( 23, 8 );
	set_natural_weapon( 5, 3, 8 );

	wield_weapon( "/d/noden/bluesand/item/stick" );
}

void die()
{
    tell_room( environment(),
		"杰夫口吐鲜血，倒在地上。\n"
		"杰夫口中喃喃地咒骂道: 你 ... 你们 .... 一定会付 ... 出代价的！\n"
		"杰夫从口袋中取出一个奇怪的烟火，用颤抖的手点燃烟火，射向空中。\n"
            "当你低头再去看杰夫，发现他已经一动也不动 .... 死了。\n",
		this_object() );
	"/adm/daemons/event/pirate"->start_war();
	::die(1);
}
