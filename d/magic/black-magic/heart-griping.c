// Heart-griping.This is a spell object, damage type -> evil.  By Yueh 1995/3/7 
// Learning from /d/noden/forest/ruin/lich
// Learner must finish wanfu quest and ali < -200
// If caster's ali < bonus_ali, then damage = damage + bonus_dam
// If caster's ali > -200, caster will cast fail 
// If caster's ali > victim's ali, caster will cast fail and hurt himself damage /4
// level       0    1    2    3    4    5    6
// cost       20   35   50   70   90  110  150
// damage     25   45   65   90  110  135  125
// bonus_ali  -3   -6   -9  -12  -15  -18  -20 * 1000
// bonus_dam   3    6    9   12   15   18   15
// type      one  one  one  one  one  one  all
// delay       1    2    2    3    3    4    4
// skill      40   50   60   70   80   90  100
// miss       10   25   40   55   70   85    ?  % when target skill is 100
// G_LVL       7   14   21   28   35   42   49
// G_EXP       3    9   18   27   40   60   80
// found by monster rate = monster(int*2+kar) - killer(int) / 80
// found by player rate  = victim(int+kar) - killer(int) / 80
// level 6 will hurt caster sef_damage 20
#include <mudlib.h>
#include "/d/magic/magic.c"
#define TYPE "black-magic"

inherit DAEMON;

#define find_rate 80
#define sef_damage 20

int query_need_spell_level(int level) { return 7+7*level; }

int query_gain_spell_exp(int level)
{
	switch( level ) {
		case 0 : return  3;
		case 1 : return 9;
		case 2 : return 18;
		case 3 : return 27;
		case 4 : return 40;
		case 5 : return 60;
		case 6 : return 80;
		default : return 0;
	}
}

int query_need_skill(int level) { return 40+10*level; }

int query_sp_cost(object caster, int level, string target) 
{
  int sp;
  switch( level ) {
    case 1 : sp =  35; break;
    case 2 : sp =  50; break;
    case 3 : sp =  70; break;
    case 4 : sp = 90; break;
    case 5 : sp = 110; break;
    case 6 : sp = 150; break;
   default : sp =  20; break;  }
   return modify_sp_cost(caster, sp, TYPE, query_need_spell_level(level));
}

int query_damage( object caster, int level )
{
  int dam;
  switch( level ) {
    case 1 : dam =  45; break;
    case 2 : dam =  65; break;
    case 3 : dam = 90; break;
    case 4 : dam = 110; break;
    case 5 : dam = 135; break;
    case 6 : dam = 125; break;
   default : dam =  25; break;  }
   return dam;
}

int query_delay_time( int level )
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

int query_bonus_ali(int level)
{
    switch( level ) {
      case 1 : return    -6000;
      case 2 : return    -9000;
      case 3 : return    -12000;
      case 4 : return    -15000;
      case 5 : return    -18000;
      case 6 : return    -20000;
     default : return    -3000;  
    }
}

int query_bonus_dam(int level)
{
    switch( level ) {
      case 1 : return    6;
      case 2 : return   9;
      case 3 : return   12;
      case 4 : return    15;
      case 5 : return    18;
      case 6 : return    15;
     default : return    3;  
    }
}

string query_effect_func( int level , int h)
{
  if( level < 6 ){
    if ( h == 1 ) 
    	return "effect_one";
	else
	return "effect_self";
  }
  else
    return "effect_all";
}

int query_find_rate(object caster, object victim)
{
  if( !userp(victim) )
    return (int)victim->query_stat("int")*2 -
           (int)caster->query_stat("int") +
           (int)victim->query_stat("kar");
  else
    return (int)victim->query_stat("int") -
           (int)caster->query_stat("int") +
           (int)victim->query_stat("kar");
}

