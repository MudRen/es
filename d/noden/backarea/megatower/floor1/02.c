#include "../megatower.h"

inherit ROOM;

void create()
{
	::create();
  set("light",0);
  set_short("Mega Tower","Ħ�������ڲ�");
  set_long(@Long
Long
,@CLong
����λ���Ħ�������ڲ���һ������߷������һ������, ����һЩ�����ɼ�����
����Ƭ��ʯ��֮��, ������һЩ�����õĴ�ˮͰ����˵�.
CLong
);
  set("exits",([
               "north" :Megatower"/floor1/03",
             ]));

::reset();
}
