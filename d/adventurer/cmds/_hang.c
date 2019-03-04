//#pragma save_binary

#include <mudlib.h>
#include <stats.h>
#include <conditions.h>
#include <daemons.h>

inherit DAEMON;


int help();
int hang_work(object me, object target,object weapon);
int cmd_hang(string arg)
{
	object target,weapon,me;
	int num,sp_cost,level,skill;
	
	me = this_player();
	
	if( me->query_level() < 5 )
	        return notify_fail("�㵽���������?\n");
	if( me->query_temp("hang_busy") )
	        return notify_fail("����ר�ĵ����������¡�\n");
	if ( ! arg ) {
	     if (!me->query("adventurer_exp/hang")) write("��Ŀǰ�Խ�ɱһ�ϲ�ͨ...\n");
	     write("��Ŀǰ�Խ�ɱ����µ��������Ѿ���"+me->query("adventurer_exp/hang")+"����...\n");
	     return 1;
	     }
	if ( !(target = present( arg,environment(this_player()))) )
		return notify_fail("����û�н�"+arg+"�Ķ�����\n");
	if ( target == this_player() )
		return notify_fail("����Լ��߸ߵĹ���һ������....\n");
	if ( ! living(target) ) 
		return notify_fail("����������ס"
			+target->query("c_name")+"����ʲ����Ҳû������\n");
	if ( !visible(target,this_player()) || target->query("invisible_player") )
		return notify_fail("�����ɱ˭?\n");
	if ( !this_player()->query_vision() )
		return notify_fail("����һƬ��� ! ��ʲ��Ҳ������ !!\n");
	if( !skill = (int)me->query_skill("hang") )
	                return notify_fail( "��û��ѧ����ɱ����!!�޷���ɱ!!\n");
	if ( target->query("no_attack") ) {
	        write("��һ����ɱ��\n");
	        return 1;
	}
	if ( userp(target) ) {
		if ( (int)target->query_level()< 5 || 
			 (int)this_player()->query_level()<5 )
		return notify_fail("�㲻�� PK �� !!\n");
	}
	weapon = this_player()->query("weapon1");
	if ( !weapon )
		return notify_fail("��û���������޷���ɱ���� !!\n");	
	if ( (string)weapon->query("type") != "whip" )
		return notify_fail("������������֣��޷���ɱ !!\n");
        level = me->query_level();
        skill = me->query_skill("hang");
        num = me->query("adventurer_exp/hang")/2500;
        sp_cost = 180 - level*2 - skill - num ;
	if( sp_cost < 30 ) sp_cost = 30;
	
	if( !sp_cost || (int)me->query("spell_points") < (sp_cost + 1) )
		return notify_fail("��ľ���̫���ˣ��޷�ר�Ľ��н�ɱ��\n");

   	if( !me->query_attackers() ) {
   	tell_object( me, set_color( 
		"��͵͵�������Ƶ�" + target->query("c_name") + "�ᣬ׼����ʱ����һ����ɱ..\n\n", "HIY",me) );
		
	tell_object(target, set_color( 
		me->query("c_name")+"͵͵�ߵ������棬��֪��Ҫ��ʲ��?\n\n", "HIM",target));

	tell_room( environment(me), "\n"+
		me->query("c_name")+"͵͵�������Ƶ�"+
		target->query("c_name")+"�����ᣬ��֪��Ҫ��ʲ��?\n\n" ,
		({ me, target }) );
        me->add("spell_points",-sp_cost);
        me->set_temp("hang_busy",1);
                call_out("hang_work", 4, me, target, weapon);
                return 1;
                       }
        write("����æ�ս�������ܷ���ȥ���������....\n");
                return 1;
}

