
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("����С��");
        set_light(1);
        set_long( @LONG_DESCRIPTION
С·�������������������������Ĳ����ߣ���Զ����������ɽᰵ�
��Х����������ԼԼ�ݷ�������������������������������Ϊ�����
��ϵ�����޷��ֱ����ʲ���������ٴ������㣬Ҫע��űߣ�����ˤ��
����֮�²���Ҳ��ȥ��������ม�
LONG_DESCRIPTION
        );
        set( "exits", ([
        "southeast" : HAWK"room1-5",
        "northwest" : HAWK"room1-3",
                        ]) );
        set("objects", ([
                "bug" : MOB"bird"
                        ]) );

    reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="southeast" || str =="northwest")
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
