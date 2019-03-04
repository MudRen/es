//#pragma save_binary

// This command is use for monk only, it let monks decide his fist-fight
// gonfu, the gonfu is defined at /d/martial/attack & /d/martial/defense.
// Sub dirs is: attack fist: monk/fist, defense fist: monk/fist.
// Attack fist & defense fist can only exist one, but some attack fist
// has defense effect, or defense fist have attack effect :P).
// Created by Angel@Eastern.Stories.
// Rewriten by Kyoko@Eastern.Stories. 09/26/94

#include <mudlib.h>
#include <martial.h>

#define FIST_DIR "monk/fist/"

inherit DAEMON;

int help();

int cmd_fist(string str)
{
	string fist_now, *know, def;
	string *fist = ({ "sh_fist", "tb_fist", "long_fist", "ro_han",
		"drunk_fist", "fu_hu", "wei_to", "ho_fist" });
	string *def_fist = ({ "sh_fist", "tb_fist", "long_fist", "ro_han",
		"drunk_fist", "fu_hu", "wei_to", "ho_fist" });
	object me;

	if( !str ) return help();

	me = this_player();
	if( me->query("gonfu_busy") || me->query_temp("gonfu_busy") )
    	return notify_fail("��Ŀǰ���˹�\�����޷��������������书\��\n");

	if( str=="now") {
		fist_now=(string)me->query("attack_skill");
		if( !fist_now || !sscanf(fist_now, FIST_DIR+"%s", fist_now) )
			write("��Ŀǰû�д���ʹ���κ�ȭ��.\n" );
		else write("������ʹ�õ�ȭ����: "+set_color(to_chinese(fist_now), "HIC")+"��\n");
		return 1;
	} else if( str == "none" ) {
		write("�������ʹ�õĻ���ȭ����\n");
		me->delete("attack_skill");
		me->delete("defense_skill");
		return 1;
	}

	if( member_array(str, fist) == -1 )
		return notify_fail("�����ֻ���ȭ����? \n");

	know = (string *)me->query("monk_gonfu/fist");
	if( !know || !sizeof(know) || member_array(str, know) == -1 )
		return notify_fail("������ֻ���ȭ����? \n");

	write("������ʹ�õ�ȭ��������: "+set_color(to_chinese(str),"HIC")+"��\n");

	me->set("attack_skill", FIST_DIR+str);
	if( member_array(str, def_fist) != -1 )
		me->set("defense_skill", FIST_DIR+"d_"+str);
	else
		me->delete("defense_skill");
	return 1;
}

int help()
{
		write( @C_HELP
ָ���ʽ: fist <���ֻ���ȭ������> | <none>
���ָ����������ʩչȭ����������� gonfus ָ���Ŀǰ�Ѿ�ѧ�����ʽ�б�

ָ���ʽ: fist now
��ʾĿǰ��ʹ�õĻ����Ʒ� 

          fist none
ֹͣʹ���κ�ȭ��  
C_HELP
		);
	return 1;
}
