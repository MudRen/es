
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("forest of GreyIsland","�Ұ�֮����ɭ��");
  set_long(@Long
Long
,@CLong
һ���������ɭ��, ��ɭ���ƺ������������밫��ľ, ���϶��Ǹ��õ���Ҷ, ��
�����˺�������ĵط�. �㷢��������ɭ�ֵ����. 
CLong
);

set("search_desc",([
    "here":"������ϸ��Ѱ�������ʱ��, ����һ��СС��ͨ������������.\n",
    ]));
set("exits",([
     "west" :Deathland"/island/forest07",
     "south":Deathland"/island/forest11",
     "north" :Deathland"/island/forest09",
     "northeast":Deathland"/island/forest12",
     ]) );

set("objects",([
    "plant":Monster"/plant01",
    ]) );

set("exit_suppress",({"northeast"}) );
 ::reset();
#include <../replace_room.h>
}

