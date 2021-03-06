// File: /d/noden/asterism/city_garden.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("席蓝洛斯花园");
	set_long( 
		@C_LONG_DESCRIPTION
这里是艾斯特律恩(asterism)城的花园,由半身人族长席蓝洛斯一世
开始建立的,直到现在这花园的规模已经相当庞大了,但是由於这里的地
势太高,所以这里的花草都是属於寒带的植物.往北你将回到大道路,而往
南边走是一栋巨大的建筑物 ,隐隐约约的在南边你看到一座很高的塔.东
边是一栋造形特殊的房子.从这里看过去你只能知道那是培养植物的温室。
C_LONG_DESCRIPTION
	);

	set_outside( "asterism" );
	set( "light", 1 );
	set( "exits", ([ 
		"north":ASTR"city31",
		"south":ASTR"city_library",
		]) );
	reset();
#include "replace_room.h"
}
