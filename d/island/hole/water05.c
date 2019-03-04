
#include <hole.h>
#include <conditions.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "ˮ��" );
	set_long(@LONG
����һ������ˮ�㼯�ĵĵز㣬�������ճ�������ˮ
�����ɴ˴���Ӧ�ġ����������ˮ�൱���ǣ�����������
����ˮ��Ŀ��Ժ���
LONG
		);
	set( "exits",([ 
			"southwest" : HOLE"water04",
			"north" : HOLE"water07",
		]) );
	set( "exit_invisble",1 );
	set( "underwater",1 );
	set( "objects",([
			"fish#1" : HMONSTER"fish1",
			"fish#2" : HMONSTER"fish1",
			"fish#3" : HMONSTER"fish2",
			"fish#4" : HMONSTER"fish2",
			]) );
	reset();
	
}

void init()
{
	UNDERWATER->apply_effect( this_player(),4,3 );
}
