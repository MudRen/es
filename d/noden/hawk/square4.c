
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
                "south" : HAWK"square7",
                "east" : HAWK"square5",
                "north" : HAWK"square1",
                        ]) );
        set( "objects", ([
                "idol" : MOB"dragon_idol",
                        ]) );
        reset();
}//end of creat

