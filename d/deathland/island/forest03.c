
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
    "here":"@@search_here",
    ]));
set("exits",([
     "west" :Deathland"/island/forest02",
     "south":Deathland"/island/forest04",
     "east" :Deathland"/island/forest06",
     ]) );
set("exit_suppress",({"south","north",}) );
 ::reset();
}

string search_here()
{
   this_player()->set_explore("deathland#22");
   return "������ϸ��Ѱ�������ʱ��, ����һ��СС��ͨ����������.\n";
}