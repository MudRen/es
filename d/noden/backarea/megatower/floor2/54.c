#include "../megatower.h"

inherit ROOM;

void create()
{
	::create();
  set("light",0);
  set_short("The stair of Mega Tower","Ħ�����Ľ���");
  set_long(@Long
Long
,@CLong
�㵽����Ħ�����ĵڶ���, һ����ʯ�����߶ѻ����, ������һ������, ͨ����
����.
CLong
);
  set("exits",([
               "up"    :Megatower"/floor3/45",
               "west"  :Megatower"/floor2/44",
             ]));

::reset();
}

