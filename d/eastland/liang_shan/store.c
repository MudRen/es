//#pragma save_binary

#include "takeda.h"
#include <money.h>

inherit SHOP;

void create()
{
	::create() ;
	set("light", 1) ;
	set_short( "商店" );
	set_long(
		"这是梁山泊最大，也是唯一的一家商店，是恶名昭彰的时迁出资的\n"
		"，因为他开设的主要目的是销售自己偷窃所得，为了吸引顾客，这里的\n"
		"商品价格反而特别公道，也正因为如此，梁山泊的强盗们乐於将出外抢\n"
		"劫的所得在此寄卖，东方大陆跑单帮的客人也常来这里搜购便宜的商品\n"
		"。\n"
	);
	
	set( "exits", ([ "west" : TROOM"path2" ]) );
	storeroom()->set( "objects", ([
		"lamp" : "/obj/lamp",
		"bandage" : "/obj/bandage",
		"map" : "/d/noden/farwind/items/pocket_map"
	]) );

	set( "objects", ([
		"trashcan" : "/obj/trashcan",
		"owner" : "/d/noden/farwind/monster/shopowner",
		"shi" : TMONSTER"shi",
	]) );
	reset();
}

int clean_up() { return 0; }