
#include <zeus.h>

inherit ROOM;

void create()
{
  ::create();
  set_short("�μҿ�����");
  set_long(@CLong
�����ǿ�ӵ����.���ܿ�������һ����Χ���ұڳ��������ھ�ĺۼ��Լ�
��ľͷ�������������ݵ��Ҷ�.�ڵ���������������.���ߴ��������ˮ����
CLong
);
   

set("exits",([
		"south" : "/d/eastland/goomay/entrance",
             "north":ZROOM"/bridge" ]));

    reset();
#include <replace_room.h>
}
