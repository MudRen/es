
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("ƶ���");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
Խ��ƶ������ߣ�Խ������һ����������Ϣ���������ܣ���δ���ľ���
�ͶԹ�ȥ���廳ʹ����Щ��ס��ƶ��ߵ�������Խ��Խ�������㷢�ֵ�·��
��һ�����Ƶ�С�ݣ����֮��������Ǭ���ģ�����Ҫ��ȥ������?
LONG_DESCRIPTION
        );
        set( "exits", ([
        "southeast" : HAWK"room1-15",
        "northwest" : HAWK"room1-13",
           ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_enter" ,"enter");
}

int to_enter(string s)
{
        if ( s!= "house") return 0;
        this_player()->move_player(HAWK"room1-20","SNEAK");
        return 1;
}

