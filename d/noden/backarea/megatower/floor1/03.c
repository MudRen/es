#include "../megatower.h"

inherit ROOM;
inherit DOORS;
void create()
{
	::create();
  set("light",0);
  set_short("Mega Tower","Ħ�������ڲ�");
  set_long(@Long
Long
,@CLong
������Ħ�������ڲ���һ�����ߵ�һ������, �����ƺ������ʧ��, �����ɼ���
�����Ƭ��ʯ��, ������һЩ����ֵֹ��㼣ӡ�ڵ���. ��ط�������겻������, 
�Ե�ʮ�ֵ�������ʪ. ��������������ڵĿ���Խ��Խ���, ����һ����ɱ��������
�㽥���رƽ�.  
CLong
);
  set("objects",([
      "goblin#01":Monster"/goblin01",
      "goblin#02":Monster"/goblin01",
      "goblin#03":Monster"/goblin01",
      ]) );
  set("exits",([
               "east" :Megatower"/floor1/13",
               "south":Megatower"/floor1/02",
               "north":Megatower"/floor1/04",
             ]));
  create_door("east","west",([
             "name":"stone door",
             "c_name":"ʯ��",
             "keyword":({"stone door","door",}),
             "c_desc":"ʯ��",
             "status":"closed",
             "desc":"a stone door",
                     ]) );

::reset();
}