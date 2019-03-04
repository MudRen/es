
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("�ڳ����");
        set_light(1);
        set_long( @LONG_DESCRIPTION
��һ��ĳǲ�һ�����ǣ����֮��������Ʈ��������еģ���������
֮�䣬����е����絽���ɾ�������ϸ���������ƣ���ŷ��������������
�󲿷ݶ��������Ϸ�����ȥ���������ڵ��ϻ�ģ�ԭ�����֮�ǵ��ڳǲ�
����������Ҫ�Ļ�����������Ϊ�������˶�����
    ̧ͷ���������ڳ��������ͷ����Ʈ��Ʈ�ġ�
LONG_DESCRIPTION
        );
        set( "exits", ([
        "west" : HAWK"room1-10",
        "north" : HAWK"room1-8",
        "up" : HAWK"room2-15",
                     ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="west" || str=="north" || str=="up" )
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
