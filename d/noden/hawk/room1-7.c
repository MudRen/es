
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("���ż����");
        set_light(1);
        set_long( @LONG_DESCRIPTION
�㿴��һ���䱸ɭ�ϵľ����ڣ�һ����ͷ��������������򣬽�������
��ӥ�����צ��սʿ�����´������㣬��������Ҫͨ����߲��Ǽ��򵥵��¡�
LONG_DESCRIPTION
        );
        set("objects", ([
                "war" : MOB"warrior",
                "war1" : MOB"warrior",
                "mage" : MOB"mage" ]) );
        set( "exits", ([
        "west" : HAWK"room1-8",
        "northeast" : HAWK"room1-6",
                     ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="west" || str=="northeast" )
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
