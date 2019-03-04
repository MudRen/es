#include "../tsunami.h"
#include <conditions.h>

inherit ROOM;

void create()
{
    ::create();
    set_short("����");
    set_long(@LONG
����������С���п���ֻ����һ�ж���Ǭ������������ͷ���ϵĹ�͸��
���ˣ�ӳ�ڵ��µ�ɳ���ϣ�ʹ�˸о��ݷ�����춳���֮�⣬����һ��δ��̽
����������һ�㡣�����������ľ��أ����㼸������Ҫ�����ˣ�
LONG
            );
    set("exits",([
        "up":AREA"upriver",
        "north":AREA"river1",
        "south":AREA"river2"]) );
    set_outside("island");
    set("underwater",1);
    reset();
}

void init()
{
UNDERWATER->apply_effect(this_player(),3,2);
}
