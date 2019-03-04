#include "../story.h"
inherit MONSTER;

void create()
{
    ::create();
    set_level(18);
    set_name( "swordman Eight-snow", "���Ŵ�ѩ" );
    add ("id", ({ "swordman" }) );
    set_short( "���� ���Ŵ�ѩ");
    set_long(@LONG
���Ŵ�ѩ������ԼĪ�ġ���ʮ����ͣ�����һ�԰��ֺ�������������硣��������
�����Ŀ�����ǣ�һ����ò��Ȼ�����ӣ������䣬ƮƮȻ��������ò������ʱ��
˫ü������͸¶������״�������ƺ�ֻӦ������֮�����Ŵ�ѩ�����ڽ�ʯ�ϣ�����
�������أ�˫üƵ�����ƺ���������ʲ�ᡣ
LONG
            );
    set("unit","λ");
    set("race","human");      
    set("age",49);
    set("gender","male" );
    set("alignment",500);
    set("weight",1000);
    set("wealth/gold",80);
    set_perm_stat("str",28);
    set_perm_stat("dex",23);
    set_perm_stat("int",25);
    set("hit_points",800);
    set("max_hp",800);
    set("max_fp",300);
    set_temp("be_joke",2);
    set_natural_armor(80,24);
    set_natural_weapon(15,15,5);
    set_skill("longblade",90);
    set_skill("dodge",90);
    set_skill("parry",90);
    set("special_defense", ([ "all": 40,"none":30]) );
    set("aim_difficulty",
    (["critical":50,"vascular":30,"ganglion":30,"weakest":30,"scholar":20]) );
    set("stun_difficulty",50);
    wield_weapon(SWEA"sword1");
    equip_armor(SARM"ring1");
    equip_armor(SARM"amulet1");
    set( "tactic_func", "my_tactic" );
}        
int my_tactic()
{
     object victim,env;
     int select;     
     
     if (!(victim= query_attacker())) return 0;
     env=environment(this_object());
     switch (random(60)) {
     case 0..8 :
        victim->receive_damage(40+random(30));
        tell_room(env,
           "\n���Ŵ�ѩ������캣ˮ��ˮ�����ƺݺ�����������һ����\n\n\n");
        return 1;
     case 9 :
        this_object()->receive_healing(60);
        tell_room(env,
           "���Ŵ�ѩ���еġ�����������һ�����⣬˲�䣬�����˿������ˣ�\n");
        return 1; 
     }
     return 0;          
}                  