
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("Troll Altar","���˼�̳");
        set_long(@Long
Long
,@Clong
�����ƺ���һ�����׳�,��������ȴ������������ֵֹ�ͼ�ڴ�����,��
��һ���ܾ޴���������������ǰ,ɽ�����˳����û���������,ȥ��������ս
����ɱ��ʤ��.
Clong
	);
set("exits",([
   "east":Deathland"/troll/cave_06",
            ]) );
::reset();
#include <../replace_room.h>
}

void init()
{
  this_player()->set_explore( "deathland#2" );
}

