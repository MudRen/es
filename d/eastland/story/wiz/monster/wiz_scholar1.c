#include "../../story.h"
inherit MONSTER ;

void create ()
{
	::create();
	set_level(18);
	set_name( "Scholar of palace", "����" );
	add ("id", ({ "scholar"}) );
	set_short( "�Ĺ� ����");
	set_long(@CLONG
����һλ�������š���������ǫǫ���ӡ�������һ����ò��Ȼ�����ӣ���ü�´�
�ֵü����������޳�����Ȼë��ҵ�Ѱ߰ף���������ȴ�������񣬾���ü��ˡ���
�ľ�̸ֹ���൱�������������ᣬ������Ȥ���޲���������̸һ���������Щ����
������������һ�Ե��Ĺ�̸������
CLONG
	);
	set("race","��ʦ");
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
      set_color("�������ϵĽ�ʱ�������ɽ�⣡\n\n\n","HIY"));   
   victim->receive_special_damage("divine",30+random(30));
   return 1;
}