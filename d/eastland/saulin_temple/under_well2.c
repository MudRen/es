#include "saulin_temple.h"

inherit ROOM;

void create()
{
       ::create();
       set_short( "���ж�Ѩ" );
       set_long( @C_LONG_DESC
����һ�����׵Ķ�Ѩ�У��ⶴ��������Ǭ����ͬʱ���е�������������
���ǻ��㣬��ʵ�ڷֱ治����ʲ����ζ����! ����ס��һ���ǰ�Ǭ���ֶ���
����������
C_LONG_DESC
       );
       set("exits",([
           "out" : SAULIN"under_well1",
       ]) );
       set("objects",([
            "bug1" : SAULIN_MONSTER"small_bug",
            "bug2" : SAULIN_MONSTER"small_bug",
            "bug3" : SAULIN_MONSTER"small_bug",
       ]) );
       reset();
}
void init()
{
        if ( this_player()) this_player()->set_explore("eastland#29");
}
