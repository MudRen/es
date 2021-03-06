#define LEVEL 4
#define COST_SP 8

int summon_me(object me)
{
        if ( (int)me->query_skill("polemic")< LEVEL*5 ) {
          write("你的辩术技能不够驱使草精灵来帮助你。\n");
          return 1;
        }

        if ( (int)me->query_skill("yinyanglogy")< LEVEL*3 ) {
          write("你的阴阳学技能不够驱使草精灵来帮助你。\n");
          return 1;
        }

	if ( (int)me->query("spell_points") < COST_SP ) {
	  write("你的精神不济了，应该好好休息一下。\n");
	  return 1;
	}
        me->add("spell_points",-COST_SP);
        tell_object(me,set_color("你集中精神开始利用心灵力量召唤草精灵来帮助你。\n","HIG"));
        call_out("check_demand",2,me);
        me->set_temp("summon_busy",1);
        return 1;
}
 
void check_demand(object me)
{
  object mob;

  me->delete_temp("summon_busy");
  if (random(me->query_skill("polemic")+LEVEL)<=LEVEL)
    write("你和草精灵之间的心灵传递没有成功\，召唤失败。\n");
  else {
    write("草精灵对你说：没问题...我马上来帮你医疗!\n");
    tell_object(me,set_color("你见到远处一个绿色的精灵站在一根草上飞了过来，草精灵将一片药草敷在你的伤口上，\n你觉的一阵刺痛，草精灵又随著风飞走了。\n","HIG"));
    tell_room(environment(me),set_color("你见到"+me->query("c_name")+"神情专注的念著一些咒语，你见到远处一个绿色的精灵站在一根草\n上飞了过来，草精灵将一片药草敷在"+me->query("c_name")+ "的伤口後，又随著风飞走了。\n","HIG"),me);
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
