#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name("spectral crow", "鬼魅乌鸦");
	add( "id", ({ "crow" }) );
	set_short( "鬼魅乌鸦");
	set_long(@LONG
你看到一只轮廓十分模糊的黑色乌鸦，一种不祥的预感告诉你这是种邪恶的化身。
LONG
	);
	set( "unit", "只" );
	set( "alignment", -300 );
	set_natural_armor( 10, 1 );
	set_natural_weapon( 7, 3, 8 );
	set_perm_stat( "int", 14 );
	set_perm_stat( "pie", 2 );
	set_perm_stat( "str", 5 );
	set( "aggressive", 1 );
	set( "tactic_func", "cry" );
	set_c_limbs( ({ "头部", "身体", "翅膀" }) );
	set_c_verbs( ({ "%s用嘴向%s用力一啄", "%s用爪子往%s抓去" }) );
}

int cry()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
	tell_room( environment(this_object()), 
		"鬼魅乌鸦发出一阵凄厉的叫声，吓得你手脚发软 ....\n",
		this_object() );
	WEAK->apply_effect( victim, 10 , 1 );
	return 1;
}
