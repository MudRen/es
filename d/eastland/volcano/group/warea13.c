#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
    set_short("�����岿��");
	set_long( 
@LONG_DESCRIPTION
�����ǰ����岿��Ⱥ�����ϱ߿�ͨ���㳡������Ľ��������ʯ��ģ�������
ס��������úܶ�ʯ���̳ɵ�·�ᴩ�������䣬����������˵ĸо��Ƿǳ�������
����ģ���춻�ɽ�Ѿ��кܶ���û�б����ˣ������һ��������Ҳ�����ľ͵����˴�
�£�һ��ʯ�췿��(house)�����������
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "southwest" : OGROUP"warea10",
     ]) );
set( "objects", ([
     "wguard":OMONSTER"wguard",
     ]) );
set("item_desc", ([
    "house": "һ��ʯ��ķ��ӣ��������ǳʺں�ɫ�ģ����и������ĵ����ڷ��ݵ��ݶ�����֪��\n��˭ס�����\n",
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
  if (!arg || arg!="house" ) {
    write("��Ҫ��ȥ���\n");
    return 1;
  }
  tell_object(this_player(),"���߽���䷿����\n");
  tell_room(this_object(),"�����"+this_player()->query("c_name")+"�߽������\n",this_player());
  this_player()->move_player(OGROUP"house4","SNEAK");
  return 1;
}
