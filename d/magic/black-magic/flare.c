// This is a spell object, damage type -> none.
// level    0    1    2    3
// cost    40   80  120  200
// damage  40   90  140  180
// type   one  one  one  all
// delay    2    2    3    4
// skill   80   90   95  100
// miss    30   65  100    ? % when target 100
// G_LVL   20   30   40   50
// G_EXP   10   30   50  100
// found by monster rate = monster(int*2+kar) - killer(int) / 80
// found by player rate  = victim(int+kar) - killer(int) / 80
// remark L3 will damage himself hp 20.
#include <mudlib.h>
#include "/d/magic/magic.c"
#define TYPE "black-magic"

inherit DAEMON;

#define self_damage 20
#define find_rate 80

int query_gain_spell_exp(int level)
{
	switch( level ) {
		case 0 : return  10;
		case 1 : return  30;
		case 2 : return  50;
		case 3 : return 100;
		default : return  0;
	}
}

int query_need_spell_level(int level)
{
	return 20+10*level;
}

int query_need_skill(int level)
{
	switch( level ) {
    case 1 : return  90;
    case 2 : return  95;
    case 3 : return 100;
   default : return  80;
  }
}

int query_sp_cost(object caster, int level, string target) 
{
  int sp;
  switch( level ) {
    case 1 : sp =  80; break;
    case 2 : sp = 120; break;
    case 3 : sp = 200; break;
   default : sp =  40; break;
  }
  return modify_sp_cost(caster, sp, TYPE, query_need_spell_level(level));
}

int query_damage(object caster,int level)
{
  int dam;
  
  switch( level ) {
    case 1 : dam =  90; break;
    case 2 : dam = 140; break;
    case 3 : dam = 180; break;
   default : dam =  40; break;
  }
  return modify_damage(caster, dam, TYPE, query_need_spell_level(level));
}

int query_delay_time(int level)
{
  switch( level ) {
    case 1 : return 2;
    case 2 : return 3;
    case 3 : return 4;
   default : return 2;
  }
}

