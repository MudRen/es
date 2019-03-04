#include <mudlib.h>
#include <daemons.h>
#define COST_SP 2 
#define END "/d/scholar/demand/spirit/end"
inherit MONSTER;
int life_time = 13;
string name;
string str1="����˵���ҵ����ѡ��ұ���Ҫ���ˣ�������Ҫ�Ұ�æ���ٽ��ҡ�\n";
string str2="��������黯��һ�ź�������շ�ȥ��\n";
string str3="HIR";

void create()
{
	::create();
	set_level(13);
	set_name( "fire spirit", "����" );
	add( "id", ({ "spirit" }) );
	set_short( "����" );
	set_long(
		"һ��ȫ��ͨ��ð�����ͷ�ϰ��˸�������ľ��顣\n"
	);
	set( "unit", "��" );
	set( "race", "elf" );
	set( "alignment",  800 );
        set( "tactic", "flank");
	set( "tactic_func", "my_tactic" );
        set_c_verbs( ({"%sͨ����ֱ�ͻȻ������ץ��%s",
                       "%s����һָ��һ�������%s",
                       "%s��˫����%s���������ɫ�Ĺ�â"}) );
// ���鲻�ٻᱻ����������Ҫ�����
//	set_skill( "dodge", 80 );
}

int environment_check()
{
  return 1;
}

// ���Ҳ����Ҫ��
/*
int receive_damage(int damage)
{
       int hits;
       object act_ob,master;

       master=(object)query_temp("master");
       hits = (int)master->query("hit_points");
       act_ob = previous_object();
       if( act_ob && living(act_ob) ) set("last_attacker", act_ob);
       if( damage <= 0 || link_data("dead") || hits < 1 || query("linkdead") )
                return 0;
       hits -= damage/2;
       master->set( "hit_points", hits );
       set( "hit_points", hits);
       seteuid(getuid());
       tell_object(master," ( ��"+(string)"/adm/daemons/statsd"->c_status_string(master)+" )\n");
       return 1;
}
*/
int my_action(object me)
{
	int life;
	object victim ;
 	seteuid(getuid());
	me->set_temp("summon_rest",1);
	life = (int)me->query("spell_points")/COST_SP ;
	if (life < life_time ) 
		life_time = life ;
	this_object()->move(environment(me));
	tell_object(me,"�������˵��û����...��������������˵���!\n");
	tell_object(me,set_color("ͻȻ����һ������������Ю������֮�ƴ����������һ�𹥻����ˡ�\n","HIR"));
	tell_room(environment(me),
	set_color("�����"+me->query("c_name")+
	"����һЩ���ͻȻ����һ��������\nһֻ����Ю������֮�ƴ��������"+
	me->query("c_name")+"�ĵ��˷���������\n","HIR"),me);
	victim = me->query_attacker();
        if (victim) {
	  kill_ob(victim);
// �����У����鲻�ڵ��˹���Ŀ��֮�ڣ�������Զ���ᱻ��
	  victim->remove_attacker(this_object());
        }
        name=me->query("name");
        call_out("check_battle",1,me,this_object());
	return 1;
}

// ��delay�ķ�ʽ��gain_exp���껹�ǻ���һЩ����.
/*
void wait_get_exp(object me,object mob)
{
  END->bye_bye(me,mob,13,str1,str2,str3);
  return;
}
*/

void check_battle(object me,object mob)
{
  object tmp;
  if ((!mob)||(!me))
    return;
  if (!(tmp=find_living(name))||(tmp->query("npc"))) {
    tell_room(environment(mob),
      "��������������У���С�ӣ���Ȼ����QUIT����...\n"
      "˵��Ҳ������ʧ�ˡ�\n");
    mob->remove();
    return;
  }
  else if (!me->query_attacker()) {
  //  ֱ����ʧ���� . player
  //  call_out("wait_get_exp",5,me,mob);
    END->bye_bye(me,mob,13,str1,str2,str3);
    return;
  }
  else if (!mob->query_attacker()) {
    END->bye_bye(me,mob,13,str1,str2,str3);
  }
  else if ( ! present(me,environment()) ) {
     END->bye_bye(me,mob,13,str1,str2,str3);
     return;
  }
  else
    call_out("check_battle",2,me,mob);
// �ж���һ������ : life time�����Ǿ�������Ϊ������ս�����غ���
// ��ÿ�� call my_tactic ʱ�����һ ( ��Ϊ my_tactic ÿ�غ� call һ��)
// ������ֻҪ��� life �Ϳ����ˣ���һ��Ҫʹ�� call_out ...
// ����������һ������Ŀ��� ..
}

int my_tactic()
{
	object master,victim;
	int dam;
	
	master = (object)query_temp("master");
        if (!master) return 1;
        if ((int)master->query("spell_points")<0)
           return END->bye_bye(master,this_object(),13,str1,str2,str3);
	master->add("spell_points",-COST_SP);
	if ( life_time-- < 0 ) 
          return END->bye_bye(master,this_object(),13,str1,str2,str3);
/*	if ( ! present(master,environment()) ) {
	  tell_object(master,"��������������У���С�ӣ����������ܣ�������Ҽ�־ ...\n");
	  tell_room(environment(),"����е� : ���� ! "+master->query("c_name")+"�����С�Ӷ��������ˣ���ҲҪ���� ..\n");
	  if ( !wizardp(master) )
  	    END->can_summon_again(master,13);
	  else
	    master->delete_temp("summon_rest");
          this_object()->init_attack();
   remove();
	  return 0;
	}
*/
	if( !(victim = query_attacker()) ) return 0;
        this_object()->execute_attack(0);
	if( random(20)<2 ) {
           dam = 10 + 2*random(13);

// ������ȷ�� mob ���ᱻ��������⹥������ ... ���˻�ò�������
//           if ( (int)victim->query("hit_points") < dam ) return 0;
// ����Ӧ�ò���������������. player 

// set_color() ʱ������������Ϊ�ж���ɫ�Ķ���������裬������ֻ����
// �����Ϊʲ����ʱ�򿴲�����ɫ��ԭ����� master ���� 
	  tell_room( environment(this_object()),
	    set_color("\n����ѿ�һ�ţ����������һ�Ż���������� !\n\n","HIR",master)
            , this_object()
	    );
          victim->receive_special_damage("fire", dam);
        }
        if (victim->query("last_attacker")==this_object())
          victim->set("last_attacker",master);
	return 1;
}

// ���ڲ�����spiritִ��gain_experience()��
/*
int gain_experience(int exp)
{
	object master;
	if ( query_attacker() ) return 1;
	master = (object)this_object()->query_temp("master");
	if ( !present(master,environment()) ) {
		return END->bye_bye(master,this_object(),13,str1,str2,str3);
	}
	if ( master->query_temp("leader") ) 
		PARTY_D->share_experience(master,exp ) ;
	else {
			master->gain_experience(exp);
            tell_object(master,sprintf("��õ� %d �㾭��ֵ��\n",exp));
 			}
 	return END->bye_bye(master,this_object(),13,str1,str2,str3);
}	
*/
