//	_deplete.c	��Ѫ�ⶾ��
//
//		Lilia
	////#pragma save_binary
#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit DAEMON;

int cmd_deplete(string arg)
{
    object dest, weapon;
    int skill, skill2;
    mixed poisoned;

    if (!arg || arg == "" || !(dest = present(arg, environment(this_player()))))
  	return notify_fail("������˭�ⶾ? \n");
    
    if (!living(dest)) return notify_fail("��������������ж���? \n");

    if (dest->query("npc")) return notify_fail("�㲻���� NPC ��Ѫ��\n");

    if (dest->query("ghost")) return notify_fail("Ҫ�ϴ�����ʵ�ҽѧԺȥ����Ҫ����������Ц��\n");
    
    weapon = this_player()->query("weapon1");
    if ((!weapon) || (string)weapon->query("type") != "dagger")
	return notify_fail("��û��װ���ʵ��Ĺ��ߣ�û�취��Ѫ��\n");

    if (this_player()->query("stop_attack") != 0)
        return notify_fail("����ϸ�������û����ɣ�û�취���˷�Ѫ��\n");

    if (!(poisoned = dest->query("conditions/simple_poison")))
        return notify_fail("�� PK ֱ�Ӵ� kill <ĳ��> �Ϳ����ˣ����ط�Ѫ��\n");

    if (dest->query_temp("depleted"))
	return notify_fail("���߸շŹ�Ѫ�������������з�Ѫ��\n");
    
    if ((int)dest->query("hit_points") <= 20)
	return notify_fail("�����Ѿ�����һϢ�ˣ����¾������Ѫ�����ơ�\n");

    skill = (int)this_player()->query_skill("clotting");
    if (!skill) return notify_fail("ûѧ��ֹѪ�����Ѫ? ���ð� ....\n");

    skill2 = (int)this_player()->query_skill("anatomlogy");
    if (!skill2) return notify_fail("ûѧ������ѧ�����Ѫ? ��ȥ����ʮ��������!\n");

    write("����" + dest->query("c_name") + "���з�Ѫ ....\n");
    tell_object(dest, this_player()->query("c_name") + "������з�Ѫ ... ����úö���!\n");
    tell_room(environment(this_player()), this_player()->query("c_name") + "��" + dest->query("c_name") + "���з�Ѫ��\n", ({this_player(), dest}));
   
    if (dest != this_player()) this_player()->add("alignment", 25);

    if (skill2/2 + random(skill2/2) > poisoned[1] * poisoned[2])
    {
	this_player()->receive_experience(skill2);
	(CONDITION_PREFIX + "simple_poison")->remove_effect(dest);
    }
    else
    {
	poisoned[2] /= 2;
	dest->set("conditions/simple_poison", poisoned);
	this_player()->receive_experience(skill2 / 2);
    }

    dest->set_temp("depleted", 1);
    dest->receive_damage(20 - random(skill/5)); 
    call_out("remove_depleted", 120, dest);
    return 1;
}

void remove_depleted(object player)
{
    if (player) player->set_temp("depleted", 0);
}

int help()
{
    write(
    @C_HELP
ָ���ʽ�� deplete <ĳ��>

���ָ��������ĳ�������Ѫ�ⶾ����Ѫ�Ľ����������ȫ��ȥ���ԣ�
���ǽ����Լ��롣�������Ƿ���ȫ�ɹ������ߵ��������п��ܻ��½���
����ʩ���ߵ�ֹѪ�����йء��Ź�Ѫ���˴�Լ���������ڲ����ٶȷ�Ѫ
�ⶾ������ѪҺ��ʧ���ࡣ
C_HELP
    );
    return 1;
}

