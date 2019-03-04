//#pragma save_binary

#include <mudlib.h>

#define SCHOLAR_GONFU_DIR "/d/scholar/gonfus/"

inherit DAEMON;

int help();

string *gonfus = ({ "force-heal", "couples_sword", "mar_short", "booyi",
                    "tanlo", "unknow", "han", "song", "tang" , "poem"});

int cmd_enhant(string str)
{
/*
        string *gonfus = ({ "force-heal", "couples_sword", "mar_short",
                            "booyi", "tanlo", "unknow", "han", "song",
                            "tang" , "poem"});
*/
        int level;
        object me, code;

        if( !str ) return help();
        me = this_player();

        if( str == "stop" ) {
                write( 
                        "��ֹͣ�����κ��书\��\n");
                me->delete("attack_skill");
                me->delete("defense_skill");
                return 1;
        }

        if( member_array(str, gonfus) == -1 )
                return notify_fail("��! ������һ�ֹ�\�� ? \n");

        if( (int)me->query("stop_attack")>0 )
                return notify_fail (
                        "( ����һ��������û����ɣ��޷�ʩչ��ʽ�� )\n");

        if( me->query("gonfu_busy") || me->query_temp("gonfu_busy") )
        return notify_fail("��Ŀǰ���˹�\�����޷��������������书\��\n");

        if( me->query_temp("stop_enhant") || me->query("stop_enhant") )
                return notify_fail("����׼��ʹ����ʽʱ����Ȼ������ͻȻ��\��ȫʧ�ˡ�\n");
        
        if( undefinedp(level=(int)me->query("scholar_gonfu/"+str)) )
                return notify_fail("��! ������ֹ�\�� ? \n");

        code = find_object_or_load(SCHOLAR_GONFU_DIR+str);
        if( !code )
                return notify_fail("û�����ֹ�\��! ��֪ͨ��ʦ���� bug ָ�����ʽ���ơ�\n");

        code->enhant(me, level);
        return 1;
}

int help()
{
                write( @C_HELP
ָ���ʽ: enhant <��ʽ����>

���ָ����������ʩչ��ʽ��������� gonfus ָ���Ŀǰ�Ѿ�ѧ�����ʽ�б�
C_HELP
                );
    return 1;
}
