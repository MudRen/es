
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
                "north" : HAWK"square5",
                "west" : HAWK"square7",
                "east" : HAWK"square9",
                        ]) );
        set( "objects", ([
                "beast" : MOB"beast",
                "beast1" : MOB"lbeast",
                        ]) );
        reset();
}//end of creat

