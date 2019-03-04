#include "../megatower.h"

inherit ROOM;

void create()
{
	::create();
  set("light",0);
  set_short("The stair of Mega Tower","摩天塔的阶梯");
  set_long(@Long
Long
,@CLong
你到达了摩天塔的第二层, 一堆乱石与破瓦堆积与此, 这里有一个阶梯, 通往第
三层.
CLong
);
  set("exits",([
               "up"    :Megatower"/floor3/45",
               "west"  :Megatower"/floor2/44",
             ]));

::reset();
}

