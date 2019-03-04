// ������
//
//		Lilia

////#pragma save_binary

#include <mudlib.h>

#define QUESTNAME "lost_kingdom"
#define SP_COST	50

int help();

int remove_block(object obj)
{
    obj->delete_temp("block_command");
    return 1;
}

int cmd_amass()
{
    int skill, delay_time;
    object me;

    me = this_player();
    if ((int)me->query(QUESTNAME) != 8) return 0;

    skill = me->query("dou-in");
    if (!skill)
	return notify_fail("�㻹û����������û�а취������\n");

    if ((int)me->query("stop_attack") > 0)
	return notify_fail("( ����һ��������û����ɣ��޷�ר�ľ����� )\n");

    if (!(!(me->query_current_attacker())))
	return notify_fail("�㻹��ս���У�ûʱ��ͣ����������\n");

    if (me->query_temp("no_concentrate"))
	return notify_fail("���ע���������ܼ��У��޷�������\n");

    if (me->query("spell_points") < SP_COST)
	return notify_fail("����������㣬�޷�������\n");

    if (me->query("npc"))
	delay_time = 0;
    else
	delay_time = 3;

    me->block_attack(delay_time);
    me->set_temp("msg_stop_attack", "( ������ר�ľ�����û�취��������! )\n");
    tell_object(me, "���Ŀ���񣬿�ʼ���� ...\n");
    tell_room(environment(me), me->query("c_name")+"��Ŀ���񣬿�ʼ���� ...\n", me);
    call_out("effect", delay_time, me);
    return 1;
}

void effect(object me)
{
    int duration, sp;

    if (me->query_temp("effect/protect"))
	tell_object(me, "һ��΢������ط���������ϣ��������ʮ����ˬ ...\n");
    else
	tell_object(me, "һ�������Ӧ��������������������Χ������������γ������ܱ�������!\n");

    tell_room(environment(me), "�ƺ���һ���Χ����"+me->query("c_name")+"������ ... �ò����Ǵ����? ...\n", me);

    duration = me->query_stat("pie") * 3 + 50;
    me->set_temp("extra_db/protect", (int)me->query("dou-in"));
    me->set_temp("extra_ac/protect", 10);
    me->set_temp("effect/protect", 1);
    me->calc_armor_class();
    me->delete_temp("msg_stop_attack");
    sp = (int)me->query("spell_points");
    sp -= SP_COST;
    me->set("spell_points", sp);
    call_out("expire", duration, me);
}

void expire(object me)
{
    if (!me) return;

    tell_object(me, "��������ܵķ���С��������������ʧ�� ...\n");

    me->delete_temp("extra_db/protect");
    me->delete_temp("extra_ac/protect");
    me->delete_temp("effect/protect");
    me->calc_armor_class();
}

