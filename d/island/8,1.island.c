// File: 8,1.island.c

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
		"west"  : ISLAND"7,1.island",
		"south" : ISLAND"8,2.island",
		]) );
	set( "original", ISLAND"8,1" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 8 );
	set( "y_coordinate", 1 );
        set( "objects",([
                  "t1":IMON"turtle3",
                  "t1":IMON"turtle3"
                  ]));
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
     {  if( (int)ob[i] -> query( "likefish" ) < 1 )
        {
        tell_object(ob[i],"\n\n �ۣ� ���һ��ͻ�������ĺ��������Ƶ������� \n\n" );
        ob[i] -> move_player( ISLAND"7,1.island.c" ,"SNEAK" ) ;
        }   
     }
}     