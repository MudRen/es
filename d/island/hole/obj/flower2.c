#include <../hole.h>

inherit OBJECT;
void create()
{
	set_name( "Red Flower","С�컨" );
	add( "id",({ "flower" }) );
	set_short( "С�컨" );
	set_long( "һ��С�컨\n" );
	set( "weight",1 );
	set( "unit","��");
	set( "prevent_get",1 );
}           

void init(){ add_action( "to_cull","cull" ); }

int to_cull(string arg)
{
	if( !arg || arg!="flower" )
		return notify_fail( "��ʲ�᣿\n" );
		
	write( "��ժ��һ���ɫҰ����\n" );
	this_object()->set( "prevent_drop",0 );
	this_object()->move( this_player() );
	return 1;
}
	