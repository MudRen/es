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
  set("exits",([
               "east" :Megatower"/floor1/46",
               "south":Megatower"/floor1/35",
               "west" :Megatower"/floor1/26",
             ]));
  create_door("south","north",([
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
