#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(8);
    set_name("Centaur Hoodlum","半人马流氓");
    add("id",({"centaur","hoodlum"}) );
    set_short("半人马流氓");
    set_long(@C_LONG
这是一个魔族的『农奴』，他们祖先被迫跟随魔族的一支来到这个荒岛上垦荒。近来
天皇希望他们能增加生产力，以增强国力，抵抗蜥蜴人及人类的侵略，已经改革了很
多政策，因此虽说是奴，生活倒也过得还不错。不过这家伙好吃懒做，所以干起流氓
来了。
C_LONG
       );
    set("gender","male");
    set("race","centaur");
    set("alignment",-350);
    set("max_hp",120);
    set("hit_points",120);
    set_perm_stat("str",11);
    set_perm_stat("dex",11);
    set("killer",1);
    set("c_killer_msg","流氓发现你在瞄他，大喝：看啥？立刻向你冲了过来....\n");
    set("wealth/silver",150);
    set_natural_weapon(15,23,26);
    set_natural_armor(32,5);
}

