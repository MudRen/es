// File: 5,4.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;
int no_branch;

void create()
{
	::create();
	set_short("�һ���");
	set_long( @LONG_DESCRIPTION
������һƬ�������һ����У�����������ν�ġ���Ӣ�ͷף�������
������Ҫ����ϸ�۲�˴�����������ᷢ��������ĳ����ֵĴ���������
�������ֿ�������������ĺۼ��������ǻ�Ȼ��ɵİɣ�������վ��Խ��
����Խ������������������Ѿ�����Զȥ�������Ŀ������ĸо���ʹ���
�������������ϱߺ���������С�ӣ������е��С��ࡣ�	
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"4,4.island", 
		"north" : ISLAND"5,3.island", 
		"east"  : ISLAND"6,4.island",
		"south" : ISLAND"5,5.island",
		]) );
	set( "original", ISLAND"5,4" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 5 );
	set( "y_coordinate", 4 );
	no_branch=0;
	reset();
}

void init(){ add_action( "to_mill","mill" ); }

int to_mill( string arg )
{
	string target,tool;
	object obj;

	if( !arg || sscanf(arg,"%s with %s",target,tool)!=2 )
	return notify_fail( "Usage: mill <Ŀ��> with <����> \n" );
	if( target!="tree" ) 
	return notify_fail( "��Ѹ�ͷֻ�ܿ���ľ��\n" );
	if( tool!="saw" )
	return notify_fail( "���־���\n" );
	if( !present( "saw",this_player() ) )
	return notify_fail( "��⣡�����˴���������\n" );
	if( no_branch < 4 ){
	tell_object(this_player(),
	"\n����˾�ţ����֮��������ҵ�һ�ú��ʵ�����������һ����֦��\n\n" );
	obj=new( "/d/island/hole/obj/branch" );
	obj->move( this_player() );
	this_player()->set_explore("island#8");
	no_branch=no_branch+1;
	return 1;
	}
	tell_object(this_player(),"\n��֪���ĸ����̰��������ľȫ���ˡ�\n\n" );
	return 1;
}
