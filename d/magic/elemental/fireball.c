// This is a spell object, damage type -> fire.
// level    0    1    2    3    4    5    6    7    8
// cost    10   20   30   40   55   70   85  100  200
// damage  10   23   36   50   70   90  110  130  160
// type   one  one  one  one  one  one  one  one  all
// delay    1    1    1    2    2    2    3    3    4
// skill   15   25   35   45   55   65   75   85   95
// miss     5   15   25   35   45   55   65   75    ? % target 100
// G_LVL    5   10   15   20   25   30   35   40   45
// G_EXP    2    5   10   17   30   45   62   75   95
// found by monster rate = monster(int*2+kar) - killer(int) / 60
// found by player rate  = victim(int+kar) - killer(int) / 60
#include <mudlib.h>
#include "/d/magic/magic.c"
#define TYPE "elemental"

inherit DAEMON;

#define find_rate 60

int query_gain_spell_exp(int level)
{
	switch( level ) {
		case 0:  return  2;
		case 1:  return  5;
		case 2:  return 10;
		case 3:  return 17;
		case 4:  return 30;
		case 5:  return 45;
		case 6:  return 62;
		case 7:  return 75;
		case 8:  return 95;
		default: return  0;
	}
}

int query_need_spell_level(int level)
{
	return 5+5*level;
}

int query_need_skill(int level)
{
	return 15+10*level;
}

int query_sp_cost(object caster, int level, string target)
{
	int sp;
	switch( level ) {
		case 1:  sp =  20; break;
		case 2:  sp =  30; break;
		case 3:  sp =  40; break;
		case 4:  sp =  55; break;
		case 5:  sp =  70; break;
		case 6:  sp =  85; break;
		case 7:  sp = 100; break;
		case 8:  sp = 200; break;
		default: sp =  10; break;
	}
	return modify_sp_cost(caster, sp, TYPE, query_need_spell_level(level));
}

int query_damage(object caster, int level)
{
	int dam;
	switch( level ) {
		case 1:  dam =  23; break;
		case 2:  dam =  36; break;
		case 3:  dam =  50; break;
		case 4:  dam =  70; break;
		case 5:  dam =  90; break;
		case 6:  dam = 110; break;
		case 7:  dam = 130; break;
		case 8:  dam = 160; break;
		default: dam =  10; break;
	}
	return modify_damage(caster, dam, TYPE, query_need_spell_level(level));
}

int query_delay_time(int level)
{
	switch( level ) {
		case 1:  return 1;
		case 2:  return 1;
		case 3:  return 2;
		case 4:  return 2;
		case 5:  return 2;
		case 6:  return 3;
		case 7:  return 3;
		case 8:  return 4;
		default: return 1;
	}
}

string query_effect_func(int level)
{
	if( level < 8 )
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
        	"���Ԫ��ħ�����ܲ�����ʹ����ȼ���ħ��! \n" );
    	return 0;
    }
	
	if( target=="NONE" && !(targ = me->query_attacker()) ) { 
		write( "Ҫ��˭ʩչ��������\n");
	    return 0;
	} else {
		if ( !targ)
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
	if( targ == me ) {
		write( "�� .... ��̫�ðɡ�\n");
		return 0;
	}
	if( !check_level( me, targ, 1 ) ) return 0;
	me->set_temp("cast_busy",1);
	if( userp(me) ) me->block_attack(query_delay_time(level)*2);
 	me->set_temp("msg_stop_attack", 
		set_color("( ������ʩ�����޷������� )\n", "HIR", me) );
	write( 
		set_color("\n�㿪ʼ������������� ���� �� ��Ī .... \n", "HIR") );
	tell_room( environment(me), 
		sprintf("%s(%s)��ʼ�����\n", me->query("c_name"), me->query("name"))
		, me);
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
	if( !userp(me) && me->query("magic_delay") )
		delay_time = (int)me->query("magic_delay")*2;
	else
		delay_time = query_delay_time(level)*2;
	call_out("pre_effect", 1, me, targ, level);
	if (delay_time > 2) call_out("pre_effect1", 2 , me, targ);
	if (delay_time > 4) call_out("pre_effect1", 4 , me, targ);
	call_out(query_effect_func(level), delay_time, level, me, targ );
	return 1;
}

