// This is a spell object.
// level    0    1    2    3    4
// cost    30   45   60   75   90
// extra_ac 5   10   15   20   30
// extra_db 0    2    5   10   20
// time     2    4    6   10   15 * magic_shield skill
// skill   40   55   70   85  100
// G_LVL    4   10   18   28   40
// G_EXP   20   50  100  200  400
#include <mudlib.h>
#include "/d/magic/magic.c"
#define TYPE "misc"

inherit DAEMON;

int query_gain_spell_exp(int level)
{
	switch( level ) {
		case 0 : return  20;
		case 1 : return  50;
		case 2 : return 100;
		case 3 : return 200;
		case 4 : return 400;
		default : return 0;
	}
}

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

int query_sp_cost(object caster, int level)
{
	return modify_sp_cost(caster, 30+15*level, TYPE, query_need_spell_level(level));
}

int query_need_skill(int level) { 40+15*level; }

int query_delay_time( object caster, int level )
{
    int skill, time;
    skill = (int)caster->query_skill("magic-shield");
    switch( level ) {
      case 0 : time =   2*skill; break;
      case 1 : time =   4*skill; break;
      case 2 : time =   6*skill; break;
      case 3 : time =  10*skill; break;
      case 4 : time =  15*skill; break;
     default : time =   0; break;  
    }
    return modify_delay_time(caster, time, TYPE, query_need_spell_level(level));
}

int query_extra_ac(int level)
{
    switch( level ) {
      case 1 : return   10;
      case 2 : return   15;
      case 3 : return   20;
      case 4 : return   30;
     default : return    5;  
    }
}

int query_extra_db(int level)
{
    switch( level ) {
      case 1 : return    2;
      case 2 : return    5;
      case 3 : return   10;
      case 4 : return   20;
     default : return    0;  
    }
}

int cast(int level)
{
	object me;
	
	me = this_player();

	if( (int)me->query_skill(TYPE) < query_need_skill(level) ) {
	  tell_object( me, "���"+to_chinese(TYPE)+"���ܲ�����ʹ����ȼ���ħ��! \n"
      );
      return 0;
    }

    if( me->query_temp("effect/magical-shield") ) {
      tell_object( me, "����һ��ħ��֮�ܻ�û��ʧ��! ���˷ѷ����ˡ�\n" );
      return 0;
    }
	write( "��ʩչħ��֮�����ģ�һ��������������������ǰ�γ�һ������"
		   "��ħ���ܡ�\n"
	);
	tell_room( environment(me), me->query("c_name") 
		+ "�૵�����һ�����ģ�һ���������������" + me->query("c_name")+
		"����ǰ�γ�һ�����ε�ħ���ܡ�\n", me );
	me->set_temp("effect/magical-shield", 1);
	gain_spell_experience(me, TYPE, query_gain_spell_exp(level));
    me->set_temp("extra_ac/magical-shield", query_extra_ac(level));
    me->set_temp("extra_db/magical-shield", query_extra_db(level));
    me->calc_armor_class();
    call_out( "release", 20+query_delay_time(me,level), me, level );
	return 1;
}

void release( object caster, int level )
{
    if( !caster ) return;
    tell_object( caster , "��о������ħ�����ƺ���ʧ�ˡ�\n" );
    caster->delete_temp("extra_ac/magical-shield");
    caster->delete_temp("extra_db/magical-shield");
    caster->set_temp("effect/magical-shield", 0);
    caster->calc_armor_class();
}
