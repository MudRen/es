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
������Ħ�������ڲ���һ��, �����ƺ������ʧ��, �����ɼ��������Ƭ��ʯ��,
������һЩ����ֵֹ��㼣ӡ�ڵ���. ��ط�������겻������, �Ե�ʮ�ֵ�������ʪ
. ��������������ڵĿ���Խ��Խ���, ����һ����ɱ���������㽥���رƽ�. һ�ֺ�
Զ�����н���Ĺֵֹ����������������봫��, ����ȫ������������ֵĸ���. 
CLong
);
  set("objects",([
      "goblin#01":Monster"/goblin01",
      "goblin#02":Monster"/goblin01",
      ]) );
  set("exits",([
               "west" :Megatower"/floor1/25",
               "east" :Megatower"/floor1/45",
               "south":Megatower"/floor1/34",
               "north":Megatower"/floor1/36",
             ]));
 
  create_door("north","south",([
             "name":"stone door",
             "c_name":"ʯ��",
             "keyword":({"stone door","door",}),
             "c_desc":"ʯ��",
             "status":"locked",
             "desc":"a stone door",
             "lock":"MEGA_TOWER_1_n",
                     ]) );

 ::reset();

}
