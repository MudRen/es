// File: /d/noden/asterism/dungeon/sewer23.c

#include "../asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("halfling tower", "��ˮ�������");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		,@C_LONG_DESCRIPTION
����ǰ�˹���ɶ���������Ϊ������ˮ��ϵͳ�� ʯǽ�ϻ谵ҡҷ�ĵƹ� , 
Ϊ�����������ƾ����Щ���������ա���ʵ�Ļ�����ǽ, ������ߵ�ˮ��, 
�ټ���ÿ��ʮ��������һƬ������ʯ��(slate)����������,  ����������
��ʩ�Ĺ��ܾ��Բ�ֻ����ˮ���ѡ�
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
                "east" : DUNGEON"sewer33",
                "west" : DUNGEON"sewer13",                
                "north": DUNGEON"sewer22",
                "south": DUNGEON"sewer24",                
		]) );
	reset();
}

void init()
{
     add_action("look_slate","look") ;
}

int look_slate(string arg)
{
    string msg ;
    string compared = ({ "slate" , "ʯ��" , "������ʯ��"}) ;
    if( member_array(arg,compared,1) < 0 ) return 0 ;
    
    msg = CENTER->slate_desc(this_player(),this_object()) ;    
    tell_object(this_player(),msg) ;
    
    return 1 ;
}


