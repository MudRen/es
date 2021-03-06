//#pragma save_binary

// File: /cmds/std/_party.c
// written by Zeus @1993
// to be used in conjunction with
// my party daemon

#include <mudlib.h>
#include <daemons.h>

#define NAME(x) (string)x->query("name")
#define CAPNAME(x) (string)x->query("cap_name")
#define C_CAPNAME(x) (string)x->query("c_name")
#define LEADER(x) (string)x->query_temp("leader")
#define POSS(x) possessive((string)x->query("gender"))

inherit DAEMON;

int help();

int handle_form()
{
	if((LEADER(this_player())))
		return notify_fail( 
			"你已经是某个队伍的成员了。\n");
	PARTY_D->form_party(this_player());
	return 1;
}

int handle_invite(string str)
{
	object ob;

	if(!(LEADER(this_player())))
		return notify_fail( 
			"你并没有组织任何冒险队伍。\n");
	if( (LEADER(this_player())) != (NAME(this_player())) )
		return notify_fail(
			"你并不是这个冒险队伍的领袖。\n");
	ob = present(lower_case(str), environment(this_player()));
	if(!ob)
		return notify_fail( 
			"这个人并不在这里。\n");
	PARTY_D->invite_member(this_player(), ob);
	return 1;
}

int handle_join(string str)
{
	object ob;

	if((LEADER(this_player())))
		return notify_fail(
			"你已经参加了一个冒险队伍。\n");
	ob = present(lower_case(str), environment(this_player()));
	if(!ob)
		return notify_fail( 
			"这里没有这个人。\n");

	if(!(LEADER(ob)))
		return notify_fail( 
			C_CAPNAME(ob) + "并不属於任何冒险队伍。\n");
	if((LEADER(ob)) != (NAME(ob)))
		return notify_fail(
			C_CAPNAME(ob)+"并不是"+to_chinese(POSS(ob))+"冒险队伍的领袖。\n");
	PARTY_D->add_member(ob, this_player());
	return 1;
}

int handle_leave()
{
	object ob;

	if(!(LEADER(this_player()))) {
		notify_fail("你并不属於任何一个队伍.\n");
		return 0;
	}
	if((LEADER(this_player())) == (NAME(this_player()))) {
		notify_fail("喂 ! 你是领袖耶 !! 有志气一点好吗？\n");
		return 0;
	}
	ob = find_living(lower_case(LEADER(this_player())));
	if(!ob) {
		notify_fail("你的领袖不见了，请跟巫师报告.\n");
		return 0;
	}
	PARTY_D->disband_member(ob, this_player(), 0);
	return 1;
}

int handle_remove(string str) {
	object ob;

	if(!(LEADER(this_player()))) {
		notify_fail("你不属於任何队伍.\n");
		return 0;
	}
	if((LEADER(this_player())) != (NAME(this_player()))) {
		notify_fail("你又不是领袖，不要乱来嘛 !!\n");
		return 0;
	}
	ob = find_living(lower_case(str));
	if(!ob) {
		notify_fail("嗯 ～ 有这个人吗？\n");
		return 0;
	}
	if((LEADER(this_player())) != (LEADER(ob))) {
		notify_fail(CAPNAME(ob)+"不是你的队友.\n");
		return 0;
	}
	PARTY_D->disband_member(this_player(), ob, 1);
	return 1;
}

int handle_disband() {
	if(!(LEADER(this_player()))) {
		notify_fail("你不属於任何冒险队伍.\n");
		return 0;
	}
	if((LEADER(this_player())) != (NAME(this_player()))) {
		notify_fail("你不是领袖，不要乱来好吗？\n");
		return 0;
	}
	PARTY_D->disband_party(this_player());
	return 1;
}

int handle_members() {
	object ob;

	if(!(LEADER(this_player()))) {
		notify_fail("你不属於任何队伍.\n");
		return 0;
	}
	if((LEADER(this_player())) == (NAME(this_player()))) ob = this_player();
	else ob = find_living(lower_case(LEADER(this_player())));
	if(!ob) {	
		notify_fail("你的领袖不见了，请跟巫师报告.\n");
		return 0;
	}
	PARTY_D->party_list(ob);
	return 1;
}

int handle_leader(string str) {
	object ob;

	if(!(LEADER(this_player()))) {
		notify_fail("你不属於任何队伍.\n");
		return 0;
	}
	if((LEADER(this_player())) != (NAME(this_player()))) {
		notify_fail("怎麽？你想篡位吗？\n");
		return 0;
	}
	ob = find_living(lower_case(str));
	if(!ob) {
		notify_fail("嗯 ～ 有这个人吗？\n");
		return 0;
	}
	if((LEADER(this_player())) != (LEADER(ob))) {
		notify_fail(CAPNAME(ob)+"不是你的队友.\n");
		return 0;
	}
	PARTY_D->change_leader(this_player(), ob);
	return 1;
}

int cmd_party(string str)
{
	string foo, fii;

	if(!str) {
		if((LEADER(this_player())))
			write("你是"+
				capitalize(LEADER(this_player()))+"的冒险队伍的队员.\n");
		else write("Usage: party <action> [<player>]\n");
		return 1;
	}
	if(sscanf(str, "%s %s", foo, fii) == 2) {
		switch(foo) {
			case "invite" : return handle_invite(fii); break;
			case "join" : return handle_join(fii); break;
			case "remove" : return handle_remove(fii); break;
//			case "leader" : return handle_leader(fii); break;
			default : return help();
		}
	} else if(sscanf(str, "%s", foo) == 1) {
		switch(foo) {
			case "form" : return handle_form(); break;
			case "leave" : return handle_leave(); break;
			case "disband" : return handle_disband(); break;
			case "members" : return handle_members(); break;
			default : return help();
		}
	}
	return help();
}

int help()
{
	write(@HELP
用法:
	party form             组建一个队伍，发出指令者为队伍首领。
	party join <player>    加入一个已建立的队伍，前提是收到邀请。
	party leave            脱离队伍。
	party members          查看自己队伍的成员名单。
	party invite <player>  邀请某人加入你的队伍。
	party remove <player>  踢某人出你的队伍。
	party disband          解散队伍，队伍首领专用。

这个指令允许你和你的伙伴组织一个队伍共同游戏。
你可以先组建一个队伍，然后对你的伙伴发出邀请，你的伙伴收到邀请后
有60秒时间考虑是否假如你的队伍.
如果你死亡或退出游戏，你就会自动退出队伍，如果你是队伍的首领，队伍
将会被解散.
HELP
);
	return 1;
}
