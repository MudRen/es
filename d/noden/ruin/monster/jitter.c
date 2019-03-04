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
    set_name("Saint Paladin Jitter", "ʥ��ʿ����");
    add("id", ({"paladin", "jitter"}));
    set_short("ʥ��ʿ����");
    set_long(@C_LONG
�����Ľ𷢣�ͬ�������ı�ɫ��ͫ��վ������ǰ�����Ӣ�����������ƺ�
�й����˵�ħ������֪����������ʲ�����飬�������������ǰѺպ���������
ħǹ��������������˾��������ǲ��õġ�
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
    tell_object(p, "ʥ��ʿ�ƺ����������û���κη�Ӧ��������ע�⵽����ǹ��ָ�����ߣ�Ҳ��\ ....\n");
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
