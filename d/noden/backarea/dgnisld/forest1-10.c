#include "dgnisld.h"

inherit ROOM;

void create()
{
	::create();
	set( "outside" , "dgnisld" ) ;
	set_short( "forest",  "É­ÁÖ" );
	set_long(
	    "A forest. \n", 
	    "Ò»×ùÉ­ÁÖ¡£\n"
        ) ;
	
	set( "exits", ([
	   "southeast"   : DGNISLD"entrance",    ]) );
}
                    
