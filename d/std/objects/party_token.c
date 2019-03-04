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
	set_name("party_token","��������");
	add( "id", ({ "token" }) );
	set_short("��������");
	set_long(
	"���Ǵ��������ڶ���������������öӳ������ֵ�ָ����������ѽ�̸��\n"
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
    	return notify_fail("����Զ���˵ʲ�᣿\n");

    leader_name = (string)this_player()->query_temp("leader");
    if( !leader_name || !(leader=find_player(leader_name)) ) 
        return notify_fail("��Ķӳ������� !\n");
    usr = (mixed *)leader->query_temp("party_members");
    for( i=0; i<sizeof(usr); i++ )
    	message( "party_line", set_color(sprintf( 
        	"[���� "+capitalize(leader_name)+"] %s��%s\n",
            	this_player()->query("c_name"), arg),"HIG",usr[i]), usr[i] 
        );
    return 1;
}
