
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("The graveyard of Drawf city","���˹��ȵ�Ĺ��");
  set_long(
@CLong
�����ǰ��˹��ȵ�Ĺ��,�����һЩӢ��ս����ʿ���ĹǺ�.
CLong
);
set("exits",([
            "north":Deathland"/city/c3",
             ]));
}
