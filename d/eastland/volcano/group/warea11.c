#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
    set_short("�����岿��");
	set_long( 
@LONG_DESCRIPTION
�����ǰ����岿��Ⱥ�������߿�ͨ���㳡������Ľ��������ʯ��ģ�������
ס��������úܶ�ʯ���̳ɵ�·�ᴩ�������䣬����������˵ĸо��Ƿǳ�������
����ģ���춻�ɽ�Ѿ��кܶ���û�б����ˣ������һ��������Ҳ�����ľ͵����˴�
�£�����Կ�����һ������(camp)�����ǰ����
LONG_DESCRIPTION
	);
set( "exits", ([
     "northwest":OGROUP"warea10",
     "east" : OGROUP"warea16" ]) );
set("objects", ([
    "wboy":OMONSTER"wboy",
    ]) );
set("item_desc", ([
   "camp" : "һ��������ַ��ŵ����񣬲�֪����˭ס�����棬�����ȥ������?\n",
   ]) );
set_outside("eastland");
reset();
}

void init()
{
   add_action("do_enter","enter");
}

int do_enter(string arg)
{
  if (!arg || arg!="camp" ) {
    write("��Ҫ��ȥ���\n");
    return 1;
  }
  tell_object(this_player(),"���߽���������\n");
  tell_room(this_object(),"�����"+this_player()->query("c_name")+"�߽������ڡ�\n",this_player());
  this_player()->move_player(OGROUP"house3","SNEAK");
  return 1;
}
