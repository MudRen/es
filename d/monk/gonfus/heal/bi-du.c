#include <mudlib.h>
#include <conditions.h>

#define COND_NAME "simple_poison"

inherit DAEMON;

int query_fp_cost() { return 25; }

varargs int eungon(object me, int level)
{
	int chinese_mode, skill, fp;

	chinese_mode = can_read_chinese(me);

	if( me->query_temp("monk_poison") ) {
		tell_object( me, 
			"��ձƹ�����û������һ�Ρ�\n" );
		return 0;
	}

	if( !me->query("conditions/"+COND_NAME) ) {
		tell_object( me, 
			"�㲢û���ж������Ρ�\n");
		return 0;
	}

	if( me->query_attackers() ) {
		tell_object( me,
			"��ս�����˹�\�ƶ�? ������?\n");
		return 0;
	}

	if( !skill = (int)me->query_skill("force-stun") ) {
		tell_object( me,
			"�㲢û��ѧ��Ѩ��ѧ�ļ��ܡ�\n");
		return 0;
	}

	fp = (int)me->query("force_points");
	if( !fp || fp < query_fp_cost() ) {
		tell_object( me,
			"����������������ܹ��˹�\�ƶ���\n");
		return 0;	
	}
	tell_object( me, 
		"�������Ѩ�����к�ȫ������ֲ�������������������ͼ�Ƴ�����֮�� ....\n");

	tell_room( environment(me), 
		me->query("c_name")+"������\����ͼ�Ƴ����ϵĶ��ء�\n" , me );

	me->set_temp("block_command", 1);
	me->set_temp("block_defense", 1);
	me->add("force_points", -query_fp_cost());
	call_out("result", 10-skill/20, me);
	return 1;
}

void result(object me)
{
	mixed poison;
	int skill, chinese_mode;

	if( !me ) return;
	me->delete_temp("block_command");
	me->delete_temp("block_defense");
	chinese_mode = can_read_chinese(me);

	if( !poison = (mixed)me->query( "conditions/" + COND_NAME ) ) {
		tell_object( me,
			"��Ķ��ոս��ˡ�\n");
		return;
	}

	if ( sizeof(poison) != 3 ) {
		log_file("Monk_bidu","Error poison index find in "+me->query("name")+"\n");
		me->delete("conditions/"+ COND_NAME);
		tell_object( me, "���еĶ������� !! ��֪ͨ��ʦ !!\n");
		return;
	}
	skill = (int)me->query_skill("force-stun");
	if( skill/2 + random(skill/2) > 5 * poison[1] * poison[2] / poison[0] ) {
		tell_object( me,
			"��ɹ�\�Ľ����ڵĶ��Ƴ�������!\n");
		SIMPLE_POISON->remove_effect(me);
	} else {
		tell_object( me,
			"�㹦\����������ѧ���ޣ�ֻ�Ƴ���һ���ݵĶ���....\n");
		// make the result random case.
		switch( random(3) ) {
			case 1 : poison[0] *= 2; break;
			case 2 : poison[1] -= poison[1]/2; break;
			case 3 : poison[2] -= poison[2]/2; break;
		}
		me->set("conditions/"+COND_NAME, poison);
	}

	tell_room( environment(me), 
		me->query("c_name")+"����һ����, վ��������\n", me );
	me->set_temp("monk_poison", 1);
	call_out("depoison_again", 120-skill/2, me);
}

void depoison_again(object player)
{
	if( !player ) return;
	tell_object( player, 
		"��е������������, ���ܱƶ��ˡ�\n");
	player->delete_temp("monk_poison");
}