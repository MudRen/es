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
����λ���Ħ�������ڲ���һ��Ķ��߷������һ������, ����һЩ�����ɼ�����
����Ƭ��ʯ��֮��, ���������һЩС��, �����������������, ���һ�ð������. ��
��һ������, ͨ��Ħ�����ĵڶ���.
CLong
);
  set("exits",([
               "south" :Megatower"/floor1/63",
               "up"    :Megatower"/floor2/64",
             ]));

::reset();
}

void init()
{
     ::trap();
}
