#include <mudlib.h>

#define MARTIAL_NAME    "monk/general/keep_flower"
#define GONFU_NAME   "keep-flower"

inherit DAEMON;

int eungon(object me, int level)
{
	if( (object)me->query("weapon1") ) {
		tell_object(me, 
			"��װ���˲��ʺϵ�������\n");
		return 0;
	}

	tell_object(me, 
		set_color("\n������ʳ��ָ�����ס�����黨֮״��׼��ʹ����"+
		to_chinese(GONFU_NAME)+"��!!\n" , "HIY") );
	tell_room( environment(me), 
		"\n"+me->query("c_name")+
		"����ʳ��ָ�����ס�����黨֮״, ׼��ʹ�������е� "+
		to_chinese(GONFU_NAME)+"��\n", me);

	me->set("attack_skill", MARTIAL_NAME); 
        me->delete("defense_skill");
       	me->set_temp("gonfu_busy",1);
        me->set_temp("eungon_times",me->query_temp("eungon_times")+1);
        if ( me->query("monk_gonfu/keep-flower") == 35 )
             me->set_temp("gonfu_top",1);
        else me->set_temp("gonfu_top",0);
	call_out("release_gonfu", 30+level, me);
	return 1;
}

void release_gonfu(object me)
{
	if( !me ) return;
	me->set_temp("eungon_times",me->query_temp("eungon_times")-1);
        if( me->query_temp("gonfu_top") && me->query_temp("eungon_times") > 0 ) return;
        if( !me->query_temp("gonfu_busy") ) return;
        if( me->query_temp("gonfu_top") )
            me->set_temp("gonfu_top",0);
	tell_object(me,
		set_color("\n\n������һ����, ֹͣʹ��"+to_chinese(GONFU_NAME)+"��\n","HIY") );
 	tell_room( environment(me),
 		me->query("c_name")+"������³�һ��������ʽ������\n", me);
 
	me->delete("attack_skill");
	me->delete_temp("gonfu_busy");
}
