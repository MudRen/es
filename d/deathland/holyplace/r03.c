//Deathland/holyplace/r03.c
//Created by Echobomber @Eastern.Stories

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
�������㿴��һЩ�ܴ�Ľ���,��Ȼ��Щ����û����������,�������ܸо���һ��
������ׯ�ص�����,���ܳ�������͵�����,���˸е�ƽ��,���.���Ѿ����ﰫ�˵�ʥ
����.���Ϸ���һ���ر����ص�С��,\��\��\��Ӧ�ý�ȥ����.
CLong
);

set("exits",([
             "west":Deathland"/holyplace/r04",
             "east":Deathland"/holyplace/r01",
             "southwest":Deathland"/holyplace/h04",
             ]));
set("objects",([
    "guard":Monster"/guard07",
    ]) );

reset();
}
