// File: /d/noden/asterism/tower1-6.c

#include "asterism.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	set_short("半身人高塔的第六层");
	set_long(
		@C_LONG_DESCRIPTION
这里是艾斯特律恩城中半身人高塔的最高层第六层.也是半身人族长席蓝洛斯十世
(Thilenros X)的住处,四周摆设了很多的奇花异卉(flowers),在平地是无法瞧见的.
C_LONG_DESCRIPTION
	);
       set("c_item_desc",([
           "flowers":"一些奇奇怪怪的奇花异卉,但是却都是寒带或高山植物.\n"
           ]) );    	
    	set( "exits", ([ 
		"down":ASTR"tower1-5",
		]) );
	create_door("down","up",([
             "name":"white door",
             "c_name":"白色的门",
             "keyword":({"white door","door",}),
             "c_desc":"白色的门",
             "status":"locked",
             "desc":"a white door",
             "lock":"ASTERISM_1",
                     ]) );
	reset();
}
