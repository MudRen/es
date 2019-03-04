//#pragma save_binary

// exchange.c
// A facility for changing money from one kind of coin to another.
// Written by Mobydick@TMI-2, 8-25-92
// For now the service is free, later we should probably attach a fee to it.

#include <money.h>
#include <move.h>
#include <mudlib.h>

#define SIGN "/obj/coinval_sign"

inherit COINVALUE ;

void create()
{
	object sign;

	seteuid(getuid());
	sign = clone_object(SIGN) ;
    sign->set_location(file_name(this_object())) ;
}

void init() {
	add_action ("change", "convert") ;
	add_action ("change", "change") ;
}

int help() ;

int change (string str)
{
	int number, i, j, k, chinese_mode;
	string oldtype, newtype ;
	int oldval, newval ;
	object ob ;

	if (!str) return help();
	if (sscanf(str, "%d %s to %s", number, oldtype, newtype)!=3)
		if (sscanf(str, "%s to %s", oldtype, newtype)==2)
			number = (int)this_player()->query("wealth/"+oldtype);
		else
			return help();
		
	oldval = coinvalue(oldtype);
	if( !oldval )
		return notify_fail( 
			"����Ǯ�������ﲢ��ͨ��....��\n");

	if( number < 0 )
		return notify_fail( 
			"��ֻ�ܹ��һ�������Ǯ�ҡ�\n");

	newval = coinvalue(newtype);
	if( !newval )
		return notify_fail( 
			"����һ�ʲ��Ǯ�ң�\n");

	if( this_player()->query("wealth/"+oldtype)<number )
		return notify_fail (
			"��û�������" + to_chinese( oldtype + " coin") + "��\n");

	i = number*oldval ;	/* Value of old coins, in cheapest coin */
	j = i/newval ;		/* Value of old coins, in new coins */
	k = (i-j*newval)/oldval ;   /* Change to be returned.  */
// If we have 0 new coins, then he is just getting back what he started with.
	if (j==0) {
		write( 
			"��Щ" + to_chinese( oldtype + " coin") + "��ֵ����һö" + to_chinese( newtype + " coin" ) + "��\n");
		return 1 ;
	}

// We need to check to see if he can carry the new number of coins.
	if( this_player()->debit( oldtype, number - k ) 
	&& this_player()->credit( newtype, j ) ) {
		write( "Ok.\n") ;
		tell_room( this_object(), 
			this_player()->query("c_name")+"��һЩ"+ to_chinese(oldtype+" coin")
			+"�һ���"+ to_chinese(newtype+" coin")+"��\n",
			this_player() );
		return 1 ;
	}
	return notify_fail( 
		"���������һЩ Bug ����֪ͨ��ʦ���\n");
}

int help() {
	write("Usage: " + query_verb() + " [num] [oldtype] to " +
		"[newtype]\n       " + query_verb() + " [oldtype] " +
		"to [newtype]\n");
	return 1 ;
}
