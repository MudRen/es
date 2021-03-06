#include <mudlib.h>
#define TRACE_OB "/u/a/aquarius/trace_object"
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

stop_trace(object me)
{
	object target,*tmp;

	target = (object) me->query_temp("trace_target");
	tmp = target->query_temp("tracers"); 
	tmp -= ({me});
	target->set_temp("tracers",tmp);
	me->delete_temp("trace_target");
	tell_object(me,"你停止跟踪"+target->query("c_name")+"。\n");
	me->set_temp("trace_skill",0);
}

int cmd_tt(string arg)
{
	object target,me,trace_ob,o_target;

	me = this_player();
	if (  !(wizardp(me) || me->query("name") == "mouse") )  return 0;
	if ( (int) me->query_temp("next_action") > time() )
		return notify_fail("你正在专心做别的事!!");
	if ( ! arg ) {
		target = me->query_temp("trace_target");
		if ( target )
			write("你正在跟踪" + target->query("c_name")+"。\n"); 
		else
			write("你现在没有跟踪任何人。\n");
		return 1;
	}
	if ( arg == "none" ) {
		stop_trace(me);
		return 1;
	}
	if ( !(target=present(arg,environment(me))) || ! visible(target,me))
		return notify_fail("这里没有叫 " + arg + " 的生物");
	if ( target == me ) {
		stop_trace(me);
		return 1;
	}	
	o_target = me->query_temp("trace_target");
	if ( o_target ) {
	    if ( o_target != target ) 
		return notify_fail("你正在跟踪另一个人,你必须先停止跟踪他。\n");
	    else 
		return notify_fail("你已经在跟踪他了。\n");
	} 
	target->add_temp("tracers",({me}) );
	me->set_temp("trace_target",target);
	if ( find_trace_ob(target) != 1 ) {
		trace_ob = new(TRACE_OB);
		trace_ob->move(target);
	}
	me->quick_message(sprintf("你开始跟踪%s...\n",target->query("c_name")));
	return 1;
}
help()
{
	write(@C_HELP
Usage : trace [ 某人 | none ]
	跟踪某个玩家, 等到适当时机再突下杀手.
C_HELP);
}
