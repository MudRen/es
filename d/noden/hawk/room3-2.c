
#include "hawk.h" 

inherit ROOM;

void create()
{
        ::create();
        set_short("������");
        set("light",1);
        set_long( @LONG_DESCRIPTION
�����������峤�ϰ칫��Ϣ�ĵط���ǽ�Ϲ������ϡ��ŹֵĶ�����
�������˳�������ʱ�����������õ���ս��Ʒ����ɫ�Ĺ��߰�����������
���������һ�㣬������ȴ�޷��о������ߵ���Դ�������Ķ���
LONG_DESCRIPTION
        );
        set( "objects", ([
                "elder" : MOB"small_elder",
                "guard1" : MOB"guard",
                "guard2" : MOB"guard",
                        ]) );

        set( "exits", ([
                "south" : HAWK"room3-1",
                     ]) );
        set("pre_exit_func",(["south" : "go_south" ]) ) ;
        reset();
}//end of creat

int go_south()
{
        object caster;
        int aa;

        caster = present("elder");
        if (!caster) return 0;
        aa = (int)caster->query_temp("no_way_out");

        if (aa)
        {
                write("���ܱ�ѩ��ס�������������û�취�뿪���\n");
                return 1;
        }
        return 0;
}
