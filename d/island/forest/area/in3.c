#include "../tsunami.h"
#include "anthill.c"

inherit ROOM;
void create()
{
    ::create();
    set_short("�ٲ�����");
    set_long(@LONG
�����������һЩ��������ߵ��ˣ�ԭ���ٲ����˵���һͷ��һ�������¡�
LONG
            );
    set_outside("island");
    set("exits",([
        "east":AREA"h2"]) ); 
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
    if( arg != "down" )
      return notify_fail("��������ٲ��Ķ����ˣ���Ҫ���Ķ����أ�\n");
    if( arg == "down" )
      to_climb_down( this_player(), AREA"in2", AREA"in", 35, 15);
    return 1;
}
