// something wrong with this room.. I dunno ;)  -Elon 03-10-94
#include "../moyada.h"

inherit ROOM;

void create()
{
	::create();
	set_short("����");
	set_long( @C_LONG_DESCRIPTION
�����ž����Ϻ�ס�ĵط�����δ�Եø����ûʣ�ֻ���������Ե���Щ
���ࡣ�Ϻ��Ӵ����������ռ�����������䣬��ֻ��������æ���������µ�
���˳�ȥ��
C_LONG_DESCRIPTION
	);
	set( "exits", ([
      "north"  : MOYADA"anthill/square",
	]) );
	set( "no_monster", 1);
	set( "objects", ([
	   "ant worker#1" : MOYADA"monster/ant_worker",
	   "ant worker#2" : MOYADA"monster/ant_worker",
	   "ant queen" : MOYADA"monster/ant_queen",
	   "kaisa ant#1" : MOYADA"monster/kaisa_ant",
	   "kaisa ant#2" : MOYADA"monster/kaisa_ant",
	]) );
	reset();
}

void reset()
{
    set( "ant_left", 5);
    ::reset();
}
