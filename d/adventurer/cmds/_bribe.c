//#pragma save_binary

#include <mudlib.h>

inherit DAEMON;

int help();
int bribe_work(object me, object victim, int charm);
int cmd_bribe()
{
	int skill, tp_cost, delay, num, charm, num1, time;
	object me, victim;
	
	me = this_player();
    if( me->query_level() < 5 )
        return notify_fail("�㵽���������?\n");
    if( me->query_temp("bribe_busy") )
    	return notify_fail("ͬʱ��¸�������ǲ����ܵġ�\n");

	victim = me->query_attacker();
	
switch( me->query("race") ) {
	case "human" : 	charm == 3;		break;
	case "elf"        :  charm == 4;		break;
	case "dwarf":  charm == 2;		break;
	case "orc"    : 	charm == 1;		break;
	case "gnome"     : 	charm == 3;		break;
	case "halfling"       : 	charm == 4;		break;
	case "lizardman" : 	charm == 1;		break;
	case "imp"   : 	charm == 3;		break;
	case "daemon"     :  charm == 4;		break;
	case "vampire"      : 	charm == 4;		break;
	case "beholder" :  charm == 5;             break;
	case "drow" :  charm == 3;             break;
	default          :	charm == 2;
		}
	

	if( !victim ) return notify_fail("��û��ս���У��Ҳ�������������!\n");
	if( !skill = (int)me->query_skill("polemic") )
		return notify_fail( "��û��ѧ���������ڲ�Ҳ���ã�����ȥ��¸������ !!!\n");
        if( victim->query("prevent_give_money") )
                return notify_fail("��һ￴���ǲ��ܻ�¸��!\n");
        num1 = (victim->query_level()+26)/me->query_level();
	
	time = victim->query_temp("bribe_time") ; 
	num = 5*(1 + time*time)*num1;
	tp_cost = 65 - (skill / 6) - (5 * charm);
	if( !tp_cost || (int)me->query("talk_points") < (tp_cost + 1) )
		return notify_fail("�㽲��̫�໰�ˣ�����һ�仰��˵��������\n");
	if (me->query("wealth/gold")<num+1)
	        return notify_fail("��¸����ý�ң�����Ľ�Ҳ�����\n");
	else
		me->add("talk_points", -tp_cost );

	tell_object(me, set_color("��������֮�࣬˫������һ�ѽ�ң���ʼ��¸��Ķ��� ! \n", "HIC",me) );
	tell_object(victim, set_color("�㿴��"+me->query("c_name")+"����һ�����ĵ�Ц���ߵ�����ǰ��ͼ��¸��! \n", "HIC",victim) ); 
        tell_room( environment(me),
                me->query("c_name")+"������Ц���ߵ�"+
                victim->query("c_name")+"����ǰ��ͼ��¸����\n" ,({ me, victim }) );
        delay = 6 - skill/10 - (charm+1)/2;  
        if( delay < 0 ) delay = 1;
        else delay = 2;
               
	
	me->set_temp("bribe_busy",1);
	call_out("bribe_work", delay, me, victim, charm);
	return 1;
}

int bribe_work(object me, object victim, int charm)
{
	int my_kar,vic_int,level,vic_level,chance,skill,num,num1,time;
        string gold;
	
	me->delete_temp("bribe_busy");
	skill = me->query_skill("polemic");
	my_kar = me->query_stat("karma");
	vic_int = victim->query_stat("int");
        time = victim->query_temp("bribe_time");
        level = me->query_level();
        vic_level = victim->query_level();
	chance = my_kar-vic_int+level-2*vic_level;
	num1 = (victim->query_level()+26)/me->query_level();
	num = 5*(1 + time*time)*num1;
	if (me->query("wealth/gold")<num+1) 
	                return notify_fail("����Ϊ��ܴ�����??��ɵ�ˣ�\n");
	if ( ! me->query_attackers() || !victim || victim->query("hit_points") < 1) {
		tell_object(me,"���ս�������ˣ���Ҫ�˷�Ǯ��! \n");
		return 1;
	}
	if( skill+chance+random(3*charm)+random(skill) < vic_int+vic_level ) {
		tell_object(me,set_color("��ĵ��˺ܸ��˵Ľӹ������ϵĽ�ң�Ȼ���������!\n", "HIG",me) );
		tell_object(victim,set_color("��ҡͷ̾��: �����ķ��ӣ�����Ǯ����Ǯ����! \n", "HIC",victim) );
	        tell_room( environment(me),"\n"+
		victim->query("c_name")+"ҡͷ̾��: �����ķ��ӣ�����Ǯ����Ǯ����! \n\n" ,
	        ({ me, victim }) );
		me->add("wealth/gold",-num);
		victim->add("wealth/gold",num);
		return 1;
	}

        victim->remove_attacker(me);
        me->remove_attacker(victim);
//        me->cease_all_attacks();
        me->add("wealth/gold",-num);
	victim->add("wealth/gold",num);
	victim->add_temp("bribe_time",1);
	tell_object( me, set_color( 
		"��ɹ���˵�����ˣ���һЩ��һ������ݵĺ�ƽ....\n", "HIY",me) );
		
	tell_object(victim, set_color( 
		me->query("c_name")+"����һ��ѽ�ң��㿴���ۻ����ң�ɥʧ��50%��ս����־��\n", "HIM",victim));

	tell_room( environment(me), "\n"+
		me->query("c_name")+"�ó�һ��ѽ������"+
		victim->query("c_name")+"�����ϣ�ʹ����ֹͣ��"+me->query("c_name")+"�Ĺ�����\n\n" ,
		({ me, victim }) );
                return 1;
}
int help()
{
   write(
@C_HELP
ָ���ʽ: bribe 
   
���ָ��������������ս��ʱʹ�ý��ȥ��¸���ˣ���ʹ�������
��ĵ��⡣�ɹ��Ļ����뻨�ѵĽ����Ŀ��ʹ���߱���ı����й�
ͬʱҲ����˵������йأ���ʩ���ɹ������ȥһ������Ҫ��ս��
����ʧ�����㽫��ʧһ��Ǯ��
����õ�����ǰ��������Ļ�¸�����ٳɹ��Ļ�¸����Ҫ��������
����Ľ�Ǯ��
C_HELP
   );
   return 1;
}   
