
#include <zeus.h>

inherit ROOM;

void create()
{
  ::create();
  set_short("�徳");
  set_long(@CLong
һ��Ũ����ҩ��ζ�˱Ƕ������ɼ��˵��ǿ��������β��ĵط���һ����
\��\��������Ǭ���Ĵ��̣���ȷ��һ����Ϣ�ĺõط������������ᳳ�ӵĻ�����
Ȼ��ͬ��
CLong
);
   

set("exits",([
             "east":ZROOM"/center1",
             ]));
set("objects",([
             "invalid":ZMOB"/invalid.c"
             ]));
             reset();
#include <replace_room.h>
             }