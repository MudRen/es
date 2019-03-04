#include "almuhara.h"

inherit ROOM;

void create()
{
	::create();
	set_short("����ʯ��");
	set_long( 
@C_LONG_DESCRIPTION
�������һ��������ʯ�ң�����ƺ����Թ����յ㡣���ܵ�ǽ�������Ϻ�ʯש���ɵģ�
�ڷ������������֧���ӣ����ϲʻ������������ľ�������Χ�������������һ�����Ƽ�̳
�Ķ�����������������������(writings)����������൱��Զ�ˡ����ǽ���ƺ���ʲ�ᶫ
���������㿴�������
C_LONG_DESCRIPTION
	);
	set( "light", 1);
	set( "exits", ([ 
		"north" : TOMB"/room4", 
		"south" : TOMB"/maze10",
		"east"  : TOMB"/room2",
		"west"  : TOMB"/room3"  ]) );
	set( "exit_suppress" , ({ "west", }) );
	set( "pre_exit_func", ([
		"west" : "check_WALL" ]) );		
	reset();	
}
void init()
{
	add_action( "do_look", "look");
	add_action( "do_search", "search");
}

int do_look (string str)
{
	object player;
	
	player = this_player();
	
	if ( !str || str == "")
	return notify_fail(" ��ɶ ??\n");
	
	if ( str == "writings" ) {
		if ( (int)player->query_skill("runes") > 50 ) {
			tell_object( player, 
			"��  ���츣��  ��\n" );
			return 1; }
		else 
			tell_object( player, 
				"������ۻ����ң����������Щ�֡�\n" );
				return 1;
	}
	if ( str == "west" ) 
		return 1;
	return 0;
}

int do_search(string str)
{
	object player;
	
	player = this_player();
	
	if ( !str || str == "" )
		return notify_fail("Search what??\n");
	
	if ( str == "corner" ) {
		tell_object( player, 
			"������ϸ��Ѱǽ�ǣ����������и�С���ſ��Խ���!!\n"
			);
	        player->set_temp("WALL",1);
	return 1; }
	else return 0;
}

int check_WALL()
{
	object player;
	
	player = this_player();
	
	if ( player->query_temp("WALL") ) {
		player->delete_temp("WALL");
		return 0; }
	else return 1;
}