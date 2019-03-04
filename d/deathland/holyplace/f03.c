// Deathland/holyplace/f03.c 
// Created by Echobomber @Eastern.Stories 
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    
    set_short("mystic cave","���صĶ�Ѩ");
    set_long(@Long
Long
,@CLong
һ�������ĵط�, ������Ѩû��ʲ���ر��, ����һ��СС��ľ�� .
CLong
);

set("item_func",([
    "door":"to_look_door",
    "description":"to_look_description",
    ]) );
set("exits",([
             "out":Deathland"/holyplace/f02",
             ]));
reset();
}

void init()
{
     add_action("to_smash","smash");
}
int to_look_door()
{
     write( can_read_chinese() ?
            "һ��СС��ľ��. �����ƺ���һ������(description)д������. \n"
            "����֮��, �㷢������û�а���, �ƺ�û���κη����ܴ�����,\n"
            "��������ײ(smash)��.\n":
            "need work.\n");
     return 1;        
}

int to_look_description()
{
    write( can_read_chinese() ?
          "ͨ�����������.\n"
          :
          "A entrance toward Death.\n"
          );
    return 1;      
}

int to_smash(string str)
{
    if (!str ||str!="door") return 0;
    write("����ײ�����ŵ�ʱ��, ��Ȼ��������ʧ��, ����Ҳ��������һ���ط�.\n");
    this_player()->move_player(Deathland"/holyplace/f04",({
    "%s disappear.\n","��ֻ��%s����ľ����ʧ��.\n",
    "%s enters.\n","%s���˽���.\n",}) );
    return 1;
}
