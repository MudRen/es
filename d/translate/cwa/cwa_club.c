#include <mudlib.h> 

inherit ROOM;

void create()
{
	::create();
	set_short("Color Wolf Association", "ɫ�Ǿ��ֲ�" );
	set_long(
"You are in Club of Color Wolf Association\n",
"�����ɫ�Ǿ��ֲ�\n"
	);
	set( "light",1 );
	set( "exits", ([
		"out" : "/u/s/supertramp/workroom"
	]) );
	"/u/s/supertramp/cwa/cwa_board"->frog();
}

