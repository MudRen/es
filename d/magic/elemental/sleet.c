// This is a spell object, damage type -> cold.
// level    0    1    2    3    4    5    6
// cost    20   35   50   70   90  110  150
// damage  25   45   65   90  120  150  125
// type   one  one  one  one  one  one  all
// delay    1    2    2    3    3    4    4
// skill   40   50   60   70   80   90  100
// miss    10   25   40   55   70   85    ?  % when target skill is 100
// G_LVL    6   13   20   27   34   41   48
// G_EXP    2    7   15   27   43   60   80
// found by monster rate = monster(int*2+kar) - killer(int) / 50
// found by player rate  = victim(int+kar) - killer(int) / 50
#include <mudlib.h>
#include "/d/magic/magic.c"
#define TYPE "elemental"

inherit DAEMON;

#define find_rate 50

int query_gain_spell_exp(int level)
{
	switch( level ) {
		case 0 : return  2;
		case 1 : return  7;
		case 2 : return 15;
		case 3 : return 27;
		case 4 : return 43;
		case 5 : return 60;
		case 6 : return 80;
		default : return 0;
	}
}

int query_need_spell_level(int level)
{
	return 6+7*level;
}

int query_need_skill(int level) { return 40+10*level; }

int query_sp_cost(object caster, int level, string target) 
{
	int sp;
    switch( level ) {
      case 1 : sp =  35; break;
      case 2 : sp =  50; break;
      case 3 : sp =  70; break;
      case 4 : sp =  90; break;
      case 5 : sp = 110; break;
      case 6 : sp = 150; break;
     default : sp =  20; break;  }
     return modify_sp_cost(caster, sp, TYPE, query_need_spell_level(level));
}

int query_damage(object caster, int level)
{
	int dam;
    switch( level ) {
      case 1 : dam =  45; break;
      case 2 : dam =  65; break;
      case 3 : dam =  90; break;
      case 4 : dam = 120; break;
      case 5 : dam = 150; break;
      case 6 : dam = 125; break;
     default : dam =  25; break;  }
     return modify_damage(caster, dam, TYPE, query_need_spell_level(level));
}

int query_delay_time(int level)
{
    switch( level ) {
      case 1 : return 2;
      case 2 : return 2;
      case 3 : return 3;
      case 4 : return 3;
      case 5 : return 4;
      case 6 : return 4;
     default : return 1;  }
}

string query_effect_func(int level)
{
    if( level < 6 )
      return "effect_one";
    else
      return "effect_all";
}

int query_find_rate(object caster, object victim)
{
  if( !userp(victim) )
    return (int)victim->query_stat("int")*2 -
           (int)caster->query_stat("int") -
           modify_find_rate(caster)+
           (int)victim->query_stat("kar");
  else
    return (int)victim->query_stat("int") -
           (int)caster->query_stat("int") +
           (int)victim->query_stat("kar");
}

int cast(int level, string target)
{
	int delay_time;
	object targ, me;

	me = this_player();

	if( (int)me->query_skill("elemental") < query_need_skill(level) ) {
	  tell_object( me,
        "你的元素魔法技能不足以使用这等级的魔法! \n" );

      return 0;
    }
    
	if( target=="NONE" && !(targ = me->query_attacker()) ) {
		write( "要对谁施展冰雹术？\n");
	    return 0;
	} else {
		if( !targ ) 
			targ = present( target, environment(me) );
		if( !targ ) {
		  write("你的目标并不在这里！\n");
	      return 0;
	    }
	}

	if( !living(targ) ) {
	    write("冰雹术的目标必须是生物！\n");
        return 0;
    }
	if( targ->query("no_attack") ) {
	    write( "不—可—以。\n");
	    return 0;
	}
	if( targ==me ) {
	    write("这 .... 不太好吧。\n");
        return 0;
    }
    if( !check_level( me, targ, 1 ) ) return 0;
    me->set_temp("cast_busy",1);
	me->block_attack(query_delay_time(level)*2);
	me->set_temp("msg_stop_attack", 
 	        "( 你正在施法，无法攻击。 ) \n" );
	write(set_color(sprintf("你开始念冰雹术咒文 撒拉 曼 伊达 .... 。\n"),"HIW",me));

	tell_room( environment(me), 
	  sprintf("%s开始喃喃自语。\n",me->query("c_name")) ,me);
	if( !targ->query_attackers() &&
	    (random(find_rate)<query_find_rate(me,targ)) ) {
		tell_object( me, set_color(
			sprintf("\n%s(%s)发现你对他不怀好意而开始攻击你。\n",
				targ->query("c_name"), targ->query("name")) ,"HIY",me));

		tell_room( environment(targ), 
			sprintf("%s发现%s对他不怀好意而主动攻击。\n",
				targ->query("c_name"), me->query("c_name")) , me);
	  targ->kill_ob(me);
	  me->block_attack(2);
	}
	if( me->query("npc") && me->query("magic_delay") )
		delay_time = (int)me->query("magic_delay")*2;
	else
	    delay_time = query_delay_time(level)*2;
	call_out( "pre_effect", 1, me, targ, level );
	if (delay_time > 2) call_out("pre_effect1", 2 , me, targ);
	if (delay_time > 4) call_out("pre_effect1", 4 , me, targ);
	call_out( query_effect_func(level), delay_time, level, me, targ );
	return 1;
}

