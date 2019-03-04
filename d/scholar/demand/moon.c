#define LEVEL 15
#define NEED_SKILLS 75
#define COST_SP 30

int summon_me(object me)
{
        if ( (int)me->query_skill("polemic")< LEVEL*5 ) {
          write("��ı������ܲ�����ʹ�¹⾫���������㡣\n");
          return 1;
        }

        if ( (int)me->query_skill("yinyanglogy")< LEVEL*3 ) {
          write("�������ѧ���ܲ�����ʹ�¹⾫���������㡣\n");
          return 1;
        }

	if ( (int)me->query("spell_points") < COST_SP ) {
	  write("��ľ��񲻼��ˣ�Ӧ�úú���Ϣһ�¡�\n");
	  return 1;
	}
        me->add("spell_points",-COST_SP);
        tell_object(me,set_color("�㼯�о���ʼ�������������ٻ��¹⾫���������㡣\n","HIY"));
        call_out("check_demand",2,me);
        me->set_temp("summon_busy",1);
        return 1;
}
 
void check_demand(object me)
{
  object mob;

  me->delete_temp("summon_busy");
  if (random(me->query_skill("polemic"))<=LEVEL)
    write("����¹⾫��֮������鴫��û�гɹ�\���ٻ�ʧ�ܡ�\n");
  else {
    write("�¹⾫�����˵��û����...������������ҽ��!\n");
    tell_object(me,set_color("�����һ���ƹ�����ֱ��������¹⾫��������˳�����ͻȻ�¹⾫��ȫ��ų�һƬ\n��ɫ��â�������㣬��о�һ����ů���¹⾫������ʧ�ڻƹ�֮�С�\n","HIY"));
    tell_room(environment(me),set_color("�����"+me->query("c_name")+"����רע������һЩ���ͻȻһ���ƹ�������ֱ�������һֻ\n�¹⾫��������˳�����������¹⾫��ͻȻȫ��ų�һƬ��ɫ��â����"+me->query("c_name")+"֮�ᣬ\n����ʧ�ڻƹ�֮�С�\n","HIY"),me);
    me->set_temp("summon_rest",1);
    me->receive_healing(LEVEL+random(LEVEL));
    call_out("can_summon_again",5+random(LEVEL),me);    
  }
  return;
}

void can_summon_again(object me)
{
  me->delete_temp("summon_rest");
  return;
}
