#include <hole.h>

inherit ROOM;

void create()
{
	object abon;
	::create();
	set_short( "��������" );
	set_long(@LONG
��䷿���������˽���ʦ���ǰ��ס�������ǰ���������
�︺���������һ���������˽�����
LONG
		);
	set( "exits",([
			"northeast" : HOLE"hole36",
			]) );
	abon = new( HMONSTER"swordman" );
	abon->move( this_object() );
	reset();
}
