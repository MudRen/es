//#pragma save_binary

// bank.c
// A basic bank object. Players can open an account, receiving a bank card.
// The bank card is an autoloading object that keeps track of how much
// money they have deposited. At the bank, players can withdraw or deposit
// funds.
// The bank has a create function which sets the euid of the object. Any
// file than inherits this file needs to ::create() in its create function.
// Note that the bank does not store the account data internally. Instead,
// each player's account data is stored in his bank card. This makes lookup
// faster but it does mean the player has to keep his card safe.
// Created by Mobydick@TMI-2, 8-28-92

#include <move.h>
#include <mudlib.h>
#include <money.h>

inherit COINVALUE;

void init()
{
	add_action ("open_account", "open");
	add_action ("deposit", "deposit");
	add_action ("withdraw", "withdraw");
}

// Open_account lets the player open his bank account. It gives him a bank
// card which is where his account data is stored. The fee is set at 25
// gold pieces but you can change that very easily if you desire.

int open_account(string str)
{
	int i;
	object ob ;

	if (!str || str != "account")
		return notify_fail(
			"��Ҫ�����Ļ������� open account��\n");

	if( present("bank card", this_player())||
		present("credit card", this_player()) ) {
		write(
			"���Ѿ����ʻ��ˡ�\n" );
		return 1 ;
	}

	if(this_player()->query("bank_balance")) {
		write (
			"�ף�������㶪�� .... û��ϵ���������Ϸ�����һ���µ�����\n");
		if( member_group(geteuid(this_player()), "admin") )
			ob = clone_object(ADM_CREDIT_CARD_FILE);
		else
			ob = clone_object(BANK_CARD_FILE);
		ob->move(this_player()) ;
		return 1 ;
	}
	if( !this_player()->debit("gold", 25) ) {
		write( 
			"����Ҫ 25 ���Ҳ��ܿ�����\n");
		return 1 ;
	}
//	if( member_group((string)this_player()->query("name"), "admin") )
//		ob = clone_object(ADM_CREDIT_CARD_FILE);
//	else
		ob = clone_object(BANK_CARD_FILE);
//	ob->assign(this_player());
	ob->move(this_player());
	write ( 
		"����������������Լ����ʻ��ˣ�������������úñ��ܰɣ�\n");
	tell_room( this_object(), 
		this_player()->query("c_name")+"������������һ���ʺš�\n",
		this_player() );
	this_player()->set("bank_balance", ([ ]) ) ;
	return 1 ;
}

// Withdraw allows a player to withdraw money from his bank account. The
// player must have his card to permit this. The function checks his card
// to make sure he has enough money to make the withdrawal.
// The bank knows about conversion: if the player wants to withdraw 5 gold
// and has 0 gold and 50 silver in the bank, the bank withdraws his 50 silver
// and gives him the 5 gold. More comments on this below.

int withdraw (string str)
{
	int number, i;
	int oldval, newval, newnum ;
	string type, word, newtype ;
	object card, coins ;
	string *types ;

	if (!str || sscanf(str,"%d %s",number,type)!=2 )
		return notify_fail( 
			"ָ���ʽ: withdraw <����> <Ǯ������>\n");

	if (number<1)
		return notify_fail(
			"�����������������Ǯ�����Ӵ���ɵ�ˣ�\n");

	card = present("bank card", this_player());
	if( !card ) card = present("credit card", this_player());
	if( !card )
		return notify_fail( 
			"������û���� .... ���� open account ���������벹����\n");
			
//	if( (int)card->query_val(type)>=number ) {
	if( (int)this_player()->query("bank_balance/"+type) >= number ) {
		if (this_player()->credit(type, number)) {
			if (number==1) word = "coin" ; else word="coins" ;
			write( 
				"����ʻ���� "+ number+ " ��" + to_chinese(type + " coin") + "��\n");
			tell_room( this_object(), 
				this_player()->query("c_name")+"���������һЩ"+to_chinese(type+" coin")+"��\n",
				this_player() );
			this_player()->add("bank_balance/"+type,-number);
//			card -> add_val (type,-number) ;
			return 1 ;
		} else
			return notify_fail(
				"�������޷�Я����ЩǮ�ң���֪ͨ��ʦ����\n");
	}
	
	return notify_fail(
		"����ʻ���û�������" + to_chinese( type + " coin") + "��\n");
}

// Deposit allows a player to put his money in the bank.

int deposit(string str)
{
	int i, number;
	string type, word ;
	object card ;

	if (!str || sscanf(str,"%d %s",number,type)!=2 )
		return notify_fail(
			"ָ���ʽ: deposit <����> <ָ������>\n");

	if (number<1)
		return notify_fail(
			"�㲻�ܴ��롸��������Ǯ��������\n");

	i = this_player()->query("wealth/"+type) ;
	if (i<number)
		return notify_fail( 
			"������û�������" + to_chinese( type + " coin" ) + "��\n");

	card = present( "bank card", this_player() );
	if( !card ) card = present( "credit card",this_player() );
	if( !card )
		return notify_fail(
			"������ȿ���(open account)���������д�Ǯ��\n");

	if( !this_player()->debit( type, number ) ) {
		write(
			"��Ŀǰ���ϵ�Ǯ�����е����⣬��֪ͨ��ʦ����\n");
		return 1;
	}
	this_player()->add("bank_balance/"+type,number);
//	card->add_val(type,number) ;
	if (number==1) word="coin" ; else word="coins" ;
	write( 
		"�����Լ����ʻ����� "+number+" ��"+to_chinese(type+" coin")+"��\n");
	tell_room( this_object(), 
		this_player()->query("c_name")+"��һЩ"+to_chinese(type+" coin") +"�����Լ����ʻ���\n",
		this_player() );
	return 1 ;
}
