#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("�����岿��");
	set_long( 
@LONG_DESCRIPTION
�����ǰ����岿��Ⱥ�������߿���ͨ�����ڣ����߿�ͨ���㳡������Ľ��������
ʯ��ģ�������ס��������úܶ�ʯ���̳ɵ�·�ᴩ�������䣬����������˵ĸ�
���Ƿǳ������Ұ���ģ���춻�ɽ�Ѿ��кܶ���û�б����ˣ������һ��������Ҳ��
���ľ͵����˴��£�����Կ�����һ������(camp)��������ֱߡ�
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "northwest" : OGROUP"warea3",
     "north" : OGROUP"warea9",
     ]) );
set( "objects", ([
     "wolder":OMONSTER"wolder",
     ]) );
set("item_desc", ([
    "camp" : "һ������Ƥ���ƶ��ɵ��������滹����һЩҰ�޵�ͼ�����ӷ��Ƶĺۼ�������\n��������ֹ�Ҳ������ģ��������������к���ס������\n",
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
  tell_room(this_object(),"�����"+this_player()->query("c_name")+"�߽�������\n",this_player());
  this_player()->move_player(OGROUP"house1","SNEAK");
  return 1;
}
