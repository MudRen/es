#include "dgnisld.h"

inherit ROOM;

void create()
{
	::create();
	set( "outside" , "dgnisld" ) ;
	set_short( "campo",  "��ԭ" );
	set_long(
	    "A campo. \n", 
	    "һƬ���Ĳ�ԭ��\n"
        ) ;
	
	set( "exits", ([
	   "south"   : DGNISLD"entrance"     ]) );
}
                    
