#define LEVEL 17
#define AC_EFFECT 25
#define DB_EFFECT 15
#define WC_EFFECT 15
#define WEAPON_CLASS1 15
#define WEAPON_CLASS2 10
#define COST_SP 34

void add_effect(object me)
{
  int i ;

  me->set_temp("extra_ac/body",AC_EFFECT+(int)me->query_temp("extra_ac/body"));
  me->set_temp("extra_db/body",DB_EFFECT+(int)me->query_temp("extra_db/body"));
  me->calc_armor_class();
  me->set_temp("extra_wc",(int)me->query_temp("extra_wc")+WC_EFFECT);
  me->set("weapon_class1",(int)me->query("weapon_class1")+WEAPON_CLASS1);
  me->set("weapon_class2",(int)me->query("weapon_class2")+WEAPON_CLASS2);
  return;
}

void remove_effect(object me)
{
  int i;

  me->set_temp("extra_ac/body",(int)me->query_temp("extra_ac/body")-AC_EFFECT);
  me->set_temp("extra_db/body",(int)me->query_temp("extra_db/body")-DB_EFFECT);
  me->calc_armor_class();
  me->set_temp("extra_wc",(int)me->query_temp("extra_wc")-WC_EFFECT);
  me->set("weapon_class1",(int)me->query("weapon_class1")-WEAPON_CLASS1);
  me->set("weapon_class2",(int)me->query("weapon_class2")-WEAPON_CLASS2);
  return ;
}

int summon_me(object me)
{
        if ( (int)me->query_skill("polemic")< LEVEL*5 ) {
          write("��ı������ܲ�����ʹ�ڰ������������㡣\n");
          return 1;
        }

        if ( (int)me->query_skill("yinyanglogy")< LEVEL*3 ) {
          write("�������ѧ���ܲ�����ʹ�ڰ������������㡣\n");
          return 1;
        }

	if ( (int)me->query("spell_points") < COST_SP ) {
	  write("��ľ��񲻼��ˣ�Ӧ�úú���Ϣһ�¡�\n");
	  return 1;
	}
        me->add("spell_points",-COST_SP);
        tell_object(me,set_color("�㼯�о���ʼ�������������ٻ��ڰ������������㡣\n","HIW"));
        call_out("check_demand",1,me);
        me->set_temp("summon_busy",1);
        return 1;
}
 
void check_demand(object me)
{
  object mob;

  me->delete_temp("summon_busy");
  if (random(me->query_skill("polemic")+LEVEL)<=LEVEL)
    write("��ͺڰ�����֮������鴫��û�гɹ�\���ٻ�ʧ�ܡ�\n");
  else {
    write("�ڰ��������˵��û����...����������������ս��Ǳ��!\n");
    tell_object(me,set_color("һ�ź���Ʈ�˹���������������ڰ��������˵:�����ð��ڶ������������ս������ ! ��֪������ʩ��ʲ�ᷨ������ͻȻ�����Լ��ľ���������\n","HIW"));
    tell_room(environment(me),set_color("�����"+me->query("c_name")+"����רע������һЩ���һ�ź���Ʈ�˹���������ԼԼ���Կ���һֻ�ڰ���������"+me->query("c_name")+"��֪��ʩʲ�ᷨ����\n","HIW"),me);
    add_effect(me);
    me->set_temp("summon_rest",1);
    call_out("check_battle",LEVEL+random(LEVEL),me,mob);
  }
  return;
}

void check_battle(object me,object mob)
{
  if (!me->query_attacker()) {
    write("�ڰ�����˵���ҵ����ѡ��ұ���Ҫ���ˣ�������Ҫ�Ұ�æ���ٽ��ҡ�\n"); 
    tell_room(environment(me),set_color("������ڰ���������������ɢ���ˡ�\n","HIW"));
    remove_effect(me);
    call_out("can_summon_again",random(LEVEL),me);
    return;
  }
  if (random(me->query_skill("polemic")+LEVEL)<=LEVEL) {
    write("�ڰ�����˵���ҵ����ѡ��ұ���Ҫ���ˣ�������Ҫ�Ұ�æ���ٽ��ҡ�\n");
    tell_room(environment(me),set_color("������ڰ���������������ɢ���ˡ�\n","HIW"));
    remove_effect(me);
    call_out("can_summon_again",random(LEVEL),me);
    return;
  }
  else 
    call_out("check_battle",4,me,mob);
  return;
}

void can_summon_again(object me)
{
  me->delete_temp("summon_rest");
  return;
}
