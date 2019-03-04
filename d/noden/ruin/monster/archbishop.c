// archbishop.c

#include "../lilia.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(19);
    set_name("archbishop kappa", "���˾ ����");
    add("id", ({ "archbishop", "kappa" }) );
    set_short("���˾ ����");
    set("unit", "λ");
    set("alignment", 1000);
    set("wealth/gold", 100);
    set_long(@C_LONG
վ������ǰ�����˳���ʮ����Ȥ��СС���۾����װ׵ĺ��ӣ������кͰ�����
�ĸо���������ȴ���������������������ֱ�������㣬��һ������Ӳ
�����Ǳ����ɵĺá�
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
    tell_object(p, "�������˵���һ�ۣ�ͻȻ�װͰ͵ض���ȵ��������������ʲ�᣿��\n");
    return;
}

void ask_blood(object p)
{
    tell_object(p, "�������ص�һЦ��˵����������Ѫ��ʽ��������ӡ��ħ�õ�ħ���󡣡�\n");
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
	tell_object(p, "������һ��������۹⿴���㣬�ƺ���м���㽻̸��\n");
	return;
    }

    if (p->query_temp("lilia_pass") >= 2)
    {
	tell_object(p, "����������һ�ۣ�˵��������Ҫ���Ϳ���ɣ���\n");
    	return;
    }

    if (!p->query_temp("lilia_question"))
    	gen_q(p);

    n = p->query_temp("lilia_question");
    q = read_file(DIARY"question", n*3-1, 1);
    qqq = sprintf("����Ц����������ͨ������ţ�û���⡣ֻҪ���ĳ�������⣬�Ҿ���������ͨ����\n�������Ŀ�ˣ�%s�뵽֮��ش� (answer) �ҡ���\n", q);
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
	return notify_fail("�����ʲ�᣿\n");

    ae = substr(read_file(DIARY"question", n*3, 1), "\n", "");
    ac = substr(read_file(DIARY"question", n*3+1, 1), "\n", "");

    if (s != ae && s != ac)
    {
	tell_object(p, "������Ц����������򵥵���ĿҲ���᣿��ȥ���������ɣ���\n");
    }
    else
    {
	tell_object(p, "��������üͷ˵������ .... �Һ���̫С����������� ....��\n");
	p->set_temp("lilia_pass", 2);
	p->delete_temp("lilia_question");
    }
    return 1;
}

