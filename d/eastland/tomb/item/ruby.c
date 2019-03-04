#include "../almuhara.h"

inherit OBJECT;

void create()
{
	set_name( "shining ruby", "�챦ʯ" );
	add( "id", ({ "ruby","stone","gem" }) );
	set_short( "��������ĺ챦ʯ" );
	set_long(
		"����һ����������ĺ챦ʯ��\n"
	);
	set( "unit", "��" );
	set( "weight", 5 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
	add_action( "put_ruby","put" );
}

int put_ruby(string str)
{
	object player,ob;
	string orb;
	int i,chinese_mode;
    
    	player = this_player();
    	chinese_mode = can_read_chinese(player);
    
	if ( !str || str=="") 
       		return 0;  
	if ( str == "ruby in hole" && present( "guilt", player ) )
	   {	   
		write( 
		"����Ѻ챦ʯ����С��ʱ��а�����еĹ�â��Ȼһ����������ʢ !! \n"
		);
		player->set_temp("NO_DRAIN", 1);
		remove();
		return 1; }
	else return 0;
}