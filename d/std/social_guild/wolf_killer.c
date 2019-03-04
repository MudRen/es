// This is a social guild object ( not guild token )
// Created by Kyoko@Eastern.Stories 4-7-94

#include <move.h>
#include <daemons.h>
#define SOCIAL_GUILD_TOKEN	"/d/std/social_guild_ob/cut_tails"

/*
 * TO DESIGN A SOCIAL GUILD:
 *    You must define the following functions in the guild object that
 * can be called in /std/social_guild.c or other place. These function should
 * do certain check to make sure its argument are correct.
 */

/************************** INTERFACE *****************************/
int is_guild_member(object obj);
/************************** INTERFACE *****************************/

void create()
{
	seteuid( getuid() );
}

string query_guild_room()
{
	return "/u/m/maverick/wolf_killer_club";
}

int check_guilds(object player, string name)
{
    mapping guilds;
    string *guild_name;
    int i;
    
    guilds = (mapping)player->query("social_guilds");
    if( !guilds || sizeof(guilds)==0 ) return 0;
    guild_name = keys(guilds);
    if( !guild_name || sizeof(guild_name)==0 ) return 0;
    for( i=0; i<sizeof(guild_name); i++ )
      if( guild_name[i] == name ) return 1;
    return 0;
}

// This function judge if a player is a member of this guild. Return 1
// means yes, and 0 for no.
int is_guild_member(object obj)
{
	if( !living(obj) || !obj->query("user") ) return 0;
	if( !check_guilds( obj, "KWA" ) return 0;
	return 1;
}

int check_token(object player)
{
	object obj;
	string unit;

	if( !is_guild_member( player ) ) return 0;
	if( !(obj = player->query("social_guild")) ) {
		obj = new( SOCIAL_GUILD_TOKEN );
		if( obj->move(player) != MOVE_OK )
			return notify_fail( can_read_chinese(player)?
				"�����ϴ��Ķ���̫���ˣ��ò�����Э������\n":
				"You are carrying a bit too more things to carry our token.\n"
		);
		if( !(unit = obj->query("unit")) ) unit = "��";
		write( can_read_chinese(player)?
			"Э�����·�����һ" + unit + obj->query("c_short") + "��\n":
			"Now you have a new " + obj->query("name") );
		return 1;
	}
	write( can_read_chinese(player)?
		"���" + obj->query("c_short") + "��û����ʧ��\n":
		"You already have " + obj->query("short") + ".\n" );
	return 1;
}
// This function is called when a player want join the social guild in 
// /std/social_guild.c. The social guild check if the player is a wizard 
// or didn't join any social guild first and call this function to enroll
// player. You can put extra check here, and return 0 if failed.
int join_player(object player)
{
	object token;
    int level;

    if( is_guild_member(player) )
      return notify_fail( can_read_chinese() ?
        "����������Ǿ��ֲ��Ļ�Ա��.\n" :
        "You are already WKA's member.\n"
      );
    if( check_guilds( this_player(), "CWA" )
      return notify_fail( can_read_chinese() ?
        "���ǲ���ӭɫ��Э��ĳ�Ա����!\n" :
        "We don't allow CWA's member join WKA.\n" 
      );
	token = new( SOCIAL_GUILD_TOKEN );
	if( token->move(player) != MOVE_OK )
		return notify_fail( can_read_chinese(player)?
			"�����ϴ��Ķ���̫���ˣ��ò�����Э������\n":
			"You are carrying a bit too more things to carry our token.\n"
		);
	write( can_read_chinese(player)?
	  "    ��ϲ��(��)��������ȷ�ľ��������(��)�ļ���������ҵ����罫��\n"
      "��һ����������Ѹ���β��С����������(��)���ϵ�������ϣ����(��)�ú�\n"
      "����ϧ����\n" :
      "Welcome!\n"
	);
	return 1;
}
