
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("The graveyard of Drawf city","矮人国度的墓场");
  set_long(
@CLong
这里是矮人国度的墓场,埋藏著一些英勇战死的士兵的骨骸.
CLong
);
set("exits",([
            "north":Deathland"/city/c3",
             ]));
}
