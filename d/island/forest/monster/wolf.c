#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(15);
    set_name("Magic Wolf","魔狼");
    add("id",({"wolf"}) );
    set_short("Magic Wolf","魔狼");
    set_long(@LONG
这是一只可怕的狼，正狰狞的露出它的獠牙，凶狠的对你咆啸著。
LONG
            );
    set("unit","只");
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
    set("c_killer_msg","突然间，魔狼咆啸一声向你扑了过来！");
    set_skill("dodge",80);
    set_c_verbs( ({"%s的獠牙咬向%s","%s的前爪抓向%s","%s的尾巴卷向%s"}) );
    set_c_limbs( ({"背心","前爪","後腿","颈部","额头"}) );
    set("death_msg","%s\n");
    set("c_death_msg","%s说:今後我愿誓死效忠您，主人!随即幻化成一把长刃....!\n");
    set("alt_corpse",TWEP"sword1");
}
