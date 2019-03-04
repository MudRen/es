// File: 5,9.island.c

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
	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"4,9.island", 
		"north" : ISLAND"5,8.island", 
		"east"  : ISLAND"6,9.island",
		"south" : ISLAND"5,10.island",
		]) );
	set( "original", ISLAND"5,9" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 5 );
	set( "y_coordinate", 9 );
        set( "objects" , ([
                  "fish #1" : IMON"salmon.c",
                  "fish #2" : IMON"s_fish.c",
                  "fish #3" : IMON"s_fish.c"
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
        ob[i] -> move_player( ISLAND"4,10.island.c" ,"SNEAK") ;
        }
     }
}     