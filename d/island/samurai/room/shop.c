//#pragma save_binary

#include "farwind.h"
#include <money.h>

inherit SHOP;

void create()
{
	::create() ;
	set("light", 1) ;
	set_short( "The Farwind Shop", "商店" );
	set_long(
			"Welcome to the biggest and the only shop in Farwind. This shop\n"
        "is always full of adventuerers from everywhere. Because of this,\n"
		"the shop owner is very familar with various strange stuff from\n"
        "most adventurers. You can buy, sell, value, and list in the shop. If\n"
		"you have something that you don't know its real name, the shop\n"
        "owner would be gald to tell you its name. Just give him the item,\n"
		"and he'll tell you what you wish to know.\n",
			"欢迎来到远风镇最大也是唯一的商店，这家商店是冒险者最常光顾\n"
		"的商店之一，因为远风镇素有冒险者故乡之称，这里的老板对冒险者从\n"
		"各地带回来的各种稀奇古怪的东西都颇有研究，在商店里你除了可以买\n"
		"(buy)、卖(sell)、估价(value)、或只是参观(list)以外，老板还愿意\n"
		"「免费」为你鉴定你身上的东西，把你想要鉴定的物品拿给老板，他就\n"
		"会告诉你物品的正确名称。\n"
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
}

