#include "../../story.h"
#include <conditions.h>
inherit MONSTER ;

void create ()
{
	::create();
	set_level(19);
	set_name( "King of the west Shu-Ha", "少昊" );
	add ("id", ({"king","shu-ha","Shu-Ha"}) );
	set_short( "西方天帝 少昊");
	set_long(@CLONG
少昊生得浓眉大眼，胸宽腰挺，耳垂如珠，一张国字脸，非常有威仪。少昊是西方
诸神的统治者，管理著西方一万二千里的地方，具有无上的权威。少昊曾在东方海
外建立一个国家，不知道经过了多少年，终於回到了这里。
CLONG
	);
	set("race","god");
	set("gender","male");
	set_perm_stat("str", 28 );
        set_perm_stat("dex", 20 );
        set_perm_stat("kar", 27 );
        set_perm_stat("int", 28 );
	set( "alignment", 2000 );
	set( "hit_points", 900 );
	set( "max_hp", 900 );
        set( "max_fp",500);
	set_natural_weapon( 5, 13, 13 );
	set_natural_armor( 23, 26 );
        set("aim_difficulty",([ 
    	  "critical":50,"vascular":50,"weakest":50 ]) );
        set("wealth/gold",300);
        set("stun_difficulty",100);
        set_skill("dodge",80);
        set_temp("bs",10);
        set_skill("parry",80);
        set_skill("thrusting",100);
        set("tactic_func","my_tactic");
        wield_weapon(SPWEA"westgod_fork");
        equip_armor(SPARM"westgod_necklace");
        equip_armor(SPARM"westgod_helmet");
        equip_armor(SPARM"westgod_cloth");
        set("special_defense",(["all":100,"none":40,"cold":30]));
        set("chat_chance",1);
        set("att_chat_output",({
           "少昊说道：哼，别傻了，任何防御在我面前都是无效的！\n"
        }) );
}
int my_tactic()
{
    object victim;
    if ( !victim=query_attacker() ) return 0;
    if ( random(10) > 1 ) return 0;
    tell_room(environment(),sprintf("少昊对著%s狠狠的一击！\n%s撤退了！\n",
      victim->query("c_name"),victim->query("c_name")),victim);
    tell_object(victim,"\n少昊对著你全身的弱点给予狠狠的一击！\n\n\n唉呀，你逃跑了！！\n\n");             
    if ( victim->query("hit_points") > 100 )
       victim->set("hit_points",100);
    else victim->receive_damage(30);
    (CONDITION_PREFIX + "bleeding")->apply_effect(victim,10,1);
    victim->move_player(SPALACE"x3","SNEAK");
    return 1;
}
