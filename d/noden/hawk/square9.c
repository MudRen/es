
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
        "west" : HAWK"square8",
        "north" : HAWK"square6",
                     ]) );
    reset();
}//end of creat

