// HellParadise.c	�����ɾ�
//
//	Effect: +MP100 +FP100
//		(�Ի�ҩϵ)
//
//			Lilia

#include <mudlib.h>
#include <conditions.h>

//#define ILLUSION "/u/l/lilia/drug/illusion"

inherit OBJECT;

void create()
{
    set_name("hell paradise", "�����ɾ�");
    add("id", ({"hell", "paradise"}));
    set_short("�����ɾ�");
    set_long("����һ����ɫ����ҩ���йɴ̱ǵ�ζ����\n");
    set("unit", "��");
    set("weight", 15);
    set("value", ({ 500, "silver" }));
}

void init()
{
    add_action("do_eat", "eat");
}

int do_eat(string arg)
{
    int max, mp;
    object p;

    p = this_player();

    if (!arg || (arg != "pill" && arg != "hell" && arg != "paradise"))
	return notify_fail("��ʲ��??");
    write("������˵����ɾ�����ʱ���и����������Ļþ� ....\n");

    (CONDITION_PREFIX + "sick")->apply_effect(p, 4, 10, 5);
    (CONDITION_PREFIX + "weak")->apply_effect(p, 10, 2);
    p->set("medication_resistance", 350);
    max = p->query("max_sp");
    if (max) {
    if ((mp = p->query("spell_points")) >= max) { remove(); return 1; }
    if (mp + 100 > max) p->set("spell_points", max);
	else p->set("spell_points", mp+100); }
    max = p->query("max_fp");
    if (max) {
    if ((mp = p->query("force_points")) >= max) { remove(); return 1; }
    if (mp + 100 > max) p->set("force_points", max);
  	else p->set("force_points", mp+100);
    (CONDITION_PREFIX + "slow")->apply_effect(p, 8, 2); }
    remove();
    return 1;
}

