//Deathland/holyplace/h05.c
//Created by Echobomber @Eastern.Stories

#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("light",1);
  set("no_monster",1);
  set_short(" Drawf holy place ","����ʥ��");
  set_long(@Long
Long
,@CLong
�������㿴��һЩ�ܴ�Ľ���,�������ܳ�������͵�����,��Ŀǰλ춰���ʥ��.
�����ߵ�ͨ������һ��ħ��ǽ,�ƺ��ڷ�ֹһЩ���µ���������.����������,���ܵ���
���˼�̳,����������һ��δ֪������.
CLong
);

set("exits",([
             "west":Deathland"/holyplace/h06",
             "east":Deathland"/holyplace/h02",
             ]));
set("objects",([
    "guard":Monster"/guard07",
    ]) );

reset();

}
