
#include <zeus.h>

inherit ROOM;
int paper_num;
void create()
{
  ::create();
  set_short("�μҿ��ͨ��");
  set_long(@CLong
����һ��������ͨ����ż�������������ǵ�ߺ�������������п�����������
���˷�����ֵ�ζ������ǰ��һ����һ���������������Ŀ������ã�
CLong
); 

set("exits",([
             "north":ZROOM"/wineroom02",
             "southeast":ZROOM"/center4"
             ]));

reset();
#include <replace_room.h>
}