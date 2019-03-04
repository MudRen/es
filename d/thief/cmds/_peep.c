//#pragma save_binary

#include <mudlib.h>
#define RATE ({ 5,20,32,41,47,50,53,59,68,80,95, })

inherit DAEMON;

int peep_idle(object me,int succeed,object target,object item)
{
	mapping wealth ;
	string *coins;
	int i,coin;
	
	me->set_temp("peeped",0);
	if ( nullp(target) )
		return notify_fail("��Ҫ͵���Ķ����Ѿ����������� !!\n");
	if ( target && !present(target,environment(me)) ) 
		return notify_fail("��Ҫ͵���Ķ����Ѿ����������� !!\n");
	if ( succeed ) {
		tell_object(me,set_color(
		sprintf("����%s�������ʱ���㾡��Ĵ���%s ...\n",
			target->query("c_name"),
			( !item ? target->query("c_name") : item->query("c_name") ))
			,"HIY") );
		me->set_temp("peeping",1);
	} else
	{
	tell_object(me,set_color(
		sprintf("%sͻȻת��ͷ�ݺݵص�����һ�ۣ��������������ͼ ...\n",
			target->query("c_name")),"HIM") );
	tell_object(target,set_color(
		sprintf("��ͻȻ�е��������쬵ģ�����������͵���� ...\n"),"HIY") );
	me->delete_temp("peeping");
	return 1;
	}
	if ( ! item ) {
		tell_object(me,"/cmds/std/_look"->living_description(me,target));
		me->delete_temp("peeping");
	// if succeed can look money .. :P)
		if ( succeed && wealth = target->query("wealth")) {
//			wealth = target->query("wealth");
			
			coins = keys(wealth);
			for ( i=0 ,coin = 0; i < sizeof(coins) ; i++ )
				coin += wealth[coins[i]] ;
			if ( coin ) 
				printf("\n%s�ı����ﻹ�� %d öǮ�ҡ�\n",target->query("c_name"),coin);	
			else
				printf("\n%s���޷��ġ�\n",target->query("c_name"));
		}
		return 1;
	}
	if ( succeed )
		tell_object(me,item->query("long"));
	return 1;
}
int check_peep(object me,object target)
{
	int iq,kar,level,rate;

//	level = (int)this_player()->query_level();
	iq = (int)me->query_stat("int") - (int)target->query("int");
	kar = (int)me->query_stat("kar") - (int)target->query("kar");
	level = (int)me->query_skill("peep")/5 - (int)target->query_level() + 1;
	level = (level < 0 ? 0 : level);
	level = ( level > 10 ? 10 : level );
   	rate = RATE[level] + iq + kar + kar;
//	rate = rate * (int) me->query_skill("peep")/100;
   	rate = ( rate > 95 ? 95 : rate ) ;
   	if ( random(100) < rate )
   		return 1;
   	else
   		return 0;
}
int cmd_peep(string arg)
{
	string tmp1,tmp2;
	object target,item;

	if ( this_player()->query_temp("peeped") )
		return notify_fail("������Ŭ��͵���� ...\n");
	if ( ! arg )
		return notify_fail("��Ҫ͵��ʲ�᣿\n");

	item = 0;
	if ( sscanf( arg,"%s of %s",tmp1,tmp2) == 2 ) {
		if ( ! target = present(tmp2,environment(this_player()) ) )
			return notify_fail("����û�н�"+tmp2+"�����\n");
		if ( ! living(target) )
			return notify_fail("����û�н�"+tmp2+"�����\n");
		if ( ! item = present(tmp1,target ) )
			return notify_fail(target->query("c_name")+"û�д�����"+tmp1+"�Ķ�����\n");
	}
	else {
	if ( ! target = present(arg,environment(this_player()) ))
		return notify_fail("����û�н�"+arg+"�Ķ�����\n");
	if ( ! living(target) )
		return notify_fail("����û�н�"+arg+"�����\n");
	}
//	if ( target == this_player() )
//		return notify_fail("��������Ү, peep �Լ�, ��̬��?\n");

	write(set_color(sprintf("�㿪ʼ���۽ǵ��Ź�͵͵����%s��һ��һ����\n",
			target->query("c_name")),"HIY"));
	this_player()->set_temp("peeped",1);
	call_out("peep_idle",3,this_player(),check_peep(this_player(),target)
				,target,item );
	return 1;
}

int help()
{
	write (@HELP
Usage: peep <target>
       peep <object> of <target>

���ָ����ʹ���ڱ��˺���֪���������͵������״����Я������Ʒ����Ǯ
��������������ӵ����ݡ�������"��"���˵Ķ���֮ǰ����������ȹ۲��
��ĺ�ϰ�ߣ����������Ǻ����ױ����ֵġ�

HELP
);
	return 1;
}
