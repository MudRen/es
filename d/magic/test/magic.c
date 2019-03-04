// default function for spells. Create by Kyoko.
#include <mudlib.h>
#include <magic.h>

int modify_find_rate(object caster)
{
	if ( caster->query("player_invisible") )
		return (int)caster->query_level()/2;
	return 0;
}

void recharging( object player, int volumn, string spell_type )
{
   object weapon;
   int left, max, number, damage;
   weapon = player->query("weapon1");
   if( !weapon ) return;
   left = weapon->query("charge_left");
   max = weapon->query("max_charge");
   if( (string)weapon->query("special_damage_type")==spell_type && left < max ) {
     number = (int)weapon->query("stored_energy");
     damage = (int)weapon->query("special_damage")*2;
     if( volumn < 5 ) number++;
    
     if( number > damage ) {
       number -= damage;
       left++;
       weapon->set("charge_left", left);
     }
     weapon->set("stored_energy", number);
     return;
   }
}

int success_hit(int number, object caster, string type, int need_spell_level)
{
   int skill, spell_lvl;

   if( caster->query("npc") ) return 1;
   skill = (int)caster->query_skill("target");
   if( member_array(type, MAGIC_TYPES) != -1 ) {
     spell_lvl = (int)caster->query("spell_levels/"+type);
     if( spell_lvl < need_spell_level )
       number += number*(need_spell_level-spell_lvl) / 10;
   }   
   if( random(number) > skill ) return 0;
   else return 1;
}

void gain_spell_experience(object caster, string type, int exp)
{
	if( !caster ) return;
	if( member_array(type, MAGIC_TYPES) == -1 ) return;
	caster->add("spell_exps/"+type, exp);
}

int modify_sp_cost(object caster, int sp, string type, int need_spell_level)
{
	int spell_lvl;
	
	if( caster->query("npc") ) return sp;
	if( member_array(type, MAGIC_TYPES) == -1 ) return sp;
	spell_lvl = (int)caster->query("spell_levels/"+type);
	if( spell_lvl < need_spell_level )
		sp += sp*(need_spell_level-spell_lvl)/10;
	else if( (spell_lvl > need_spell_level+5) &&
			 (spell_lvl < (need_spell_level+15)) )
		sp -= sp * (spell_lvl-need_spell_level-5) / 20;
	else if( spell_lvl >= need_spell_level+15 )
		sp /= 2;
	return sp;
}

int modify_damage(object caster, int dam, string type, int need_spell_level)
{
	int spell_lvl;
	
	if( caster->query("npc") ) return dam;
	if( member_array(type, MAGIC_TYPES) == -1 ) return dam;
	spell_lvl = (int)caster->query("spell_levels/"+type);
	if( spell_lvl < need_spell_level )
		dam -= dam*(need_spell_level-spell_lvl)/20;
	if( dam < 1 ) dam = 1;
	return dam;
}

int modify_delay_time(object caster, int delay_time, string type, int need_spell_level)
{
	int spell_lvl;
	
	if( caster->query("npc") ) return delay_time;
	if( member_array(type, MAGIC_TYPES) == -1 ) return delay_time;
	spell_lvl = (int)caster->query("spell_levels/"+type);
	if( spell_lvl < need_spell_level )
		delay_time -= delay_time*(need_spell_level-spell_lvl)/25;
	if( delay_time < 1 ) delay_time = 1;
	return delay_time;
}

void report( object caster, object victim )
{
   string message;
   message= "/adm/daemons/statsd"->status_string(victim);
   if( living( caster ) )
     tell_object( caster, 
       "( " + victim->query("c_name") + message+" )\n" );

   if( living( victim ) )
     tell_object( victim, 
       "( ��"+message+" )\n" );
}

int check_level(object caster, object victim, int one)
{
	if( !userp(caster) || !userp(victim) || 
		( (int)victim->query_level()>4 && ( (int)caster->query_level()>4)) )
		return 1;
	if( one ) {
		tell_object( caster, set_color(
			"������֮��, �㲻���Թ�������ˡ�\n","HIY",caster) );
		tell_object( victim, set_color(
			sprintf("%s(%s)���Թ�����, �������ܵ�������ֹ���������辯�档\n",
				caster->query("c_cap_name"), caster->query("name")), "HIC", victim));
		tell_room( environment( victim ), 
			sprintf("%s(%s)���Թ���%s(%s), �������ܵ�������ֹ���������辯�档\n",
				caster->query("c_cap_name"), caster->query("name"),
				victim->query("c_name"), victim->query("name")) ,
				({ caster, victim }));
	} else
		tell_object( victim, set_color(
			"����ͻȻ����һ�����������: ��ĵȼ�̫���ˣ����ܱ� PK��\n"
			"���ܵ�����ΰ���ħ����������ܵ��˺���\n", "HIC", victim));
	return 0;
}
