
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" the small pool","Сˮ��");
  set_long(@Long
Long
,@CLong
һ��СС��ˮ��,Ȼ��ȴ�ѻ����˹Ǻ�,����Ӧ�ô�����һ����ǿ�Ĺ���.
CLong
);
set("item_func",([
    "skeleton":"look_skeleton",
    ]) );
set("exits",([
             "out":Mine"/d05",
             ]));
set("objects",([
    "siren":Monster"/siren",
    ]) );
reset();
}

int look_skeleton()
{
    write("һ�ѹǺ�,�ƺ��б��й��ĺۼ�\n");
    this_player()->set_explore("deathland#6");
    return 1;
}