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
������Ħ�������ڲ���һ��, �����ƺ������ʧ��, �����ɼ��������Ƭ��ʯ��,
������һЩ����ֵֹ��㼣ӡ�ڵ���. ��ط�������겻������, �Ե�ʮ�ֵ�������ʪ
. ��������������ڵĿ���Խ��Խ���, ����һ����ɱ���������㽥���رƽ�. һ�ֺ�
Զ�����н���Ĺֵֹ����������������봫��, ����ȫ������������ֵĸ���.
CLong
);
  set("exits",([
               "west" :Megatower"/floor1/12",
               "north":Megatower"/floor1/23",
               "east" :Megatower"/floor1/32",
               "south":Megatower"/floor1/21",
             ]));

::reset();
}
