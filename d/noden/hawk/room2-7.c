
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("�ڳ�С��");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
Զ�����ڳǴ���������;��½��ŵ����գ����������֮������ĵ�
��֮һ���������������ǣ���һ����ŵ�����֮�У�����æ��͵�еĵ���
���лΣ�������Ҫ������·�������ҪС���ޣ�����Ҫ������������ǻ�ˤ
�Ĳ���ม�
LONG_DESCRIPTION
        );
        set( "exits", ([
        "northeast" : HAWK"room2-8",
        "south" : HAWK"room2-5",
                     ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="northeast" || str=="south" )
                return 0;
        write("��! ����....\n\n");
        tell_room(environment(this_player()),
                "�㿴������ʧ����!\n",this_player());
        this_player()->receive_damage(90);
        this_player()->move_player(HAWK"room1-18","SNEAK");
        tell_room(environment(this_player()),
                "�㿴��"+(string)this_player()->query("c_name")+
                "�Ӹ��ʵľ�����ˤ����!\n"+
                "��Ȼû��! ��������!\n",this_player());
        return 1;
}
