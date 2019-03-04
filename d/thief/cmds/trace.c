#include <mudlib.h>

inherit DAEMON;

int help();

int cmd_trace(string arg)
{
	object target,me;

	me = this_player();
	if ( (int) me->query_temp("next_action") > time() )
		return notify_fail("������ר���������!!");
	if ( ! arg ) {
		target = me->query_temp("trace_target");
		if ( nullp(target) )
			write("������û�и����κ���.");
		else
			write("�����ڸ���" + target->query("c_name")+"."); 
		return 1;
	}
	if ( !(target=present(arg,environment(me))) )
		return notify_fail("����û�н� " + arg + " ������");
	if ( ! visible(target,me) )
		return notify_fail("����û�н� " + arg + " ������");
	if ( target == me ) {
		stop_trace(me);
		return 1;
	}	
	target->add_temp("tracer",({"me" }));
	
}

stop_trace(object me)
{
	me->delete_temp("trace_target");
//	target->_temp("tracer",({"me" }));
}

help()
{
	write(@C_HELP
Usage : trace <ĳ��>
	����ĳ��, �ȵ��ʵ�ʱ����ͻ��ɱ��.
	trace <�Լ�>
	ֹͣ����
	trace 
	���ڸ���˭
C_HELP);
}
