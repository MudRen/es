
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
����.������������ĺۼ�,�ƺ����˿�ר�õĵ�·.
CLong
);
set("direction","south");
set("exits",([
             "north":Deathland"/holyplace/h01",
             "west":Deathland"/holyplace/r03",
             "south":Deathland"/holyplace/r02",
             ]));
reset();
}
