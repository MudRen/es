
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    set_short("The entrance of the dwarf village","���˴����С·");
    set_long(@Long
Long
,@CLong
��Ŀǰλ춰��˵Ĵ�ׯ�Ļ�ׯ��·��,���������ǳ���ƽ���������,�з���һ����
����Դ.�����Ѿ�����û��ս����,�����ǵ�ͯ�꼸���ڴ˶ɹ�.�����ǰ��˵���Ӥ��,��
���ݵİ��˶����ڴ˵س�����
CLong
    );
    set("exits",([
                "west":Deathland"/village/v35",
                "north":Deathland"/village/vr5",
                "east":Deathland"/village/v55",
             ]));
    ::reset();
#include <../replace_room.h>
}
