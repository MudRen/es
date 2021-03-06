// Saint Paladin Jitter
//
//		Lilia@Eastern.Stories

#include "../lilia.h"

inherit MONSTER;

object sword;

void create()
{
    ::create();
    set_level(19);
    set_name("Saint Paladin Jitter", "圣骑士杰特");
    add("id", ({"paladin", "jitter"}));
    set_short("圣骑士杰特");
    set_long(@C_LONG
美丽的金发，同样美丽的碧色眼瞳，站在你眼前的这个英俊的年轻人似乎
有股慑人的魔力。不知道他正在想什麽事情，不过由他身上那把赫赫有名的铠
魔枪看来，这个年轻人绝对是招惹不得的。
C_LONG
	    );
    set_perm_stat("str", 30);
    set_perm_stat("con", 25);
    set_perm_stat("int", 20);
    set_perm_stat("dex", 25);
    set_perm_stat("kar", 25);
    set_perm_stat("pie", 30);
    set_skill("jousting", 100);
    set_skill("parry", 100);
    set_skill("dodge", 100);
    set_skill("block", 100);
    set("alignment", 1500);
    set("race", "human");
    set("class", "knight");
    set("gender", "male");
    set("hit_points", 2000);
    set("max_hp", 2000);
    set("aim_difficulty", (["critical" : 80, "vascular" : 80, "weakest" : 80, "ganglion" : 80]));
    set_natural_weapon(45, 15, 30);
    set_natural_armor(90, 30);
    set("special_defense", (["all" : 40, "none" : 50]));
    sword = new(WP"lance");
    sword->move(this_object());
    set("tactic_func", "my_tactic");
    set("inquiry", (["exit" : "@@point"]));
}

void point(object p)
{
    tell_object(p, "圣骑士似乎对你的问题没有任何反应，不过你注意到他的枪尖指向西边，也许\ ....\n");
    p->set_temp("lilia_direction", 1);
    return;
}

int my_tactic(string arg)
{
    command("grin");
    command("wield lance");
    delete("tactic_func");
    return 1;
}

void die()
{
    command("unwield lance");
    ::die(1);
}