void pre_effect( object caster, object target, int level )
{
   tell_object( caster,set_color(sprintf( 
     "突然间你周围的气温急速下降，空气都渐渐凝结起来。\n" ),"HIW",caster));
   tell_room( environment(caster), 
     sprintf("突然间%s周围的气温急速下降，隐约的可看见小雪花。\n",
            caster->query("c_name") ) , caster );
// default message.
   tell_object( caster,set_color(sprintf( 
       "渐渐地，空中凝聚出小小的冰块。\n" ),"HIW",caster));
     tell_room( environment(caster), 
       "渐渐地，雪花凝聚成小小的冰块。\n" , caster );
   if( level > 2 ) {
     tell_room( environment(caster),set_color(sprintf(
       "这些冰块进而结成更大的冰柱。\n"  ),"HIW"));
   } 
   if( level > 5 ) {
     tell_object( caster,set_color(sprintf(
       "瞬间你的周围布满了无数的冰晶。\n" ),"HIW",caster));
     tell_room( environment(caster),set_color(
       sprintf("突然间%s的周围布满了无数的冰晶。\n"
       ,caster->query("c_name") ) ,"HIW", caster) );
   }
	if( !target || !present(target, environment(caster)) ) 
		caster->set_temp("cast_flee",1);
}

void pre_effect1( object caster, object target)
{
	if ( !caster ) return;
	if( !target || !present(target, environment(caster)) ) 
		caster->set_temp("cast_flee",1);
}

void effect_one(int level, object caster, object victim)
{
	int damage;
	
	if ( !caster ) return;
    caster->set_temp("cast_busy",0);
    damage = query_damage(caster, level);
	damage += random((int)caster->query_stat("int"));
	recharging( caster, damage, "cold" );
	
	if( !victim || !present(victim, environment(caster)) ) {
		tell_object( caster, 
	      "你身旁的冰块全往地上激射而去，打得铿然作响。\n");

        tell_room( environment(caster), 
          sprintf("%s身旁的冰块全往地上激射而去，打得铿然做响。\n",
            caster->query("c_name") ) , caster );
        gain_spell_experience(caster, TYPE, query_gain_spell_exp(level)/2);
		return;
	}
    if( !success_hit( 10+level*15, caster, TYPE, query_need_spell_level(level) ) ) {
      tell_object( caster, 
		sprintf("你身旁的冰块全往%s激射而去，可是全没打中！\n",
			victim->query("c_name") ));

	  tell_room( environment(caster), 
		sprintf("%s身旁的冰块全往前激射而去，幸好没打中任何人！\n",
		  caster->query("c_name") ) , caster );
	  gain_spell_experience(caster, TYPE, query_gain_spell_exp(level)/2);
      return;
    }
// hit effect ...	
	tell_object( caster, 
		sprintf(bold("你身旁的冰块全往%s激射而去！\n",caster),
			victim->query("c_name") ));

	tell_object( victim, 
		sprintf("%s身旁的冰块全向你激射而来，打得你好痛！\n",
		         caster->query("c_name") ) );

	tell_room( environment(caster), 
		sprintf("%s身旁的冰块全向%s激射而去！\n",
		  caster->query("c_name"), victim->query("c_name") )
		,({ caster, victim }) );
	
	damage -= random((int)victim->query_stat("int"));
	if( damage < 0 ) damage = 1;
	victim->kill_ob(caster);
	caster->kill_ob(victim);
	caster->gain_experience(damage);
	gain_spell_experience(caster, TYPE, query_gain_spell_exp(level));
	victim->receive_special_damage( "cold", damage, 0 );
	victim->set("last_attacker", caster);
	report( caster, victim );
}

int is_a_victim( object obj )
{
    if( living(obj) ) return 1;
}

void effect_all(int level, object caster, object targ)
{
    int i,damage;
    object *victim;
    
    caster->set_temp("cast_busy",0);
    gain_spell_experience(caster, TYPE, query_gain_spell_exp(level));
    damage = query_damage(caster, level);
    damage += random( (int)caster->query_stat("int") );
    recharging( caster, damage, "cold" );
    
    tell_object( caster, 
      bold("你手往前一挥，大喊「冰雪风暴」。无数的冰晶开始无情的肆掠起来！\n",caster) );
    tell_room( environment(caster), 
	  sprintf("%s的手往前一挥，大喊「冰雪风暴」！\n"+
		"突然间，无数的冰晶开始无情的肆掠起来！你彷如置身於可怕的\n"+
		"暴风雪之中，无数的雪花在你的面前飞舞，彷佛要将大地吞噬！\n"
	    ,caster->query("c_name") )
	, caster);
	victim = filter_array( all_inventory( environment(caster) ),
	         "is_a_victim", this_object() );
	if( sizeof(victim) ) {
	  i = sizeof(victim);
	  while(i--)
	   if( victim[i]!=caster && !(victim[i]->query("no_attack")) &&
	       check_level( caster, victim[i], 0 ) ) {
	    damage -= random( (int)victim[i]->query("int") );
	    if( damage < 0 ) damage = 1;
	    victim[i]->kill_ob(caster);
	    caster->kill_ob(victim[i]);
	    victim[i]->receive_special_damage( "cold", damage, 0 );
	    victim[i]->set( "last_attacker", caster );
	    report( caster, victim[i] );
	   }
	}
}
