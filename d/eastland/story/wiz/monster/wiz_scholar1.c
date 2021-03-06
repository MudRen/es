#include "../../story.h"
inherit MONSTER ;

void create ()
{
	::create();
	set_level(18);
	set_name( "Scholar of palace", "巫礼" );
	add ("id", ({ "scholar"}) );
	set_short( "文官 巫礼");
	set_long(@CLONG
这是一位温文儒雅、彬彬有礼的谦谦君子。他生就一副道貌岸然的样子，两眉下垂
分得极开，脸颊修长，虽然毛发业已斑白，两个眸子却炯炯有神，精神好极了。他
的举止谈吐相当不凡，字字珠玑，横生妙趣，恨不得与他多谈一会儿多增长些见闻
。他现在正与一旁的文官谈论著。
CLONG
	);
	set("race","巫师");
	set("gender","male");
	set_perm_stat("str", 25 );
        set_perm_stat("dex", 20 );
        set_perm_stat("int", 28 );
	set( "alignment", 500 );
	set( "hit_points", 700 );
	set( "max_hp", 700 );
        set( "max_fp",200);
        set("weight",800);
	set_natural_armor( 38, 30 );
        set("aim_difficulty",([ 
    	  "critical":70,"vascular":40,"ganglion":40,"weakest":40 ]) );
        set("wealth/gold",40);
        set("stun_difficulty",50);
        set_skill("parry",85);
        set_skill("dodge",85);
        set_skill("anatomlogy",40);
        set_skill("thrusting",100);
        set_skill("two-weapon",100);
        set("aiming_loc","ganglion");
        set("tactic_func","my_tactic");
        set("tactic","melee");
        set_natural_weapon(20,6,15);
        set_natural_weapon2(29,6,15);
        wield_weapon(SWWEA"wiz_pen1");
        wield_weapon2(SWWEA"wiz_pen1");
        equip_armor(SWARM"wiz_belt1");
        equip_armor(SWARM"wiz_cloth1");
        set("special_defense",(["all":30,"none":30]));
}
int my_tactic()
{
   object victim;
   if ( !victim=query_attacker() ) return 0;
   if ( random(10) > 1 ) return 0;
   tell_room(environment(this_object()),
      set_color("巫礼手上的金笔迸射出万丈金光！\n\n\n","HIY"));   
   victim->receive_special_damage("divine",30+random(30));
   return 1;
}