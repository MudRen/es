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
			"���Ѿ���ĳ������ĳ�Ա�ˡ�\n");
	PARTY_D->form_party(this_player());
	return 1;
}

int handle_invite(string str)
{
	object ob;

	if(!(LEADER(this_player())))
		return notify_fail( 
			"�㲢û����֯�κ�ð�ն��顣\n");
	if( (LEADER(this_player())) != (NAME(this_player())) )
		return notify_fail(
			"�㲢�������ð�ն�������䡣\n");
	ob = present(lower_case(str), environment(this_player()));
	if(!ob)
		return notify_fail( 
			"����˲��������\n");
	PARTY_D->invite_member(this_player(), ob);
	return 1;
}

int handle_join(string str)
{
	object ob;

	if((LEADER(this_player())))
		return notify_fail(
			"���Ѿ��μ���һ��ð�ն��顣\n");
	ob = present(lower_case(str), environment(this_player()));
	if(!ob)
		return notify_fail( 
			"����û������ˡ�\n");

	if(!(LEADER(ob)))
		return notify_fail( 
			C_CAPNAME(ob) + "��������κ�ð�ն��顣\n");
	if((LEADER(ob)) != (NAME(ob)))
		return notify_fail(
			C_CAPNAME(ob)+"������"+to_chinese(POSS(ob))+"ð�ն�������䡣\n");
	PARTY_D->add_member(ob, this_player());
	return 1;
}

int handle_leave()
{
	object ob;

	if(!(LEADER(this_player()))) {
		notify_fail("�㲢������κ�һ������.\n");
		return 0;
	}
	if((LEADER(this_player())) == (NAME(this_player()))) {
		notify_fail("ι ! ��������Ү !! ��־��һ�����\n");
		return 0;
	}
	ob = find_living(lower_case(LEADER(this_player())));
	if(!ob) {
		notify_fail("������䲻���ˣ������ʦ����.\n");
		return 0;
	}
	PARTY_D->disband_member(ob, this_player(), 0);
	return 1;
}

int handle_remove(string str) {
	object ob;

	if(!(LEADER(this_player()))) {
		notify_fail("�㲻����κζ���.\n");
		return 0;
	}
	if((LEADER(this_player())) != (NAME(this_player()))) {
		notify_fail("���ֲ������䣬��Ҫ������ !!\n");
		return 0;
	}
	ob = find_living(lower_case(str));
	if(!ob) {
		notify_fail("�� �� ���������\n");
		return 0;
	}
	if((LEADER(this_player())) != (LEADER(ob))) {
		notify_fail(CAPNAME(ob)+"������Ķ���.\n");
		return 0;
	}
	PARTY_D->disband_member(this_player(), ob, 1);
	return 1;
}

int handle_disband() {
	if(!(LEADER(this_player()))) {
		notify_fail("�㲻����κ�ð�ն���.\n");
		return 0;
	}
	if((LEADER(this_player())) != (NAME(this_player()))) {
		notify_fail("�㲻�����䣬��Ҫ��������\n");
		return 0;
	}
	PARTY_D->disband_party(this_player());
	return 1;
}

int handle_members() {
	object ob;

	if(!(LEADER(this_player()))) {
		notify_fail("�㲻����κζ���.\n");
		return 0;
	}
	if((LEADER(this_player())) == (NAME(this_player()))) ob = this_player();
	else ob = find_living(lower_case(LEADER(this_player())));
	if(!ob) {	
		notify_fail("������䲻���ˣ������ʦ����.\n");
		return 0;
	}
	PARTY_D->party_list(ob);
	return 1;
}

int handle_leader(string str) {
	object ob;

	if(!(LEADER(this_player()))) {
		notify_fail("�㲻����κζ���.\n");
		return 0;
	}
	if((LEADER(this_player())) != (NAME(this_player()))) {
		notify_fail("���᣿�����λ��\n");
		return 0;
	}
	ob = find_living(lower_case(str));
	if(!ob) {
		notify_fail("�� �� ���������\n");
		return 0;
	}
	if((LEADER(this_player())) != (LEADER(ob))) {
		notify_fail(CAPNAME(ob)+"������Ķ���.\n");
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
			write("����"+
				capitalize(LEADER(this_player()))+"��ð�ն���Ķ�Ա.\n");
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
�÷�:
	party form             �齨һ�����飬����ָ����Ϊ�������졣
	party join <player>    ����һ���ѽ����Ķ��飬ǰ�����յ����롣
	party leave            ������顣
	party members          �鿴�Լ�����ĳ�Ա������
	party invite <player>  ����ĳ�˼�����Ķ��顣
	party remove <player>  ��ĳ�˳���Ķ��顣
	party disband          ��ɢ���飬��������ר�á�

���ָ�����������Ļ����֯һ�����鹲ͬ��Ϸ��
��������齨һ�����飬Ȼ�����Ļ�鷢�����룬��Ļ���յ������
��60��ʱ�俼���Ƿ������Ķ���.
������������˳���Ϸ����ͻ��Զ��˳����飬������Ƕ�������죬����
���ᱻ��ɢ.
HELP
);
	return 1;
}
