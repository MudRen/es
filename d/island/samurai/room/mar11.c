//#pragma save_binary

#include <mercury.h>
#include <money.h>

inherit SHOP;

void create()
{
	::create() ;
	set("light", 1) ;
	set_short( "The Small Shop", "小商店" );
	set_long(@AAA
这是一间小小不起眼的自助商店，仅仅提供著货物买卖的功能，如果
你想问一下物品的价格，那只能看你的经验来决定了，这里不提供额外的
服务．
AAA
	);
	
	set( "exits", ([ "west" : MR"mar08" ]) );
	storeroom()->set( "objects", ([
		"lamp" : "/obj/lamp",
		"bandage" : "/obj/bandage",
		"map" : "/d/noden/farwind/items/pocket_map"
	]) );

	set( "objects", ([
		"trashcan" : "/obj/trashcan"
	]) );
	reset();
}

