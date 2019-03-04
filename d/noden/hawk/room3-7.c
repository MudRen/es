
#include "hawk.h" 

inherit ROOM;
inherit DOORS;

void create()
{
        ::create();
        set_short("���صķ���");
        set("light",1);
        set_long( @LONG_DESCRIPTION
���߽���һ�䷿�䣬ӳ������ǰ�ģ����˰�ɫ�����ǰ�ɫ���ݷ����һ�
���ݷ�����������ܲ������������ʡ�
LONG_DESCRIPTION
        );
        set( "exits", ([
                "northeast" : HAWK"room3-8",
                "southeast" : HAWK"room3-9",
                "west" : HAWK"room3-1",
                     ]) );
        create_door("west","east",([
                "keyword":({"whitedoor","door"}),
                "status":"closed",
                "c_desc":"һ����ɫ��С��",
                "c_name":"������",
                "name":"white jade door",
                "desc":"a white jade door",
        ]) );
    reset();

}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str =="west" || str=="southeast" || str=="northeast" )
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
