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
����λ���Ħ�������ڲ���һ��Ķ��Ϸ���һ������, �����ƺ������ʧ��, ��
���ɼ��������Ƭ��ʯ��, ������һЩ����ֵֹ��㼣ӡ�ڵ���. ��ط�������겻
������, �Ե�ʮ�ֵ�������ʪ. 
CLong
);
  set("objects",([
      "goblin":Monster"/goblin01",
      ]) );
  
  set("exits",([
               "west" :Megatower"/floor1/30",
             ]));
  
::reset();
}
