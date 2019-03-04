// File: 7,2.island.c

#include <mudlib.h>
#include "island.h"
#define GATE_OBJ "/d/island/island_gate"

inherit ROOM;
string location;

string long=("������һƬ�������һ����У�����������ν�ġ���Ӣ�ͷף�������\n"+
       "������Ҫ����ϸ�۲�˴�����������ᷢ��������ĳ������Ĵ���������\n"+
       "��������վ��Խ�ã���Խ���������������̫���ˣ�����....������ƶ�\n"+
       "���������Σ������������ϸ�۲�һ�£�˵���������ջ�ࡣ�\n" );

void create()
{
        ::create();
        set_short("�һ���");
        set("long","@@query_gate");

        set_outside( "island" );
        set( "exits", ([ 
                "down"  : "/d/noden/6,6.noden",
                "west"  : ISLAND"6,2.island", 
                "north" : ISLAND"7,1.island", 
                "east"  : ISLAND"8,2.island",
                "south" : ISLAND"7,3.island",
                ]) );
        set( "original", ISLAND"7,2" );
        set( "virtual_server", ISLAND"virtual/island_server" );
        set( "x_coordinate", 7 );
        set( "y_coordinate", 2 );
        set( "no_monster" , 1 );
        reset();
}
string query_gate()
{     
        string describe;
        if (location == "virtual" )
        {
              describe = long ;
              return describe ;
        }
        else
        {
              describe = long +"�ţ� ���Ͼ��и���������Ĵ󶴣�\n" ;
              return describe ;
        }
        
}
varargs void set_location( string new_loc , string exit )
{
        location = new_loc ;
        if (location=="virtual" || !exit )
        {
          delete("exits");
          set( "exits" , ([
                 "west"  : ISLAND"6,2.island",
                 "north" : ISLAND"7,1.island",
                 "east"  : ISLAND"8,2.island",
                 "south" : ISLAND"7,3.island",
                 ]) );
          GATE_OBJ->move( "/d/island/chaos" );
          tell_room( find_object(ISLAND"7,2.island"),@LONG
          
�׹�һ����һ�ж��ָ�ԭ���ˡ�

LONG
              );
        }
        else
        {
         
          set("exits" , ([
                   "down"  : exit ,
                   "west"  : ISLAND"6,2.island",
                   "north" : ISLAND"7,1.island",
                   "east"  : ISLAND"8,2.island",
                   "south" : ISLAND"7,3.island"
                         ]) );
          GATE_OBJ->move( exit );
          tell_room( find_object(ISLAND"7,2.island"),@LONG
          
���еĵ����Ȼ�������⣬���������һ����Ѩ�ˣ�

LONG
             );
        }
        
 }       
      
  