string query_effect_func(int level)
{
  if( level < 3 )
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
	int chinese_mode, delay_time;
	object targ, me;

	me = this_player();
	chinese_mode = can_read_chinese();
	
	if( (int)me->query_skill("black-magic") < query_need_skill(level) ) {
	  tell_object( me, 
        "��ĺ�ħ�����ܲ�����ʹ����ȼ���ħ��! \n" );

      return 0;
    }
    
	if( target=="NONE" && !(targ = me->query_attacker()) ) {
		write( "Ҫ��˭ʩչ���׺�������\n");
	    return 0;
	} else {
		if( !targ ) 
			targ = present( target, environment(me) );
		if( !targ ) { 
		  write("���Ŀ�겢�������\n");
	      return 0;
	    }
	}

	if( !living(targ) ) { 
	  write( "���׺�������Ŀ����������\n");
      return 0;
    }
	if( targ->query("no_attack") ) { 
	  write("�����ɡ��ԡ�\n");
	  return 0;
	}
	if( targ==me ) {
	   write("�� .... ��̫�ðɡ�\n");
       return 0;
    }
    if( !check_level( me, targ, 1 ) ) return 0; 
	me->block_attack(query_delay_time(level)*2);
	me->set_temp("cast_busy",1);
	me->set_temp("msg_stop_attack", 
 	        "( ������ʩ�����޷������� )\n"   );
	write(set_color(sprintf("�㿪ʼ�����׺��������� ���ð����� ����ܽ���� .... \n" ),"HIM",));
	tell_room( environment(me), 
	    sprintf("%s��ʼ�����\n" ,me->query("c_name")),
	  me);
	if( !targ->query_attackers() && 
	    (random(find_rate)<query_find_rate(me, targ)) ) {
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
	call_out( "pre_effect", 1, me, targ, level);
	if (delay_time > 2) call_out("pre_effect1", 2 , me, targ);
	if (delay_time > 4) call_out("pre_effect1", 4 , me, targ);
	call_out( query_effect_func(level), delay_time, level, me, targ );
	return 1;
}

void pre_effect( object caster, object target, int level )
{
    if( level < 1 ) { 
      tell_object( caster,set_color(sprintf( 
	"һ�����ȵı�����ʼ��������оۼ����ɳ�����\n"),"HIM",));

	  tell_room( environment(caster), sprintf(
		"һ��СС�ĺڰ�������%s  ������Ѹ�ٵ��γɡ�\n" ,caster->query("c_name") ),
		caster);
	} else if( level < 2 ) {
	  tell_object( caster,set_color(sprintf(
		"������п�ʼ�ۼ�һ�ž޴����ȵı�����\n"),"HIM",));

	  tell_room( environment(caster), 
		 
sprintf("%s�����п�ʼ�ۼ�һ�źڰ���ħ������, �������ܵĹ�â���ϵ����������ľۼ�, ���忪ʼ���͡��޴󻯡�\n" ,caster->query("c_name"))
		,caster);
	} else if( level < 3 ) {
	  tell_room( environment(caster),set_color(sprintf(
        "ͻȻ���ذ�, ��ر�ɫ, �ƺ���������µ����齫Ҫ������\n" 
	  ),"HIM"));
	} else {
	  tell_room( environment(caster),set_color(sprintf( 
        "ͻȻ���ذ�, ��ر�ɫ, �����Ǿ��ŵ����ܱ���, �ƺ�������\n���µ����齫Ҫ������\n" 
	  ),"HIM",));
	  tell_room( environment(caster), 
        "��ı��ܸ�����, ��øϿ��뿪��\n" , caster
	  );
	}
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
    
    if ( !caster ) return;
    caster->set_temp("cast_busy",0);
    damage = query_damage(caster, level);
	damage += random((int)caster->query_stat("int"));
	
	if( !victim || !present(victim, environment(caster)) )
	  if( level < 2 ) {
		tell_object( caster, 
		  "�㽫���еı�����������һ��, ���䡹��һ����ը�ˡ�\n");

		tell_room( environment(caster), 
		 sprintf("%s�����еı�����������һ��, ���䡹��һ���ͱ����ˡ�\n",
		  caster->query("c_name") ), caster  );
		gain_spell_experience(caster, TYPE, query_gain_spell_exp(level)/2);
		return;
	  } else {
	    tell_room( environment(caster), 
		  "����ʲ�����鶼û�з�����\n" 
		);
		gain_spell_experience(caster, TYPE, query_gain_spell_exp(level)/2);
		return;
      }
    if( level < 2 &&
    	!success_hit( 30+level*35, caster, TYPE, query_need_spell_level(level) ) ) {
      tell_object( caster, 
        "�㽫���еı����򶪳�ȥ����ϧû�л��е��ˡ�\n");
      tell_room( environment(caster), 
        sprintf("%s�����еı����򶪳�ȥ������û�����κ��ˡ�\n",
		  caster->query("c_name") ), caster);
	  gain_spell_experience(caster, TYPE, query_gain_spell_exp(level)/2);
      return;
    }
// hit effect ...
    if( level < 1 ) {
	  tell_object( caster, 		sprintf(bold("�㽫���еı����򶪳�ȥ�����䡹��һ����%s����ǰը����\n",caster),
			victim->query("c_name")) );

	  tell_object( victim,
	sprintf("%s���������źڰ������ȵ�������������϶����������䡹��һ��������ǰը����\n",
			caster->query("c_name") ));

	  tell_room( environment(caster), 
		sprintf("%s�����еĺڰ����嶪��ȥ�����䡹��һ����%s����ǰը����\n",
			caster->query("c_name"), victim->query("c_name") )
		,({ caster, victim })
	  );
	} else if( level < 2 ) {
	  tell_object( caster,
		sprintf(bold("�㽫���еĴ����򶪳�ȥ������¡����һ����%s����ը����\n",caster),
			victim->query("c_name")) );

	  tell_object( victim, 
		sprintf("%s�����еĺڰ����塸��¡����һ��, ������ǰը�������ȵĻ�����ص����������Ƥ����\n",
			caster->query("c_name") ));

	  tell_room( environment(caster), 
		sprintf("%s�����еĺڰ����塸��¡����һ����%s����ը��, ͬʱ����һ�źڰ��Ļ��������%s��\n",
			caster->query("c_name"), victim->query("c_name"), victim->query("c_name") )
		    , ({ caster, victim })
	  );
	} else if( level < 3 ) {
	  tell_object( victim, 
		sprintf(bold("%s���еĺڰ�����ͻȻ����, ������������ܡ�����һֻ��ɫ�Ļ���\nͻȻ���� ��������������������Ȼ����\n",caster)
		  ,caster->query("c_name") ));

	  tell_room( environment(victim), 
		sprintf("%s���еĺڰ����廯��һ��ħ����Χ����%s, ����һֻ��ɫ�Ļ���\nͻȻ�����������%s����������Ȼ����\n"
		  ,caster->query("c_name"), victim->query("c_name"), victim->query("c_name") )
		, ({ caster, victim }));

	  tell_object( caster, 
		sprintf(bold("�����еĺڰ����廯��һ��ħ����Χ����%s, ����һֻ��ɫ�Ļ���\nͻȻ�����������%s����������Ȼ����\n",caster)
		  ,victim->query("c_name"), victim->query("c_name") ));
	}
	
	damage -= random((int)victim->query_stat("int"));
	damage -= (int)victim->query("defense_bonus")/4 +
	          random((int)victim->query("defense_bonus")/2);
	if( damage < 0 ) damage = 1;
	victim->kill_ob(caster);
	caster->kill_ob(victim);
	gain_spell_experience(caster, TYPE, query_gain_spell_exp(level));
	caster->gain_experience(damage);
	victim->receive_special_damage( "none", damage, 1 );
	victim->set("last_attacker", caster);
    report( caster, victim );
}

int is_a_victim( object obj )
{
    if( living(obj) ) return 1;
}

void effect_all( int level, object caster, object targ )
{
    object *victim;
    int i,damage;
    
    if (!caster) return;
    caster->set_temp("cast_busy",0);
    gain_spell_experience(caster, TYPE, query_gain_spell_exp(level));
    damage = query_damage(caster, level);
    damage += random((int)caster->query_stat("int"));
    
    tell_object( caster,
      sprintf( bold(
      "�������͹�ķ�ء�ͻȻ�����������������������Ȼ����\n ��������Χһ�����ε�������ס�˻�����������˺���\n",caster )));

    tell_room( environment(caster), 
	  "�������͹�ķ�ء�ͻȻ�����������������������Ȼ�����������\n 
��������ʧȥ֪�������е�ϸ����ʼ�ֽ� ����������һ�����������ˣ�\n"
	  ,caster
	);
	
	caster->receive_damage( self_damage );
    victim = filter_array( all_inventory( environment( caster ) ),
             "is_a_victim", this_object() );
    if( sizeof(victim) ) {
      i = sizeof(victim);
      while(i--)
       if( (victim[i] != caster) && !(victim[i]->query("no_attack")) &&
           check_level( caster, victim[i], 0 ) ) {
        damage -= random((int)victim[i]->query_stat("int"));
        damage -= (int)victim[i]->query("defense_bonus")/4 +
                  random((int)victim[i]->query("defense_bonus")/2);
        if( damage < 0 ) damage = 1;
        victim[i]->kill_ob(caster);
	    caster->kill_ob(victim[i]);
	    caster->gain_experience(damage);
	    victim[i]->receive_special_damage( "none", damage, 1 );
	    victim[i]->set("last_attacker", caster);
	    report( caster, victim[i] );
       }
    }
}