void pre_effect(object caster, object target, int level)
{
	string c_msg;

	if( !caster ) return;
	switch( level ) {
		case 0..1:
			c_msg = "\n%s�����п�ʼ�ۼ�һ��СС�Ļ���\n\n";
			break;
		case 2..5:
			c_msg = "%s�����п�ʼ�ۼ�һ�����ȵĴ����\n\n";
			break;
		case 6:
			c_msg = "\n%s�����п�ʼ�ۼ�һ�ſ��¶��޴�Ļ���\n\n";
			break;
		case 7:
			c_msg = "\n%s�����п�ʼ�ۼ�һ�����ܵ��һ��γ�һ���޴�Ļ���\n\n";
			break;
		case 8:
			c_msg = "\n%s�����п�ʼ�ۼ�һ�Ż��, ���γ�һֻ���ȵĻ��� �� ����֮ӥ��\n\n";
			break;
		default:
			c_msg = "\n%s�����п�ʼ�ۼ�һ�Ż���\n\n";
			break;
	}
	tell_object(caster, set_color(
		sprintf(c_msg, "��"), "HIR", caster));
	tell_room(environment(caster), 
		sprintf(c_msg, sprintf("%s(%s)", caster->query("c_name"),
			caster->query("name"))), caster);
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
	string msgc, cmsgc, msgv, cmsgv, msgo, cmsgo;

	if( !caster ) return;
	caster->delete_temp("cast_busy");
	damage = query_damage(caster, level);
	damage += random((int)caster->query_stat("int"));
	recharging( caster, damage, "fire" );

	// Caster or dest moved or dest dead.
	if( !victim || !present(victim, environment(caster)) ) {
		tell_object( caster, 
			"\n�㽫���еĻ���������һ��, ը��һ���󶴡�\n\n");
		tell_room( environment(caster), 
			sprintf("%s(%s)�����еĻ���������һ��, ը��һ���󶴡�\n",
				caster->query("c_name"), caster->query("name")) ,caster);
		gain_spell_experience(caster, TYPE, query_gain_spell_exp(level)/2);
		return;
	}
	// Miss. :(
	if( !success_hit( 5+level*10, caster, TYPE, query_need_spell_level(level) ) ) {
		tell_object( caster, 
			sprintf("�㽫���еĻ�����%s(%s)����ȥ, ��ϧ������!\n",
				victim->query("c_name"), victim->query("name")));

		tell_room( environment(caster), 
			sprintf("%s(%s)�����еĻ��򶪳�ȥ, ��֪����δ�?\n",
				caster->query("c_name"), caster->query("name")) , caster);
		gain_spell_experience(caster, TYPE, query_gain_spell_exp(level)/2);
		return;
	}

	// hit effect ...	
	switch( level ) {
		case 0..3:
			cmsgc = "�㽫���еĻ���������ȥ, ���䡹��һ����%s(%s)������ը��!\n";
			cmsgv = "%s(%s)�����еĻ�����������϶�����, ���䡹��һ��ը��!\n";
			cmsgo = "%s(%s)�����еĻ��򶪳�ȥ, ���䡹��һ����%s(%s)����ը��!\n";
			break;
		case 4..6:
			cmsgc = "�㽫���еĻ��򶪳�ȥ, ����¡����һ��ը��%s(%s)����!\n";
			cmsgv = "%s(%s)�����еĻ������㶪����, ����¡����һ��ը��!\n";
			cmsgo = "%s(%s)�����еĻ��򶪳�ȥ,����¡����һ��ը��%s(%s)����!\n";
			break;
		case 7:
			cmsgc = "�㽫���еĻ��򶪳�ȥ, ����¡����һ����%s(%s)������һ�������һ�֮��!\n";
			cmsgv = "%s(%s)�����еĻ������㶪����, ����¡����һ������������һ�������һ�֮��!\n";
			cmsgo = "%s(%s)�����еĻ��򶪳�ȥ,����¡����һ����%s(%s)������һ�������һ�֮��!\n";
			break;
		default:
			cmsgc = "�㽫���еĻ���������ȥ, ���䡹��һ����%s(%s)����ը��!\n";
			cmsgv = "%s(%s)�����еĻ�����������϶�����, ���䡹��һ��ը��!\n";
			cmsgo = "%s(%s)�����еĻ��򶪳�ȥ, ���䡹��һ����%s(%s)����ը��!\n";
			break;
	}
	tell_object(caster, set_color(
		sprintf(cmsgc, victim->query("c_name"), victim->query("name"))
				, "HIC", caster) );
	tell_object(victim, set_color(
		sprintf(cmsgv, caster->query("c_name"), caster->query("name"))
				, "HIR", victim) );
	tell_room(environment(caster), 
		sprintf(cmsgo, caster->query("c_name"), caster->query("name"),
			victim->query("c_name"), victim->query("name")),
		({ caster, victim }) );

	// Count the Damage.
	damage -= random((int)victim->query_stat("int"));
	if( damage < 0 ) damage = 1;
	victim->kill_ob(caster);
	caster->kill_ob(victim);
	caster->gain_experience(damage);
	gain_spell_experience(caster, TYPE, query_gain_spell_exp(level));
	victim->receive_special_damage("fire", damage);
	victim->set("last_attacker", caster);
	report( caster, victim );
}

int is_a_victim(object obj, object me)
{
	if( !living(obj) ) return 0;
	if( obj->query("no_attack") ) return 0;
	if( obj == me ) return 0;
	if( !check_level(me, obj, 0) ) return 0;
	return 1;
}

void effect_all( int level, object caster, object targ )
{
	object *victim;
	int i,damage;

	caster->delete_temp("cast_busy");
	gain_spell_experience(caster, TYPE, query_gain_spell_exp(level));
	damage = query_damage(caster, level);
	damage += random((int)caster->query_stat("int"));
	recharging( caster, damage, "fire" );

	if( !targ || !present(targ, environment(caster)) ) {
		tell_room( environment(caster), 
			"\n���񡸿���֮ӥ��һ�ɳ��죬��ʧ���١�\n\n" );
		return;
	}

	tell_object( caster, 
		set_color("\n������ǰһָ, ���񡸿���֮ӥ������˵�����,"+
			"����¡����һ�������ը!\n\n", "HIR", caster) );
	tell_room( environment(caster), 
		sprintf("\n%s��ָ��ǰһָ, ���񡸿���֮ӥ������˵�����, ����¡����һ��\n"+
			"������ǰͻȻһ��, ��ֻ�е����ȵĵ���֮���ƺ�Ҫ��һ���ճɻҽ�!\n\n",
			caster->query("c_name") ) , caster);
	victim = filter_array(all_inventory(environment(caster)),
		"is_a_victim", this_object(), caster);
	for( i=sizeof(victim)-1; i>=0; i-- ) {
		damage -= random((int)victim[i]->query_stat("int"));
		if( damage < 0 ) damage = 1;
		victim[i]->kill_ob(caster);
		caster->kill_ob(victim[i]);
		caster->gain_experience(damage);
		victim[i]->receive_special_damage("fire", damage);
		victim[i]->set("last_attacker", caster);
		report( caster, victim[i] );
	}
}