int hang_work(object me, object target, object weapon)
{
   int i,dam,dam1,skill1,skill2,my_str,wc,explore,total_points,EXPLORE1,time;
   object *who_fight;
   
   time = target->query_temp("hang_time");
   who_fight = (object *)target->query_attackers();
   me->delete_temp("hang_busy");
   wc = weapon->query("weapon_class")/2;
   explore  = (int)this_player()->query_explore_points();
   total_points=EXPLORE_D->query_total_explore();
   EXPLORE1=explore*40/total_points;
   if (EXPLORE1 > 40) EXPLORE1 = 40;
   skill1 = me->query_skill("hang");
   skill2 = me->query_skill("anatomlogy");
   my_str = me->query_stat("str");
   dam1 = my_str - 2*(int)target->query_stat("con") + skill2 + wc + EXPLORE1 ;
   dam = dam1*2/5  ;
   if (dam < 15) dam = 15; 
  
   if ( !present(target,environment(me)) ) {
   tell_object( me, set_color(
            "��! ��ͻȻ�������Ŀ�겻����?\n" , "HIY",me) );
   return 1;
   }                  
  
   //����Ϊ�˷������do ָ���ȥ�ٽ�����ɱ������Բ�����һ��ʼ�ĵط�check
   //�������/std/npc2.c    Takeda@ES  
   
      for( i=sizeof(who_fight)-1; i>=0; i-- ) {
      if ( who_fight[i]->query("name") == me->query("name") ) {
      
      tell_object( me, set_color(
               "���������е�"+ weapon->query("c_name")+ "��" + target->query("c_name")+"���ӻ�ȥ\n"
               "û�뵽���������������....������������ˤ���ڵ�\n" , "HIY",me) );
   
      tell_object(target, set_color("\n"+
         me->query("c_name")+"��Ҫ��"+weapon->query("c_name")+"��ɱ�㣬����ȴ�Լ�ˤ���ڵء�\n", "HIM",target));
 
      tell_room( environment(me), "\n"+
                   me->query("c_name")+"�����е�"+weapon->query("c_name")+"����"+target->query("c_name")+"�Ĳ��ӣ�����\n"
                   "����û����Ŀ�꣬�Լ������ȵ����ӵ�����\n\n" ,
                    ({ me, target }) );   
   me->kill_ob(target);
   me->block_attack(2);
   me->set_temp("msg_stop_attack", "�� ������ˤ���ڵ��޷����� ��\n\n");
   return 1;
   }
   else continue ;
   }
   
   
   if ( random(skill1/3) + skill2/3 + wc + random(EXPLORE1)/4 - 2*(int)target->query_stat("dex") - random(time) < 0) {
      tell_object( me, set_color( 
		"���������е�"+ weapon->query("c_name")+ "��" + target->query("c_name")+"���ӻ�ȥ��"
		"��ϧ����������....\n\n" , "HIY",me) );
	tell_object(target, set_color("\n"+ 
		me->query("c_name")+"��Ҫ��"+weapon->query("c_name")+"��ɱ�㣬�����������ˡ�\n", "HIM",target));

	tell_room( environment(me), "\n"+
		me->query("c_name")+"�����е�"+weapon->query("c_name")+"����"+
		target->query("c_name")+"�Ĳ��ӣ�����û����Ŀ�ꡣ\n\n" ,
		({ me, target }) );
                
                target->kill_ob(me);
                me->block_attack(2);
                me->set_temp("msg_stop_attack", "�� ��������æ�����޷����� ��\n\n");
                return 1;
       }
   	tell_object( me, set_color( 
		"��ɹ������е�" + weapon->query("c_name") + "��ɱ" + target->query("c_name") +
		"��ʹ���ܵ����ص��˺���\n\n", "HIY",me) );
		
	tell_object(target, set_color( "\n" +
		me->query("c_name")+ "�����е�" + weapon->query("c_name") + "��ס��Ĳ��ӡ�\n"
		"��о���һ����Ϣ���ʹ�ࡣ\n\n", "HIM",target));

	tell_room( environment(me), "\n"+
		me->query("c_name")+"�����е�"+ weapon->query("c_name") + "��ס" +
		target->query("c_name")+"�Ĳ��ӣ�ʹ����¶���ǳ�ʹ��ı��顣\n\n" ,
		({ me, target }) );
   target->kill_ob(me);
   target->block_attack(5);
   target->add_temp("hang_time",1);
   target->set_temp("msg_stop_attack", "�� ��ղű�"+me->query("c_name")+"��ɱ��ʹ����δ�ָ����޷�����...\n\n");
   target->receive_damage( dam );
   target->set("last_attacker", me );
   (CONDITION_PREFIX + "weak")->apply_effect( target, 2, 10 );
   me->add("adventurer_exp/hang",(int)dam/2 + target->query_level());
   return 1;
}
int help()
{
    write(
@C_LONG
ָ���ʽ: hang + <ָ������>
�����Ӷ�����Ϊ��ѯ��Խ�ɱ��������

ʹ�ñ�������ʱ��ð������������ɱ���޽��ĵĵ��ˡ�
��ʩ���ɹ��������߲��������ܵ��˺�������������ʱ�Դ���
�½��������ɻغ��޷������ж�����ʩ����Ϊά�ֽ�ɱ��Ч����
���軨�Ѵ����ľ������Կ��ƶԷ����ж���
C_LONG
    );
    return 1;
}    
