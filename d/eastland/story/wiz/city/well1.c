#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("����");
	set_long( @LONG
������һ�ڿݾ��ס���ھ���Ϊ�������ˮԴ�Ѷϣ�����ʹ�ã�������������
�����������ǽ�ڶ�����̦���ײ���һ�����ࡣ���ڻ�������ǰ�˼�ʹ�õ�����ˮ
Ͱ�����ӣ����������������ȥ��
LONG
	);
	set( "exits", ([ 
           "up" : SCITY"wn2"
        ]) );
        set( "objects", ([
          "objects":SWMOB"dog1"
        ]) );
	reset();
}
