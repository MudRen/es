// Deathland/holyplace/h09.c 
// Created by Echobomber @Eastern.Stories 
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" A strange place","��ֵĵط�");
  set_long(@Long
Long
,@CLong
һ����ֵĵط�, �Ĵ��ĺ�Ӱ������Ϣ��������Ϯ����. ���涼����ʯ, ���ƺ�
��ͨ����ʯ��������ط�. ������˽��Ǳߵ��ұ��Ǽٵ�, ����������뿪����.
CLong
);

set("exits",([
             "north":Deathland"/holyplace/h14",
             "east":Deathland"/holyplace/h22",
             ]));
set("exit_invisble",1);
reset();
}

