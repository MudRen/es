#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(15);
    set_name("Magic Wolf","ħ��");
    add("id",({"wolf"}) );
    set_short("Magic Wolf","ħ��");
    set_long(@LONG
����һֻ���µ��ǣ���������¶������������׺ݵĶ�����Х����
LONG
            );
    set("unit","ֻ");
    set("alignment",-800);
    set("weight",600);
    set_perm_stat("str",18);
    set_perm_stat("dex",18);
    set("hit_points",400);
    set("max_hp",400);
    set("killer",1);
    set("pursuing",1);
    set("exp_reward",7000);
    set_natural_weapon(30,20,30);
    set_natural_armor(50,30);
    set("unbleed",1);
    set("c_killer_msg","ͻȻ�䣬ħ����Хһ���������˹�����");
    set_skill("dodge",80);
    set_c_verbs( ({"%s�����ҧ��%s","%s��ǰצץ��%s","%s��β�;���%s"}) );
    set_c_limbs( ({"����","ǰצ","����","����","��ͷ"}) );
    set("death_msg","%s\n");
    set("c_death_msg","%s˵:������Ը����Ч����������!�漴�û���һ�ѳ���....!\n");
    set("alt_corpse",TWEP"sword1");
}
