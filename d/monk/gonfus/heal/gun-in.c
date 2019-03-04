#include <mudlib.h>

inherit DAEMON;

string *c_illusion =({

"���������Ѩ���������������򱳲�������Ѩ...\n",

"�ɶ�������������Ѩ��ȴ�ƺ��������谭���޷���ǰ�߶�...\n",

"�����������ľ��ļ�ȪѨ��������������������С����������Ѩ��\n", 

"����̫���ξ����и�Ѩ���������š��츮�����ס����󡢿���Ѩ...\n",

"���������ʡ��󶼡�̫�ס��������������Ѩ��ͨ���ٺ�Ѩ...\n",

"������ļ�Ȫ�����顢�ٺ��������ͨ��Ѩ��\n", 

"�����ӿȪѨ��ͨ���պ�Ѩ��\n",

"ͨ������⡢���桢��ء����С���\���������������������Ĺ۳�Ѩ��\n", });

void do_heal(object player, int skill, int degree, int ok)
{
	int fp, hp, max, alig ,heal;

	if( !player ) return;
	fp = (int)player->query("force_points");
	if( degree <= 10 && skill > random(degree*degree*2) 
		&& fp > 10 && !ok ) {
		player->quick_message(
			"һ�������"+c_illusion[random(sizeof(c_illusion))]);
		alig = (int)player->query("alignment");
		hp = (int)player->query("hit_points");
		max = (int)player->query("max_hp");
		player->set("force_points", fp-degree);
		if( (random(100) < 2) && (alig > 5000) ) {
			player->set("hit_points", max );
 			tell_object( player, @LONG
******************************************************************
*                   ������ʿ����ͻ��.....                        *
*                                                                *
*  �����¶������£���һ������Ҳ�����Ծ�ƿˮ�ָ����ȫ���˺�...�� *
*  ............................ ..... ..... ...                  * 
*                                                                *
*  �㷢�������ȫ����... ������ͷĬ�������ʿ����...             *
******************************************************************
LONG
			);
			call_out("do_heal", 5, player, 0, 0, 1);
			return;
		}
		heal = degree + random(degree/2);
		if( heal + hp > max ) {
			player->set("hit_points", max);
			call_out("do_heal", 3, player, 0, 0, 1);
		} else {
			player->set("hit_points", hp+heal);
			call_out("do_heal", 2, player, skill, degree+1, 0);
		}
	} else {
		player->delete_temp("block_command");
		player->delete_temp("block_defense");
		tell_object( player, 
			"...... \n�����������һ�������������˹�\���ˣ���վ��������\n\n");
		tell_room( environment(player), 
			player->query("c_name")+ "������ˬ��վ��������\n",
			player );
	}
}

int eungon(object me, int level)
{
	int skill;

	if( !skill = (int)me->query_skill("heal-cycle") ) {
		tell_object( me, 
			"�㲻���˹�\���˵��ķ���\n");
		return 0;
	}

	if( me->query_attackers() ) {
		tell_object( me, 
			"��ս�����˹�\����? ������!\n");
		return 0;
	}

	tell_object( me, 
		"����������, Ĭ�̹����ľ�����������������֮��... �㿪ʼ�˹�\���ˡ�\n");

	tell_room( environment(me), 
		me->query("c_name")+"���ȶ�������ʼ�˹�\����...��\n", me );

	if( !wizardp(me) ) {
		me->set_temp("block_command", 1);
		me->set_temp("block_defense", 1);
	}

	call_out("do_heal", 2, me, skill, 1, 0);
	return 1;
}

