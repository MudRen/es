
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("ͨ����Ӫ��С·");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
����Կ�������Ӫ (military building)������С·�����ԣ���������
���������Ǻ;۾ӵĵط����ƺ�����һ���߸ߵĽ������֪����ɶ��������
������ܿ��Դ��Աߵ�¥������ȥ������
LONG_DESCRIPTION
        );
        set( "exits", ([
        "south" : HAWK"room1-13",
        "east" : HAWK"room1-11"
              ]) );
        set("c_item_desc",([
                "building":"����һ�����������۵ľ�Ӫ��������Լ��������������ߺ������\n",
                        ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_climb","climb");
}

int to_climb(string s)
{
        if ( (s != "ladder") && (s != "¥��") ) return 0;
        tell_room(environment(this_player()),
                "�㿴��"+this_player()->query("c_name")+
                "���ڹ�һ������¥������������!\n",this_player());
        this_player()->move_player(HAWK"room1-19","SNEAK");
        return 1;
}
