// Created by Kyoko.

#include <mudlib.h>
#include <gonfu.h>

inherit DAEMON ;

int gonfu_exists(string gonfu);

int help() ;

int cmd_enhant(string gonfu)
{
	int fp_cost, delay_time;
    object code;
    
	if( !gonfu ) return help();

	if( (int)this_player()->query("stop_attack")>0 )
		return notify_fail (can_read_chinese()?
			"( ����һ��������û����ɣ��޷�ʩչ��ʽ�� )\n":
			"( You are too busy to enhant a gonfu now. )\n"
		);
    if( this_player()->query_temp("no_enhant") ||
        this_player()->query("no_enhant") )
      return notify_fail( can_read_chinese() ?
        "����׼��ʹ����ʽʱ����Ȼ������ͻȻ��������ʽ�ˡ�\n" :
        "You forget how to enhant any gonfu!\n"
      );
    if( environment(this_player())->query_temp("no_enhant") ||
        environment(this_player())->query("no_enhant") )
      return notify_fail( can_read_chinese() ?
        "���ﲻ��ʹ���κ���ʽ��\n" :
        "You can not enhant any gonfu here!\n"
      );
	if( !(this_player()->query("gonfus/"+gonfu)) )
	  return notify_fail( can_read_chinese()?
		"�㲻������\��\��\n":
		"You don't know such a gonfu.\n"
	  );
	code = GONFU_D->find_gonfu( gonfu );
	if( !code )
		return notify_fail( can_read_chinese()?
			"û�����ֹ��� .... ��֪ͨ��ʦ���� bug ָ�����ʽ���ơ�\n":
			"No such gonfu .... please tell a wizard or report bug.\n"
		);
	fp_cost = (int)code->query_fp_cost();
	delay_time = (int)code->query_delay_time();
	if( !fp_cost || (int)this_player()->query("force_points") < fp_cost )
		return notify_fail( can_read_chinese()?
			"�������������\n":
			"You don't have enough force points!\n"
		);
    if( (string)this_player()->query_temp("gonfu_now") == gonfu )
        return notify_fail( can_read_chinese()?
			"������ʩչ�⹦\���ˣ�\n":
			"You have enhanting this gonfu!\n"
		);
    this_player()->set_temp("gonfu_now", gonfu);
    this_player()->set_temp("gonfu_delay_time", delay_time);
	if( code->enhant() )
	  this_player()->add("force_points", -fp_cost );
	return 1;
}

int help()
{
	if( can_read_chinese() )
		write( @C_HELP
ָ���ʽ: enhant <��ʽ����>

���ָ����������ʩչ��ʽ��������� gonfus ָ���Ŀǰ�Ѿ�ѧ�����ʽ�б�
C_HELP
		);
	else write ( @HELP
Usage:	enhant <gonfu name>

This command let you enhant gonfus. You can type "gonfus" to see the 
gonfus you have learned.
HELP
    );
    return 1;
}