int cast(int level, string target)
{
	int delay_time,ali1, ali2;
	object me, targ;

	me = this_player();	
	if( (int)me->query_skill("black-magic") < query_need_skill(level) ) {
	  tell_object( me, "��ĺ�ħ�����ܲ�����ʹ����ȼ���ħ��! \n");
      return 0;
    }	
	if( target=="NONE" && !(targ = me->query_attacker()) ) { 
		write( "Ҫ��˭ʩչ��������\n");
	    return 0;
	} else {
		if( !targ ) 
			targ = present( target, environment(me) );
		if( !targ ) {
		   write( "���Ŀ�겢�������\n");
	       return 0;
	    }
	}
	if( !living(targ) ) {
	    write( "��������Ŀ����������\n");
	        return 0;
	}
	if( targ->query("no_attack") ) {
	    write( "�����ɡ��ԡ�\n");
	    return 0;
	}
	if( targ==me ) {
	    write( "�� .... ��̫�ðɡ�\n");
	     return 0;
	}
	if( !check_level( me, targ, 1 ) ) return 0;
	me->set_temp("cast_busy",1);
	me->block_attack(query_delay_time(level)*2);
	me->set_temp("msg_stop_attack","( ������ʩ�����޷������� )\n"  );
	write( set_color(sprintf("�㿪ʼ�������������...\n"),"HIG",me));
	tell_room( environment(me), 
		sprintf("%s(%s)��ʼ�����\n", me->query("c_name"), me->query("name"))
		, me);
	ali1 = (int) me->query("alignment") ;
	ali2 = (int) targ->query("alignment") ;
	    if( !targ->query_attackers() &&
	       (random(find_rate)<query_find_rate(me,targ)) ) {
		tell_object( me, set_color(
			sprintf("\n%s(%s)��������������������ʼ�����㡣\n",
				targ->query("c_name"), targ->query("name")) ,"HIY",me));

		tell_room( environment(targ), 
			sprintf("%s����%s�����������������������\n",
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
		if (ali1 > ali2)
			call_out( query_effect_func(level,0), delay_time, level, me, targ );
		else
			call_out( query_effect_func(level,1), delay_time, level, me, targ );
	return 1;
}

void pre_effect( object caster, object target, int level )
{
   if( level < 3 ) {
     tell_object( caster,set_color(sprintf( "����������ٻ���а���������\n" ),"HIG"));
	 tell_room( environment(caster), 
sprintf("%s���������дʣ��ƺ�����ʩչĳ��������\n",caster->query("c_name")) , caster);
   } else
     if (level < 6 ) {
     tell_object( caster,set_color(sprintf( "����������ٻ�ǿ���а������ǰ����\n" ),"HIG"));
	 tell_room( environment(caster),set_color( 
sprintf( "%s���������дʣ��ƺ�����ʩչĳ�����������Ȼ�е�һ��Ī���Ŀ־塣\n",caster->query("c_name")) ,"HIG"), caster );
	} else
     tell_room( environment(caster),set_color(sprintf( "ͻȻ��һ�ɼ�ǿ�������������ʼ���������������ʲ����Ҫ�����ˣ�����е�����������\n" ),"HIG"));
	if( !target || !present(target, environment(caster)) ) 
		caster->set_temp("cast_flee",1);
}

void pre_effect1(object caster, object target)
{
	if( !caster ) return;
	if( !target || !present(target, environment(caster)) ) 
		caster->set_temp("cast_flee",1);
}

void effect_one(int level, object caster, object victim)
{
	int damage;
	int ali;
	if ( ! caster || nullp(caster)) return ;
	caster->set_temp("cast_busy",0);
	damage = query_damage(caster, level);
	ali = (int) caster->query("alignment") ;
	if (ali > -200) {
		tell_room( environment(caster), "������������������ʲ����Ҳû�з���....��\n");
		return;
	}
	if (ali < query_bonus_ali(level)) 
		damage = damage + query_bonus_dam(level);
	damage = modify_damage(caster, damage, TYPE, query_need_spell_level(level));
	damage += random((int)caster->query_stat("int"));
    recharging( caster, damage, "evil" );
    
	if( !victim || !present(victim, environment(caster)) ) {
	    tell_object( caster, "�����������������ǵ����Ѿ������ˣ�ʲ����Ҳû������\n");
	    tell_room( environment(caster), sprintf("%s����������ֵ��������ʲ����Ҳû�з�����\n",
	      caster->query("c_name")) , caster);
	  gain_spell_experience(caster, TYPE, query_gain_spell_exp(level)/2);
      return ;
    }
    if( !success_hit( 10+level*15, caster, TYPE, query_need_spell_level(level) ) ) {
      tell_object( caster, 	sprintf("������������������%sȴû���µ����ӣ��ɶ���û���С�\n", victim->query("c_name") ) );
	  tell_room( environment(caster), sprintf("%s����������ֵ��������ʲ����Ҳû�з�����\n",
	    caster->query("c_name")), caster);
	  gain_spell_experience(caster, TYPE, query_gain_spell_exp(level)/2);
	  return;
    }
// hit effect ....
    if( level < 3 ) {

	  tell_object( caster,set_color( sprintf("������������������%s¶��ʹ��ı��顣\n",
		 victim->query("c_name") ),"HIG",) );
	    tell_object( victim, sprintf("%s�૵�������������ģ�ʹ����������ʹ��\n ",
		 caster->query("c_name") ) );
	  tell_room( environment(caster),sprintf("%s�૵�������������ģ��㿴��%s¶��ʹ��ı��顣\n",
	     caster->query("c_name"), victim->query("c_name")) ,  ({caster,victim}));
    } else {
	  tell_room( environment(caster),set_color( sprintf( "%s����Ϊ֮һ��ҡ���˼��£�����¶����ʹ��ı��顣\n",
			victim->query("c_name")),"HIG") ,victim);
	  tell_object( victim,sprintf( 
"\n�������ǰһ��, ĳ�����ص����������������, ʹ��ʹ�಻��!\n"));
	}

	damage -= random((int)victim->query_stat("int"));
	if( damage < 0 ) damage = 1;
	victim->kill_ob(caster);
	caster->kill_ob(victim);
	caster->gain_experience(damage);
	gain_spell_experience(caster, TYPE, query_gain_spell_exp(level));
	victim->receive_special_damage( "evil", damage, 0 );
	victim->set("last_attacker", caster);
	report( caster, victim );
}

void report1( object caster)
{
   string message;
   message= "/adm/daemons/statsd"->status_string(caster);

   if( living( caster ) )
     tell_object( caster,
       "( ��"+message+" )\n" );
}

void effect_self(int level, object caster, object victim)
{
	int damage;
	int ali;
	caster->set_temp("cast_busy",0);
	damage = query_damage(caster, level);
	ali = (int) caster->query("alignment") ;
	if (ali > -200) {
		tell_room( environment(caster), "������������������ʲ����Ҳû�з���....��\n");
		return;
	}
	damage = modify_damage(caster, damage, TYPE, query_need_spell_level(level));
	damage += random((int)caster->query_stat("int"));
    recharging( caster, damage, "evil" );
    
	if( !victim || !present(victim, environment(caster)) ) {
	    tell_object( caster, "�����������������ǵ����Ѿ������ˣ�ʲ����Ҳû������\n");
	    tell_room( environment(caster), sprintf("%s����������ֵ��������ʲ����Ҳû�з�����\n",
	      caster->query("c_name")) , caster);
	  gain_spell_experience(caster, TYPE, query_gain_spell_exp(level)/2);
      return ;
    }
// hit effect ....
    if( level < 3 ) {
/*	  tell_object( caster, sprintf(bold("����������������ȴ��Ȼ���������ʹ��\n") ) );
*/
	  tell_object( caster,set_color( sprintf("����������������ȴ��Ȼ���������ʹ��\n"),"HIR" )) ;
	  tell_room( environment(caster),sprintf("%s�૵�������������ģ�ȴ��Ȼ¶��ʹ��ı��顣\n",
	     caster->query("c_name")) , caster);
    } else {
	  tell_room( environment(caster),set_color( sprintf( "%s����Ϊ֮һ��ҡ���˼��£�����¶����ʹ��ı��顣\n",
			caster->query("c_name") ),"HIR" ,caster));
/*	  tell_object(caster,sprintf( bold(
"\n�������ǰһ��, ĳ�����ص����������������, ʹ��ʹ�಻��!\n")));
*/
	  tell_object(caster,set_color(sprintf(
"\n�������ǰһ��, ĳ�����ص����������������, ʹ��ʹ�಻��!\n"),"HIR"));

	}
	damage -= random((int)caster->query_stat("int"));
	damage = damage /4;
	if( damage < 0 ) damage = 1;
	caster->gain_experience(damage);
	gain_spell_experience(caster, TYPE, query_gain_spell_exp(level));
	caster->receive_special_damage( "evil", damage, 0 );
	report1( caster);

}

int is_a_victim( object obj )
{
    if( living(obj) ) return 1;
}

void effect_all(int level, object caster, object targ)
{
    int i, ali, damage;
    object *victim;
    caster->set_temp("cast_busy",0);
    gain_spell_experience(caster, TYPE, query_gain_spell_exp(level));
    damage = query_damage(caster, level);
    ali = (int) caster->query("alignment") ;
    if (ali < query_bonus_ali(level)) 
        damage = damage + query_bonus_dam(level);
    damage = modify_damage(caster, damage, TYPE, query_need_spell_level(level));
    damage += random( (int)caster->query("int") );
    recharging( caster, damage, "evil" );
    
    tell_room( environment(caster),set_color(sprintf( " ͻȻ���㿴��һ�źڰ���������ٵ����ͱ���������Ϯ����\n" ),"HIG",));
    tell_room( environment(caster),set_color(sprintf(  "\n��ֻ����ǰһ�������ж��ݵĿհ�֮�ᣬ�漴�е�ȫ���Ѫ�ܺ��񶼱����ˡ�\n\n" ),"HIG"));
	victim = filter_array( all_inventory( environment(caster) ),
	         "is_a_victim", this_object() );
	if( sizeof(victim) ) {
	  i = sizeof(victim);
	  while( i-- )
	    if( (victim[i]!=caster) && !(victim[i]->query("no_attack")) &&
	        check_level( caster, victim[i], 0 ) ) {
	      damage -= random( (int)victim[i]->query("int") );
	      if( damage < 0 ) damage = 1;
	      victim[i]->kill_ob(caster);
	      caster->kill_ob(victim[i]);
	      victim[i]->receive_special_damage( "evil", damage, 0);
	      victim[i]->set("last_attacker", caster);
	      report(caster, victim[i]);
	    }
	}
	caster->receive_special_damage( "evil", sef_damage, 0);
}
