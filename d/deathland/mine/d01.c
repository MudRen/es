
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" the big hole of Drawf mine ","���˿�ӵĴ�");
  set_long(@Long
Long
,@CLong
һ���ܺںܰ��Ĵ�Ѩ,�����Ǹ������ḻ�Ŀ��,�����ԴӴ���������ֹ�����
��û��ʲ���˸�����.
CLong
);
set("direction","machine");
set("exits",([
             "up":Mine"/m63",
             "west":Mine"/d02",
             ]));
set("pre_exit_func",([
    "west":"to_west",
    ]) );
set("no_monster",1);
reset();
}

int to_west()
{
    write("���������ߵ�ʱ��,�ƺ�һ�����ε�������Խ���ұ���.\n");
    return 0;
}
