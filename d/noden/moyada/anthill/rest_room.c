// rest room sounds like .. WC :) -Elon 03-10-94
#include "../moyada.h"

inherit ROOM;

void create()
{
	::create();
    set_short("��Ϣ��");
	set_long( @C_LONG_DESCRIPTION
�����ǹ�������Ϣ�ĵط�������ֻ�������ں�����˯��
C_LONG_DESCRIPTION
	);
	set( "exits", ([
		"north" : MOYADA"anthill/cellar1",
	]) );
	set( "objects", ([
	   "ant worker#1" : MOYADA"monster/ant_worker",
	   "ant worker#2" : MOYADA"monster/ant_worker",
	   "ant worker#3" : MOYADA"monster/ant_worker",
	   "ant worker#4" : MOYADA"monster/ant_worker",
	   "ant worker#5" : MOYADA"monster/ant_worker",
	   "ant worker#6" : MOYADA"monster/ant_worker",
	]) );
	reset();
}

void reset()
{
    ::reset();
    set("ant_left",4);
}
