#include "../megatower.h"

inherit ROOM;
inherit Megatower+"/daemon/trap";

void create()
{
	::create();
  set("light",0);
  set_short("Mega Tower","Ħ�������ڲ�");
  set_long(@Long
Long
,@CLong
����λ���Ħ�������ڲ���һ������߷������һ������, ����һЩ�����ɼ�����
����Ƭ��ʯ��֮��, ���������һЩС��, �����������������, ���һ�ð������.
CLong
);
  set("exits",([
               "south" :Megatower"/floor1/03",
             ]));

::reset();
}

void init()
{
     ::trap();
}
