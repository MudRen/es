#include <takeda.h>

inherit DOORS;
inherit ROOM;

void create()
{
	::create();
	set_short("洞穴");
	set_long( @C_LONG_DESCRIPTION
这里是一个天然形成的岩洞，西边有一扇厚实的大铁门，从门缝中传来一
阵阵的寒气，砭人肌肤，据说里面是个地牢，真不知道那些犯人是怎麽熬下去
的，墙边有一张小桌子，一个汉子正坐在桌边喝酒驱寒。
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"west" : TROOM"jail1",
	        "southwest" : TROOM"down_hall"
	        ]));
	set( "objects", ([
	        "han" : TMONSTER"han" 
	        ]));
	create_door( "west", "east", ([
	        "keyword" : ({"door", "iron door"}),
		"name" : "iron door",
		"c_name" : "铁门",
		"desc" : "A strudy iron door",
		"c_desc" : "一扇厚实的大铁门",
		"status" : "locked",
		"lock" : "LiangShankey-1"
	]) );
	reset();
}
int clean_up() { return 0; }