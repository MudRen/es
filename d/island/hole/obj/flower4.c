#include <../hole.h>

inherit OBJECT;
void create()
{
	set_name( "Yellew Flower","С�ƻ�" );
	add( "id",({ "flower" }) );
	set_short( "С�ƻ�" );
	set_long( "һ��С�ƻ�\n" );
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
	