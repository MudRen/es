#include "takeda.h"
#include <conditions.h>

inherit ROOM;

void create()
{
        object ob;

	::create();
        set_short( "ˮ��֮��" );
	set_long(@C_LONG
������ˮ�����棬��С�պù���������������ˮ���������Ϊ���û����
���������㷢�ָ��е����������Ĵ������㡣
C_LONG
	);
	set( "exits", ([
	     "out" : TROOM"room2"
	]) );
        set( "objects",([
             "fish1" : TMONSTER"fish11",
             "fish2" : TMONSTER"fish11",
             "fish3" : TMONSTER"fish11"]));
        set("underwater",1);
          reset();
}
void init()
{
  UNDERWATER->apply_effect(this_player(),4,1);
}



