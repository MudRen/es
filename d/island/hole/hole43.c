#include <hole.h>

inherit ROOM;

void create()
{
	object rasoda;
	::create();
	set_short( "��������" );
	set_long(@LONG
��䷿���������˼�˾���������ס�����������Ŀǰ�����
���ȸ���ħ�������һ������
LONG
		);
	set( "exits",([
			"west" : HOLE"hole42",
			]) );
	rasoda = new( HMONSTER"poutiff" );
	rasoda->move( this_object() );
	reset();
//#include <replace_room.h>
}
