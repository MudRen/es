#include <hole.h>

inherit ROOM;

void create()
{
	object akaba;
	::create();
	set_short( "��������" );
	set_long(@LONG
��䷿���������˴󽫾������͵�ס����������������������
������һ��һ��սʿ�����ϵ�˫����֪�����ܶ��ٺú���
LONG
		);
	set( "exits",([
			"southwest" : HOLE"hole36",
			]) );
	akaba = new( HMONSTER"imperator" );
	akaba->move( this_object() );
	reset();
}

int clean_up() { return 0; }
