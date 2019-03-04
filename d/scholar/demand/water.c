#define LEVEL 10
#define COST_SP 20

int summon_me(object me)
{
        if ( (int)me->query_skill("polemic")< LEVEL*5 ) {
          write("��ı������ܲ�����ʹˮ�����������㡣\n");
          return 1;
        }

        if ( (int)me->query_skill("yinyanglogy")< LEVEL*3 ) {
          write("�������ѧ���ܲ�����ʹˮ�����������㡣\n");
          return 1;
        }

	if ( (int)me->query("spell_points") < COST_SP ) {
	  write("��ľ��񲻼��ˣ�Ӧ�úú���Ϣһ�¡�\n");
	  return 1;
	}
        me->add("spell_points",-COST_SP);
        tell_object(me,set_color("�㼯�о���ʼ�������������ٻ�ˮ�����������㡣\n","HIB"));
        call_out("check_demand",2,me);
        me->set_temp("summon_busy",1);
        return 1;
}
 
void check_demand(object me)
{
  object mob;

  me->delete_temp("summon_busy");
  if (random(me->query_skill("polemic")+LEVEL)<=LEVEL)
    write("���ˮ����֮������鴫��û�гɹ�\���ٻ�ʧ�ܡ�\n");
  else {
    write("ˮ�������˵��û����...������������ҽ��!\n");
    tell_object(me,set_color("��������һ������Ʈ����ˮ�������Ʈ�˳�����ˮ�������ִ�������˿ڣ������һ��\n������ˮ��������������Ʈ���ˡ�\n","HIB"));
    tell_room(environment(me),set_color("�����"+me->query("c_name")+"����רע������һЩ���ͻȻ�����Ʈ��һ�����ƣ�һֻˮ����\nƮ�˳����������ˮ���������ȥ����"+me->query("c_name")+ "���˿�֮�ᣬ����������Ʈ���ˡ�\n","HIB"),me);
    me->set_temp("summon_rest",1);
    me->receive_healing(LEVEL+random(LEVEL));
    call_out("can_summon_again",random(LEVEL),me);
  }
  return;
}

void can_summon_again(object me)
{
  me->delete_temp("summon_rest");
  return;
}
