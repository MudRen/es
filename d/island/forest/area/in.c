#include "../tsunami.h"
#include "anthill.c"

inherit ROOM;
void create()
{
    ::create();
    set_short("�ٲ��ڲ�");
    set_long(@LONG
ԭ���ٲ���ͷ����һ����������ĵط����������µĳ�ʴʹ����ʯ��
�ù⻬�����ҳ�����̦޺�������ȷ�ŵ��ǣ���ط��ƺ�������Ȼ�γɵġ�
LONG
            );
    set("light",1);
    set_outside("island");
    reset();
}

void init()
{
    add_action("do_search","search");
    add_action("do_climb","climb");
}

int do_search()
{
      tell_object(this_player(),
      "�š������������ƶϵĽ����ȷ������������(climb)���ĺۼ�.......\n");
      return 1;
}

int do_climb( string arg)
{
    if( !arg || arg=="" )
      return notify_fail("��Ҫ���ĸ������أ�\n");
    if( arg != "up")
      return notify_fail("��������ٲ����·��ˣ��㻹�����Ķ����أ�\n");
    to_climb_up(this_player(),AREA"in1",40);
    return 1;
}
