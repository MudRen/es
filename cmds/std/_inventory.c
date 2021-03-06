//#pragma save_binary

/*
// This file is part of the TMI Distribution Mudlib.
// Please include this header if you use this code.
// Slick Ace, 01/02/91
// Help added by Brian (1/28/92)
// Rewritten by Buddha to show equipped items properly (2/3/92)
// Changed by Mobydick@TMI-2 (9/16/92) to capitalize short descriptions
// and to handle the new equipping system.
// Replaced the hardcoded weight limit with included #defines. Moby, 4-26-93
*/

// Modified by Annihilator to fit mounted animals.

#include <move.h>
#include <player.h>
#include <mudlib.h>

#define SHORT_DESCRIPTION "short"

inherit DAEMON ;

int filter_invis(object ob, object carrier)
{
	return visible(ob,carrier);
}
int cmd_inventory(string arg)
{
	object *items, me, ob;
	int coin, i, x, count;
	string result, tmp, *names, unit;
	mapping inv;

	count = 0;
	if( arg && wizardp(this_player()) ) {
		me = find_living(arg);
		if( !me ) return notify_fail("没有这个人....。\n");
	} else me = this_player();

	coin = me->coins_carried();
	items = filter_array(all_inventory(me), "filter_invis", this_object(), me);
	for (i = 0; i < sizeof(items); i++)
		if(items[i]->query(SHORT_DESCRIPTION))
			count++;
	result = count? ("你现在总共带著 "+count+" 样物品" + (coin?("，与 "+coin+" 枚钱币: \n"):": \n"))
			 : ("你现在身上没有任何东西"+(coin?"，但是有 "+coin+" 枚钱币。\n":"。\n"));

	result += sprintf("(总重量 %d.%d 公斤, 上限 %d.%d 公斤)\n",
		(int)me->query("load")/10,
		(int)me->query("load")%10,
		(int)me->query("max_load")/10,
		(int)me->query("max_load")%10);

	ob = me->query_temp("mounting");
	if( ob ) result += 
		"你现在正骑在一" + ob->query("unit") + ob->query("c_name") + "上，有 * 记号的物品\n"
		"表示正驮在它身上。\n";

// Always use compact mode. Compact mode is more convenient for players.
// It also costs fewer eval cost when the user carry many objs of the same.
//                            Modified by Iris 2/24/96
//	if( this_player()->getenv("compact") ) {
		inv = unique_mapping(items, "query", "short");
		names = keys(inv);
		for (x=sizeof(names)-1; x > -1; x--) {
			if(tmp=(string)inv[names[x]][0]->query(SHORT_DESCRIPTION)) {
		tmp += " ("+inv[names[x]][0]->query("name")+")";
		if( inv[names[x]][0]->query("wielded")) tmp += " (武器)";
		if( inv[names[x]][0]->query("equipped")) tmp += " (护甲)";
		if( inv[names[x]][0]->query("invisible")) tmp += " (隐形)";
		if( inv[names[x]][0]->query("mounted")) tmp += " (座骑)";
		if( inv[names[x]][0]->query("secure")) tmp+= " [标记设定]";
				if( sizeof(inv[names[x]]) > 1 ) {
					if( !unit= inv[names[x]][0]->query("unit") ) unit = "个";
					tmp = chinese_number(sizeof(inv[names[x]])) + unit + tmp;
				}
				if( inv[names[x]][0]->query("on_mounted")) result += "* " + tmp + ".\n";
				else result += "  " + tmp + ".\n";
			}
		}
//	}
/*	else for (x=0; x < sizeof(items); x++) {
		if(tmp=(string)items[x]->query(SHORT_DESCRIPTION)) {
		tmp += " ("+items[x]->query("name")+")";
		if(items[x]->query("wielded")) tmp += " (武器)";
		if(items[x]->query("equipped")) tmp += " (护甲)";
		if(items[x]->query("invisible")) tmp += " (隐形)";
		if(items[x]->query("mounted")) tmp += " (座骑)";
		if(items[x]->query("secure")) tmp += " [标记设定]";
		if(items[x]->query("on_mounted")) result += "* " + tmp + ".\n";
			else result += "  " + tmp + ".\n" ;
		}
	}
*/
	write(result);
	return 1;
}

int help()
{
	write( @HELP
指令格式: inventory

	这个指令可以列出你现在身上所携带的物品。
HELP
	);
	return 1;
}
/* EOF */
