#include "dgnisld.h"

inherit ROOM;

void create()
{
	::create();
	set( "outside" , "dgnisld" ) ;
	set_short( "forest",  "ɭ��" );
	set_long(
	    "A forest. \n", 
	    "һ��ɭ�֡�\n"
        ) ;
	
	set( "exits", ([
	   "southeast"   : DGNISLD"entrance",    ]) );
}
                    
