#include <hole.h>

inherit ROOM;

void create()
{
	object arthur;
	::create();
	set_short( "��������" );
	set_long(@LONG
��䷿������������ʿ���ų�����ɪ����ס��������ɪ��Ŀǰ�����
��������ʿ���ŵ��쵼�ߡ�
LONG
		);
	set( "exits",([
			"east" : HOLE"hole42",
			]) );
	arthur = new( HMONSTER"colonel" );
	arthur->move( this_object() );
	reset();
}

int clean_up(){ return 0; }
