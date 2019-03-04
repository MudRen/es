// This is a spell object. type -> other (defense evil).
//  (reverse divine)        By Yueh 1995/3/4
// Learning from /d/noden/forest/ruin/lich
// Learner must finish wanfu quest and ali < -200
// If caster's ali < bonus_ali, then dec = dec + bonus_dec
// If caster' ali > -200, it will fail.
// level      0    1    2    3    4
// cost      30   45   60   75   90
// dec       10   20   35   55   60
// rev_dec    5    7   10   20    0
// bonus_dec  2    4    6    8   10
// bonus_ali -3   -6   -9  -12  -20 * 1000
// time       2    5    8   12    8 * magic_shield skill
// skill     40   55   70   85  100
// G_LVL      4   10   18   28   40
// G_EXP      2    5   10   20   40
// Players can learn level 3.
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

int query_delay_time(object caster, int level)
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

int query_bonus_ali(int level)
{
    switch( level ) {
      case 1 : return    -6000;
      case 2 : return    -9000;
      case 3 : return    -12000;
      case 4 : return    -20000;
     default : return    -3000;  
    }
}

int query_bonus_dec(int level)
{
    switch( level ) {
      case 1 : return    4;
      case 2 : return   6;
      case 3 : return   8;
      case 4 : return    10;
     default : return    2;  
    }
}

int cast(int level)
{
	int chinese_mode, dec, ali;
	object me;
	
	me = this_player();
	chinese_mode = can_read_chinese();

	if( (int)me->query_skill(TYPE) < query_need_skill(level) ) {
	  tell_object( me, "���"+to_chinese(TYPE)+"���ܲ�����ʹ����ȼ���ħ��! \n" );
      return 0;
    }
	
    if( me->query_temp("effect/heart-protect-shield") ) {
      tell_object( me, "����һ��ħ�����Ķܻ�û��ʧ��! ���˷ѷ����ˡ�\n" );
      return 0;
    }
	ali = (int) me->query("alignment") ;
	if ( ali > -200){
		write( "��ʩչ����֮�����ģ�����ȴû���κ��·�����\n");
		tell_room( environment(me), me->query("c_name") + "�૵�����һ�����ģ�����ȴû���κ��·�����\n" , me);
	return 1;
	}

	write( "��ʩչ����֮�����ģ��������ǰ���γ�һ�����ε�������\n");
	tell_room( environment(me), 
		me->query("c_name") 
		+ "�૵�����һ�����ģ�һ��а���������"+
		me->query("c_name")+"����ǰ���γ�һ�����ε�������\n" ,	me
	);
	gain_spell_experience(me, TYPE, query_gain_spell_exp(level));
	me->set_temp("effect/heart-protect-shield", 1);
	dec = query_proportion(level);
	if (ali < query_bonus_ali(level)) 
		dec = dec + query_bonus_dec(level);

    me->apply_special_defense("evil", dec );
    me->apply_special_defense("divine", -query_reverse_proportion(level) );
    call_out( "release", 20+query_delay_time(me,level), me, level );
	return 1;
}

void release( object caster, int level )
{
    if( !caster ) return;
    tell_object( caster , "��о������ħ�����Ķ��ƺ���ʧ�ˡ�\n" );
    caster->apply_special_defense("evil", -query_proportion(level) );
    caster->apply_special_defense("divine", query_reverse_proportion(level) );
    caster->set_temp("effect/heart-protect-shield", 0);
}
