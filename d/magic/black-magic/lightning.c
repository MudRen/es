// This is a spell object, damage type -> electric.
// level    0    1    2    3    4    5
// cost    20   40   60   80  100  150
// damage  25   50   75  100  125  120
// type   one  one  one  one  one  all
// delay    1    2    2    3    3    4
// skill   50   60   70   80   90  100
// miss    20   40   60   80  100    ? % when target 100
// G_LVL    5   10   17   26   37   50
// G_EXP    3   10   20   32   50   70
// found by monster rate = monster(int*2+kar) - killer(int) / 70
// found by player rate  = victim(int+kar) - killer(int) / 70
// remark L3-L5 must be outside!
#include <mudlib.h>
#include "/d/magic/magic.c"
#define TYPE "black-magic"

inherit DAEMON;

#define find_rate 70

int query_need_spell_level(int level)
{
	switch( level ) {
		case 0 : return  5;
		case 1 : return 10;
		case 2 : return 17;
		case 3 : return 26;
		case 4 : return 37;
		case 5 : return 50;
		default : return 99;
	}
}

int query_gain_spell_exp(int level)
{
	switch( level ) {
		case 0 : return  3;
		case 1 : return 10;
		case 2 : return 20;
		case 3 : return 32;
		case 4 : return 50;
		case 5 : return 70;
		default : return 0;
	}
}

int query_need_skill(int level) { return 50+10*level; }

int query_sp_cost(object caster, int level, string target) 
{
  int sp;
  switch( level ) {
    case 1 : sp =  40; break;
    case 2 : sp =  60; break;
    case 3 : sp =  80; break;
    case 4 : sp = 100; break;
    case 5 : sp = 150; break;
   default : sp =  20; break;  }
   return modify_sp_cost(caster, sp, TYPE, query_need_spell_level(level));
}

int query_damage( object caster, int level )
{
  int dam;
  switch( level ) {
    case 1 : dam =  50; break;
    case 2 : dam =  75; break;
    case 3 : dam = 100; break;
    case 4 : dam = 125; break;
    case 5 : dam = 120; break;
   default : dam =  25; break;  }
   return modify_damage(caster, dam, TYPE, query_need_spell_level(level));
}

int query_delay_time( int level )
{
  switch( level ) {
    case 1 : return 2;
    case 2 : return 2;
    case 3 : return 3;
    case 4 : return 3;
    case 5 : return 4;
   default : return 1;  }
}

string query_effect_func( int level )
{
  if( level < 5 )
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
	object me, targ;

	me = this_player();
	
	if( (int)me->query_skill("black-magic") < query_need_skill(level) ) {
	  tell_object( me, "��ĺ�ħ�����ܲ�����ʹ����ȼ���ħ��! \n"
      );
      return 0;
    }
	
	if( target=="NONE" && !(targ = me->query_attacker()) ) { 
		write( "Ҫ��˭ʩչ��������\n");
	    return 0;
	} else {
		if( !targ ) 
			targ = present( target, environment(me) );
		if( !targ ) {
		   write( "���Ŀ�겢�������\n" );
	       return 0;
	    }
	}

	if( !living(targ) ) {
	    write( "��������Ŀ����������\n" );
        return 0;
    }
	if( targ->query("no_attack") ) {
	    write( "�����ɡ��ԡ�\n" );
	    return 0;
	}
	if( targ==me ) {
	    write( "�� .... ��̫�ðɡ�\n" );
        return 0;
    }
    if( !check_level( me, targ, 1 ) ) return 0;
	write(set_color( "�㿪ʼ������������: ���������ꡤ������̹....��\n","HIB") );
	tell_room( environment(me), 
		sprintf("%s(%s)��ʼ�����\n", me->query("c_name"), me->query("name"))
		, me);
	if( (!environment(me)->query("outside")) && (level>2) )
		tell_room( environment(me), "����ʲ����Ҳû�з���....��\n" );
	else {
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
	    me->set_temp("cast_busy",1);
	    me->block_attack(query_delay_time(level)*2);
	    me->set_temp("msg_stop_attack", 
 	            "( ������ʩ�����޷������� )\n"  );
 	    if( me->query("npc") && me->query("magic_delay") )
 	    	delay_time = (int)me->query("magic_delay")*2;
 	    else
 	    	delay_time = query_delay_time(level)*2;
		call_out( "pre_effect", 1, me, targ, level );
	if (delay_time > 2) call_out("pre_effect1", 2 , me, targ);
	if (delay_time > 4) call_out("pre_effect1", 4 , me, targ);
		call_out( query_effect_func(level), delay_time, level, me, targ );
	}
	return 1;
}

