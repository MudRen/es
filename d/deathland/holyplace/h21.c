
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("light",0);
  set_short("strange fog","��ֵ�����");
  set_long(@Long
Long
,@CLong
��������ֻ����Խ��Խ����, Ȼ�����ߵĺ�ɫ����ȴ������, ����������ܸ�
�ܵ����Ż������. ��������ʲ����? 
CLong
);

set("exits",([
             "east":Deathland"/holyplace/h19",
             "west":Deathland"/holyplace/h23",
             ]));
reset();
}