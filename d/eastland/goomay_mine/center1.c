
#include <zeus.h>

inherit ROOM;

void create()
{
  ::create();
  set_short("��Ӵ���");
  set_long(@CLong
������ʮ�ֿ����ĵط�����\��\��İ����ӣ��ɼ��˵��ǿ�����Ϣ�ĵط���
���������䱻����ɰ����ͣ�����֩���������ĵ㣬�ǿ��ƿ���ڸ����ڵ���Ҫ
��Ŧ��Ҫ�����ӵ��κν��䣬�����뾭���˵أ�
CLong
);
   

set("exits",([
             "southwest":ZROOM"/mine01",
             "east":ZROOM"/center2",
             "west":ZROOM"/hospital",
             "north":ZROOM"/center4",
             ]));
set("exit_suppress",({"west"}));

reset();
#include <replace_room.h>
}