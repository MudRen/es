#include "../megatower.h"

inherit ROOM;

void create()
{
	::create();
  set("light",0);
  set_short("The 2rd floor of Mega Tower","Ħ�����Ķ�¥");
  set_long(@Long
Long
,@CLong
�㵽����Ħ�����ĵڶ���,  ���ﵽ���ɼ��������Ƭ��ʯ��. �����и�����,ͨ����
���. ����һ������, ����ͨ��Ħ�����ĵײ�.
CLong
);
  set("exits",([
               "south" :Megatower"/floor2/63",
               "down"    :Megatower"/floor1/64",
             ]));

::reset();
}

