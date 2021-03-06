#include "../../story.h"
inherit MONSTER ;

void create ()
{
	::create();
	set_level(18);
	set_name( "Gerneral of palace", "巫既" );
	add ("id", ({ "general"}) );
	set_short( "武将 巫既");
	set_long(@CLONG
巫既长的身材魁伟，孔武有力，浓眉阔颐，一张国字脸剽悍之气浮现於上。巫既可
谓「巫咸国」里第一位勇士，兵书阵法无不娴熟，其人更忠心耿耿，战场多建功绩
，於是倍受城主看重。巫既内和外刚，平时极易和旁人亲近，颇得人缘。
CLONG
	);
	set("race","god");
	set("gender","male");
	set_perm_stat("str", 28 );
        set_perm_stat("dex", 25 );
        set_perm_stat("kar", 25 );
        set_perm_stat("int", 24 );
	set( "alignment", 500 );
	set( "hit_points", 700 );
	set( "max_hp", 700 );
        set( "max_fp",200);
	set_natural_armor( 50, 1 );
        set("aim_difficulty",([ 
    	  "critical":60,"vascular":60,"ganglion":60,"weakest":50 ]) );
        set("wealth/gold",50);
        set("stun_difficulty",100);
        set_skill("parry",85);
        set_skill("block",85);
        set_skill("jousting",100);
        set_skill("tactic",100);
        set("weight",100);
        set("tactic_func","my_tactic");
        set_natural_weapon(20,8,20);
        wield_weapon(SWWEA"jousting2");
        equip_armor(SWARM"wiz_shield2");
        equip_armor(SWARM"wiz_plate1");
        set("special_defense",(["all":40,"none":30]));
}
int my_tactic()
{
   object victim;
   if ( !victim=query_attacker() ) return 0;
   if ( random(10) > 1 ) return 0;
   tell_room(environment(this_object()),set_color(sprintf(
      "巫既愈发抖擞精神，手中长枪变成一只黄龙直捣%s！\n",
      victim->query("c_name")),"HIY"),victim);   
   tell_object(victim,set_color(
     "\n巫既愈发抖擞精神，手中长枪变成一只黄龙狠狠往你面门一刺！\n\n","HIY"));
   victim->receive_special_damage("divine",50+random(20));
   return 1;
}