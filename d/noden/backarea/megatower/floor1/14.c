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
������Ħ�������ڲ���һ���������, �����ƺ������ʧ��, �����ɼ��������
Ƭ��ʯ��, ������һЩ����ֵֹ��㼣ӡ�ڵ���. ��ط�������겻������, �Ե�ʮ
�ֵ�������ʪ. 
CLong
);
  set("exits",([
               "east" :Megatower"/floor1/24",
               "south":Megatower"/floor1/13",
             ]));

::reset();
}
