
#include <zeus.h>

inherit ROOM;

void create()
{
  ::create();
  set_short("�μҿ��ͨ��");
  set_long(@CLong
����һ��������ͨ�������������Ŀ�ӣ���ط��ƺ��������\�࣬������
��\���ľ��֧����������ɢ����\��\��޴�Ľ�ӡ����������������ͨ�������У�
CLong
);
   

set("exits",([
             "south":ZROOM"/bridge",
             "northeast":ZROOM"/center1"
             ]));
reset();
#include <replace_room.h>
}
