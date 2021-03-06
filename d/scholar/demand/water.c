#define LEVEL 10
#define COST_SP 20

int summon_me(object me)
{
        if ( (int)me->query_skill("polemic")< LEVEL*5 ) {
          write("你的辩术技能不够驱使水精灵来帮助你。\n");
          return 1;
        }

        if ( (int)me->query_skill("yinyanglogy")< LEVEL*3 ) {
          write("你的阴阳学技能不够驱使水精灵来帮助你。\n");
          return 1;
        }

	if ( (int)me->query("spell_points") < COST_SP ) {
	  write("你的精神不济了，应该好好休息一下。\n");
	  return 1;
	}
        me->add("spell_points",-COST_SP);
        tell_object(me,set_color("你集中精神开始利用心灵力量召唤水精灵来帮助你。\n","HIB"));
        call_out("check_demand",2,me);
        me->set_temp("summon_busy",1);
        return 1;
}
 
void check_demand(object me)
{
  object mob;

  me->delete_temp("summon_busy");
  if (random(me->query_skill("polemic")+LEVEL)<=LEVEL)
    write("你和水精灵之间的心灵传递没有成功\，召唤失败。\n");
  else {
    write("水精灵对你说：没问题...我马上来帮你医疗!\n");
    tell_object(me,set_color("你见到天空一朵乌云飘来，水精灵从中飘了出来，水精灵用手触摸你的伤口，你觉的一阵\n冰凉，水精灵又随著乌云飘走了。\n","HIB"));
    tell_room(environment(me),set_color("你见到"+me->query("c_name")+"神情专注的念著一些咒语，突然天空中飘来一朵乌云，一只水精灵\n飘了出来，你见到水精灵伸出手去触摸"+me->query("c_name")+ "的伤口之後，又随著乌云飘走了。\n","HIB"),me);
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
