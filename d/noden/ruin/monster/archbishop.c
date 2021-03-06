// archbishop.c

#include "../lilia.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(19);
    set_name("archbishop kappa", "大祭司 卡帕");
    add("id", ({ "archbishop", "kappa" }) );
    set_short("大祭司 卡帕");
    set("unit", "位");
    set("alignment", 1000);
    set("wealth/gold", 100);
    set_long(@C_LONG
站在你面前的男人长得十分有趣，小小的眼睛，白白的胡子，令人有和蔼亲切
的感觉，不过他却有著坚毅明亮的眼神。你的直觉告诉你，这家伙吃软不吃硬
，还是别蛮干的好。
C_LONG
        );
    set_perm_stat("str", 25);
    set_perm_stat("dex", 27);
    set_perm_stat("int", 30);
    set_perm_stat("pie", 20);
    set_perm_stat("kar", 25);
    set_perm_stat("con", 30);
    set("max_hp", 1000);
    set("hit_points", 1000);
    set("max_sp", 2700);
    set("spell_points", 2700);
    set_natural_armor(50, 30);
    set_natural_weapon(35, 20, 30);
    set("special_defense", ([
	"cold" : 90,
	"fire" : 70,
	"all" : 70 ,
	"none" : 80
	]) );
    set("aim_difficulty", ([
	"critical" : 100,
	"weakest" : 100
	]) );
    set_skill("dodge", 70);
    set_skill("white-magic", 100);
    set_skill("elemental", 100);
    set_skill("concentrate", 100);
    set_skill("target", 100);
    set_skill("dagger", 100);
    set("gender", "male");
    set("race", "daemon");
    set("magic_delay", 1);
    set("spells/fireball", 7);
    set("spells/heal", 2);
    set("exp_reward", 30000);
    set("inquiry", ([
	"alphabet" : "@@ask_alphabet",
	"blood" : "@@ask_blood", 
	"pass" : "@@ask_pass"
	]) );
    equip_armor(ARM"bishop_robe");
    wield_weapon(WP"holy_dagger");
    set("tactic_func", "cast_spell");
}

void init()
{
    ::init();
    add_action("to_answer", "answer");
}

int cast_spell()
{
    if (random(10) > 3) return 0;
    if (this_object()->query("hit_points") < 500 && random(10) < 3)
	command("cast heal on archbishop");
    else
	command("cast fireball on "+query_attacker()->query("name"));
    return 1;
}

void ask_alphabet(object p)
{
    tell_object(p, "卡帕瞄了地上一眼，突然凶巴巴地对你喝道：「你问这个干什麽？」\n");
    return;
}

void ask_blood(object p)
{
    tell_object(p, "卡帕神秘的一笑，说道：「这是血仪式，用来封印恶魔用的魔法阵。」\n");
    return;
}

void gen_q(object p)
{
    int r;
    string buf;
    buf = read_file(DIARY"question", 1, 1);
    r = random(atoi(buf)) + 1;
    p->set_temp("lilia_question", r);
}

void ask_pass(object p)
{
    string q, qqq;
    int n;

    if (p->query_perm_stat("int") <= 5)
    {
	tell_object(p, "卡帕以一种轻蔑的眼光看著你，似乎不屑与你交谈。\n");
	return;
    }

    if (p->query_temp("lilia_pass") >= 2)
    {
	tell_object(p, "卡帕瞪了你一眼，说道：「你要过就快过吧！」\n");
    	return;
    }

    if (!p->query_temp("lilia_question"))
    	gen_q(p);

    n = p->query_temp("lilia_question");
    q = read_file(DIARY"question", n*3-1, 1);
    qqq = sprintf("卡帕笑道：「你想通过这道门？没问题。只要你答的出这道谜题，我就认输让你通过。\n听清楚题目了：%s想到之後回答 (answer) 我。」\n", q);
    tell_object(p, qqq);
    p->set_temp("lilia_pass", 1);
    return;
}

int to_answer(string s)
{
    object p;
    string ae, ac;
    int n;

    p = this_player();
    n = p->query_temp("lilia_question");

    if (!s || p->query_temp("lilia_pass") != 1) 
	return notify_fail("你想答什麽？\n");

    ae = substr(read_file(DIARY"question", n*3, 1), "\n", "");
    ac = substr(read_file(DIARY"question", n*3+1, 1), "\n", "");

    if (s != ae && s != ac)
    {
	tell_object(p, "卡帕大笑道：「这麽简单的题目也不会？回去想想再来吧！」\n");
    }
    else
    {
	tell_object(p, "卡帕皱著眉头说：「嗯 .... 我好像太小看你的智商了 ....」\n");
	p->set_temp("lilia_pass", 2);
	p->delete_temp("lilia_question");
    }
    return 1;
}

