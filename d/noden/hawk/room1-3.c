
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("����С��");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
����Ȼ���ֵ����Ǿ���֮�ᣬ������������һ��С�����㲻����̾
�������һ����С�������������ֵ��ǣ�С������൱�ֲڣ�����
�����������Ĳ��������֪����Ϊ��ʲ�ᡣ���⣬����λ���ͱڱߵ�С
��Ҳ�����������ע��һ����ĽŲ�������ɽ�¿ɲ���һ���������
ࡣ�
LONG_DESCRIPTION
        );
        set( "exits", ([
        "southeast" : HAWK"room1-4",
                     ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="southeast" )
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
