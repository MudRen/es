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
������Ħ�������ڲ���һ��Ķ��Ͻ�, �����ƺ������ʧ��, �����ɼ��������
Ƭ��ʯ��, ������һЩ����ֵֹ��㼣ӡ�ڵ���. ��ط�������겻������, �Ե�ʮ
�ֵ�������ʪ. 
CLong
);
  set("exits",([
               "west" :Megatower"/floor1/44",
               "south":Megatower"/floor1/53",
             ]));

::reset();
}
