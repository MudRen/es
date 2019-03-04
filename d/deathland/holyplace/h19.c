// Deathland/holyplace/h19.c 
// Created by Echobomber @Eastern.Stories 
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" A strange place","����������Ʈ�촦");
  set_long(@Long
Long
,@CLong
һ�������ĵ�������,�Ĵ��ĺ�Ӱ������Ϣ��������Ϯ����.����ļž����˸е�����,
���㲻��������Ҫ����һЩ����.û�з���,û��ˮ��,�������޷������Լ��ĽŲ���,�㲻
�������Լ�����һ�����޵ĵط�.�����ҰԽ��ԽС,�ƺ�����۾���һЩ��ɫ��\"��\"��ס
������.�����Σ�յĵط�,�������߾���,��Ϊ��ʱ���п��ܴӺڰ����߳�а�������.
CLong
);

set("search_desc",([
    "here":"�������������ƺ���������ʧ�����,���ͣ������һ��,ȴ����һ�����"
           "�ĺ�ɫ���ų�����������,�������ߵĵ��ƺܸ�,��Ӧ����������ȥ\n",
    ]) );
set("c_item_desc",([
    "fog":"@@to_look_fog",
    ]) );
set("exits",([
             "southwest":Deathland"/holyplace/h20",
             "northeast":Deathland"/holyplace/h18",
             ]));
reset();
}

void init()
{
   add_action("to_west","climb");
}

string to_look_fog()
{
     return can_read_chinese() ?
            "������?�㻳����,���ܺ�����ؿ���һЩ��������Ʈɢ�������Χ.\n"
            "\��\��\��һ��а�������,���ܸо�������а��ĳɷݲ�������.��\n" 
            "���ط�������Խ��Խ����,�������ҲԽ��Խģ����.\n" :
            "need work.\n"; 
}

int to_west()
{
    write("���������ұ�,����һ�����صĵط�.\n");
    this_player()->move_player(Deathland"/holyplace/h21","SNEAK");
    return 1; 
}
