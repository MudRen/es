
#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name("jojo zombie", "啾啾僵□");
	add( "id", ({ "zombie","jojo" }) );
   set_short( "啾啾僵□" );
	set_long(
"啾啾僵□是被超渡失败的坏人,因怨恨无法消灭而变成的疆□...\n"
"它的身体都腐烂了,你可以见到许\多蛆虫从它的身上掉落下来,它全身都是□毒\n"
"它要找一个替身,才能脱离可怕的地狱... 它正轻轻的对著你喷气呢!!!\n"
	);
	set( "unit", "只" );
	set( "alignment", -1600 );
	set_natural_armor( 10, 4 );
	set_natural_weapon( 4, 3, 7 );
	set_perm_stat( "int", 2 );
	set_perm_stat( "pie", 1 );
	set_perm_stat( "str", 5 );
	set_skill("dodge",20);
   set( "killer", 1 );
	set( "pursuing", 1 );
	set( "tactic_func", "emit_poison" );
	set_c_limbs( ({ "半个脑袋", "腐烂的身体", "满是蛆的腿", "快断掉的眼睛" }) );
	set_c_verbs( ({ "%s伸出污黑的爪子，抓向%s","%s伸长利齿咬向%s", }) );
        set("alt_corpse","/d/monk/monster/corpse1.c"); 
        set("c_death_msg","僵□被你杀死後化成一滩血水... \n"); 


}

int emit_poison()
{
	object victim;

	if( random(21)>3 || !(victim= query_attacker()) ) return 0;
   tell_room( environment(this_object()), 
"僵□挥动著它的双手，一团腐烂的肉喷到你的身上 ....\n",
		this_object() );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 4, 4 );
	return 1;
}
