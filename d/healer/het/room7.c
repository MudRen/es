#include <mudlib.h>
#include "wang.h"
inherit ROOM;

void create()
{
 	::create();
        set_short("����");
	set_long(@LONG
�ߵ����������ǰһ�������￪���˸��ֻ���������ȥ��һƬ�����������㣬
��������ݷ������ɾ�����ġ��Ƶġ��׵ġ����ġ��ϵ�����ϡ�еĺ�ɫ�Ļ�������
�����Կ�����ˮͰ��С���ӣ���ͷ�ȵȹ����Ĵ�ɢ������Ȼ����Ļ�������ϸ���չ�
�ġ�
LONG
);
	set("light", 1);
	set("exits",([
		"west" : WANG"room1" 
	]));

	reset();
}

void init()
{
    add_action("to_search", "search");
}

int to_search(string arg)
{
    object o;

    write("�����˰��죬���˻�֮�⻹�ǻ� ....\n");
    o = new("/d/healer/plant/opium_poppy_plant");
    o->move(this_object());
    return 1;
}

