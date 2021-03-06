//#pragma save_binary

// party_token.c
// The guild token of the a party.
// Created by Kyoko Autinashi JUNE 5 '94.

#include <mudlib.h>

inherit OBJECT;

string party_name;

void create()
{
	seteuid( getuid() );
	set_name("party_token","队伍信物");
	add( "id", ({ "token" }) );
	set_short("队伍信物");
	set_long(
	"这是代表你所在队伍的信物，你可以利用队长的名字当指令和其他队友交谈。\n"
	);
	set("prevent_drop", 1);
	set("prevent_insert", 1);
}

void set_party_name(string name)
{
	party_name = name;
}

void init()
{
	add_action("do_chat", party_name);
}

int do_chat(string arg)
{
	string leader_name;
    object *usr, leader;
    int i;
        
    if( !arg ) 
    	return notify_fail("你想对队友说什麽？\n");

    leader_name = (string)this_player()->query_temp("leader");
    if( !leader_name || !(leader=find_player(leader_name)) ) 
        return notify_fail("你的队长不见了 !\n");
    usr = (mixed *)leader->query_temp("party_members");
    for( i=0; i<sizeof(usr); i++ )
    	message( "party_line", set_color(sprintf( 
        	"[队伍 "+capitalize(leader_name)+"] %s：%s\n",
            	this_player()->query("c_name"), arg),"HIG",usr[i]), usr[i] 
        );
    return 1;
}
