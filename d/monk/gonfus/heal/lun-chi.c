#include <mudlib.h>
#include <conditions.h>

#define COND_NAME "bleeding"

inherit DAEMON;

int query_fp_cost() { return 25; }

int eungon(object me, int level)
{
	mixed bleed;
	int chinese_mode, skill, fp;
        
	chinese_mode=can_read_chinese(me);
	if( me->query_temp("monk_bleeding") ) {
		tell_object( me, 
			"����˿ڸոմ�����ˡ�\n");
		return 0;
	}
	
	if( me->query("weapon1") ) {
		tell_object(me, 
			"ι...���������޷�ʩչ��ָ��Ѩ�ġ�\n");
		return 0;
	}

	if( !bleed = me->query("conditions/"+COND_NAME) ) {
		tell_object( me, 
			"�㲢û��ʧѪ�����Ρ�\n");
		return 0;
	}

	if( !skill = (int)me->query_skill("force-stun") ) {
		tell_object( me,
			"�㲢û��ѧ����Ѩ�ļ��ܡ�\n");
		return 0;
	}

    fp = (int)me->query("force_points");
    if ( !fp || fp < query_fp_cost() ) {
        tell_object( me,
            "����������������ܹ�ʩչ��ָ��Ѩ��\n");
        return 0;
    }

	me->set_temp("monk_bleeding", 1);
	me->add("force_points", -query_fp_cost());
	tell_object( me,
		"�����ּ����Լ�����������ޣ�̫�׵�Ѩ�����Լ����˿�ֹѪ....\n");
	tell_room( environment(me), 
		me->query("c_name")+"���ּ��㣬�������˿�ֹѪ��\n", me );
		
	if( skill/2 + random(skill/2) > 10 * bleed[1] * bleed[2] / bleed[0] )
		BLEEDING->remove_effect(me);
	else {
		tell_object( me, 
			"���ǽ��ֻ�Ǽ��������ƣ���δ��ȫ�ɹ�\��\n");
		// make the result random case.
		switch( random(3) ) {
			case 1 : bleed[0] *= 2; break;
			case 2 : bleed[1] -= bleed[1]/2; break;
			case 3 : bleed[2] -= bleed[2]/2; break;
		}
		me->set("conditions/"+COND_NAME, bleed);
	}
	call_out("debleeding_again", 100-skill/2, me);
	return 1;
}

void debleeding_again(object player)
{
	if( !player ) return;
	player->delete_temp("monk_bleeding");
}
