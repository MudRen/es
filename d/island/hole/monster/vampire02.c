#include <../hole.h>

inherit REPORT;
inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Vampire","吸血鬼" );
	add("id",({ "kill_vampire1","vampire" }) );
	set_short( "吸血鬼" );
	set_long(@LONG
    一个面无血色的吸血鬼。
LONG
		);
	set( "alignment",-5000 );
	set( "exp_reward",45000 );
	set( "max_hp",7500 );
	set( "hit_points",7500 );
	set( "time_to_heal",8 );
	set_perm_stat( "dex",25 );
	set_perm_stat( "str",15 );
	set_perm_stat( "int",15 );
	set_perm_stat( "kar",25 );
	set_natural_armor( 100,0 );
 	set_natural_weapon( 75,25,50 );
//	set( "unbleeding",1 );
	set_c_limbs( ({ "头部","身体","翅膀","爪子" }) );
	set_c_verbs( ({ "%s用它长满利牙的嘴咬向%s","%s用它的利爪抓向%s","%s用它的翅膀拍向%s" }) );
	set( "tactic_func","my_tactic" );
}

int my_tactic()
{
	object obj1,obj2,obj3,victim;
	string him;

	if( !(victim=query_attacker()) ) return 0;
	if( random(20)< 3 && !present( "kill_vampire2",environment(this_object()) ) )
	{
	him = victim->query( "c_name" );
	tell_room( environment(this_object()),"\n吸鬼血召唤出吸血蝙蝠攻击敌人。\n\n" );
	obj1=new( HMONSTER"vampire03" );
	obj2=new( HMONSTER"vampire03" );
//	obj3=new( HMONSTER"vampire03" );
	obj1->move( environment(this_object()) );
	obj2->move( environment(this_object()) );
//	obj3->move( environment(this_object()) );
	return 1;
	}
}

void die()
{
	object killer;
	
	killer=query( "last_attacker" );
	tell_room(environment(),@ALONG

吸血鬼有气无力的说：不～～这是不可能的～～你别得意的太早，
		    我会再回来的报仇的。
		    
    说完这句话，吸血鬼化做一只小蝙蝠，迅速消失地无影无踪。

ALONG
		);
        if( (int)killer->query_quest_level("q_vampire")<1){
        tell_object(killer,set_color("恭喜你完成了〔勇士的烦恼〕任务，你获得20000点经验值！\n","HIY",killer));
        killer->set_explore("island#10");
	killer->gain_experience( 20000 );
	killer->finish_quest("q_vampire",1);
	}
	::die();
}
