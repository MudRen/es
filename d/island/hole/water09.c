
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
			"south" : HOLE"water08",
		]) );
	set( "exit_invisble",1 );
	set( "underwater",1 );
	reset();
	
}

void init()
{
	UNDERWATER->apply_effect( this_player(),4,3 );
}
