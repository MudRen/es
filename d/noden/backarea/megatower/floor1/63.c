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
������Ħ�������ڲ���һ�㶫�ߵ�һ������, �����ƺ������ʧ��, �����ɼ���
�����Ƭ��ʯ��, ������һЩ����ֵֹ��㼣ӡ�ڵ���. ��ط�������겻������, 
�Ե�ʮ�ֵ�������ʪ. ��������������ڵĿ���Խ��Խ���, ����һ����ɱ��������
�㽥���رƽ�.  
CLong
);
  set("exits",([
               "west" :Megatower"/floor1/53",
               "south":Megatower"/floor1/62",
               "north":Megatower"/floor1/64",
             ]));
  create_door("west","east",([
             "name":"stone door",
             "c_name":"ʯ��",
             "keyword":({"stone door","door",}),
             "c_desc":"ʯ��",
             "status":"closed",
             "desc":"a stone door",
                     ]) );

::reset();
}
