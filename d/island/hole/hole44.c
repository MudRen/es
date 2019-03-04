#include <hole.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "��������" );
	set_long(@LONG
��������վ�ĵ�λ���������������ĵڶ��㣬�������ῴ������
�Ǹ���ٹ��˵���Ϣ������������˵�Ǹ���Ѩ��Ϊǡ��������������
Ϊ�����������ͱȽϲ�������ס��������ɵġ������¾�����������
�䡺����������ס����
LONG
	);
	set( "exits",([
			"south" : HOLE"hole42",
			"down" : HOLE"hole45",
			]) );
	set( "objects",([
			"guard#1" : HMONSTER"life_guard",
			"guard#2" : HMONSTER"life_guard",
			]) );
	set( "pre_exit_func",([ "down" : "check_invis" ]) );
	reset();
}

int check_invis()
{
	object player;
	string him;
	
	player=this_player();
	him=player->query( "c_name" );
	if( (int)player->query( "player_invisible" )==1 )
	{
	if( present( "guard",environment(player) ) ){
	tell_room( environment(player),set_color(
	"����ŭ�Ե�����͵͵���������������������˰�����\n","HIR") );
	return 1;
	}
	else{
	tell_room( environment(player),set_color(
	"ͻȻһ������������˵��������Ϊ���ξͿ����ӹ��ҵķ��ۣ��Թ����ΰɡ���\n","HIR") );
	return 1;
	}
	}
	return 0;
}
