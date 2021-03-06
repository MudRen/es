#include <mudlib.h>

inherit DAEMON;

int help();

int cmd_trace(string arg)
{
	object target,me;

	me = this_player();
	if ( (int) me->query_temp("next_action") > time() )
		return notify_fail("你正在专心做别的事!!");
	if ( ! arg ) {
		target = me->query_temp("trace_target");
		if ( nullp(target) )
			write("你现在没有跟踪任何人.");
		else
			write("你正在跟踪" + target->query("c_name")+"."); 
		return 1;
	}
	if ( !(target=present(arg,environment(me))) )
		return notify_fail("这里没有叫 " + arg + " 的生物");
	if ( ! visible(target,me) )
		return notify_fail("这里没有叫 " + arg + " 的生物");
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
Usage : trace <某人>
	跟踪某人, 等到适当时机再突下杀手.
	trace <自己>
	停止跟踪
	trace 
	正在跟踪谁
C_HELP);
}
