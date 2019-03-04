//room1-11.c
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("���С��");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
    ������ǵ�С���ϣ�Զ������ո�������С����������ող�����
����龰���Լ���������᫵�ɽ·��������ƺ����ѻ��е����ܹ�����
�ɣ���֪������������Щʲ�ᣬ��������������ǻ�����Եõ�һЩ��
Ϣ�ɡ������߾Ϳ��Ե���ʿ���Ǿ�ס�ľ�Ӫ������Կ��������Ⱥ��ʿ
�������⸽��Ѳ������
LONG_DESCRIPTION
        );
        set( "objects", ([
                "soldier1" : MOB"warrior",
                "soldier2" : MOB"warrior",
                "soldier3" : MOB"warrior"
                        ]) );
        set( "exits", ([
        "west" : HAWK"room1-12",
        "north" : HAWK"room1-10",
                ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="west" || str=="north" )
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
