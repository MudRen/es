// bard.c

#include "../lilia.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(19);
    set_name("Bard Xerox", "吟游诗人 纪罗斯");
    add("id", ({"bard", "xerox"}));
    set_short("吟游诗人 纪罗斯");
    set_long(@C_LONG
深紫色的头发，湛蓝的眼睛，搭配著黑暗精灵独有的脸色，和吟游诗人独
有的吊儿郎当的悠闲气质，你发觉纪罗斯是个很有魅力的混合体。嗯，或许该
说是很有魅力的男人。不过由他腰间那闪闪发亮的银笛看来，和他做朋友要比
和他做敌人来的愉快的多。
C_LONG
     	);
    set_perm_stat("str", 30);
    set_perm_stat("con", 25);
    set_perm_stat("int", 30);
    set_perm_stat("dex", 20);
    set_perm_stat("pie", 20);
    set_perm_stat("kar", 20);
    set_skill("dodge", 100);
    set_skill("blunt", 85);
    set("race", "drow");
    set("gender", "male");
    set("hit_points", 1200);
    set("max_hp", 1200);
    set("aim_difficulty", (["critical" : 80, "weakest" : 80]));
    set("special_defense", (["all" : 30, "none" : 30, "monk" : 20, "scholar" : 20]));
    set_natural_armor(30, 40);
    set_natural_weapon(20, 25, 40);
    wield_weapon(WP"flute.c");
    equip_armor("/d/deathland/armour/cloth03.c");
    set("chat_chance", 10);
    set("chat_output", ({
	"纪罗斯唱道：「给我一个吻，可以不可以？」\n",
	"纪罗斯唱道：「留在我的脸上，做个爱标记。」\n",
	"纪罗斯唱道：「Seven lonely days make a lonely week ...」\n", 
	"纪罗斯唱道：「Seven lonely nights make a lonely me ...」\n"
	}));
    set("inquiry", ([
	"carmue" : "@@ask_carmue",
	"paladin" : "@@ask_carmue", 
	"statue" : "@@ask_statue"
	]));
}

void ask_carmue(object p)
{
    tell_object(p, @CARMUE
你说那个酷哥呀？他是女王座下三大骑士之一唷 .... 凶的很哪 .... 没事不要惹
他，除非你想去找老黑泡茶呵呵 ....
CARMUE
		);
    return;
}

void ask_statue(object p)
{
    tell_object(p, @STATUE
那个不是雕像，那是个因为偷汉子遭到女王咀咒的可怜女人。如果你还有点同情心
的话，摘 (pick) 几朵花去供在祭坛上吧。
STATUE
		);
    return;
}

