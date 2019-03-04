#include <mudlib.h>

#define MARTIAL_NAME      "monk/general/wu_sur"
#define D_MARTIAL_NAME    "monk/general/d_wu_sur"
#define GONFU_NAME   "wu-sur"

inherit DAEMON;

int eungon(object me, int level)
{
	object weapon;
	
	weapon = (object)me->query("weapon1");
	if( !weapon || (string)weapon->query("type") != "longblade" ) {
		tell_object(me, 
			"�㲢δװ���ʺϵ�������\n");
		return 0;
	}

	tell_object(me, 
		"\n����ˡСɮ����!!�����˹�\��֣�׼��ʹ����"+
		to_chinese(GONFU_NAME)+"��!!\n" );

	tell_room( environment(me), 
		me->query("c_name")+
		"˫�ֺ�ʮ��΢΢��Ҿ�������ϵ�"+weapon->query("short")+
		"����׼��ʹ��"+to_chinese(GONFU_NAME)+"��\n", me);

	me->set("attack_skill", MARTIAL_NAME);
	me->set("defense_skill", D_MARTIAL_NAME);
	me->set_temp("gonfu_busy",1);
        me->set_temp("eungon_times",me->query_temp("eungon_times")+1);
        if ( me->query("monk_gonfu/wu-sur") == 35 )
             me->set_temp("gonfu_top",1);
        else me->set_temp("gonfu_top",0);
	call_out("release_gonfu", 20+level, me);
	return 1;
}

void release_gonfu(object me)
{
	if( !me ) return;
        me->set_temp("eungon_times",me->query_temp("eungon_times")-1);
        if( me->query_temp("eungon_times") > 0 ) return;
        if( me->query_temp("gonfu_top") && !me->query_temp("gonfu_busy") ) return;
        if( !me->query_temp("gonfu_busy") ) return;
        if( me->query_temp("gonfu_top") )
            me->set_temp("gonfu_top",0);
	tell_object(me, 
		"\n\n������һ����, ֹͣʹ��"+to_chinese(GONFU_NAME)+"��\n" );
 
 	tell_room( environment(me),
 		me->query("c_name")+
 		"������³�һ��������ʽ������\n", me);
 
	me->delete("attack_skill");
	me->delete("defense_skill");
	me->delete_temp("gonfu_busy");
}
