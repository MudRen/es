
#include "hawk.h" 

inherit ROOM;
inherit DOORS;
void create()
{
        ::create();
        set_short("���صķ���");
        set("no_vision",1);
        set_long( @LONG_DESCRIPTION
�Ǻ�....����д....��Ҷ���������
LONG_DESCRIPTION
        );
        set( "exits", ([
                "northwest" : HAWK"room3-4",
                "southwest" : HAWK"room3-5",
                "east" : HAWK"room3-1",
                        ]) );
        create_door("east","west",
                ([
                "keyword":({"blackdoor","door"}),
                "status":"closed",
                "c_desc":"һ����ɫ����",
                "c_name":"������",
                "name":"black jade door",
                "desc":"a black jade door",
                ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str == "east" || str=="southwest" || str=="northwest" )
                return 0;
        write("��! ����....\n\n");
        tell_room(environment(this_player()),
                "�㿴������ʧ����!\n",this_player());
        this_player()->receive_damage(120);
        this_player()->move_player(HAWK"room1-18","SNEAK");
        tell_room(environment(this_player()),
                "�㿴��"+(string)this_player()->query("c_name")+
                "�Ӹ��ʵľ�����ˤ����!\n"+
                "��Ȼû��! ��������!\n",this_player());
        return 1;
}
