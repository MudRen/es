
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
�������Լ�����һ�����޵ĵط�.�����ҰԽ��ԽС,����ѵ�����ҲԽ��Խ��. �ƺ����
�۾���һЩ��ɫ��\"��\"��ס������.
CLong
);

set("c_item_desc",([
    "fog":"@@to_look_fog",
    ]) );
set("exits",([
             "west":Deathland"/holyplace/h08",
             "east":Deathland"/holyplace/h06",
             "southwest":Deathland"/holyplace/h15",
             "south":Deathland"/holyplace/h10",
             ]));
reset();
}

string to_look_fog()
{
     return can_read_chinese() ?
            "������?�㻳����,���ܺ�����ؿ���һЩ��������Ʈɢ�������Χ.\n"
            "\��\��\��һ��а�������,���ܸо�������а��ĳɷݲ�������.\n" :
            "need work.\n"; 
}
