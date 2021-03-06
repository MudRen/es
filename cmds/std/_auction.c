//#pragma save_binary

// _auction.c
// Command to auction an item .
// Created by Ruby@Eastern_Story, 6-11-94

#include <mudlib.h>

inherit DAEMON;
inherit COINVALUE ;
#define STOREROOM "/d/noden/farwind/auc_room.c"

int help()
{
        write(@HELP_TEXT
Syntax	: auction on/off
	打开/关掉拍卖广播网
	: auction <something> for <price>
	拍卖身上的某一件物品。起价 price 枚银币。如果你定的起价太低，
	拍卖公司会替你定个好价格。
	: auction <price>
	出 <price> 枚银币抢标正在拍卖的拍卖品。

HELP_TEXT
);
        return 1;
}

object custom,buyer,auc_item;
int last_price,val;
int first = 1 ;
int auction_now = 0 ;

int check_auction()
{
	if (auction_now) {
//	if ( find_call_out("count_down") != -1 ) {
		write("对不起，正在拍卖物品中，请稍候 !!\n");
		return 0;
	}
	return 1;
}

int boardcast(string msg)
{
        object *usr;
        int i;

	usr = users();
        if( sizeof(usr) )
                for( i=sizeof(usr)-1; i >= 0; i-- ) {
			if (!usr[i]->query("seller_channel")) continue;
			usr[i]->quick_message(
				sprintf(set_color("[拍卖兔女郎] :","HIY",usr[i])+" %s \n",msg),usr[i]);
		}
        return 1;
}
int channel_on()
{
        this_player()->set("seller_channel",1);
        write(set_color("你的耳边传来一阵奇怪的声音：欢迎收听拍卖广播网 ..\n","HIY",this_player()));
        return 1;
}
int channel_off()
{
        this_player()->delete("seller_channel");
	write(set_color("你扭扭你的耳朵，关掉拍卖广播网的噪音 ..\n","HIY",this_player()));
        return 1;
}

void count_down(int timer, int price)
{
	if ( last_price > price ) { 
		price = last_price ;
		call_out("count_down",9,1,price);
		return ;
 	}

	if ( nullp(custom) ) {
		boardcast("哇 .. 卖方 Quit 了 .. 拍卖取消 ..");
		if ( !nullp(auc_item) )
			auc_item->delete("prevent_get");
		auction_now = 0;
		buyer = 0;
		return ;
	}

	if ( nullp(auc_item) ) {
                boardcast("哇 .. 拍卖品消失了 .. 拍卖取消 ..");
                auction_now = 0;
                buyer = 0;
                return ;
	}
	if ( timer<3 ) {
		boardcast(
//			  sprintf("%s标售的%s一件，第 %d 次喊价 %d 枚银币 !! 请出价 !!",
			  sprintf("%s一件，第 %d 次喊价 %d 枚银币 !! 请出价 !!",
//				  custom->query("c_name"),
				  auc_item->query("short"),
				  timer,price));

                call_out("count_down",8,timer+1,price);
		return ;
	}
	if ( buyer ) {
		if ((int)buyer->query("wealth/silver") > price ) {

			buyer->add("wealth/silver",-price);
//              boardcast(sprintf("%s一件 !! 以 %d 枚银币卖给%s，谢谢惠顾 !!",
                boardcast(sprintf("%s一件 !! 以 %d 枚银币卖出，谢谢惠顾 !!",
				  auc_item->query("short"),price,
//				  buyer->query("c_name")
				  ));
		if (custom) {				  
                	tell_object(custom,
			sprintf("你卖掉了你的%s，扣掉 50 %% 的拍卖差额，你得到了 %d 枚银币 !! \n",
				auc_item->query("c_name"),val + (price-val)/2));
                        custom->add("wealth/silver",val + ( price-val)/2);
		}
		tell_object(buyer,
			"一只戴著茹比快递公司帽子的陆行鸟飞奔过来，把一件东西丢在你面前，\n又「咻～～」的一声跑掉了。\n");
		tell_room(environment(buyer),
			sprintf("一只戴著某某快递公司帽子的陆行鸟飞奔过来，把一件东西丢给%s，\n然後又飞也似的跑了。\n",buyer->query("c_name")),buyer);
		
		environment(auc_item)->add("money",(price-val)/2);
		auc_item->move(environment(buyer));

		} else {
		tell_object(buyer,"一个轰雷似的声音在你的耳边响起：你想欺骗伟大的拍卖公司吗？给你一点教训 !!\n");
                environment(auc_item)->add("money",(int)buyer->query("wealth/silver")-1);
		buyer->set("wealth/silver",0);
                if (custom ) {
                	tell_object(custom,
			"一只戴著茹比快递公司帽子的陆行鸟飞奔过来，把一件东西丢在你面前，\n又「咻～～」的一声跑掉了。\n"
			"真倒霉，遇到一个没钱的笨骗子，东西还在但是拍卖失败了 !!\n");

                	tell_room(environment(custom),
			sprintf("一只戴著某某快递公司帽子的陆行鸟飞奔过来，把一件东西丢给%s，\n然後又飞也似的跑了。\n",custom->query("c_name")),custom);
                	auc_item->move(environment(custom));
		}
		
		}
		
	}
	else {
		boardcast(sprintf("%s才不过卖 %d 枚银币，居然没人买，真是太可怜了 !!",auc_item->query("short"),price));
                tell_object(custom,"哈哈 !! 你太贪心了吧，不值钱的东西也 ...\n"
                        "一只戴著茹比快递公司帽子的陆行鸟飞奔过来，把一件东西丢在你面前，\n又「咻～～」的一声跑掉了。\n");
                tell_room(environment(custom),
			sprintf("一只戴著某某快递公司帽子的陆行鸟飞奔过来，把一件东西丢给%s，\n然後又飞也似的跑了。\n",custom->query("c_name")),custom);
                auc_item->move(environment(custom));

	}
	auc_item->delete("prevent_get");
	auction_now = 0;
        first=1;
	buyer = 0;
	return ;
}

