#include "../../story.h"

inherit "/std/bank";
inherit "/std/exchange";
inherit ROOM;

void create()
{
	exchange::create();
	room::create();
	set_short("钱庄");
	set_long( @LONG
这里是东方故事里所有钱庄的连锁店之一。自从在北山发现金矿之後，一时城
里的人都跟著富有起来，馀钱也就愈来愈多，再加上人民有储蓄的习惯，所以银行
的事业也就跟著蒸蒸日上。你可以在这里 存(deposit) 提(withdraw) 款，或者是
在这里用 25 枚金币开个户头 (open account) ，就可以将你的钱寄放在钱庄里。
另外在这里也提供兑换服务，你可以用(convert) 指令兑换身上的钱币，所有流通
的钱币种类都写在墙壁的一张布告 (sign) 上。
LONG
	);
	set( "light", 1 );
	set( "exits", ([ 
           "north" : SCITY"nw1" ]) );
	reset();
}
void init()
{
	bank::init();
	exchange::init();
}