void pre_effect( object caster, object target, int level )
{
   if( level < 3 ) {
     tell_object( caster, set_color(sprintf("������п�ʼ���۴���������ĵ�����\n" ),"HIB",caster));
	 tell_room( environment(caster), 
	   sprintf("%s�����п�ʼ���۴���������ĵ���������������Լ���������ŵ�⡣\n",caster->query("c_name")), caster
	 );
   } else
     tell_room( environment(caster),set_color(sprintf(
       "ͻȻ������������ܲ�����Լ�������������Ƶ���������Զ����....��\n"),"HIB",caster ));
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

	if ( ! caster ) return ;	
    caster->set_temp("cast_busy",0);
    damage = query_damage(caster, level);
	damage += random((int)caster->query_stat("int"));
    recharging( caster, damage, "electric" );
    
	if( !victim || !present(victim, environment(caster)) ) {
	  if( level < 3 ) {
	    tell_object( caster, 		  "�㽫���е��������ǰһ�䣬һ�������Х��������ʧ�ڿ��У�\n");
	    tell_room( environment(caster), 
	      sprintf("%s�����е��������ǰһ�䣬һ�������Х��������ʧ�ڿ��У�\n",
	      caster->query("c_name")), caster );
	  } else
		tell_room( environment(caster), 
		  "һ���������������е��棬���һ����....��\n" );
	  gain_spell_experience(caster, TYPE, query_gain_spell_exp(level)/2);
      return ;
    }
    if( !success_hit( 20+level*20, caster, TYPE, query_need_spell_level(level) ) ) {
      tell_object( caster, 		sprintf("������ǰ%sһָ��һ�������Х��������ϧû���У�\n",
		victim->query("c_name") ) );
	  tell_room( environment(caster), 
	    sprintf("%s������ǰһָ��һ�������Х����������û�����κ��ˣ�\n",
	      caster->query("c_name") ), caster );
	  gain_spell_experience(caster, TYPE, query_gain_spell_exp(level)/2);
	  return;
    }
// hit effect ....
    if( level < 3 ) {
	  tell_object( caster,set_color(
		sprintf("�㽫���е��������%sһ�䣬һ�������Х�����������������壡\n",
		 victim->query("c_name")  ),"HIB",caster));

      tell_object( victim,  set_color(
                sprintf("%s�����е����������һ�䣬��ֻ����ǰ�׹�һ�����漴�е�һ���ʹ��\n",
		 caster->query("c_name") ),"HIB",victim) 
      );
	  tell_room( environment(caster), 
	    sprintf("%s�����е��������%sһ�䣬һ�������Х�����������������壡\n",
	     caster->query("c_name"), victim->query("c_name")), 
	     ({caster,victim }));
    } else if ( level < 4 ) {
	  tell_room( environment(caster),set_color(
		sprintf( "һ��������������ֻ��������¡��һ�����죬����%sͷ�ϣ�\n",
			victim->query("c_name") ) ,"HIB",
		victim)
	  );
	  tell_object( victim,set_color(
	    sprintf( 
		"ͻȻ����ֻ����ǰѣĿ�İ׹�һ�������ж��ݵĿհ�֮�ᣬ�漴�е�һ���ʹ��\n"),"HIB"
		));
	}
	else {
	  tell_room( environment(caster),set_color(
		sprintf( "�㿴�������һ����⣬����������¡��һ���׵�Ю���֮���������������%s��ͷ�ϣ�\n",
			victim->query("c_name") ) ,"HIB",
		victim)
	  );
	  tell_object( victim,set_color(
	    sprintf( 
		"\nͻȻ��һ����������������������ͷ���������ǰһ�������ð��Ȼ����\nȫ����ʹ��һ�ɽ�ζ ....\n"),"HIB"
		));
	}


	damage -= random((int)victim->query_stat("int"));
	if( damage < 0 ) damage = 1;
	victim->kill_ob(caster);
	caster->kill_ob(victim);
	caster->gain_experience(damage);
	gain_spell_experience(caster, TYPE, query_gain_spell_exp(level));
	victim->receive_special_damage( "electric", damage, 0 );
	victim->set("last_attacker", caster);
	report( caster, victim );
}

int is_a_victim( object obj )
{
    if( living(obj) ) return 1;
}

void effect_all(int level, object caster, object targ)
{
    int i, damage;
    object *victim;
    caster->set_temp("cast_busy",0);
    gain_spell_experience(caster, TYPE, query_gain_spell_exp(level));
    damage = query_damage(caster, level);
    damage += random( (int)caster->query("int") );
    recharging( caster, damage, "electric" );
    
    tell_room( environment(caster),set_color (sprintf(
      "ͻȻ��ֻ��������¡��֮������춶����������������������\n" ),"HIB",caster));
    tell_object( caster, set_color (sprintf(
      "����ȫ������������Աߡ�\n"),"HIB",caster) 
    );
    tell_room( environment(caster), 
	  "��ֻ����ǰѣĿ�İ׹�һ�������ж��ݵĿհ�֮�ᣬ�漴�е�һ���ʹ��\n", 
	  caster );
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
	      victim[i]->receive_special_damage( "electric", damage, 0);
	      victim[i]->set("last_attacker", caster);
	      report(caster, victim[i]);
	    }
	}
}