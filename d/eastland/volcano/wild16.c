#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("�յ�");
	set_long(
@LONG_DESCRIPTION
��Ƭ�յ���᫲�ƽ���������Ǻ�ɫ��ʯͷ�����ɫ����������һ��������͵���
��֪��һ���ǻ�ɽ������Ĳ����������Ҳ�����������ȵģ����һ���л�ɽ����
�������㷢�ֲ�Զ��ǰ���и��ǹ��ƵĽ��������и����ţ������ƺ������˵����ӣ�
�����ǿ��ܾ��ǿ��µİ����岿�䣬��������ȴ��ʹ�����ȥ���ơ�
LONG_DESCRIPTION
	);
set( "exits", ([
     "near" : OGROUP"warea1",
     "north" : ONEW"wild17",
     "southwest" : ONEW"wild13",
     ]) );
set( "pre_exit_func", ([
     "near":"to_near" ]) );
set_outside("eastland");
reset();
#include <replace_room.h>
}

int to_near()
{
  write("����������˹�ȥ��\n");
  return 0;
}
