#include <mudlib.h>

#define MARTIAL_NAME    "/god/kitgonfu"
#define GONFU_NAME      "ru-lai"

inherit DAEMON;

int eungon(object me, int level)
{
        
        if( (object)me->query("weapon1") ) {
                tell_object(me, 
                        "��װ���˲��ʺϵ�������\n");
                return 0;
        }

        tell_object(me, 
                "\n��ȫ����ԡ�ڷ��֮�У�׼��ʹ����"+
                to_chinese(GONFU_NAME)+"��!!\n" );

        tell_room( environment(me), 
                me->query("c_name")+
                "ȫ��ɢ����һ�ɼ�ƽ������Ϣ���������ƺ��ְ���һ��ɽ����������¥��ɱ�����ѵ���׼��ʹ��"+to_chinese(GONFU_NAME)+"? \n", me);

        me->set("attack_skill", MARTIAL_NAME); 
        me->set_temp("gonfu_busy",1);
        call_out("release_gonfu", 30+level, me);
        return 1;
}

void release_gonfu(object me)
{
        if( !me ) return;
        tell_object(me, 
                "\n\n������һ����, ֹͣʹ��"+to_chinese(GONFU_NAME)+"��\n" );
 
        tell_room( environment(me),
                me->query("c_name")+
                "������³�һ��������ʽ������\n", me);
 
        me->delete("attack_skill");
        me->delete_temp("gonfu_busy");
}
