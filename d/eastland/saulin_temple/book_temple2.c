//File: book_temple2.c �����²ؾ�¥

#include "saulin_temple.h"

inherit ROOM;

int pull=0;

void create()
{
       ::create();
       set_short("�����²ؾ�¥");
       set_long( @C_LONG_DESC
���߽������ѾõĲؾ��󣬸��ڼż�����������ǽ�ڶ���ֱ���ݶ�����ܣ�
ÿһ����϶�����һ��С��������д�������������Ĺ��֣���������ģ�����
����������麣���ҵ������µ��书\�����������ϼ��ѡ��ҷ������������
�ȳ���(windows)������ȴû�й��������������Ǳ��鼮�������ˡ�
C_LONG_DESC
       );
	   set("light",1);
	set("objects",([ "monk" : SAULIN_MONSTER"shu_ju" ,]));
       set("exits",([
         "out" : SAULIN"book_temple1",
       ]) );
       reset();
       set("item_desc",([ "windows":
@C_LONG
    �������ȳ�ľ������Ȼ�����õĺ�Ǭ��������ȴû�й���͸������
C_LONG
       ]));
}

void init()
{
     add_action("pull_window","pull");
     add_action("climb_ladder","climb");
}

int pull_window(string str)
{
    if( !str || str != "windows" )
       return notify_fail(can_read_chinese()?
         "��Ҫ��ʲ��?\n" :
         "What do you want to pull ?\n" );
if (present("shu ju",this_object()))
{
    tell_object(this_player(), can_read_chinese() ? @C_OPEN
�����������Ѵ����������������˹�����ֹ�㣬����ʮ����Ϊ�˱������
�ı��棬��������ǿ����õģ��벻Ҫ�����򿪡�
C_OPEN
: "You want to pull the window but shu ju stop you.\n"
    );
	return 1;
}

    tell_object(this_player(),@C_LONG
�������Ѵ���һ�������洰��ͻȻ�����ƶ��������ֳ�������һ��ľ��
��ľ�ݺ�Ǭ�����������˳��룬����\�������(climb)��ȥ������
C_LONG
    );
    pull = 1;
    return 1;
}
                   
int climb_ladder(string str)
{
      if( !str || str != "ladder" || !pull )
        return notify_fail("��Ҫ��ʲ��?\n");
       this_player()->move_player(SAULIN"book_temple3");
       return 1;
}
