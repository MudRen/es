
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
����.���ﱱ�ߵ���Ԩ�ִ�����,��������ǰ��˿��.������������ĺۼ�,�ƺ��˿�
��ר�õĵ�·.
CLong
);
set("direction","south");

set("exits",([
             "south":Deathland"/holyplace/r01",
             ]));
reset();
}
