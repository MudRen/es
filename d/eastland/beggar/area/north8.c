#include "../dony.h"

inherit ROOM;

void create()
{
	::create();
        set_short( "north8", "��·" );
	set_long(@C_LONG
������������һ����Ϊ���Ĵ�·��,Լ��������ƥ���С���·�򶫡�����
�����졣������·�������Ǭ����,·�Ե�ֲ���޼��ĺ�����,������������,����
�㳡��Ƭ��ͺͺ�ľ������ǲ��ɶ���Ͼ����������Ӽ����ϴ�����,��˵�Ǵ���
����ĵ�·���������, ȴ�������κ��˹������������ĺۼ�,��һ���ǳ����
ĳλ����֮�֡��ɱ���ԶԶ����ȥ,һ���Ű����ķ�����Ȼ�Ǵ������Ǿ�ס�ĵط�
������ͨ�������Ʒ���������
C_LONG
	);
        set_outside("noden");
	set( "exits", ([
                      "east":DBEGGAR"north5.c",
                      "west":DBEGGAR"north10.c" 
	]) );
        set( "pre_exit_func", 
                      ([ 
                      "east": "can_pass",
                      "west": "can_pass"
        ]) );
        set( "objects", ([
                      "chau":DMONSTER"chau.c",
                      "burro":DMONSTER"donkey.c"
        ]) );                                    
     reset();
}

int can_pass()
{ 
   
   if( this_player()->query_temp("mounting") && !wizardp(this_player() ) 
       &&  present("chau") ){  
      tell_object(this_player(),
        "��Ǯ�������������ˡ��:�����������ҵ�¿��������,�ǲ����ҵ�?\n" );
            return 1;
     } return 0;
}
