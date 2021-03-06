
#include <goomay.h>

inherit DOORS;
inherit ROOM;

void create()
{
	::create();
	set_short("地洞");
	set_long( @LONG_DESCRIPTION
你现在正位於一条阴暗的通道中，这条通道布满了许\多煤渣和炭灰，
通道两旁则规律地排放著一方方的火炉和铁□，这里原来可能是一个铁工厂
，从地面上四处乱丢的工具看来，原来的主人似乎走的很匆忙，而且再也不
曾回来过。这里没有任何的透气孔，可是不知道从哪里来的热风一阵阵地吹
来，你感觉燠热难耐....
LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"north" : Goomay"cellar1" ,
                "south" : Goomay"cellar3" ,
                "east" : Goomay"cellar4" ,

	]) );

	create_door( "north", "south", ([
                "keyword" : ({ "steel door", "door" }),
                "name" : "steel door",
                "c_name" : "钢门",
                "c_desc" : @C_DESC
这是一扇由精钢铸成的门，厚重结实的门上虽然布满了灰尘蛛丝，
但是当年精□的纯钢仍然在微弱的火光下倔强地泛出闪闪的辉光。
C_DESC
,		"status" : "locked",
                "lock" : "FIRE_ELEMENT_KEY"
        ]) );

	reset();
}

