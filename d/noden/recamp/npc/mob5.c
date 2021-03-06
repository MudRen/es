
#include <mudlib.h> 
#include "../camp.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name( "brontosaurus statue", "雷龙雕像" );
	add("id",({"statue"}));
	set_short( "雷龙雕像" );
	set_long(
   "你看到一只巨大的雷龙雕像，样子有点像真的一样，虽然很旧了，却仍能感觉\n"
   "一双滴溜溜的眼珠子正盯著你瞧著。\n"
	);
	set( "alignment", -800 );
	set_perm_stat( "dex", 18 );
	set_perm_stat( "int", 5 );
	set_perm_stat( "kar", 10 );
	set_skill( "dodge", 70 );
        set("unbleeding",1) ;
        set("weight",350) ;
        set("exp_reward",900) ;
	set( "tactic_func", "my_tactic" );
        set( "max_hp", 300 );
        set("hit_points",300) ;
}

int my_tactic()
{
  object victim;

    if( random(50)<30 || !(victim= query_attacker()) ) return 0;
      tell_object(victim,"( 你发现被电的毫无力气! )\n" );
      tell_room(environment(victim),
          "你发现"+victim->query("c_name")+
          "被电的毫无力气!\n", victim);
      victim->block_attack(3) ; 
      victim->set_temp("msg_stop_attacker","( 你发现被电的毫无力气! )\n") ; 
      return 1;
}

int accept_item(object who,object item)
{
  int code ;

  if ( !item->query_inked() ) return 1 ;
  if ( (int)who->query_quest_level("lulu") >= 1 ) code = 1 ; else 
  if (!(who->query_temp("lulu_active"))) return 1 ;  

    write("\n突然一阵耀眼的光芒照亮的让你几乎看不清楚眼前的东西......\n") ;
    write("咦？你不禁怀疑自己是不是眼花了...怎麽雕像竟然动了？\n") ;

// 把布片收起来*grin*
   item->remove();
    tell_object( who,"雕像说道: 谢谢！为了报答你就让我送你上西天吧!!\n");
   kill_ob(who);
   if( who ) who->set_explore("noden#39");
    return 1;
}

