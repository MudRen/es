
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("���С��");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
�ԴӼ���ǰһ����ս֮�ᣬ����������ص����֮�ǣ���Ϊ�˱����
���ٶ����֣������������������Ĺ��£������֮�����ּӸ���һС��
��Ҳ�������������ڵ���ǡ�
    ����Ǿ�ס���������ˣ�һ���Ǹ����������֮�ǵ�ʿ���ǣ������
��һЩ�Ƚ�������������������ǣ����Ǿ�ס����ǵ�ƶ����
LONG_DESCRIPTION
        );
        set( "exits", ([
        "east" : HAWK"room1-9",
        "south" : HAWK"room1-11",
                     ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="east" || str=="south" )
                return 0;
        write("��! ����....\n\n");
        tell_room(environment(this_player()),
                "�㿴������ʧ����!\n",this_player());
        this_player()->receive_damage(70);
        this_player()->move_player(HAWK"room1-18","SNEAK");
        tell_room(environment(this_player()),
                "�㿴��"+(string)this_player()->query("c_name")+
                "�Ӹ��ʵľ�����ˤ����!\n"+
                "��Ȼû��! ��������!\n",this_player());
        return 1;
}
