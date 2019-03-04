//#pragma save_binary

#include <mudlib.h>
#include "knight.h"

inherit GUILD_OB;
inherit WEAPON;

void create()
{
	seteuid( getuid() );
	guild_ob::create();
	set_class_name("knight");
#include <compress_obj.h>
	set_name("sabre", "�嵶");
	set_short("�ƽ��嵶");
	set_long( @LONG
����һ�����ŵ����ʿ�ų�Ա�Ļƽ��嵶������嵶Ҳ��������õ�������
������������ʿ��������������������� help sabre �õ��й�����嵶�Ľ�
һ��˵����
LONG
	);

	set( "unit", "��" );
	set( "weapon_class", "@@query_weapon_class" );
	set( "type", "longblade" );
	set( "min_damage", "@@query_min_damage" );
	set( "max_damage", "@@query_max_damage" );
	set( "wield_func", "wield_sabre" );
	set( "weight", 60 );
	set( "extra_look", "$N����һ��������ʿ�ľ�����\n");
}

void init()
{
	// Apply guild_ob checks
	guild_ob::init();

	add_action("help", "help");
	add_action("info", "info");
	add_action("do_knights", "knights");
	add_action("do_chat", "knight");
}

int query_weapon_class() { return 10; }
int query_min_damage() { return 5; }
int query_max_damage() { return 10; }

void wield_sabre()
{
	write("�㽫�䵶�ӵ����г��������ŵ�����������ķ�������һ������\n");
    tell_room( environment(this_player()),
		this_player()->query("c_name")+"����ƽ��䵶������һ��Ư���ľ���\n",
		({ this_player()}) );
}

int do_knights()
{
	return guild_ob::list_guild_members();
}

// The guild channel
int do_chat(string arg)
{
	if( !arg )
		return notify_fail( 
			"�����������ʿ˵ʲ�᣿\n");

	return guild_ob::guild_line(arg);
}

int info(string arg)
{
	switch(arg) {
		case "history": cat( GUILD_DATA"c_kni_history" );
			break;
		case "commands": cat( GUILD_DATA"c_kni_commands" );
			break;
		case "topics":
		default: 
			cat ( GUILD_DATA"c_topics");
			break;
	}
	return 1;
}

int help(string arg)
{
	if( !arg || arg!="sabre" ) return 0;
	cat( GUILD_DATA"c_sabre");
	return 1;
}
