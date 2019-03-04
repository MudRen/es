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
    if( arg != "down" && arg != "up")
      return notify_fail("���ٲ������������䣬��Ҫ���Ǳ��أ�\n");
    if( arg == "down" )
      to_climb_down( this_player(), AREA"in", AREA"in",35,5);
    else if( arg == "up")
      to_climb_up(this_player(),AREA"in2",35);
    return 1;
}
