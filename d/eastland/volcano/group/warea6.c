#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
    set_short("�����岿��");
    set_long( 
@LONG_DESCRIPTION
�����ǰ����岿��Ⱥ�����ϱ߿���ͨ�����ڣ��ϱ߿�ͨ���㳡������Ľ��������
ʯ��ģ�������ס��������úܶ�ʯ���̳ɵ�·�ᴩ�������䣬����������˵ĸ�
���Ƿǳ������Ұ���ģ���춻�ɽ�Ѿ��кܶ���û�б����ˣ������һ��������Ҳ��
���ľ͵����˴��£�����Կ�����һ������(camp)��������ֱߡ�
LONG_DESCRIPTION
	);
set( "exits", ([
     "southwest" : OGROUP"warea3",
     "south" : OGROUP"warea9" ]) );
set( "objects", ([
     "wgirl":OMONSTER"wgirl",
     ]) );
set("item_desc", ([
    "camp" : "һ������Ƥ���ƶ��ɵ����������ϻ���һЩ�������̵�װ��Ʒ���ӷ��Ƶĺۼ�\n��������������ֹ�Ҳ������ģ��������ڲ����������Ů����ס�ĵط���\n",
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
  if (!arg || arg!="camp") {
    write("��Ҫ��ȥ���\n");
    return 1;
  }
  tell_object(this_player(),"���߽���������\n");
  tell_room(this_object(),"�㿴��"+this_player()->query("c_name")+"�߽������ڡ�\n",this_player());
  this_player()->move_player(OGROUP"house2","SNEAK");
  return 1;
}
