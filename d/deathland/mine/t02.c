
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("On the Stair","������");
  set_long(@Long
Long
,@CLong
��ע�⵽����վ�ڽ�����, ����һ��������Ľ���.  
CLong
);
set("exits",([
             "westup":Mine"/t03",
             "eastdown":Mine"/t04",
             ]));
#include <replace_room.h>
}
