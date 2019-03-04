#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(15);
    set_name("Magic Hawk","ħӥ");
    add("id",({"hawk","eagle"}) );
    set_short("ħӥ");
    set_long(@LONG
����һֻ���µ�ӥ���������Ķ����ĳ�򣬶���ŭĿ���ӡ�
LONG
            );
    set("unit","ֻ");
    set("alignment",-800);
    set("weight",600);
    set_perm_stat("str",17);
    set_perm_stat("dex",16);
    set("hit_points",300);
    set("max_hp",300);
    set("killer",1);
    set("pursuing",1);
    set("exp_reward",6000);
    set_natural_weapon(40,30,40);
    set_natural_armor(45,25);
    set("unbleed",1);
    set("c_killer_msg","ͻȻ�䣬ħӥ��չ˫����צ������˹�����");
    set_skill("dodge",80);
    set_c_verbs( ({"%s�ļ������%s","%s����צץ��%s","%s�ĳ��ɨ��%s"}) );
    set_c_limbs( ({"����","��צ","����","��ͷ","���"}) );
    set("alt_corpse",TWEP"dagger1");
    set( "death_msg","%s\n");
    set( "c_death_msg","%s˵:������Ը�����������ˣ�����û���һ��ذ��....\n");
 }
