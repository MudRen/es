
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("The graveyard of Drawf city","����Ĺ��");
  set_long(@Long
�����ǰ��˹��ȵ�Ĺ��,Ĺ���������һЩӢ��ս����ʿ���ĹǺ�.ÿһ��Ĺ��
�ĵ��¶���һ��Ӣ�µ���갲Ϣ��.
Long
);
set("exits",([
            "north":Deathland"/city/g1",
            "south":Deathland"/city/g3",           
             ]));
}
