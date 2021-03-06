#define LEVEL 19
#define NEED_SKILLS 95
#define COST_SP 38
#define SCHOLAR_SUMMON_SPIRIT "/d/scholar/demand/spirit/"

int summon_me(object me)
{
        if ( (int)me->query_skill("polemic")< LEVEL*5 ) {
          write("你的辩术技能不够驱使大地精灵来帮助你。\n");
          return 1;
        }

        if ( (int)me->query_skill("yinyanglogy")< LEVEL*3 ) {
          write("你的阴阳学技能不够驱使大地精灵来帮助你。\n");
          return 1;
        }

	if ( (int)me->query("spell_points") < COST_SP ) {
	  write("你的精神不济了，应该好好休息一下。\n");
	  return 1;
	}
        me->add("spell_points",-COST_SP);
        tell_object(me,set_color("你集中精神开始利用心灵力量召唤大地精灵来帮助你。\n","HIM"));
        call_out("check_demand",1,me);
        me->set_temp("summon_busy",1);
        return 1;
}
 
void check_demand(object me)
{
  object mob;

  me->delete_temp("summon_busy");
  if (random(me->query_skill("polemic")+LEVEL)<=LEVEL)
    write("你和大地精灵之间的心灵传递没有成功\，召唤失败。\n");
  else {
    write("大地精灵对你说：没问题...我马上来帮你击退敌人!\n");
    tell_object(me,set_color("你见到地面突然裂开，大地精灵从中冲了出来和你一起攻击敌人。\n","HIM"));
    tell_room(environment(me),set_color("你见到"+me->query("c_name")+"神情专注的念著一些咒语，突然从地面裂开，出现一个大地精灵\n对"+me->query("c_name")+"的敌人发动攻击。\n","HIM"),me);
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
    tell_object(me,"大地精灵说：我的朋友、我必须要走了，假如须要我帮忙请再叫我。\n");
    tell_room(environment(mob),set_color("你见到地面裂了开来，大地精灵钻了进去。\n","HIM"));
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
    tell_object(me,"大地精灵说：我的朋友、我必须要走了，假如须要我帮忙请再叫我。\n");
    tell_room(environment(mob),set_color("你见到地面裂了开来，大地精灵钻了进去。\n","HIM"));
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
