//This is a green-magic spell for adventurer casting only 
// Made by Takeda 11.10.1995////#pragma save_binary

#include <mudlib.h>
#include "/d/adventurer/magic/adm/magic.c"

#define TYPE "green-magic"
#define find_rate 70

int query_sp_cost(object caster, int level, string target) { return 20 + level * 10; }

int query_need_skill(int level) { return 15+10*level; }

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
      modify_find_rate(caster) +
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
	  write( "Ҫ��˭ʩչǣ������\n");
	  return 0;
	  } else {
	  if( !dest ) 
	  dest = present( target, environment(me) );
	  if( !dest ) {
	         write("���Ŀ�겢�������\n");
	         return 0;
	              }}                                       
	    if( !living(dest) ) {
	              write( "ǣ������Ŀ����������\n");
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
	          if( (!environment(me)->query("outside")) ) {
	                    write("�������ֻ��������ʩչ...\n");
	                    return 0;
	                    }
	if( me->query("npc") && me->query("magic_delay") )
	    delay_time = (int)me->query("magic_delay");
	else
	    delay_time = 3;
	me->set("stop_attack",delay_time);
	me->set_temp("cast_busy", 1);
	tell_object(me,set_color("�㿪ʼ������ħ����ǣ����������....��\n","HIG",me));
	tell_room( environment(me),
		me->query("c_name") + "��ʼ������ħ����ǣ����������....��\n",
		me );
	call_out( "effect", delay_time+1, level, me, dest );
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
    int time,skill1,skill2;
    object env;
    
    caster->set_temp("cast_busy", 0);
    if( !dest ) {
      tell_object( caster,"�㷢�����Ŀ���Ѿ����ˡ�\n");
      return;
    }
    env = environment(caster);
    if( !env || !present( dest, env ) ) {
      tell_object( caster,"�㷢�����Ŀ���Ѿ����������ˡ�\n");
      return;
    }

//need add some limit to modify the chance of success
		
		skill1 = caster->query_skill("target");
		skill2 = caster->query_skill("concentrate");
		
		if ( skill2 -5 < 20+level*3-random(5) ) {
                tell_room( environment(dest),
                "ͻȻ�����¡�𣬵��ܿ��ָֻ�ԭ״\n");
                return;
                }		
		if ( skill1 -5 < 30+level*2-random(5) ) {
		tell_room( environment(dest),
		"ͻȻһ��������ӽ�������������������һ��\n");
		return;
		}
		tell_object( dest,
			"ͻȻһ�������������������������㱻���ǽ�����ס����������....��\n"
		);
		time = level -1 + ((int)caster->query_stat("pie")/4);
		if (time < 2) time = 2; 
	
                dest->set_temp("block_defense", 1 );
                dest->set_temp("block_command", 1 );
	 tell_room( environment(dest),
		"ͻȻһ���������"+dest->query("c_name")+"������������������������ס��\n",
		dest );
		dest->kill_ob(caster);
		caster->kill_ob(dest);
		call_out( "expire", time, dest);
}

void expire( object dest )
{
    if( !dest ) return;
	tell_object( dest,
		"�������������Щ�ɶ���������ָ��ж������ɡ�\n"
    );
                 dest->delete_temp("block_defense");
                 dest->delete_temp("block_command");
        return ;         
}
