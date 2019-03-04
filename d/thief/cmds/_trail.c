#include <mudlib.h>
#define TRACE_OB "/obj/trace_object"
inherit DAEMON;

int help();

int find_trace_ob(object env)
{
	object *ob;
	int i;
	ob = all_inventory(env);
	for ( i = sizeof(ob)-1; i >= 0; i-- ) 
		if ( (string) ob[i]->query("name") == "trace object" )
			return 1;
	return 0;
}

void stop_trace(object me)
{
	object target,*tmp;

	if ( ! (target = (object) me->query_temp("trace_target")) ) {
		tell_object(me,"�㲢û�и����κ��ˡ�\n");
		return ;
	}
	if ( !(tmp = target->query_temp("tracers")) ) {
		tell_object(me,"�㲢û�и����κ��ˡ�\n");
		return ;
	}
	tmp -= ({me});
	target->set_temp("tracers",tmp);
	me->delete_temp("trace_target");
	tell_object(me,"��ֹͣ����"+target->query("c_name")+"��\n");
//	me->set_temp("trace_skill",0);
}

int cmd_trail(string arg)
{
	object target,me,trace_ob,o_target;

	me = this_player();
	if (  !wizardp(me) )  return 0;
	if ( (int) me->query_temp("next_action") > time() )
		return notify_fail("������ר���������!!\n");
	if ( ! arg ) {
		target = me->query_temp("trace_target");
		if ( target )
			write("�����ڸ���" + target->query("c_name")+"��\n"); 
		else
			write("������û�и����κ��ˡ�\n");
		return 1;
	}
	if ( arg == "none" ) {
		stop_trace(me);
		return 1;
	}
	if ( !(target=present(arg,environment(me))) )
		return notify_fail("����û�н� " + arg + " �����\n");
	if ( !visible(target,me))
		return notify_fail("����û�н� " + arg + " �����\n");

	if ( ! living(target) ) 
		return notify_fail("��ֻ�ܸ������\n");

	if ( target == me ) {
		stop_trace(me);
		return 1;
	}	
	o_target = me->query_temp("trace_target");
	if ( o_target ) {
	    if ( o_target != target ) 
		return notify_fail("�����ڸ�����һ����,�������ֹͣ��������\n");
	    else 
		return notify_fail("���Ѿ��ڸ������ˡ�\n");
	} 
	target->add_temp("tracers",({me}) );
	me->set_temp("trace_target",target);
	if ( find_trace_ob(target) != 1 ) {
		trace_ob = new(TRACE_OB);
		trace_ob->move(target);
	}
	me->quick_message(sprintf("�㿪ʼ����%s...\n",target->query("c_name")));
	return 1;
}

help()
{
	write(@C_HELP
Usage : trail [ ĳ�� | none ]
	���ָ�����ʹ���������Լ�������֮��, ���ĵĸ���ĳ���߶��������֣�
	��Ȼ��, ���ٵĳɰܸ����ɵ�������Ǻܴ��, ����Ҳ��������ء���һ��
	������, ���ܻᱻ��һ��� ..
	����, ��ֻ�ܸ�����ҡ�
	trail none : ֹͣ���١�
C_HELP);
}
