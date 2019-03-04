#include <mudlib.h>
#include "wang.h"
inherit ROOM;

void create()
{
 	::create();
        set_short("茅屋");
	set_long(@C_LONG
一走进这屋子，你闻到一股浓浓的药味，有点恶心。屋里有各种炼药用的
工具，什麽炼丹炉、药钵、药杵，应有尽有。墙上挂了一些奇奇怪怪的东东，
看起来像是晒过的药材。靠窗的一边有个桌子，桌上有些小小工具。
C_LONG
);
	set("light", 1);
	set("exits",([
		"north" : WANG"room2.c",
		"east" :  WANG"room4" // 书房
	]));

	set("objects", ([
		"boy"  : WANG_MOB"boy02.c",
	]) );

	set( "c_item_desc" , ([
		"table" : "桌上摆了些白瓷做的药钵，有层绿绿的垢，看起来使用过一段时间了。\n",
		"oven"  : "一个小巧的炼丹炉，炉火还蛮旺的，不晓得正在练啥丹药\n"
			  "说不定是太上老君的啥神丹妙药，你不禁有点好奇。\n",
	]));

	set( "search_desc", ([
		"oven" :    "@@search_oven",
		"炼丹炉" :  "@@search_oven",
		"炉" :      "@@search_oven",
	]));
	reset();
}

string search_oven()
{
		return "这炉子太烫了，你不敢打开来看。\n";
}


