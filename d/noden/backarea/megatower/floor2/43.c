#include "../megatower.h"

inherit ROOM;

void create()
{
	::create();
  set("light",0);
  set_short("The 2rd floor of Mega Tower","Ħ�����Ķ�¥����");
  set_long(@Long
Long
,@CLong
�㵽����Ħ�����ĵڶ���, ���ﵽ���ɼ��������Ƭ��ʯ��. �������۵Ļ���
��������ɫ, ÿ��ת���㶼����С������, Ī���Ĺ���Ҳ�����ڽ��䴦����͵Ϯ
��.  
CLong
);
  set("exits",([
               "south" :Megatower"/floor2/42",
               "east"  :Megatower"/floor2/53",
               "north" :Megatower"/floor2/44",
             ]));

::reset();
}

