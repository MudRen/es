#include <../hole.h>

inherit OBJECT;
void create()
{
	set_name( "Red Flower","小红花" );
	add( "id",({ "flower" }) );
	set_short( "小红花" );
	set_long( "一朵小红花\n" );
	set( "weight",1 );
	set( "unit","朵");
	set( "prevent_get",1 );
}           

void init(){ add_action( "to_cull","cull" ); }

int to_cull(string arg)
{
	if( !arg || arg!="flower" )
		return notify_fail( "采什麽？\n" );
		
	write( "你摘下一朵红色野花。\n" );
	this_object()->set( "prevent_drop",0 );
	this_object()->move( this_player() );
	return 1;
}
	