//Deathland/holyplace/r07.c
//Created by Echobomber Eastern.Stories

#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("light",1);
  set_short(" Drawf holy place ","����ʥ��");
  set_long(@Long
Long
,@CLong
�������㿴��һЩ�ܴ�Ľ���,�������ܳ�������͵�����,���Ѿ����ﰫ�˵�ʥ����.
һЩ������˿󳵱�����춵���,���ϱ��е������ǽ��,�ƺ�����������ײ�ĳ����.
CLong
);
set("direction","block");
set("exits",([
             "north":Deathland"/holyplace/r05",
             ]));
reset();
}
