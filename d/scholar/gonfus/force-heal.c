#include <mudlib.h>

inherit DAEMON;

string *c_illusion =({

"����̫���ξ����и�Ѩ���������š��츮�����ס����󡢿���Ѩ...\n",

"���������ʡ��󶼡�̫�ס��������������Ѩ��ͨ���ٺ�Ѩ...\n",

"������ļ�Ȫ�����顢�ٺ��������ͨ��Ѩ��\n", 

"ͨ������⡢���桢��ء����С���\���������������������Ĺ۳�Ѩ��\n",

});

void do_heal(object player, int skill, int degree, int ok)
{
	int fp, hp, max, heal;

	fp = (int)player->query("force_points");
	if( !ok && degree < 10 && skill > random(degree*degree*2) && fp > 10 ) {
		message("illusion", can_read_chinese(player)?
			"һ������"+c_illusion[random(sizeof(c_illusion))]:
			"You feel some colorful illusions around you.\n", player);
		hp = (int)player->query("hit_points");
		max = (int)player->query("max_hp");
		player->set("force_points", fp-degree);
		heal = degree+degree/2+random(degree);
		if( hp + heal > max ) {
			player->set("hit_points", max );
			call_out("do_heal", 2, player, 0, 0, 1);
		} else {
			player->set("hit_points", hp+heal);
			call_out("do_heal", 2, player, skill, degree+1, 0);
		}
	} else {
		player->delete_temp("block_command");
		player->delete_temp("block_defense");
		player->delete_temp("block_message");
		player->delete_temp("gonfu_busy");
		tell_object( player, can_read_chinese(player)?
			"...... \n�����������һ�������������˹�\���ˣ���վ��������\n\n":
			"And then you see the scene surrounding you come solid, you awake.\n" );
		tell_room( environment(player), ({
			player->query("cap_name")+" opens eyes, looks around, and then stands up.\n",
			player->query("c_cap_name")+"������ˬ��վ��������\n"}), player);
		call_out("heal_again", degree*10, player);
	}
}

int enhant(object me)
{
	int skill, chinese_mode;

	chinese_mode = can_read_chinese(me);
	if( !skill = (int)me->query_skill("chutan") ) {
		tell_object( me, chinese_mode?
			"�㲻���˹����˵��ķ���\n":
			"You don't know method!\n");
		return 0;
	}

	if( me->query_attackers() ) {
		tell_object( me, chinese_mode?
			"��ս�����˹�����? ������!\n":
			"You are combating, can't do that!\n");
		return 0;
	}

	if( me->query_temp("scholar_heal") ) {
		tell_object( me, chinese_mode?
			"�������Ϣһ�����˹�\���ˡ�\n":
			"You would better take a rest.\n");
		return 0;
	}
	
	tell_object( me, chinese_mode?
		"����������, ��������������֮��... �㿪ʼ�˹�\���ˡ�\n":
		"You sit down, try to chutan for heal....\n");

	tell_room( environment(me), ({
		me->query("cap_name")+" sits down and starts to heal cycle.\n",
		me->query("c_cap_name")+"���ȶ�������ʼ�˹�\����...��\n"}), me );
		
	if( !wizardp(me) ) {
		me->set_temp("block_command", 1);
		me->set_temp("block_defense", 1);
		me->set_temp("block_message", 1);
	}

	me->set_temp("scholar_heal", 1);
	me->set_temp("gonfu_busy", 1);
	call_out("do_heal", 2, me, skill, 1, 0);
	return 1;
}

void heal_again(object player)
{
	if( !player ) return;
	player->delete_temp("scholar_heal");
}
