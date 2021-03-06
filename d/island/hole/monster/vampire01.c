#include <../hole.h>

inherit REPORT;
inherit MONSTER;

void create()
{
	::create();
	set_level(16);
	set_name( "Vampire","吸血蝙蝠" );
	add("id",({ "vampire","bat" }) );
	set_short( "吸血蝙蝠" );
	set_long(@LONG
    一只巨大的吸血蝙蝠正倒挂在岩壁上，一双泛红的眼睛紧盯著你
不放，似乎正盘算著要将你当作晚餐。你最好在它攻击你之前赶快离
开这里。
LONG
		);
	set( "alignment",-3000 );
	set( "exp_reward",100 );
	set( "max_hp",9000 );
	set( "hit_points",9000 );
	set( "time_to_heal",4 );
	set_perm_stat( "dex",30 );
	set_perm_stat( "str",25 );
	set_perm_stat( "int",15 );
	set_perm_stat( "kar",25 );
	set_skill( "dodge",100 );
	set_skill( "tactic",100 );
	set_natural_armor( 150,80 );
 	set_natural_weapon( 90,19,43 );
	set( "special_defense",([ "all":80,"none":80 ]) );
	set( "aim_difficulty",([ "ganglion":100,"critical":80 ]) );
	set( "stun_diffculty",100 );
	set( "tactic","assault" );
	set( "unbleeding",1 );
	set_c_limbs( ({ "头部","身体","翅膀","爪子" }) );
	set_c_verbs( ({ "%s用它长满利牙的嘴咬向%s","%s用它的利爪抓向%s","%s用它的翅膀拍向%s" }) );
	set( "tactic_func","my_tactic" );
}

int my_tactic()
{
	object victim;
	string him;

	if( random(20)>3 || !(victim=query_attacker()) ) return 0;
	else
	{
	him = victim->query( "c_name" );
	tell_object(victim,"\n吸血蝙蝠飞到你的脖子上狠狠的吸了一大口鲜血\n\n");
	tell_room(environment(this_object()),
	"吸血蝙蝠突然飞到"+him+"的脖子上狠狠地吸了一大口鲜血\n\n",victim);
	victim->receive_damage( 20 + random(30) );
	report( victim );
	return 1;
	}
}

void change( object what, object player )
{
	object ob;
	ob = new( HMONSTER"vampire02" );
	ob->move( environment( what ) );
	tell_object( player,@ALONG
     
吸血蝙蝠发出一阵尖锐叫声後，突然变成一个面无血色的吸血鬼!
吸血鬼满怀恨意地说道：该死，你竟敢坏了我多年的修行，去死吧!

ALONG
		);       
	ob->kill_ob( player );
	what->remove();
}
