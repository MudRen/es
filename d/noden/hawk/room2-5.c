#include "hawk.h"
inherit ROOM;
void create()
{
        ::create();
        set_short("�ڳ�С��");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
�������ľ����˵��ڳ�С��������Բ���õ�·�ߵ�ֲ��Ҳ���о�������
�չˣ������й��á�����������������С������������֣�ҲΪ��������֮
��������һЩ���õ����գ���ʱ�������Զ�������ĸо���ã��е��ֲ�˼��
�ĸо���
LONG_DESCRIPTION
        );
        set( "objects", ([
                "boy1" : MOB"boy.c",
                "boy2" : MOB"boy.c",
                "girl" : MOB"girl.c",
                        ]) );

        set( "exits", ([
                "southwest" : HAWK"room2-4",
                "north" : HAWK"room2-7",
                        ]) );
        reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="southwest" || str =="north")
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
