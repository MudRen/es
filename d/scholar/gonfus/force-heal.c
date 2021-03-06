#include <mudlib.h>

inherit DAEMON;

string *c_illusion =({

"从手太阴肺经的中府穴流过、云门、天府、侠白、尺泽、孔最穴...\n",

"冲过你的隐臼、大都、太白、公孙、商邱、三阴交穴，通往少海穴...\n",

"流向你的极泉、青灵、少海、灵道、通里穴。\n", 

"通过了神封、灵墟、神藏、□中、俞\府，流向手少阳三焦经的观冲穴。\n",

});

void do_heal(object player, int skill, int degree, int ok)
{
	int fp, hp, max, heal;

	fp = (int)player->query("force_points");
	if( !ok && degree < 10 && skill > random(degree*degree*2) && fp > 10 ) {
		message("illusion", can_read_chinese(player)?
			"一股真气"+c_illusion[random(sizeof(c_illusion))]:
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
			"...... \n你深深的吸了一口气，结束了运功\疗伤，你站了起来。\n\n":
			"And then you see the scene surrounding you come solid, you awake.\n" );
		tell_room( environment(player), ({
			player->query("cap_name")+" opens eyes, looks around, and then stands up.\n",
			player->query("c_cap_name")+"神清气爽地站了起来。\n"}), player);
		call_out("heal_again", degree*10, player);
	}
}

int enhant(object me)
{
	int skill, chinese_mode;

	chinese_mode = can_read_chinese(me);
	if( !skill = (int)me->query_skill("chutan") ) {
		tell_object( me, chinese_mode?
			"你不会运功疗伤的心法。\n":
			"You don't know method!\n");
		return 0;
	}

	if( me->query_attackers() ) {
		tell_object( me, chinese_mode?
			"在战斗中运功疗伤? 想死吗!\n":
			"You are combating, can't do that!\n");
		return 0;
	}

	if( me->query_temp("scholar_heal") ) {
		tell_object( me, chinese_mode?
			"你最好休息一下再运功\疗伤。\n":
			"You would better take a rest.\n");
		return 0;
	}
	
	tell_object( me, chinese_mode?
		"你坐了下来, 将精神运至空灵之境... 你开始运功\疗伤。\n":
		"You sit down, try to chutan for heal....\n");

	tell_room( environment(me), ({
		me->query("cap_name")+" sits down and starts to heal cycle.\n",
		me->query("c_cap_name")+"盘腿而坐，开始运功\疗伤...。\n"}), me );
		
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
