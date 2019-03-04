
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
 set_short("the dwarf village","矮人村入口");
  set_long(@Long
Long
,@CLong
一个很大的洞穴,有好几个洞穴通向未知的区域,矮人为了能安安全全地生
活著,把自己的村落建筑於这个宛如迷宫的大洞之中,除了矮人自己能够快速且
安全地走到自己的村落外,似乎要到矮人村落是一件困难的事.
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
