
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    set_short("The road of the dwarf village","���˴����С·");
    set_long(@Long
Long
,@CLong
��Ŀǰλ춰��˵Ĵ�ׯ�Ļ�ׯ��·��,���������ǳ���ƽ���������,�з���һ����
����Դ.�����Ѿ�����û��ս����,�����ǵ�ͯ�꼸���ڴ˶ɹ�.
CLong
    );
    set("exits",([
                "north":Deathland"/village/v12",
                "east":Deathland"/village/v21",
             ]));
    set("objects",([
        "child":Monster"/child",
                  ]) );
    ::reset();
#include <../replace_room.h>
}
