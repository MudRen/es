// File: 8,8.island.c

#include <mudlib.h>
#include <conditions.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("СϪ");
	set_long( @LONG_DESCRIPTION
�����㻹���ܲ������峺��ˮ���ٻ���������������ʮ�����õ��£�
����Ҫע�������£���һ�������˻������ڶ�����Ȼ������ˮ��ץ�㣬��
����Ⱦ����ร���СϪһ·��������ȥ��
LONG_DESCRIPTION
	);
	
        set( "underwater",1 );
	set_outside( "noden" );
	set( "exits", ([ 
		"east"  : ISLAND"9,8.island",
		"south" : ISLAND"8,9.island",
		]) );
	set( "original", ISLAND"8,8" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 8 );
	set( "y_coordinate", 8 );
        set( "objects" , ([
                  "fish #1" : IMON"s_fish.c",
                  "fish #2" : IMON"salmon.c"
                         ]) );     
        call_out( "flow_away",40 );
	reset();
	
}

void init()
{
     UNDERWATER -> apply_effect ( this_player(), 7, 1 );
}
void flow_away()
{
     int i;
     object *ob;
     
     ob = all_inventory( );
     i = sizeof( ob );
     
     while( --i>=0 )
     {  
        if( (int)ob[i] -> query ( "likefish" ) < 1 ) 
        {
        tell_object( ob[i],"\n\n �ۣ� �㱻ˮ�������������������� ࡺǣ� \n\n" );
        ob[i] -> move_player( ISLAND"9,9.island.c" ,"SNEAK") ;
        }
     }
}     