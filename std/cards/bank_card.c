// A bank card. Keeps track of how much money the player has in the bank.
// Autoloading. Can't be moved except by the player. Thus, only the player
// can pick it up if he drops it, etc.
// The actual account data is stored on the player, not on the card.
// This is done so that if the card gets dested or some such, nothing
// is lost. Only the name of the owner is kept on the card proper.
// be careful to keep track of it... :)
// The property "wealth" is a mapping whose keys are the names of the coins
// and whose values are the number of each type the player has in the bank.
// Thus, if the owning player had 50 gold and 70 sludge coins in the bank,
// the wealth property would be set to ([ "gold" : 50, "sludge" : 70 ]).
// You can put any kind of coins into this mapping you like; there are no
// checks or restrictions on the keys.
// Created by Mobydick at TMI-2, 8-28-92.
// Total rewrite by Ruby@ES at 95' 6/26

#include <mudlib.h>

inherit OBJECT;

void create()
{
	seteuid(getuid());
	set("short","@@query_short");
	set("long","@@query_long");
#include <compress_obj.h>
	set_name( "bank card", "提款卡" );
	add("id", ({ "card" }) ) ;
	set ("weight", 5);
	set ("prevent_drop", 1);
}

int query_auto_load()
{
	return 1;
}

// The player can check his balance any time he wants as long as he has his
// card. If you want, you can move this procedure into the bank object; then
// he'll only be able to check his balance when he's at the bank.
void init()
{
	add_action ("balance", "balance") ;
}

string query_short()
{
	
	if ( environment() && userp(environment()) )
		return environment()->query("c_name")+"的提款卡" ;
	else
		return "空白的提款卡" ;
}
string query_long()
{
	if ( userp(environment()) )
		return ("这是一张提款卡，你可以用它在各地的银行存、提款。\n"
				"用 balance 指令可以查看你目前的帐户金额。\n") ;
	else
		return "这是一张没用的提款卡。\n";
}
// Balance writes out the name of each kind of coin for which the player has
// positive amounts in the bank, and writes out the amount.

int balance() {

	int i, flag;
	mapping wealth ;
	string *types ;

	flag = 0;
	wealth = this_player()->query("bank_balance") ;
	if (!wealth || wealth==([])) {
		write ("你现在银行里半毛钱也没有。\n");
		return 1 ;
	}
	types = keys(wealth) ;
	for (i=0;i<sizeof(types);i++) {
	    if (wealth[types[i]]>0) {
		if (flag==0) 
		    write("你目前在银行里的存款有:\n");
		write( sprintf("   %-12s : %d\n", to_chinese(types[i]+" coin"), wealth[types[i]]));
		flag=1 ;
	    }
	}
	if (flag==0)
		write ("你现在银行里半毛钱也没有。\n");
	return 1 ;
}
