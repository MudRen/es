#include "dgnisld.h"

inherit ROOM;

void create()
{
	::create();
	set( "light", 0 ) ;
	set_short( "small hole", "С��" ) ;
	set_long(
	    "Inside of the small hole, it's very dark and adust!\n"
	"The enterence is broken. There seems be a exit forward.\n",
	    "ʮ����խ�Ķ�����Ǭ��������������Ѿ����ˣ�ǰ����Զ\n"
	"�����г��ڡ�\n"
        ) ;
        
    	set( "objects", ([ "bats_king" : DGNISLD"monster/large_bat.c",
    	                   "small_bat" : DGNISLD"monster/bat.c",
    	                ])  );
    	reset();
	set( "exits", ([
	     "forward"    : DGNISLD"swamp5-5",	]) );
        set( "exit_msg", ([
             "forward"    : "$N climb up from the hole," 
                            "and the hole becomes broken.\n",   ])  );
}
