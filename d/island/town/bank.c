#include "../island.h"

inherit "/std/bank";
inherit "/std/exchange";
inherit ROOM;

void create()
{
	exchange::create();
	room::create();
	set_short("宝来号");
	set_long( @C_LONG
这里是一家颇负盛名的钱庄，只见头上一片匾额『财源滚滚』，似乎
暗示著这店的老板是位精打细算的家伙。你可以在这儿开户，只要25枚金
币就能将钱存在钱庄中；要是你已经有户头了，也可以在这里存提款。钱
庄里除了存提款，也提供钱币的兑换服务，当然你在这儿可以兑换身上的
钱币。墙上还贴了一张字条(help_list)，可以看看！
C_LONG
	);
	set("item_desc",(["help_list":@LONG
⊙ 专门给不会用指令的看的 ⊙

   (1) 开帐户：
        □ 先确定你的确有二十五块金币（一定要金币唷！ 没有要先换）
        □ 再来就用 open account 来开户就可以了，简单吧....:P
        □ 还有那些散形的啊，提款卡掉了，只要再 open account 一次就可以了！
        
   (2) 存款和提款：
        □ 存款用 deposit 这个字，格式是： deposit [数量] [钱币种类] 。
        □ 提款用 withdraw 就可以，格式是： withdraw [数量] [钱币种类] 。
        
   (3) 换币：
        □ 只要用 convert 我们就会帮你换钱啦！ 格式有两种 ：
           □ convert [数量] [钱币种类] to [新的钱币种类] 。
           □ convert [钱币种类] to [新的钱币种类] 。
        □ 秘密大公开：（英文不好的看这边）
           ES 钱币种类列表 ：
              □ 白金币 → platinum  (你也可以去看某种原子笔上的 mark)
              □ 金  币 → gold
              □ 银  币 → silver        
              □ 铜  币 → copper    (把钱换成铜币，看来比较多...:P)
LONG
        ]));
	set( "light", 1 );
	set( "exits", ([ 
		"south" : ITOWN"town04" ]) );
	set("objects",([
	        "taxman" : IMON"taxman" ]) );	
	reset();
}

void init()
{
	bank::init();
	exchange::init();
}
