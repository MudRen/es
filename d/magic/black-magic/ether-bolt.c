// This is a spell object, damage type -> energy.
// level    0    1    2    3    4    5    6    7    8
// cost    20   27   34   41   48   55   62   69   76
// damage  20   30   40   50   60   70   80   90  100
// type   one  one  one  one  one  one  one  one  one
// delay    1    1    1    2    2    2    3    3    3
// skills  20   30   40   50   60   70   80   90  100
// miss    10   20   30   40   50   60   70   80   90 % target 100
// G_LVL    5   10   15   20   25   30   35   40   45
// G_EXP    1    3    6   10   15   21   28   36   45
// found by monster rate = monster(int*3+kar) - killer(int) / 60
// found by player rate  = victim(int+kar) - killer(int) / 60
#include <mudlib.h>
#include "/d/magic/magic.c"
#define TYPE "black-magic"

inherit DAEMON;

#define find_rate 60

int query_gain_spell_exp(int level)
{
	switch( level ) {
		case 0 : return  1;
		case 1 : return  3;
		case 2 : return  6;
		case 3 : return 10;
		case 4 : return 15;
		case 5 : return 21;
		case 6 : return 28;
		case 7 : return 36;
		case 8 : return 45;
		default : return 0;
	}
}

int query_need_spell_level(int level)
{
	return 5+5*level;
}

int query_sp_cost(object caster, int level, string target)
{
	return modify_sp_cost(caster, 20+7*level, TYPE, query_need_spell_level(level));
}

int query_need_skill(int level) { return 20+10*level; }

int query_delay_time( int level )
{
   switch( level ) {
     case 1 : return 1;
     case 2 : return 1;
     case 3 : return 2;
     case 4 : return 2;
     case 5 : return 2;
     case 6 : return 3;
     case 7 : return 3;
     case 8 : return 3;
    default : return 1;  }
}

int query_damage(object caster, int level)
{
   return modify_damage(caster, 20+level*10, TYPE, query_need_spell_level(level));
}

int query_find_rate(object caster, object victim)
{
  if( !userp(victim) )
    return (int)victim->query_stat("int")*3 -
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
	  tell_object( me, 
        "��ĺ�ħ�����ܲ�����ʹ����ȼ���ħ��! \n" );

      return 0;
    }
	if( target=="NONE" && !(targ = me->query_attacker()) ) { 
		write("Ҫ��˭ʩչ��̫֮����\n");
		return 0;
	} else {
		if ( !targ)
			targ = present( target, environment(me) );
		if( !targ ) { 
		  write("���Ŀ�겢�������\n");
	      return 0;
	    }
	}

	if( !living(targ) ) {
	    write("��̫֮����Ŀ����������\n");
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
	me->block_attack( query_delay_time(level)*2 );
	me->set_temp("msg_stop_attack", 
 	        "( ������ʩ�����޷������� )\n"   );
	write(set_color(sprintf( 
		"�㿪ʼ���о����ռ����ڿռ��е���������....��\n"),"HIY"));

	tell_room( environment(me), 
		me->query("c_name") + "��ʼ���о�������ĳ������....��\n" ,
		me
	);
	if( !(targ->query_attackers()) && 
	   ( random(find_rate)<query_find_rate(me, targ) )  ) {
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
	if (delay_time > 2) call_out("pre_effect1", 2 , me, targ);
	if (delay_time > 4) call_out("pre_effect1", 4 , me, targ);
	call_out("effect", delay_time, level, me, targ );
	return 1;
}

void pre_effect1(object caster, object target)
{
	if( !caster ) return;
	if( !target || !present(target, environment(caster)) ) 
		caster->set_temp("cast_flee",1);
}

void effect(int level, object caster, object victim)
{
	int damage;
	string msgc, cmsgc, msgv, cmsgv, msgo, cmsgo;

	if (!caster || nullp(caster) ) return;
    caster->set_temp("cast_busy",0);
    damage = query_damage(caster, level);
	damage += random((int)caster->query_stat("int"));
    recharging( caster, damage, "energy" );
    
	if( !victim || !present(victim, environment(caster)) ) {
		tell_object( caster,set_color (sprintf(
			"���Ŀ���Ѿ����������ˡ�\n"),"HIY"));

		gain_spell_experience(caster, TYPE, query_gain_spell_exp(level)/2);
		return;
	}
	
	if( !success_hit( 10+level*10, caster, TYPE, query_need_spell_level(level) ) ) {
	  tell_object(caster, 
	    sprintf("�㽫��������������%sһָ����쬡���һ����������ˣ�\n",
			victim->query("c_name") ));
	  tell_room( environment(caster), 
		sprintf("��Ȼ%s������ǰһָ����쬡���һ����֪ʲ�ᶫ�����˳�������û�����κ��ˣ�\n",
		  caster->query("c_name") )
		,caster
	  );
	  gain_spell_experience(caster, TYPE, query_gain_spell_exp(level)/2);
	  return;
	}

	// hit effect ...	
	switch( level ) {
		case 0..7:
			cmsgc = "�㽫��������������%s(%s)һָ����쬡���һ�����һ�����ε�������\n";
			cmsgv = "%s(%s)��������һָ����쬡���һ����֪��ʲ�ᶫ���������㣡\n";
			cmsgo = "��Ȼ%s(%s)������%sһָ����쬡���һ����%s(%s)����¶��ʹ��ı��顣\n";
			break;
		case 8:
			cmsgc = "�㽫��������������%s(%s)һָ�������һ������Ĺ�â��\n";
			cmsgv = "%s(%s)��������һָ��һ������Ĺ�â�������㣡\n";
			cmsgo = "��Ȼ%s(%s)������%sһָ��һ������Ĺ�â������%s(%s)��\n";
			break;
		default:
			cmsgc = "�㽫��������������%s(%s)һָ����쬡���һ�����һ�����ε�������\n";
			cmsgv = "%s(%s)��������һָ����쬡���һ����֪��ʲ�ᶫ���������㣡\n";
			cmsgo = "��Ȼ%s(%s)������%sһָ����쬡���һ����%s(%s)����¶��ʹ��ı��顣\n";
			break;	}
	tell_object(caster, set_color(
		sprintf(cmsgc, victim->query("c_name"), victim->query("name"))
				, "HIY", caster) );
	tell_object(victim, set_color(
		sprintf(cmsgv, caster->query("c_name"), caster->query("name"))
				, "HIY", victim) );
	tell_room(environment(caster), 
		sprintf(cmsgo, caster->query("c_name"), caster->query("name"),
		    	victim->query("c_name"),victim->query("c_name"), victim->query("name")),
		({ caster, victim }) );

	// Count the Damage.
	damage -= random((int)victim->query_stat("int"));
	if( damage < 0 ) damage = 1;
	victim->kill_ob(caster);
	caster->kill_ob(victim);
	caster->gain_experience(damage);
	gain_spell_experience(caster, TYPE, query_gain_spell_exp(level));
	victim->receive_special_damage( "energy", damage, 0 );
	victim->set("last_attacker", caster);
	report( caster, victim );
}
