//Deathland/holyplace/h03.c
//Created by Echobomber @Eastern.Stories

#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("light",1);
  set_short("mystic house","����С��");
  set_long(@Long
Long
,@CLong
һ�����ص�С��,����Ķ�����������,������\��\��������ֵֹ�ƿ��,���޷���
������ط���������������.
CLong
);

set("exits",([
             "north":Deathland"/holyplace/h02",
             ]));
reset();
}