int cmd_auction(string str)
{
	string item,file;
	object ob1,room,*obs;
	int price1,bid_price,i;
	mixed *value ;

	if ( !room = find_object(STOREROOM) ) 
		room = new(STOREROOM);
	if (!str || !stringp (str)) return help();
	if (str == "on" ) return channel_on();

        if (str == "off" ) return channel_off();

        if (!this_player()->query("seller_channel"))
		return notify_fail("请先打开拍卖广播网。\n");

	if ((sscanf(str,"%s for %d",item,price1) != 2) && 
	    (sscanf(str,"%d",bid_price) != 1)) return help();

	if ( item ) {
	if ( !(ob1=present (item,this_player()))) 
		return notify_fail("想买空卖空吗？你根本没有这件东西 !!\n");

    if ( find_call_out("count_down") != -1 ) 
    	return notify_fail("对不起，正在拍卖物品中，请稍候 !!\n");

	if ( (ob1->query("prevent_drop")) || (ob1->query("no_sale")) ||
		(ob1->query("prevent_insert")) )
		return notify_fail("对不起 !! 这种东西不能拍卖 !!\n");
/*
	if ( obs = deep_inventory(ob1) ) {
		for ( i = sizeof(obs)-1 ; i >=0; i-- )
			if ( obs[i]->query("no_sale") )
				return notify_fail("这里面装了不能拍卖的东西 !!\n");
	}
*/		
        if ( price1 < 1 ) return notify_fail("钱太多吗？别闹了 ^oo^ \n");
        custom = this_player();
        value = ob1->query("value");
    	if ( !value || !intp(value[0]) ) {
			return notify_fail("对不起 !! 这种东西不能拍卖 !!\n");
	}
	val = value[0] * coinvalue( value[1] ) / coinvalue("silver");
	price1 = ( val > price1 ? val : price1 ) ;
	last_price = price1 ;
	
	auc_item = ob1;
	ob1->move(room);
	ob1->set("prevent_get",1);
	auction_now = 1;
                tell_object(custom,
			"一只戴著茹比快递公司帽子的陆行鸟飞奔过来，把你的拍卖品抢走，\n又「咻～～」的一声跑掉了。\n");
                tell_room(environment(custom),
			sprintf("一只戴著某某快递公司帽子的陆行鸟飞奔过来，抢走了%s的一件东西，\n然後又飞也似的跑了。\n",custom->query("c_name")),custom);

		boardcast(
//			sprintf("跳楼大拍卖 !! %s标售%s(%s)一件 !!\n起价 %d 枚银币 !! 有没有人要出价的啊？",
			sprintf("跳楼大拍卖 !! %s(%s)一件 !!\n起价 %d 枚银币 !! 有没有人要出价的啊？",
//			  custom->query("c_name"),
			  auc_item->query("short"),
			  auc_item->query("name"),
			  price1));

		call_out("count_down",9,1,price1);

	    return 1;
	}
	else if ( bid_price > 0 ) {

	if ( !auction_now )
		return notify_fail("你出价要买什麽？现在又没有拍卖。\n");
	if (this_player() == custom ) 
		return notify_fail("喂 ! 是你在拍卖耶，想哄抬价格吗？\n");
	if (this_player() == buyer )
		return notify_fail("你的价码已经是最高价了 !!\n");
	if ( (int)this_player()->query("wealth/silver") < bid_price )
		return notify_fail("你身上的银币不够 !!\n");
        if (first) {
	if ( bid_price <= last_price )
		return notify_fail("你出的价要高於底价喔 !!\n");
             first=0;
                   } else
	if ( bid_price < last_price+50 )
		return notify_fail("你出的价要高於现在的价格再加 50 枚银币喔 !!\n");
	buyer = this_player();
	if ( nullp(buyer) ) return 1;
	last_price = bid_price;
//	boardcast( sprintf("%s出价 %d 枚银币抢标%s !! 有没有人要加价的？",
	boardcast( sprintf("有人出价 %d 枚银币抢标%s !! 有没有人要加价的？",
//			   buyer->query("c_name"),
				bid_price,
			   	auc_item->query("short")));
	return 1;
	}
	else return help();
}


