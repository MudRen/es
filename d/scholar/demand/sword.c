#define LEVEL 16
#define NEED_SKILLS 80
#define COST_SP 32
#define SCHOLAR_SUMMON_SPIRIT "/d/scholar/demand/spirit/"

int summon_me(object me)
{
        if ( (int)me->query_skill("polemic")< LEVEL*5 ) {
          write("��ı������ܲ�����ʹ�����������㡣\n");
          return 1;
        }

        if ( (int)me->query_skill("yinyanglogy")< LEVEL*3 ) {
          write("�������ѧ���ܲ�����ʹ�����������㡣\n");
          return 1;
        }

	if ( (int)me->query("spell_points") < COST_SP ) {
	  write("��ľ��񲻼��ˣ�Ӧ�úú���Ϣһ�¡�\n");
	  return 1;
	}
        me->add("spell_points",-COST_SP);
        tell_object(me,set_color("�㼯�о���ʼ�������������ٻ������������㡣\n","HIW"));
        call_out("check_demand",1,me);
        me->set_temp("summon_busy",1);
        return 1;
}
 
void check_demand(object me)
{
  object mob;

  me->delete_temp("summon_busy");
  if (random(me->query_skill("polemic")+LEVEL)<=LEVEL)
    write("��ͽ���֮������鴫��û�гɹ�\���ٻ�ʧ�ܡ�\n");
  else {
    write("�������˵��û����...��������������˵���!\n");
    tell_object(me,set_color("��о���һ������ֱ����������껯��һ�ѱ����ڿ��з�����Ԥ������һ�𹥻����ˡ�\n","HIW"));
    tell_room(environment(me),set_color("�����"+me->query("c_name")+"����רע������һЩ���ͻȻ��е�һ������ֱ����������껯��һ�ѱ����ڿ��з���������ʼ��"+me->query("c_name")+"�ĵ��˷�������\n","HIW"),me);
    me->set_temp("summon_rest",1);
    seteuid(getuid());
    mob=new(SCHOLAR_SUMMON_SPIRIT"sword_spirit");
    mob->move(environment(me));    
    mob->set("master",me);
    mob->kill_ob(me->query_attacker());
    call_out("check_battle1",1,me,mob);
    call_out("check_battle2",random(LEVEL),me,mob);
  }
  return;
}

void check_battle1(object me,object mob)
{
  if (!mob)
    return;
  if (!me->query_attacker()) {
    tell_room(environment(mob),set_color("�㿴�����껯��һ�����������ȥ��\n","HIW"));
    tell_object(me,"����˵���ҵ����ѡ��ұ���Ҫ���ˣ�������Ҫ�Ұ�æ���ٽ��ҡ�\n");
    mob->remove();
    call_out("can_summon_again",random(LEVEL),me);
    return;
  }
  else
    call_out("check_battle1",1,me,mob);
}

void check_battle2(object me,object mob)
{
  if (!mob)
    return;
  if (random(me->query_skill("polemic")+LEVEL)<=LEVEL) {
    tell_object(me,"����˵���ҵ����ѡ��ұ���Ҫ���ˣ�������Ҫ�Ұ�æ���ٽ��ҡ�\n");
    tell_room(environment(mob),set_color("�㿴�����껯��һ�����������ȥ��\��\n","HIW"));
    mob->remove();
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
