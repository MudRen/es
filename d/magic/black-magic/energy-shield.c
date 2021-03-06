// This is a spell object. type -> other (defense   energy).
// level    0    1    2    3    4        (reverse electric)
// cost    30   45   60   75   90 when spell_level enough
// dec     10   20   35   55   60
// rev_dec  5    7   10   20    0
// time     2    5    8   12    8 * magic_shield skill
// skill   40   55   70   85  100
// G_LVL    4   10   18   28   40
// G_EXP    2    5   10   20   40
#include <mudlib.h>
#include "/d/magic/magic.c"
#define TYPE "black-magic"

inherit DAEMON;

int query_need_spell_level(int level)
{
	switch( level ) {
		case 0 : return  4;
		case 1 : return 10;
		case 2 : return 18;
		case 3 : return 28;
		case 4 : return 40;
		default : return 99;
	}
}

int query_gain_spell_exp(int level)
{
	switch( level ) {
		case 0 : return  2;
		case 1 : return  5;
		case 2 : return 10;
		case 3 : return 20;
		case 4 : return 40;
		default : return 0;
	}
}

int query_sp_cost(object caster, int level)
{
	return modify_sp_cost(caster, 30+15*level, TYPE, query_need_spell_level(level));
}

int query_need_skill(int level) { return 40+15*level; }

int query_delay_time( object caster, int level )
{
    int skill, time;
    skill = (int)caster->query_skill("magic-shield");
    switch( level ) {
      case 1 : time =  5*skill;  break;
      case 2 : time =  8*skill;  break;
      case 3 : time = 12*skill;  break;
      case 4 : time =  8*skill;  break;
     default : time =  2*skill;  break;
    }
    return modify_delay_time(caster, time, TYPE, query_need_spell_level(level));
}

int query_proportion(int level)
{
    switch( level ) {
      case 1 : return   20;
      case 2 : return   35;
      case 3 : return   55;
      case 4 : return   60;
     default : return   10;  
    }
}

int query_reverse_proportion(int level)
{
    switch( level ) {
      case 1 : return    7;
      case 2 : return   10;
      case 3 : return   20;
      case 4 : return    0;
     default : return    5;  
    }
}

int cast(int level)
{
	object me;
	
	me = this_player();

	if( (int)me->query_skill(TYPE) < query_need_skill(level) ) {
	  tell_object( me,         "你的"+to_chinese(TYPE)+"技能不足以使用这等级的魔法! \n" 
      );
      return 0;
    }
    if( me->query_temp("effect/energy-shield") ) {
      tell_object( me,
        "你上一个魔法能源盾还没消失呢! 别浪费法力了。\n" 
      );
      return 0;
    }
	write( 
		"你施展能源障壁咒文，一股奇异的能源在你的面前逐渐形成一层无形的力场。\n"
	);
	tell_room( environment(me), 
		me->query("c_name") 
		+ "喃喃地念了一段咒文，一股奇异的能源在"+
		me->query("c_name")+"的面前逐渐形成一层无形的力场。\n" ,
		me
	);
	gain_spell_experience(me, TYPE, query_gain_spell_exp(level));
	me->set_temp("effect/energy-shield", 1);
    me->apply_special_defense("energy", query_proportion(level) );
    me->apply_special_defense("electric", -query_reverse_proportion(level) );
    call_out( "release", 20+query_delay_time(me, level), me, level );
	return 1;
}

void release( object caster, int level )
{
    if( !caster ) return;
    tell_object( caster ,       "你感觉到你的魔法盾似乎消失了。\n" 
    );
    caster->apply_special_defense("energy", -query_proportion(level) );
    caster->apply_special_defense("electric", query_reverse_proportion(level) );
    caster->set_temp("effect/energy-shield", 0);
}
