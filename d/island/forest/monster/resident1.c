#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(7);
    set_name("Centaur Resident","半人马住民");
    add("id",({"centaur","resident","inhabitant"}) );
    set_short("半人马住民");
    set_long(@C_LONG
这是一个魔族的『农奴』，他们祖先被迫跟随魔族的一支来到这个荒岛上垦荒。近来
天皇希望他们能增加生产力，以增强国力，抵抗蜥蜴人及人类的侵略，已经改革了很
多政策，因此虽说是奴，生活倒也过得还不错。他现在下工了，所以在公社中休息。
C_LONG
       );
    set("gender","male");
    set("race","centaur");
    set("alignment",-500);
    set("max_hp",120);
    set("hit_points",120);
    set_perm_stat("str",10);
    set_perm_stat("dex",10);
    set("wealth/silver",100);
    set_natural_weapon(15,13,22);
    set_natural_armor(30,5);
}

