#include <mudlib.h>

#define MARTIAL_NAME    "monk/general/body_def"
#define GONFU_NAME   "body-def"

inherit DAEMON;

int eungon(object me, int level)
{
	tell_object(me,
            sprintf( "\n��ǿ���ɾã������... ����������\���壬׼��ʹ����%s��!!\n"
            ,to_chinese(GONFU_NAME) ) );

	tell_room( environment(me), 
	    sprintf("\n%s���һ����ȫ������������֮�У�׼��ʹ��%s��\n" 
	    ,me->query("c_name"),to_chinese(GONFU_NAME))
	, me);

	me->set("defense_skill", MARTIAL_NAME); 
        me->delete("attack_skill");
	me->set_temp("gonfu_busy",1);
	me->set_temp("eungon_times",me->query_temp("eungon_times")+1);
        if ( me->query("monk_gonfu/body-def") == 35 )
             me->set_temp("gonfu_top",1);
        else me->set_temp("gonfu_top",0);
	call_out("release_gonfu", 20+level, me);
	return 1;
}

void release_gonfu(object me)
{
	if( !me ) return;
	me->set_temp("eungon_times",me->query_temp("eungon_times")-1);
        if( me->query_temp("gonfu_top") && me->query_temp("eungon_times") > 0 )  return;
        if( !me->query_temp("gonfu_busy") ) return;
        if( me->query_temp("gonfu_top") ) 
            me->set_temp("gonfu_top",0);
	tell_object(me,
		"\n\n"+"������һ����, ֹͣʹ��"+to_chinese(GONFU_NAME)+"��\n");
 
 	tell_room( environment(me),
 		me->query("c_name")+
 		"������³�һ��������ʽ������\n" , me);
 
	me->delete("defense_skill");
	me->delete_temp("gonfu_busy");
}
