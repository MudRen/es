
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
 set_short("the dwarf village","���˴����");
  set_long(@Long
Long
,@CLong
һ���ܴ�Ķ�Ѩ,�кü�����Ѩͨ��δ֪������,����Ϊ���ܰ���ȫȫ����
����,���Լ��Ĵ��佨�����������Թ��Ĵ�֮��,���˰����Լ��ܹ�������
��ȫ���ߵ��Լ��Ĵ�����,�ƺ�Ҫ�����˴�����һ�����ѵ���.
CLong
);
set("exits",([
                "west":Deathland"/dwarf/village_07",
                "east":Deathland"/dwarf/maze01",
             ]));
set("objects",([
    "guard":Monster"/guard02",
               ]) );
::reset();               

  set("pre_exit_func",([
      "east":"to_maze_check",
     ]) );

}

int to_maze_check()
{
    this_player()->set_temp("dwarf_echomaze",
                    (["m1":0,"m2":0,"m3":0,"m4":0,"check":0])  );
    return 0;
}
