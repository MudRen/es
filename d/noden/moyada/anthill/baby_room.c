// translation done -Elon 03-10-94 (desc is kinda dumb, I know..)
#include "../moyada.h"

inherit ROOM;

void create()
{
	::create();
	set_short("��Ӥ��");
	set_long( @C_LONG_DESCRIPTION
���￴�����ǹ��ϵ���Ӥ�ң��ö�ֻС�������ڿ���������������һ��
�ƺ�ɫ��Һ��ι��С���ϵĿ��С�
C_LONG_DESCRIPTION
	);
	set( "exits", ([
	   "west"   : MOYADA"anthill/square",
	]) );
	set( "objects", ([
	   "ant worker#1" : MOYADA"monster/ant_worker",
	   "ant worker#2" : MOYADA"monster/ant_worker",
	   "ant baby#1"   : MOYADA"monster/ant_baby",
	   "ant baby#2"   : MOYADA"monster/ant_baby",
	   "ant baby#3"   : MOYADA"monster/ant_baby",
	   "ant baby#4"   : MOYADA"monster/ant_baby",
	   "ant baby#5"   : MOYADA"monster/ant_baby",
	   "ant baby#6"   : MOYADA"monster/ant_baby",
	]) );
	reset();
}

void reset()
{
    set( "ant_left", 6);
    ::reset();
}
