#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
      set_short( "��ի" );
	set_long(
             "����һ����˶���ķ��䣬�ڷ��м����һ�������������������£�\n"
     "���������鱾��\n"
	);
        set( "light",1 );
        set( "exits", ([
 "down" : "/u/s/sage/test/pet_shop",
  "up" : "/d/wiz/wiz_hall",
    "east" : "/u/s/sage/work.c"
        ]) );
}
