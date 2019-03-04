
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("���֮�ǳ���");
        set_light(1);
        set_long( @LONG_DESCRIPTION
�ߵ�������Ծ���������Ŀ������֮�Ǹߴ�Ĵ��ſ��ˡ�����ϸ����
�����ţ����־�����������Ĵ���ʯ������������������������޵�ͼ����
�治֪����Щ�������˶�����������ɡ���������һ�����㷢�ֵ���������ʵ
�Ǹ��ڿ��еģ���ʱ����������Ŵ�˵�е����֮���Ǵ��ڵġ�������Ҳ����
����������ڳ��ڷ�����ȥ������������������Ѿõĳ��д�ſ���˵������
���������Դ��ΪԤ�����˵����֣�������Ҳ�������������սʿפ�ء�
LONG_DESCRIPTION
        );
        set("objects", ([
                "war" : MOB"fighter",
                "war1" : MOB"fighter"]) );

        set( "exits", ([
        "east" : HAWK"room1-7",
        "south" : HAWK"room1-9",
                    ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="south" || str=="east" )
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
