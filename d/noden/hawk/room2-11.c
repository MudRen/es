
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("������");
        set("light",1);
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
����������ڳǵĵ�·�ϣ��۲��������������ķ��ӣ����ִ󲿷ݱȽ���
ΰ�����Ӷ������µģ����Ͼɵķ��������������õģ����ǻ��Ǻܶ���ס��
�����½Ϻõķ��ӷ����տյ�������������������ϲ��ס�ڱȽϼ�ª�ķ��Ӱ�
....����֪��Ϊʲ�������Щ�½����أ������еķ��ӵ��У���ע�⵽һ��
�ر�Ư���ķ��ӣ���Ҫ��ȥ(enter) ������
LONG_DESCRIPTION
        );
        set( "exits", ([
        "northwest" : HAWK"room2-8",
        "south" : HAWK"room2-13",
                     ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_enter","enter");
}

int to_enter(string str)
{
        if (str == "house" || str == "building")
        {
                this_player()->move_player(HAWK"traroom","SNEAK");
                return 1;
        }
        else
        {
                tell_object(this_player(),"�����ȥ����??\n");
                return 1;
        }
        return 1;
}
