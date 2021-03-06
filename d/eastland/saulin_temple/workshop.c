#include "saulin_temple.h"

#include <money.h>

inherit "/std/shop";

void create()
{
	::create() ;
	set("light", 1) ;
	set_short( "惜物工房" );
	set_long( @C_LONG
你走进了一个工作坊，四周吵杂的各种响声乱成一片，几名僧人正制作著各
种不同的器具－铜灯、烛台，甚至兵器、禅杖。後面还有人在缝制僧衣，看来整
个少林寺的日常用品都是由这里制造的。一名老僧(old monk)站在众僧之中监督
著他们工作，他应该是这里的负责人。
C_LONG
);
    set( "item_desc",([ "monk" : @C_LONG
你仔细打量那位老僧，他突然回头对你点头笑笑，并向你合十道：

  阿弥陀佛! 施主可是来参观的吗？欢迎之至，本工房专门负责寺中一切器物
  的修理(fix) 、制造(make)，也接受施主们的工作委托。同时我们负责旧货
  的回收再利用，你可以在这里买(buy) 、卖(sell)物品。本工作坊一切营利
  所得完全用於济助贫苦，欢迎施主共襄盛举。
  
C_LONG
    ]));
// rating 1,5 mean 1/5 Because monk is no money!
    set("rating", ({ 1, 5 }));
	set( "exits", ([ 
	     "south" : SAULIN"kitchen2", 
	]) );
	::reset();
}
