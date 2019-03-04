// Saint Paladin Emerald Leitz
//
//		Lilia@Eastern.Stories

#include "../lilia.h"

inherit MONSTER;

object sword;

void create()
{
    ::create();
    set_level(19);
    set_name("Saint Paladin Emerald Leitz", "ʥ��ʿ��ķ����");
    add("id", ({"paladin", "emerald", "leitz"}));
    set_short("ʥ��ʿ��ķ����");
    set_long(@C_LONG
���صĺ췢��ͬ�����صĺ�ɫ��ͫ��վ������ǰ�����Ӣ�����������ƺ�
�й����˵�ħ������֪����������ʲ�����飬��������������ɢ������������
ս�⿴������������˾��������ǲ��õġ�
C_LONG
	    );
    set_perm_stat("str", 30);
    set_perm_stat("con", 25);
    set_perm_stat("int", 20);
    set_perm_stat("dex", 25);
    set_perm_stat("kar", 25);
    set_perm_stat("pie", 30);
    set_skill("polearm", 100);
    set_skill("longblade", 100);
    set_skill("parry", 100);
    set_skill("dodge", 100);
    set("alignment", 1500);
    set("race", "daemon");
    set("class", "knight");
    set("gender", "male");
    set("hit_points", 2000);
    set("max_hp", 2000);
    set("spell_points", 2000);
    set("max_sp", 2000);
    set("aim_difficulty", (["critical" : 80, "vascular" : 80, "weakest" : 80, "ganglion" : 80]));
    set_natural_weapon(45, 15, 30);
    set_natural_armor(90, 30);
    set("special_defense", (["all" : 40, "none" : 50]));
    wield_weapon(WP"polearm.c");
    equip_armor("/d/noden/nodania/obj/steel_plate.c");
    equip_armor("/d/noden/nodania/obj/steel_leggings.c");
    equip_armor("/d/noden/nodania/obj/steel_helmet.c");
    equip_armor("/d/noden/nodania/obj/steel_boots.c");
    equip_armor("/d/noden/nodania/obj/steel_gauntlets.c");
    equip_armor("/d/noden/nodania/obj/white_cape.c");
    sword = new("/d/noden/drow/obj/god2.c");
    sword->move(this_object());
    set("weapon2", sword);
    sword->set("wielded", 1);
}

