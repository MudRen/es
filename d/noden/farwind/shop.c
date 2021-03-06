//#pragma save_binary

#include "farwind.h"
#include <money.h>

inherit SHOP;

void create()
{
	::create() ;
	set("light", 1) ;
	set_short("商店");
	set_long(@C_LONG
欢迎来到远风镇最大也是唯一的商店，这家商店是冒险者最常光顾
的商店之一，因为远风镇素有冒险者故乡之称，这里的老板对冒险者从
各地带回来的各种稀奇古怪的东西都颇有研究，在商店里除了可以买
(buy)、卖(sell)、估价(value)、或只是参观(list)以外，老板还愿意
「免费」为你鉴定你身上的东西，把你想要鉴定的物品拿给老板，他就
会告诉你物品的正确名称。
C_LONG
	);
	
	set( "exits", ([ "west" : FARWIND"smain" ]) );
	storeroom()->set( "objects", ([
		"lamp" : "/obj/lamp",
		"bandage" : "/obj/bandage",
		"map" : "/d/noden/farwind/items/pocket_map"
	]) );

	set( "objects", ([
		"trashcan" : "/obj/trashcan",
		"shop owner" : FARWIND"monster/shopowner",
		"traveller" : FARWIND"monster/traveller"
	]) );
	reset();
	replace_program(SHOP);
}
