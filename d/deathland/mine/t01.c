
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("Mine","��ӵ��");
  set_long(@Long
Long
,@CLong
�����ǿ�ӵ��. ������һ����ʯ��ͨ������ס��, Ŀǰ�����ϱߵ�һ��
խխ���ѷ�, ��û���κεĳ�·. 
CLong
);
set("direction","block");
set("exits",([
             "south":Mine"/t02",
             ]));
#include <replace_room.h>
}
