#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("ɽ��");
	set_long( 
@LONG_DESCRIPTION
�����������Ļ�ɽɽ���ƺ�����������Ũ��ð������֪��ʱ�����ٱ����������
����ǳ����ȣ���������������������������ȥ�����ﵽ�����ǻ�ɽ�Һ͸�ʯ����վ
��ɽ������������ȥ����������Ҫ�����ɽ����һ��ξ��룬��Ϣһ�°ɣ������ɻ�
ɽ�������ɵĻ�ɽ����춵����Ǿ޴���ѷ죬����뵽��ɽ�����൱���ѵġ�
LONG_DESCRIPTION
	);

set( "exits", ([
     "south": ONEW"varea2",
     "southeast" : ONEW"varea5" ]) );
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
    this_player()->move_player( ONEW"varea6.c","SNEAK" );
    return 1;
}

