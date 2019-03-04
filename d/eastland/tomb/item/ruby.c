#include "../almuhara.h"

inherit OBJECT;

void create()
{
	set_name( "shining ruby", "红宝石" );
	add( "id", ({ "ruby","stone","gem" }) );
	set_short( "闪闪发光的红宝石" );
	set_long(
		"这是一颗闪闪发光的红宝石。\n"
	);
	set( "unit", "颗" );
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
		"当你把红宝石放入小洞时，邪像眼中的光芒忽然一暗，接著大盛 !! \n"
		);
		player->set_temp("NO_DRAIN", 1);
		remove();
		return 1; }
	else return 0;
}