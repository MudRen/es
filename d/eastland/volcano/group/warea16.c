#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
    set_short("�����岿��");
	set_long(
@LONG_DESCRIPTION
�����ǰ����岿��Ⱥ�����߿���ͨ�����ڣ����߿�ͨ���㳡������Ľ��������ʯ
��ģ�������ס��������úܶ�ʯ���̳ɵ�·�ᴩ�������䣬����������˵ĸо�
�Ƿǳ������Ұ���ģ���춻�ɽ�Ѿ��кܶ���û�б����ˣ������һ��������Ҳ����
�ľ͵����˴��¡�һ��������ΰ�����(temple)�����������
LONG_DESCRIPTION
	);
set("item_desc", ([
    "temple" : "һ���޴�İ������������������������ݵ��񣬻���\n",
    ]) );
set( "exits", ([ 
     "west" : OGROUP"warea11" ]) );
set_outside("eastland");
reset();
}

void init()
{
   add_action("do_enter","enter");
}

int do_enter(string arg)
{
  if (!arg || arg!="temple" ) {
    write("��Ҫ��ȥ���\n");
    return 1;
  }
  tell_object(this_player(),"���߽���������С�\n");
  tell_room(this_object(),"�����"+this_player()->query("c_name")+"�߽�����ڡ�\n",this_player());
  this_player()->move_player(OTEMP"temple1","SNEAK");
  return 1;
}
