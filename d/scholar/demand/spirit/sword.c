#include <mudlib.h>
#include <daemons.h>
#include <conditions.h>

#define COST_SP 3
#define END "/d/scholar/demand/spirit/end"
inherit MONSTER;
int life_time=15;
string name;
string str1="����˵���ҵ����ѡ��ұ���Ҫ���ˣ�������Ҫ�Ұ�æ���ٽ��ҡ�\n";
string str2="�㿴�����껯��һ�����������ȥ��\n";
string str3="HIW";

void create()
{
	::create();
	set_level(15);
	set_name( "sword spirit", "����" );
	add( "id", ({ "spirit" }) );
	set_short( "����" );
	set_long(
		"һ���ɹŴ��������ɵĻ��ǡ�\n"
	);
	set( "unit", "��" );
	set( "race", "monster" );
	set( "alignment",  800 );
        set( "tactic", "flank");
	set( "tactic_func", "my_tactic" );
        set_c_verbs( ({"%s����ֱ��%s","%s����б��%s","%s����ײ��%s"}) );
}

int environment_check()
{
  return 1;
}

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
        object victim;
        seteuid(getuid());
        me->set_temp("summon_rest",1);
        life = (int)me->query("spell_points")/COST_SP ;
        if (life < life_time )
                life_time = life ;
        this_object()->move(environment(me));
        tell_object(me,"�������˵��û����...��������������˵���!\n");
    tell_object(me,set_color("��о���һ������ֱ����������껯��һ�ѱ����ڿ��з�����Ԥ������һ�𹥻����ˡ�\n","HIW"));
    tell_room(environment(me),set_color("�����"+me->query("c_name")+"����רע������һЩ���ͻȻ��е�һ������ֱ����������껯��һ�ѱ����ڿ��з���������ʹ��"+me->query("c_name")+"�ĵ��˷���������\n","HIW"),me);
        victim=me->query_attacker();
        if (victim) {
          kill_ob(victim);
          victim->remove_attacker(this_object());
        }
        name=me->query("name");
        call_out("check_battle",1,me,this_object());
        return 1;
}

/*
void wait_get_exp(object me,object mob)
{
  END->bye_bye(me,mob,15,str1,str2,str3);
  return;
}
*/

void check_battle(object me,object mob)
{
  object tmp;
  if (!mob)
    return;
  if (!(tmp=find_living(name))||(tmp->query("npc"))) {
    tell_room(environment(mob),
      "��������������У���С�ӣ���Ȼ����QUIT����...\n"
      "˵��Ҳ������ʧ�ˡ�\n");
    mob->remove();
    return;
  }
  else if (!me->query_attacker()) {
    //call_out("wait_get_exp",1,me,mob);
    END->bye_bye(me,mob,15,str1,str2,str3);
    return;
  }
  else if ( !mob->query_attacker()) {
    END->bye_bye(me,mob,15,str1,str2,str3);
    return;
  }
  else if ( ! present(me,environment()) ) {
     END->bye_bye(me,mob,15,str1,str2,str3);
     return;
  }
  else
    call_out("check_battle",2,me,mob);
}

int my_tactic()
{
        object master,victim;
        int dam;

        master = (object)query_temp("master");
        if ((int)master->query("spell_points")<0)
           return END->bye_bye(master,this_object(),15,str1,str2,str3);
        master->add("spell_points",-COST_SP);
        if ( life_time-- < 0 ) 
           return END->bye_bye(master,this_object(),15,str1,str2,str3);
/*
        if ( ! present(master,environment()) ) {
          tell_object(master,"��������������У���С�ӣ����������ܣ�������Ҽ�־ ...\n");
          tell_room(environment(),"����е� : ���� ! "+master->query("c_name")+"�����С�Ӷ��������ˣ���ҲҪ���� ..\n");
          if ( !wizardp(master) )
            END->can_summon_again(master,15);
          else
            master->delete_temp("summon_rest");
          this_object()->init_attack();
          this_object()->remove();
          return 0;
        }
*/
	if( !(victim = query_attacker()) ) return 0;
	this_object()->execute_attack();
	if( random(20)<2 ) {
          dam=10+2*random(15);
//        if ( (int)victim->query("hit_points")<dam) return 0;
          BLEEDING->apply_effect(victim,3,5);
	  tell_room( environment(this_object()),
	    set_color("\n����ͻȻһ������Ԫ�����ѽ��Ľ����³��졢��������ɫ��â�������ȥ !\n\n","HIW",master)
	    , this_object()
            );
	  victim->receive_special_damage("energy", dam);
	}
	if (victim->query("last_attacker")==this_object())
	  victim->set("last_attacker",master);
	return 1;
}

int gain_experience(int exp)
{
        object master;
        if ( query_attacker() ) return 1;
        master = (object)this_object()->query_temp("master");
        if ( !present(master,environment()) )
                return END->bye_bye(master,this_object(),15,str1,str2,str3);
        if ( master->query_temp("leader") )
                PARTY_D->share_experience(master,exp ) ;
        else {
                        master->gain_experience(exp);
            tell_object(master,sprintf("��õ� %d �㾭��ֵ��\n",exp));
                        }
        return END->bye_bye(master,this_object(),15,str1,str2,str3);
}
