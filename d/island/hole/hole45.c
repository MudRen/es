#include <hole.h>

inherit ROOM;

void create()
{
	object bulansido;
	::create();
	set_short( "��������" );
	set_long(@LONG
��䷿�������С�ս�񡻳ƺŵ����������䡺����������ס����
LONG
		);
	set( "exits",([
			"up" : HOLE"hole44",
			]) );
	bulansido = new( HMONSTER"leader" );
	bulansido->move( this_object() );
	reset();
//#include <replace_room.h>
}

int clean_up(){ return 0; }
