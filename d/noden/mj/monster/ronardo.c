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
    set_name("Saint Paladin Carmue", "ʥ��ʿ����");
    add("id", ({"paladin", "carmue"}));
    set_short("ʥ��ʿ����");
    set_long(@C_LONG
Ʈ�ݵ���ɫ��������������ɫ��ͫ��վ������ǰ�����Ӣ�����������ƺ�
�������֡���֪�������ڷ�ʲ�����飬�������������ǰѺպ���������ħ����
������������˾��������ǲ��õġ�
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
