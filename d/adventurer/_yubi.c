//#pragma save_binary

#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit DAEMON;


int help();
int hang_work(object me, object target,object weapon);
int cmd_hang(string arg)
{
	object target,weapon,me,*who_fight;
	int sp_cost,level,skill;
	
	me = this_player();
	
	if( me->query_level() < 5 )
	        return notify_fail("�㵽���������?\n");
	if( me->query_temp("hang_busy") )
	        return notify_fail("����ר�ĵ�����������?\n");
	if ( ! arg ) return notify_fail("�����ɱ˭?\n");
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
	        write("��һ��������ɱ��\n");
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
        who_fight = (object *)target->query_attacker("who_protect");
        level = me->query_level();
        skill = me->query_skill("hang");
        sp_cost = 180 - level*2 - skill;
	
	if( !sp_cost || (int)me->query("spell_points") < (sp_cost + 1) )
		return notify_fail("��ľ���̫���ˣ��޷�ר�Ľ��н�ɱ��\n");
        if( !me->query_attacker(); ) { 

   	tell_object( me, set_color( 
		"��͵͵�������Ƶ�" + target->query("c_name") + "�ᣬ׼����ʱ����һ����ɱ..\n\n", "HIY",me) );
		
	tell_object(target, set_color( 
		me->query("c_name")+"͵͵�ߵ������棬��֪��Ҫ��ʲ��?\n\n", "HIM",target));

	tell_room( environment(me), "\n"+
		me->query("c_name")+"͵͵�������Ƶ�"+
		target->query("c_name")+"�����ᣬ��֪��Ҫ��ʲ��?\n\n" ,
		({ me, target }) );
        me->set("spell_points",(int)me->query("spell_points")-sp_cost);
        me->set_temp("hang_busy",1);
                call_out("hang_work", 3, me, target, weapon);
                return 1;
                       }
        write("����æ�ս�������ܷ���ȥ���������....\n");
                return 1;
}

int hang_work(object me, object target, object weapon)
{
   int dam,skill1,skill2,my_str,my_kar,wc;
   
   me->delete_temp("hang_busy");
   wc = weapon->query("weapon_class")/2;
   skill1 = me->query_skill("hang");
   skill2 = me->query_skill("anatomlogy");
   my_str = me->query_stat("str");
   my_kar = me->query_stat("kar");
   dam = my_str + my_kar - 3*(int)target->query_stat("dex") + skill2/2 + wc;
   if (dam < 10) dam = 10; 
   if (dam > 30) dam = 30;
   if (skill1/3 + skill2/5 + wc + random(my_kar) - 2*(int)target->query_stat("dex") < 0) {
      tell_object( me, set_color( 
		"\n ���������е�"+ weapon->query("c_name")+ "��" + target->query("c_name")+"���ӻ�ȥ\n"
		"��ϧ����������....\n\n" , "HIY",me) );
	tell_object(target, set_color("\n"+ 
		me->query("c_name")+"��Ҫ��"+weapon->query("c_name")+"��ɱ�㣬�����������ˡ�\n", "HIM",target));

	tell_room( environment(me), "\n"+
		me->query("c_name")+"�����е�"+weapon->query("c_name")+"����"+
		target->query("c_name")+"�Ĳ��ӣ�����û����Ŀ�ꡣ\n\n" ,
		({ me, target }) );
                me->set("stop_attack",2);
                target->kill_ob(me);
                me->kill_ob(target);
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
   target->set("stop_attack",4);
   target->receive_damage( dam );
   target->set("last_attacker", me );
   (CONDITION_PREFIX + "weak")->apply_effect( target, 2, 12 );
   target->kill_ob(me);
   me->kill_ob(target);
   return 1;
}
int help()
{
    write(
@C_LONG
ָ���ʽ: hang + <ָ������>

ʹ�ñ�������ʱ��ð������������ɱ���޽��ĵĵ��ˡ�
��ʩ���ɹ��������߲��������ܵ��˺��������������ݾ���ʱ��
�½��������ɻغ��޷������ж�����ʩ����Ϊά�ֽ�ɱ��Ч����
���軨�Ѵ����ľ������Կ��ƶԷ����ж���
C_LONG
    );
    return 1;
}    
