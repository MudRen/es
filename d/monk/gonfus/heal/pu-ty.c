#include <mudlib.h>

inherit DAEMON;

string *c_illusion =({

"由你的气海穴流出，缓缓的流向背部的阳堂穴...\n",

"由督脉流向足三里穴，却似忽遇到了阻碍而无法向前催动...\n",

"从你手少阴心经的极泉穴慢慢流出，流入手少阳小肠经的少泽穴。\n", 

"从手太阴肺经的中府穴流过、云门、天府、侠白、尺泽、孔最穴...\n",

"冲过你的隐臼、大都、太白、公孙、商邱、三阴交穴，通往少海穴...\n",

"流向你的极泉、青灵、少海、灵道、通里穴。\n", 

"从你的涌泉穴，通往照海穴。\n",

"通过了神封、灵墟、神藏、□中、俞\府，流向手少阳三焦经的观冲穴。\n", });

void do_heal(object player, int skill, int degree , int ok)
{
	int fp, hp, max, heal;

	if( !player ) return;
	fp = (int)player->query("force_points");
       if( !ok && degree <= 10 && skill > random(degree*degree*2) && fp > 10 ) {
		message("illusion", can_read_chinese(player)?
			"一股真气"+c_illusion[random(sizeof(c_illusion))]:
			"You feel some colorful illusions around you.\n", player);
		hp = (int)player->query("hit_points");
		max = (int)player->query("max_hp");
		player->set("force_points", fp-degree);
		heal = degree+random(degree/2);
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
		tell_object( player,
			"...... \n你深深的吸了一口气，结束了运功\疗伤，你站了起来。\n\n");
		tell_room( environment(player), 
			player->query("c_name")+"神清气爽地站了起来。\n", player);
	}
}

int eungon(object me, int level)
{
	int skill, chinese_mode;

	chinese_mode = can_read_chinese(me);
	if( !skill = (int)me->query_skill("heal-cycle") ) {
		tell_object( me, 
			"你不会运功\疗伤的心法。\n");
		return 0;
	}

	if( me->query_attackers() ) {
		tell_object( me, 
			"在战斗中运功\疗伤? 想死吗!\n");
		return 0;
	}

	tell_object( me,
		"你坐了下来, 默颂菩提心法, 将精神运至空灵之境... 你开始运功\聚气疗伤。\n");

	tell_room( environment(me), 
		me->query("c_name")+"盘腿而坐，开始运功\疗伤...。\n", me );
		
	if( !wizardp(me) ) {
		me->set_temp("block_command", 1);
		me->set_temp("block_defense", 1);
	}

	call_out("do_heal", 2, me, skill, 1, 0);
	return 1;
}

