
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
��ร�ޡ������Ҫ��ͷ�Ļ������������ִֵ�����(rope)��������������
(climb) ��
LONG_DESCRIPTION
        );
        set( "exits", ([
        "east" : HAWK"square2",
        "south" : HAWK"square4",
                     ]) );
    reset();
}//end of creat


void init()
{
        add_action("to_climb","climb");
}

int to_climb(string str)
{
        if ( !str || str != "rope") return 0;
        tell_object(this_player(),@LONG
����������������������
LONG
        );
        this_player()->move_player(HAWK"room3-4","SNEAK");
        return 1;
}
