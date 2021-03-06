
#include "../echobomber.h"

inherit ROOM;
inherit DOORS;
void create()
{
	::create();
  set("light",1);
  set_short("矮人国度的入口");
  set_long(@CLong
往西边看过去,有一个很大很大的空间,那里正是矮人国度.在矮人的辛勤的
努力工作下,目前矮人国度已经能够自给自足了.但是由於山顶巨人的攻击,矮人
们数代的辛苦经营几乎毁於一旦.所以矮人为了保卫自己的家园,正在加强 本身
的武力与防护措施.
这是通往矮人国度的入口,你看到有极佳的防御工事正在修筑.无论任何时刻,矮
人在此地的武力都十分强大,因为这里是通往矮人国度的唯一路径.
CLong
);
set("exits",([
              "west":Deathland"/main/d7",
              "east":Deathland"/city/c2",
             ]));
set("objects",(["soldier#1":Monster"/soldier",
                "soldier#2":Monster"/soldier",
                "captain":Monster"/captain_1",
               ]) );
 create_door("west","east",([
             "c_desc" : "一扇结实厚重的石门",
             "keyword" : ({"stone door","door" }),
              "name" : "stone door",
             "desc" : "A stone door",
             "c_name" : "石门",
             "status":"closed",
              ]) );
  ::reset();
}
