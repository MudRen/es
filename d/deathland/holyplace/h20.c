// Deathland/holyplace/h20.c 
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

set("c_item_desc",([
    "fog":"@@to_look_fog",
    ]) );
set("exits",([
             "southwest":Deathland"/holyplace/h18",
             "northeast":Deathland"/holyplace/h19",
             ]));
set("pre_exit_func",([
             "southwest":"to_in",
             ]) );
reset();
}

string to_look_fog()
{
     return can_read_chinese() ?
            "������?�㻳����,���ܺ�����ؿ���һЩ��������Ʈɢ�������Χ.\n"
            "\��\��\��һ��а�������,���ܸо�������а��ĳɷݲ�������.��\n" 
            "���ط�������Խ��Խ����,�������ҲԽ��Խģ����.\n" :
            "need work.\n"; 
}

int to_in()
{
    write("�㷢����ķ�����ƺ��е㲻��Ծ���.\n");
    return 0;
}
