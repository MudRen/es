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
������Ħ�������ڲ���һ������Ͻ�, �����ƺ������ʧ��, �����ɼ��������
Ƭ��ʯ��, ������һЩ����ֵֹ��㼣ӡ�ڵ���. ��ط�������겻������, �Ե�ʮ
�ֵ�������ʪ. 
CLong
);
  set("objects",([
      "goblin#01":Monster"/goblin01",
      "goblin#02":Monster"/goblin01",
      "goblin#03":Monster"/goblin01",
      ]) );
  set("exits",([
               "east" :Megatower"/floor1/22",
               "north":Megatower"/floor1/13",
               "southeast":Megatower"/floor1/21",
               
             ]));

::reset();
}
