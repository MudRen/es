
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" the big cave of Drawf mine ","���˿�ӵĴ�Ѩ");
  set_long(@Long
Long
,@CLong
һ���ܺںܰ��Ĵ�Ѩ,�����Ǹ������ḻ�Ŀ��,�����ԴӴ���������ֹ�����
��û��ʲ���˸�����.Խ������,�;����ƺ������ڿ�̽�������.
CLong
);
set("exits",([
             "west":Mine"/d03",
             "east":Mine"/d01",
             ]));
set("pre_exit_func",([
    "east":"to_east",
    ]) );
reset();
}

int to_east()
{
    write("���������ߵ�ʱ��,�ƺ�һ�����ε�������Խ���ұ���.\n");
    return 0;
}
