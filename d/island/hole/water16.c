
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
			"west" : HOLE"water17",
			"south" : HOLE"water15",
		]) );
	set( "exit_invisble",1 );
	set( "underwater",1 );
	reset();
	
}

void init()
{
	UNDERWATER->apply_effect( this_player(),4,3 );
	add_action( "to_out","out" );
}

int to_out()
{
	string him;
	
	him=this_player()->query( "c_name" );
	tell_room( environment(this_player()),set_color(
	him+"�ܲ���ˮ�׻����������ȳ�ȥ��������\n","HIR"),this_player() );
	this_player()->move( HOLE"hole24","SNEAK" );
	this_player()->force_me( "look" );
	tell_room( environment(this_player()),set_color(
	him+"��Ȼ������ǰ�ĳ�����ð�˳�����\n","HIY"),this_player() );
	return 1;
}