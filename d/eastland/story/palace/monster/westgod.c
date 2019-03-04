#include "../../story.h"
#include <conditions.h>
inherit MONSTER ;

void create ()
{
	::create();
	set_level(19);
	set_name( "King of the west Shu-Ha", "���" );
	add ("id", ({"king","shu-ha","Shu-Ha"}) );
	set_short( "������� ���");
	set_long(@CLONG
�������Ũü���ۣ��ؿ���ͦ���������飬һ�Ź��������ǳ������ǡ����������
�����ͳ���ߣ�����������һ���ǧ��ĵط����������ϵ�Ȩ����������ڶ�����
�⽨��һ�����ң���֪�������˶����꣬��춻ص������
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
           "���˵�����ߣ���ɵ�ˣ��κη���������ǰ������Ч�ģ�\n"
        }) );
}
int my_tactic()
{
    object victim;
    if ( !victim=query_attacker() ) return 0;
    if ( random(10) > 1 ) return 0;
    tell_room(environment(),sprintf("��껶���%s�ݺݵ�һ����\n%s�����ˣ�\n",
      victim->query("c_name"),victim->query("c_name")),victim);
    tell_object(victim,"\n��껶�����ȫ����������ݺݵ�һ����\n\n\n��ѽ���������ˣ���\n\n");             
    if ( victim->query("hit_points") > 100 )
       victim->set("hit_points",100);
    else victim->receive_damage(30);
    (CONDITION_PREFIX + "bleeding")->apply_effect(victim,10,1);
    victim->move_player(SPALACE"x3","SNEAK");
    return 1;
}
