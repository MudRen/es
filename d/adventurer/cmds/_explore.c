//#pragma save_binary

#include <mudlib.h>

#define MESSAGE ({"��������ʼ���·�ߵ�Ұ��...\n","��ֻ�Ŵ󾵶Ե�������...\n","�ڵ������˺ô�һ����Ȼ������ȥ...\n","ſ�ڵ��϶�������...\n","���ֲ��˲���ͷ�ϵĺ�ˮ...\n" })
inherit DAEMON;


int help();
int explore_work(object me,object env,int time);
int cmd_explore()
{
	int skill,tp_cost,sp_cost,hp_cost,time;
	object me, env;
	
	time = 5;
	me = this_player();
    if( me->query_attacker() )
        return notify_fail("�㻹��ս��ร���Ҫ�����...\n");
    if( me->query_temp("explore_busy") )
    	return notify_fail("�����ˣ��㲻���������� \n");

	env = environment(me);
	
	if( !env ) return 0;
    if( !env->query("outside") )
        return notify_fail("�������û��ʲ���ر�ֵ��ע�����Ȼ� \n");	
	if( !skill = (int)me->query_skill("natural_history") )
		return notify_fail( "��û��ѧ������ѧ�������˷�ʱ���� !!!\n");
	tp_cost = 60 - skill/5 ;
	sp_cost = 15 - skill/10 ;
	hp_cost = 20 - skill/10 ;
	
	if( !tp_cost || (int)me->query("talk_points") < (tp_cost + 1) )
		return notify_fail("��̫���ˣ��ٲ��ҵ�ˮ������һ�¿ɲ�̫�ã�\n");
	if( !sp_cost || (int)me->query("spell_points") < (sp_cost + 1) )
	        return notify_fail("�㾫����̫���ˣ�����ҵط���Ϣ�ɣ�\n");
	if( !hp_cost || (int)me->query("hit_points") < (hp_cost + 1) )
	        return notify_fail("��Ϳ�ݺ������ˣ�����Ҫ���ﰡ��\n");
	                
	                
	else
		me->add("talk_points", -tp_cost );
		me->add("spell_points", -sp_cost );
		me->add("hit_points", -hp_cost );

	tell_object(me, set_color("������Ӿ�����������ʼ��ϸ��̽��������һ��һľ ! \n", "HIC",me) ); 
	
	me->set_temp("explore_busy",1);
	me->set_temp("block_command", 1 );
	me->set_temp("msg_stop_attack",
	         "( ����춳����̽������Ȼ����Ȥ֮�У��޷�����... )\n" );
	call_out("explore_work", 5, me, env, time);
	return 1;
}

int explore_work(object me,object env,int time)
{
	int skill,my_kar,my_pie,num,chance,n,i,delay;
	object thing;
	skill = me->query_skill("natural_history");
	delay = 40 - skill/10 - me->query_stat("pie")/2 ;
	if ( time < delay ) {
	time = time + 5 ;
	i = random(4);
	tell_object( me, set_color(
	 "��"+MESSAGE[i] , "HIY", me) );
	tell_room( env,
	                "�㿴��"+ me->query("c_name")+MESSAGE[i],me );
	
	call_out("explore_work", 5, me, env, time, delay);
	return 1;
	}
        num = env->query("explore_time");
	my_kar = me->query_stat("karma");
	my_pie = me->query_stat("piety");
	chance = 57 - my_pie/2 - skill/4 - my_kar/2 + num*10 ;
	me->delete_temp("msg_stop_attack");
	me->delete_temp("block_command");
	me->delete_temp("explore_busy");
	
	if ( random(chance) >3 ) {
	tell_object( me, set_color( 
		"�����˰��죬ʲ�ᶼû���ҵ�����������������˴�...\n", "HIY", me) );
	tell_room( env, 
		"�㿴��"+ me->query("c_name")+"��һ�Ѳݴ������������������ʧ���ı��顣\n\n" ,me );
                return 1;
                }
         switch( n= random(4) ) {
                    case 0: thing = new("/d/noden/monster/hornet");   break;
                    case 1: thing = new("/d/noden/monster/snake");   break;
                    case 2: thing = new("/d/adventurer/natural_history/unknow_tree");   break;
                    case 3: thing = new("/d/adventurer/natural_history/unknow_gem");   break;
                    default : break;
                    }
                  thing->move(environment(this_player()));
                  tell_object( me,
                      "���첻�������ˣ����ҵ�һ"+thing->query("unit")+thing->query("c_name")+"...\n");
                  tell_room( env,
                      me->query("c_name")+"�Ӳݴ����ҵ���"+thing->query("unit")+thing->query("c_name")+"...\n",me);
                      
                  me->gain_experience(100);
                  if (n < 2) thing->kill_ob(this_player());
                  env->add("explore_time",1);
                  return 1;
}
int help()
{
write(
@C_LONG
ָ���ʽ: explore

���ָ���ܹ�ʹ��������ѧ�Ĳ���ѧ(natural_history) ֪ʶ���Ӵ���Ȼ��
Ѱ�����õ���Ȼ����������Ļ�������Ĳ���ѧ�������Լ����Ķ��й�

C_LONG
);
    return 1;
}
