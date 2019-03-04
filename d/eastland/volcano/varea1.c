#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("��ɽɽ����");
	set_long( 
@LONG_DESCRIPTION
��վ��һ���޴�Ļ�ɽɽ���£������������Ļ�ɽɽ���ƺ�����������Ũ��
ð������֪��ʱ�����ٱ��������������ǳ����ȣ�������������������������
��ȥ�����ﵽ�����ǻ�ɽ�Һ͸�ʯ�������ɻ�ɽ�������ɵĻ�ɽ(volcano)�����
�����Ǿ޴���ѷ죬����뵽��ɽ�����൱���ѵġ�
LONG_DESCRIPTION
	);

set("item_desc",([
    "volcano" : "������ɽ�ǳ��ĸߣ���������������޷�����ȥ��\n",
       ]));
set( "exits", ([
     "south" : ONEW"wild20",
     "southwest" : ONEW"wild17",
     ]) );
set_outside("eastland");
reset();
}

void init()
{
  add_action("do_climb","climb");
}

int do_climb()
{  if( random( (int)this_player()->query_skill("climbing") ) < 50 ) {
      write( 
         "������ȥ���Ŷ���û��!\n");
      return 1;
    };
    write(
          "��ʹ�����̵��������������ȥ��\n");
    this_player()->move_player( ONEW"varea2.c","SNEAK" );
    return 1;
}
