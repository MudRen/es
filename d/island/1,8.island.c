// File: 1,8.island.c

#include <mudlib.h>
#include <conditions.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("ǳ��");
	set_long( @LONG_DESCRIPTION
����ǿ������ߵĵ�ǳ������Ȼ��ǳ��һ��������10�������ڣ�����
��Σ�յģ���ʱҪע���Լ�������״������ҪӲ�ţ�ࡣ����ˣ��������
��������С�Ŀ��ܻᱻ��ú�Զ��
LONG_DESCRIPTION
	);
	
        set( "underwater",1 );
	set_outside( "island" );
	set( "exits", ([ 
		"east"  : ISLAND"2,8.island",
		"north" : ISLAND"1,7.island",
		]) );
	set( "original", ISLAND"1,8" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 1 );
	set( "y_coordinate", 8 );
        call_out( "flow_away",30 );
	reset();
	
}

void init()
{
     UNDERWATER -> apply_effect ( this_player(), 3, 3 );
}
void flow_away()
{
     int i;
     object *ob;
     
     ob = all_inventory();
     i = sizeof( ob );
     
     while( --i>=0 )
     {  if( (int)ob[i] -> query( "likefish" ) < 1||(string)ob[i]->query("name")=="shark" )
        {
        tell_object(ob[i],"\n\n �ۣ� ���һ��ͻ�������ĺ��������Ƶ������� \n\n" );
        ob[i] -> move_player( ISLAND"2,9.island.c" ,"SNEAK" ) ;
        } 
        else
        {
         tell_object(ob[i],"Ү? ���˱�������! ����!\n");  
       }
       }
}     