#define LEVEL 4
#define COST_SP 8

int summon_me(object me)
{
        if ( (int)me->query_skill("polemic")< LEVEL*5 ) {
          write("��ı������ܲ�����ʹ�ݾ����������㡣\n");
          return 1;
        }

        if ( (int)me->query_skill("yinyanglogy")< LEVEL*3 ) {
          write("�������ѧ���ܲ�����ʹ�ݾ����������㡣\n");
          return 1;
        }

	if ( (int)me->query("spell_points") < COST_SP ) {
	  write("��ľ��񲻼��ˣ�Ӧ�úú���Ϣһ�¡�\n");
	  return 1;
	}
        me->add("spell_points",-COST_SP);
        tell_object(me,set_color("�㼯�о���ʼ�������������ٻ��ݾ����������㡣\n","HIG"));
        call_out("check_demand",2,me);
        me->set_temp("summon_busy",1);
        return 1;
}
 
void check_demand(object me)
{
  object mob;

  me->delete_temp("summon_busy");
  if (random(me->query_skill("polemic")+LEVEL)<=LEVEL)
    write("��Ͳݾ���֮������鴫��û�гɹ�\���ٻ�ʧ�ܡ�\n");
  else {
    write("�ݾ������˵��û����...������������ҽ��!\n");
    tell_object(me,set_color("�����Զ��һ����ɫ�ľ���վ��һ�����Ϸ��˹������ݾ��齫һƬҩ�ݷ�������˿��ϣ�\n�����һ���ʹ���ݾ���������������ˡ�\n","HIG"));
    tell_room(environment(me),set_color("�����"+me->query("c_name")+"����רע������һЩ��������Զ��һ����ɫ�ľ���վ��һ����\n�Ϸ��˹������ݾ��齫һƬҩ�ݷ���"+me->query("c_name")+ "���˿��ᣬ������������ˡ�\n","HIG"),me);
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
