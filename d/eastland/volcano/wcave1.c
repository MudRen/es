#include "oldcat.h"

inherit ROOM;
inherit DOORS;
void create()
{
        ::create();
        set_short("������" );
        set_long(
@LONG
����һ����ɭɭ�İ�����Ŀ����ң��Ǹ���������ץ����Ʒ�ĵط������ƺ�������
���ߴ�����ȵ�������
LONG
        );
	set( "exits", ([
        "out" : ONEW"varea6",
        "east" : ONEW"wcave2"
	]) );
        set( "pre_exit_func",([
             "east":"to_east"
              ]) );
        set( "objects",([
               "wjailor" : OMONSTER"wjailor"
             ]) );
        create_door( "east","west", ([
                     "keyword" : ({"door","thick door"}),
                     "name" : "thick door",
                     "c_name" : "������",
                     "status" : "locked",
                     "lock" : "WGUARD",
                     "desc" : "You see a door.\n",
                     "c_desc" : "һ�Ⱥ���ľ�������и�Կ�ס�\n"
                    ]) );
        reset();
}

int to_east()
{
  if(!present("guard")) {
      return 0;
  }
  else {
      write("����˵�������������ͨ������һ����˵�ɡ�\n");
      return 1;
  }
}
