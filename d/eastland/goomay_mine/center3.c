
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
             "south":ZROOM"/center2",
             "northeast":ZROOM"/keyroom01",
             "west":ZROOM"/center4",
             ]));
set("objects",([
              "miner01" : ZMOB"/miner01",
              ]));

reset();
#include <replace_room.h>
}