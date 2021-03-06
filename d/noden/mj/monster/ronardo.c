// Saint Paladin Carmue
//
//		Lilia@Eastern.Stories

#include "../lilia.h"

inherit MONSTER;

object sword;

void create()
{
    ::create();
    set_level(19);
    set_name("Saint Paladin Carmue", "圣骑士卡谬");
    add("id", ({"paladin", "carmue"}));
    set_short("圣骑士卡谬");
    set_long(@C_LONG
飘逸的紫色长发，忧郁的蓝色眼瞳，站在你眼前的这个英俊的年轻人似乎
并不快乐。不知道他正在烦什麽事情，不过由他身上那把赫赫有名的铠魔剑看
来，这个年轻人绝对是招惹不得的。
C_LONG
	    );
    set_perm_stat("str", 30);
    set_perm_stat("con", 25);
    set_perm_stat("int", 20);
    set_perm_stat("dex", 25);
    set_perm_stat("kar", 25);
    set_perm_stat("pie", 30);
    set_skill("longblade", 100);
    set_skill("parry", 100);
    set_skill("dodge", 100);
    set("alignment", 1500);
    set("race", "drow");
    set("class", "knight");
    set("gender", "male");
    set("hit_points", 2000);
    set("max_hp", 2000);
    set("aim_difficulty", (["critical" : 80, "vascular" : 80, "weakest" : 80, "ganglion" : 80]));
    set_natural_weapon(45, 15, 30);
    set_natural_armor(90, 30);
    set("special_defense", (["all" : 40, "none" : 50]));
    sword = new(WP"sword");
    sword->move(this_object());
    set("tactic_func", "my_tactic");
}

int my_tactic(string arg)
{
    command("grin");
    command("wield sword");
    delete("tactic_func");
    return 1;
}

void die()
{
    command("unwield sword");
    ::die(1);
}
