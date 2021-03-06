// This is a spell magic-cube. By Yueh 1995/3/2
// magic-cube  weight 0, prevent_insert, prevent_put_money, wieght_apply 0,
//		prevent_drop, One magician can have only one cube.
//		Using modify_damage() to modify max_load
// level	0	1	2
// cost		60	80	100
// max_load	400	600	800
// skill	20	40	60
// G_LVL	20	30	40
// G_EXP	50	75	100
// mininum of max_load 50
#include <mudlib.h>
#include "/d/magic/magic.c"
#define TYPE "misc"

inherit DAEMON;

int query_gain_spell_exp(int level)
{
	switch( level ) {
		case 0 : return  50;
		case 1 : return  75;
		case 2 : return 100;
		default : return 0;
	}
}

int query_need_spell_level(int level)
{
	switch( level ) {
		case 0 : return 20;
		case 1 : return 30;
		case 2 : return 40;
		default : return 99;
	}
}

int query_sp_cost(object caster, int level)
{
	return modify_sp_cost(caster, 60+20*level, TYPE, query_need_spell_level(level));
}

int query_need_skill(int level) { return 20+20*level; }

void effect( object caster, int level )
{
	object ob;
	int m_load;
	string c_name;
	c_name=caster->query("c_name");
	ob = new("/d/magic/misc/cube");
    if( level < 1 ) { 
      tell_object( caster, set_color("你口中念念有词，一个发著奇异光芒的魔法方块出现在你的身旁。\n","HIW"));

	  tell_room( environment(caster), sprintf("%s口中念念有词，一个发著奇异光芒的魔法方块出现在他的身旁。\n",c_name) ,caster);
	m_load = modify_damage(caster, 400, TYPE, 20);
	if (m_load < 50) m_load = 50;
	ob->set("max_load",m_load);
	ob->move(caster);
	} else if( level < 2 ) {
	  tell_object( caster, set_color("你口中念念有词，一个发著奇异光芒的大型魔法方块出现在你的身旁。\n","HIW"));

	  tell_room( environment(caster), sprintf("%s口中念念有词，一个发著奇异光芒的大型魔法方块出现在他的身旁。\n",c_name) ,caster);
	m_load = modify_damage(caster, 600, TYPE, 30);
	if (m_load < 50) m_load = 50;
	ob->set("max_load",m_load);
	ob->move(caster);
	} else if( level < 3 ) {
      	  tell_object( caster, set_color("你口中念念有词，一个发著奇异光芒的巨大魔法方块出现在你的身旁。\n","HIW"));
	  tell_room( environment(caster), sprintf("%s口中念念有词，一个发著奇异光芒的巨大魔法方块出现在他的身旁。\n",c_name) ,caster);
	m_load = modify_damage(caster, 800, TYPE, 40);
	if (m_load < 50) m_load = 50;
	ob->set("max_load",m_load);
	ob->move(caster);
	}
}

int cast(int level)
{
	object me;
	
	me = this_player();

	if( (int)me->query_skill(TYPE) < query_need_skill(level) ) {
	  tell_object( me, sprintf("你的%s技能不足以使用这等级的魔法! \n" ,to_chinese(TYPE)));
      return 0;
    }

    if( present("magic cube",me)) {
      tell_object( me, "你已经制造出一个魔法方块了，别浪费法力了。\n");
      return 0;
    }

	effect(me, level);
	me->set_temp("magic-cube", 1);
	gain_spell_experience(me, TYPE, query_gain_spell_exp(level));
	return 1;
}

