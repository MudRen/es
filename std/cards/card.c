//#pragma save_binary

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

#define FILENAME "/std/cards/bank_card"

#include <move.h>
#include <mudlib.h>

inherit SECURE_OBJECT;
inherit COINVALUE;

string *types;

void assign (object fellow);

void create()
{
// These are null descriptions. They should never appear in practice because
// when the bank creates a card for the player it also sets new descriptions.
// See the assign function.
	seteuid(getuid());
	set_name( "bank card", "��" );
//	set_short( "һ�ſհ׵���" );
	set("short","@@query_short");
	set("long","@@query_long");
//	set_long(
//		"��ֻҪ�������ſ�Ƭ���Ϳ������������д�Ǯ����\n"
//	);
	add ("id", ({ "card" }) ) ;
	set ("weight", 5);
	set ("prevent_drop", 1);
}

// This causes the card to be cloned and assigned to the player when he
// logs in.
// See the man page on query_auto_load for more information.
mixed *query_auto_load()
{
//	return ({ FILENAME, query("owner") });
	return 1;
}

// This procedure sets the "wealth" property when the card is autoloaded.
// See the top comments for more information on how wealth is stored on
// the card.
/*
void init_arg (mixed *arg)
{
	set ("owner",arg) ;
	assign(find_player(query("owner")));
}
*/
// Probably not a good idea to let this be shadowed.
int query_no_shadow()
{
	return 1 ;
}

// The player can check his balance any time he wants as long as he has his
// card. If you want, you can move this procedure into the bank object; then
// he'll only be able to check his balance when he's at the bank.
void init()
{
	add_action ("balance", "balance") ;
}

// The assign procedure sets the short and long descriptions to include the
// player's name, and moves it into his inventory. You should never clone
// a bank card unless you immediately assign it to a player.
void assign(object owner)
{
//	seteuid(geteuid(owner));
//	set_short( (string)owner->query("c_name")+"����");
/*
	set_long(
		"����һ�����"+(string)owner->query("c_name")
		+"�����������������Զ��������д桢��\n"+
		"�� balance ָ����Բ鿴��Ŀǰ���ʻ���\n") ;
*/
	move(owner);
	set ("owner", owner->query("name"));
}
string query_short()
{
	if ( !environment() )
		return "�հ���" ;
	else
		return (environment()->query("c_name")+"����") ;
}
string query_long()
{
		if ( !environment() )
			return "����һ�ſհ׵�����ûʲ���� ...\n";
		else
		return sprintf(
		"����һ�����%s����������������ڸ��ص����д桢��\n"
		"�� balance ָ����Բ鿴��Ŀǰ���ʻ���\n",
		environment()->query("c_name")) ;
}
// Only the player has the right to move his bank card, ie drop it and pick
// it up. This improves security on it tremendously.
/*
int move(mixed dest)
{
	string str;

	sscanf (query("short"), "%s����",str) ;
	if ((string)this_player()->query("c_name")==str) {
		return ::move(dest) ;
	} else {
		if (str && dest == present( str, environment( this_player()) ) ) {
			return ::move(dest) ;
		}
	}
	return MOVE_NOT_ALLOWED;
}
*/
// Set_val sets the number of coins of type str on the player's card.
int set_val (string str, int amount)
{
	find_player(query("owner"))->set("bank_balance/"+str,amount) ;
	return 1 ;
}
// Add_val increases the number of coins of type str on the player's card.
int add_val (string str, int amount) {
	int i ;
	object owner ;

	owner = find_player(query("owner")) ;
	if (!owner) return 0 ;
	i=owner->query("bank_balance/"+str) ;
	owner->set("bank_balance/"+str,i+amount) ;
	return 1 ;
}
// Query_val returns the number of coins of type str on the player's card.

int query_val (string str) {
	return (int)find_player(query("owner"))->query("bank_balance/"+str) ; 
}

// Balance writes out the name of each kind of coin for which the player has
// positive amounts in the bank, and writes out the amount.

int balance() {

	int i, flag;
	mapping wealth ;
	string *types ;

	flag = 0;
	wealth = find_player(query("owner"))->query("bank_balance") ;
	if (!wealth || wealth==([])) {
		write ("�������������ëǮҲû�С�\n");
		return 1 ;
	}
	types = keys(wealth) ;
	for (i=0;i<sizeof(types);i++) {
	    if (wealth[types[i]]>0) {
		if (flag==0) 
		    write("��Ŀǰ��������Ĵ����:\n");
		write( sprintf("   %-12s : %d\n", to_chinese(types[i]+" coin"), wealth[types[i]]));
		flag=1 ;
	    }
	}
	if (flag==0)
		write ("�������������ëǮҲû�С�\n");
	return 1 ;
}
