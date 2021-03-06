
#include <goomay.h>

inherit DOORS;
inherit ROOM;

void create()
{
	::create();
	set_short("地洞");
	set_long( @LONG_DESCRIPTION
你现在来到一个阴暗的地洞，空气似乎一点也不潮湿，还带著一丝丝热气，
一点也不像一般的地洞，黝黑的洞壁好像是被火焰烧灼过，幽幽地反射著你的
火把的微光。
LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"south" : Goomay"cellar2", 
		"up"    : Goomay"blacksmith" ]) );
        set( "objects", ([
                "rat1" : "/d/noden/farwind/monster/rat",
                "rat2" : "/d/noden/farwind/monster/rat",
        ]) );

	create_door( "south", "north", ([
		"keyword" : ({ "steel door", "door" }),
		"name" : "steel door",
		"c_name" : "钢门",
		"c_desc" : @C_DESC
这是一扇由精钢铸成的门，厚重结实的门上虽然布满了灰尘蛛丝，
但是当年精□的纯钢仍然在微弱的火光下倔强地泛出闪闪的辉光，门的
左上角镌著一个红色下凹的印记－一个火焰的记号，同时你也注意到，
印记下刻著一行大字：

	擅	启	此	门	者	死

C_DESC
,		"status" : "locked",
		"lock" : "FIRE_ELEMENT_KEY"
	]) );
	reset();
}
