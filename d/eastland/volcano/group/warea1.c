#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("�����岿�����");
	set_long( 
@LONG_DESCRIPTION
�����ǰ����岿��Ⱥ����ڣ������������Χ������������ĺ���֮�⣬����һ����
��ľ׮����������Χ���������Ĳ������޶��ǻ�ɽż���������������ҽ�����������
���辭��һ���ɿ��Ƶĵ��ţ�������ƽ���������Ŷ��Ƿ������ģ�����������վ����
�ڱ������䲢�۲��ɽ��״����
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "out" : ONEW"wild16",
     "east" : OGROUP"warea3" ]) );
set( "objects", ([
     "wguard#1":OMONSTER"wguard",
     "wguard#2":OMONSTER"wguard",
     ]) );
set( "pre_exit_func", ([
     "east" : "to_east",
     "out":"to_leave" ]) );
set_outside("eastland");
reset();
}

int to_leave()
{
  write("���뿪���䣬������ȥ��\n");
  return 0;
}

int to_east()
{
  if (!present("soldier"))
    return 0;

  if (present("head",this_player()))
  {  write("������һ���������ͷ��˵�����š��������ǵ��ֵܣ���ȥ��!\n");
     this_player()->set_explore("eastland#37");
     return 0;
  }

  write("����˵����û������ͷ�����ܱ�Ǹ��������ͨ����\n");
  write("        ��һ����ù����������ͷ�� ! \n");
  return 1;
}
