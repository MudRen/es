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
����λ���Ħ�������ڲ���һ��Ķ��߷������һ������, ����һЩ�����ɼ�����
����Ƭ��ʯ��֮��, �����������Ӫ��, �ƺ����������ļ���.
CLong
);
  set("exits",([
               "north" :Megatower"/floor1/63",
             ]));

::reset();
}

