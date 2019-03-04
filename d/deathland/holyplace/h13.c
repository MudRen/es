// Deathland/holyplace/h13.c 
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
���ƺ��о���һ�����������ߴ�����,�Լ�΢���Ļ���������,�������ߵ����ر��Ũ,
����Ӿ�����ֻ�Ǹ�������·�Ĺ���,����㿴����,\��\��ֻ�ǻ�Ӱ����.
CLong
);

set("c_item_desc",([
    "fog":"@@to_look_fog",
    ]) );
set("exits",([
             "east":Deathland"/holyplace/h12",
             "west":Deathland"/holyplace/f01",
             ]));
set("pre_exit_func",([
    "west":"to_west",
   ]) );
reset();
}


string to_look_fog()
{
     return can_read_chinese() ?
            "������?�㻳����,���ܺ�����ؿ���һЩ��������Ʈɢ�������Χ.\n"
            "\��\��\��һ��а�������,���ܸо�������а��ĳɷݲ�������.\n" :
            "need work.\n"; 
}

int to_west()
{
    if ( random(10)>1 ) {
      write(
      "��Ȼ����������,��������������ȴ����һ����Ȧ���߻�ԭ��.\n"
      );     
      return 1;
      }
    else {
      write(
      "��������˵��߳��˴���.\n"
      );
      return 0;  
      }  
}
