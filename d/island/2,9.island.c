// File: 2,9.island.c

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
		"east"  : ISLAND"3,9.island",
		"north" : ISLAND"2,8.island",
		]) );
	set( "original", ISLAND"2,9" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 2 );
	set( "y_coordinate", 9 );
        call_out( "flow_away",40 );
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
     {
       if( (string) ob[i]->query("name")=="shark")
       {
         ob[i]-> move_player(ISLAND"1,8.island.c","SNEAK");
        } 
       if( (int)ob[i] -> query( "likefish" ) < 1 )
        {
        tell_object(ob[i],"\n\n �ۣ� ���һ��ͻ�������ĺ��������Ƶ������� \n\n" );
        ob[i] -> move_player( ISLAND"3,10.island.c" ,"SNEAK" ) ;
        }   
     }
}     