//This is a green-magic spell for adventurer casting only 
// Made by Takeda 11.8.1995////#pragma save_binary

#include <mudlib.h>
#include "/d/adventurer/magic/adm/magic.c"


#define TYPE "green-magic"
#define find_rate 50

int query_sp_cost(object caster, int level, string target) {return 20 + level * 20; }

int query_need_skill(int level) { return 10+30*level; }

int modify_find_rate(object caster)
{
   if ( caster->query("player_invisible") )
      return (int)caster->query_level()/2;
      return 0;
}
int query_find_rate(object caster, object dest)
{
  if( !userp(dest) )
      return (int)dest->query_stat("int")*2 -
      (int)caster->query_stat("int") +
      modify_find_rate(caster)+
      (int)dest->query_stat("kar");
else
      return (int)dest->query_stat("int") -
      (int)caster->query_stat("int") +
      (int)dest->query_stat("kar");
}

int cast(int level, string target)
{
	int chinese_mode, delay_time;
	object me, dest;

    me = this_player();
	chinese_mode = can_read_chinese(me);
	
	if( (int)me->query_skill("green-magic") < query_need_skill(level) ) {
		tell_object(me,set_color("�����ħ�����ܲ�����ʹ����ȼ���ħ��!\n","HIG"));
		return 0;
	}
	
	  if( target=="NONE" && !(dest = me->query_attacker()) ) {
	  write( "Ҫ��˭ʩչ����ֹͣ����\n");
	  return 0;
	  } else {
	  if( !dest ) 
	  dest = present( target, environment(me) );
	  if( !dest ) {
	         write("���Ŀ�겢�������\n");
	         return 0;
	              }}                                       
	    if( !living(dest) ) {
	              write( "����ֹͣ����Ŀ����������\n");
	                    return 0;
	                        }
	          if( dest->query("no_attack") ) {
	                    write("��һﲻ��ɱ��\n");
	                    return 0;
	                    }
	          if( dest==me ) {
	                    write("����Դ�suicide �ȽϺá�\n");
	                    return 0; 
	                    } 
	          if( dest->query_level()<5 ) {
	                    write("���ֻ�˵��û������ζ...\n");
	                    return 0;
	                    }                       
	if( me->query("npc") && me->query("magic_delay") )
	    delay_time = (int)me->query("magic_delay");
	else
	    delay_time = 3;
	me->set("stop_attack",delay_time);
	me->set_temp("cast_busy", 1);
	tell_object(me,set_color("�㿪ʼ������ħ���л���ֹͣ��������....��\n","HIG",me));
	tell_room( environment(me),
		me->query("c_name") + "��ʼ������ħ���л���ֹͣ��������....��\n",
		me );
	call_out( "effect", delay_time, level, me, dest );
	if( !dest->query_attackers() &&
	        (random(find_rate)<query_find_rate(me,dest)) ) {
	        tell_object( me, dest->query("c_name")+
                "��������������������ʼ�����㡣\n" );
	tell_room( environment(dest),
	        dest->query("c_name")+"����"+me->query("c_name")+
	        "�����������������������\n", me
	        );
	        dest->kill_ob(me);
	        me->kill_ob(dest);
	return 1;
	}
	return 1;
}

void effect(int level, object caster, object dest)
{
	int power,duration;

	caster->set_temp("cast_busy", 0);
	
	if( !dest ) {
	      tell_object( caster,"�㷢�����Ŀ���Ѿ����ˡ�\n");
	      return;
	            }
	if( !dest || !present(dest, environment(caster)) ) {
	      tell_object( caster,"�㷢�����Ŀ���Ѿ��뿪�����ˡ�\n");
	      return;
	            }
	tell_room( environment(dest),
		"һЩ����ɫ�Ĺ�����"+dest->query("c_name")+"��������Ȼ������ʧ��\n",
		dest );
	tell_object( dest,"��ͻȻ��һ����ֵĸо���������ͻȻʧȥ�����е�������\n",dest );	
		dest->set_temp("stop_heal_hp",1);
		dest->set_temp("stop_heal_tp",1);
		dest->set_temp("stop_heal_sp",1);
		duration = (level+1) * 20 + (int)caster->query_stat("pie") * 4;
		dest->kill_ob(caster);
		caster->kill_ob(dest);
		call_out( "expire", duration, dest);
	}

void expire( object dest )
{
    if( !dest ) return;
	tell_object( dest,
		"�����ȫ��һ���泩��������������ֿ�ʼ��������..��\n"
    );
                 dest->set_temp("stop_heal_hp",0);
                 dest->set_temp("stop_heal_tp",0);
                 dest->set_temp("stop_heal_sp",0);
}
