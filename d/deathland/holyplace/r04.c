//Deathland/holyplace/r04.c
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
����.
CLong
);

set("exits",([
             "west":Deathland"/holyplace/r05",
             "east":Deathland"/holyplace/r03",
             ]));
set("objects",([
    "guard":Monster"/guard07",
    ]) );

reset();
}
