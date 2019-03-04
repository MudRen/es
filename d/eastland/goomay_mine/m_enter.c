
#include <zeus.h>

inherit ROOM;

void create()
{
  ::create();
  set_short("段家矿坑入口");
  set_long(@CLong
这里是矿坑的入口.你能看到的是一个周围的岩壁充满著被挖掘的痕迹以及
用木头架设著以免塌陷的岩洞.在地上有铁轨铺设著.北边传来阵阵的水声，
CLong
);
   

set("exits",([
		"south" : "/d/eastland/goomay/entrance",
             "north":ZROOM"/bridge" ]));

    reset();
#include <replace_room.h>
}
