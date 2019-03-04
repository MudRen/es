#include "forest.h"
 
inherit ROOM;
 
void create()
{
  ::create();
  set_short("��ɭ��һ��");
  set_long(@CLong
�����Ǻ�ɭ�ֵ�һ��, �Ƚ��ر����, �������һ���Ĺ������⴩
�������е�϶��, �ճ�һ��С��������С����ĩ��, һ����Ϊͻ���Сƽ
̨(plate) �ںڰ��з�����, ���������֡�
CLong
        );
        set("exits",([
        "west"      : HERE"3n2w",
        "southeast" : HERE"2n",
        "plate"     : RUIN"plate",
    ]));
//        set("pre_exit_func", ([
//                "plate" : "go_plate",
//        ]) );
    set("objects", ([ "ammunt" : MOB"ammunt", ]) );
        set("exit_suppress", ({ "plate", "west", }) );
//        set("exit_msg", ([
//                "plate" : "@@go_plate",
//        ]) );
        ::reset();
}
 
void init()
{
        add_action("to_look", "look");
        add_action("go_plate","plate");
}
 
int to_look(string arg)
{
        if( arg != "plate" ) return 0;
        write("����߿���ȥ�ǿ�ƽ̨�ƺ�����, ����ȥ���￴��Ӧ�û����������Ŷԡ�\n");
        return 1;
}

int go_plate()
{
        tell_room( environment(this_player()),
                this_player()->query("c_name")+"���ǿ�ƽ̨��ȥ��\n"
                , ({this_player(),this_object()}) );
        this_player()->move_player(RUIN"plate","SNEAK");
        return 1;
}

