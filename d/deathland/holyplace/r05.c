//Deathland/holyplace/r05.c
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
����.������������ĺۼ�,�ƺ����˿�ר�õĵ�·.�����ƺ���һ����̳,���ܿ���
һ���ܴ������.
CLong
);
set("direction","south");
set("exits",([
             "north":Deathland"/holyplace/r06",
             "west":Deathland"/holyplace/h02",
             "south":Deathland"/holyplace/r07",
             "east":Deathland"/holyplace/r04",
             ]));
reset();
}
