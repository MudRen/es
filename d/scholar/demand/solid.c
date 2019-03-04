#define LEVEL 19
#define NEED_SKILLS 95
#define COST_SP 38
#define SCHOLAR_SUMMON_SPIRIT "/d/scholar/demand/spirit/"

int summon_me(object me)
{
        if ( (int)me->query_skill("polemic")< LEVEL*5 ) {
          write("��ı������ܲ�����ʹ��ؾ����������㡣\n");
          return 1;
        }

        if ( (int)me->query_skill("yinyanglogy")< LEVEL*3 ) {
          write("�������ѧ���ܲ�����ʹ��ؾ����������㡣\n");
          return 1;
        }

	if ( (int)me->query("spell_points") < COST_SP ) {
	  write("��ľ��񲻼��ˣ�Ӧ�úú���Ϣһ�¡�\n");
	  return 1;
	}
        me->add("spell_points",-COST_SP);
        tell_object(me,set_color("�㼯�о���ʼ�������������ٻ���ؾ����������㡣\n","HIM"));
        call_out("check_demand",1,me);
        me->set_temp("summon_busy",1);
        return 1;
}
 
void check_demand(object me)
{
  object mob;

  me->delete_temp("summon_busy");
  if (random(me->query_skill("polemic")+LEVEL)<=LEVEL)
    write("��ʹ�ؾ���֮������鴫��û�гɹ�\���ٻ�ʧ�ܡ�\n");
  else {
    write("��ؾ������˵��û����...��������������˵���!\n");
    tell_object(me,set_color("���������ͻȻ�ѿ�����ؾ�����г��˳�������һ�𹥻����ˡ�\n","HIM"));
    tell_room(environment(me),set_color("�����"+me->query("c_name")+"����רע������һЩ���ͻȻ�ӵ����ѿ�������һ����ؾ���\n��"+me->query("c_name")+"�ĵ��˷���������\n","HIM"),me);
    me->set_temp("summon_rest",1);
    seteuid(getuid());
    mob=new(SCHOLAR_SUMMON_SPIRIT"solid_spirit");
    mob->move(environment(me));    
    mob->set("master",me);
    mob->kill_ob(me->query_attacker());
    call_out("check_battle1",1,me,mob);
    call_out("check_battle2",LEVEL+random(LEVEL),me,mob);
  }
  return;
}

void check_battle1(object me,object mob)
{
  if (!mob)
    return;
  if (!me->query_attacker()) {
    tell_object(me,"��ؾ���˵���ҵ����ѡ��ұ���Ҫ���ˣ�������Ҫ�Ұ�æ���ٽ��ҡ�\n");
    tell_room(environment(mob),set_color("������������˿�������ؾ������˽�ȥ��\n","HIM"));
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
    tell_object(me,"��ؾ���˵���ҵ����ѡ��ұ���Ҫ���ˣ�������Ҫ�Ұ�æ���ٽ��ҡ�\n");
    tell_room(environment(mob),set_color("������������˿�������ؾ������˽�ȥ��\n","HIM"));
    mob->remove();
    call_out("can_summon_again",random(LEVEL),me);
    return;
  }
  else 
    call_out("check_battle2",4,me,mob);
  return;
}

void can_summon_again(object me)
{
  me->delete_temp("summon_rest");
  return;
}
