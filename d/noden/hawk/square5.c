
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("������");
        set_long( @LONG_DESCRIPTION
������������ÿ���������еĵص㣬����Կ������ܿյ�����ɶ��
û�У����Ǳ���ĺõط�����������ȴ���������е㲻һ�����۲�һ�£���
�ƺ�������������ԼԼ����Ұ�޵���Х������˻������������������Ҫ��
��ร�ޡ�
LONG_DESCRIPTION
        );
        set( "exits", ([
                "south" : HAWK"square8",
                "north" : HAWK"square2",
                "west" : HAWK"square4",
                "east" : HAWK"square6",
                        ]) );
        set( "objects", ([
                "las" : MOB"las",
                "knight" : MOB"knight",
                        ]) );
        reset();
}//end of creat

