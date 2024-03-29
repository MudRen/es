//#pragma save_binary

/*
// This file is part of the TMI distribution mudlib.
// Please include this header if you use the code here.
// Originally written by Brian Leet.
// Adapted by Sulam (12-13-91)
// Help added by Brian (1/28/92)  *smirk*
// Better messages added by Brian (2/5/92)
// Money functions and comments added by Mobydick@TMI-II  (8-24-92)
// Prevent_get added by Watcher@TMI (3/5/93)
*/

#include <mudlib.h>
#include <money.h>
#include <move.h>

inherit DAEMON;

#define SYNTAX	"Syntax: get [物品 | all] <from [容器]>\n"

int cmd_get( string str )
{
	object ob, *inv, ob2, *all;
	int res, i, number, is_money;
	string short, tmp, type, unit;
	string word;
	int ammount;

	if(!str || str == "")
		return notify_fail("要拿什麽？\n");

	this_player()-> block_attack( 2 );

	if(!this_player()->query("vision"))
		return notify_fail("要拿什麽？你什麽也看不见。\n");

	/* Check for form "get 30 gold coins"  */
	if( sscanf( str, "%d %s %s", ammount, type, tmp ) != 3 )
		/* Check for form "get 30 gold" */
		if( sscanf( str, "%d %s", ammount, type ) != 2 ) {
			/* Check for command "get all" */
			if( str == "all" ) {
				if (environment(this_player())) {
					inv = all_inventory( environment( this_player() ) );
					inv = filter_array(inv, "filter_short", this_object());
					all = filter_array(inv, "filter_get", this_object());
				}

				if(sizeof(inv) <= 1 || sizeof(all) == 1)
					return notify_fail(
					"这里什麽也没有，你想拿走什麽？\n");

				for( i = 0; i <sizeof( inv ); i++ ) {
					if ( living(inv[i]) ) continue;
					if( ( int ) inv[i]-> query( "money" ) == 1 ) {
						type = inv[i]-> query_type();
						number = inv[i]-> query_number();
					}

					if((int)inv[i]->query("prevent_get")) {
						write(
						sprintf("你不能拿走%s。\n",(string)inv[i]->query("short")));
						continue;
					}
					res = ( int ) inv[i]-> move( this_player() );
					if( res == MOVE_OK ) {
						if( number > 0 ) {
							if( number == 1 ) word = "coin"; else word = "coins";
							write(
								sprintf("你捡起 %d 枚%s。\n",number,to_chinese(type+" coin")));
							tell_room( environment(this_player()),
								sprintf("%s捡起一些%s。\n" ,this_player()->query("c_name"),to_chinese(type + " coin")),
								this_player() );
							number = 0;
						} else {
							// Auto load items on your mounted animal.
							if(this_player()->query_temp("mounting")) inv[i]->set("on_mounted",1);
							if( !(unit= inv[i]->query("unit")) ) unit = "个";
							short = inv[i]->query("short");
							if(!short)	short = "东西";
							write(
								sprintf("你捡起一%s%s。\n",unit,short));
							tell_room( environment(this_player()),
								sprintf("%s捡起一%s%s。\n" ,
							this_player()-> query("c_name"),unit ,inv[i]->query("short")),
								this_player() );
						}
					} else if( res==MOVE_TOO_HEAVY ) {
						write(
							sprintf("你拿不动%s，太重了。\n",inv[i]->query("short")));
					}
				}
				return 1;
			}
			/* Assume he's trying to pick up a single object. */
			ob = environment( this_player() );
			if (!ob)
				return notify_fail(
					"你不能在一片虚无中捡取任何东西。\n"
					);

			ob = present( str, ob );
			if( !ob ) {
				if( ( int ) environment( this_player() )-> id( str ) )
					return notify_fail(
						"这东西你不能拿走。\n"
						);
				return notify_fail(
					"这里没有这样东西....。\n"
					);
			}
			is_money = ob-> query( "money" );
			if( is_money == 1 ) {
				number = ob-> query_number();
				type = ob-> query_type();
			}

			if((int)ob->query("prevent_get")) {
				if( ob->query("prevent_get_c_msg") )
				  write((string)ob->query("prevent_get_c_msg"));
				else
				  write("这东西——不能拿！\n");
			  return 1;
			}
			if ( living(ob) )
				return notify_fail("看来对方不需要你背 !!\n");
			res = ( int ) ob->move( this_player() );
			if( res == MOVE_OK ) {
				if( is_money == 1 ) {
					if( number == 1 ) word = "coin"; else word = "coins";
					write(
						sprintf("你捡起 %d 枚%s。\n",number,to_chinese(type + " coin")));
					tell_room( environment(this_player()),
						sprintf("%s捡起一些%s。\n",this_player()->query("c_name"),to_chinese(type +" coin")),
						this_player() );
				} else {
					// Auto load items on your mounted animal.
					if(this_player()->query_temp("mounting")) ob->set("on_mounted",1);
					if( !(unit= ob->query("unit")) ) unit = "个";
					short = (string) ob->query("short");
					if(!short)	short = "东西";
					write(
						sprintf("你捡起一%s%s。\n",unit,short));
					tell_room( environment(this_player()),
						sprintf("%s捡起一%s%s。\n",this_player()->query("c_name"),unit,ob->query("short")),
						this_player() );
				}
				return 1;
			}
			if( res == MOVE_NOT_ALLOWED )
				notify_fail("这个东西你不能拿走。\n" );
			else if( res == MOVE_TOO_HEAVY )
				notify_fail( "....太重了，你搬不动。\n" );
			return 0;
		}
	/* If we get here, it means we tried to "get 20 gold coins" or "get 20 gold" */
	type = lower_case( type );
	tmp = type + " coins";
	if( ammount < 1 )
		return notify_fail(
			"拿负数个钱币？别异想天开了。\n");
	i = this_player()-> query( "wealth/" + type );
	if( i < 0 ) return 0;
	ob = present( tmp, environment( this_player() ) );
	if( !ob || ob-> query_number() <ammount )
		return notify_fail(
			"这里没有那麽多钱币....。\n");

	/* Split the pile of coins into two, the part taken and the part left behind.*/
	ob2 = clone_object( COINS );
	type = ob->query_type();
	number = ob->query_number();
	ob2-> set_type( type );
	ob2-> set_number( ammount );
	res = ( int ) ob2-> move( this_player() );
	if( res == MOVE_OK ) {
		if( number > ammount ) ob-> set_number( number - ammount );
		else ob->remove();
		if( ammount == 1 ) word = "coin"; else word = "coins";
		write(
			sprintf("你捡起 %d 枚%s。\n",ammount ,to_chinese(type + " coin")));
		tell_room( environment(this_player()),
			sprintf("%s捡起一些%s。\n",this_player()-> query( "c_name" ) ,to_chinese(type +" coin")),
			this_player() );
		return 1;
	}
	notify_fail(
		"你已经拿不动这麽多钱币了，存一些到银行里吧。\n");
	ob2-> remove();
	return 0;
}

protected int filter_short(object obj)
{
	return ( obj->query("name")!= 0 );
}

protected int filter_get(object obj)
{
	return !(obj->query("prevent_get"));
}

int
help() {
  write(@HELP
指令格式：get <物品名>
          get <物品名 form 容器名>
          get all

这条指令可以让你捡起地上或容器内的物品。
HELP
);
  return 1;
}
/* EOF */
