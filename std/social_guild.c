//#pragma save_binary

// Written by Kyoko@Eastern.Stories, 4-7-94

#include <daemons.h>
#include <stats.h>
#include <quest.h>
#include <mudlib.h>
#include <move.h>
#include <guilds.h>

inherit ROOM;

// The variable trainable_skills stores the skills which this guild can
// train you in.

string this_social_guild;

void set_social_guild(string social_class);

int do_help(string arg);

void set_social_guild(string social_guild)
{
	if( file_size(social_guild)>0 )
		this_social_guild = social_guild;
	else
		this_social_guild = SOCIAL_GUILD_MASTER(social_guild);
}

// Init adds the cost and train commands. You must call this if you
// add your own init functions. (i.e. you must call guild::init();
// in the init() of your guild.

void init()
{
	add_action("do_join", "join");
	add_action("do_verify", "verify");
	add_action("do_help", "help");
}

int max_guild(object player)
{
    mapping guilds;
    guilds = (mapping)player->query("socail_guilds");
    if( !guilds || sizeof(guilds)==0 ) return 0;
    if( sizeof(guilds) >= MAX_SOCIAL_GUILDS ) return 1;
    return 0;
}

int do_join(string arg)
{
	object ob, token;
	int chinese_mode;

	if( arg ) return 0;

	chinese_mode = can_read_chinese();
	ob = this_player();
	if( this_social_guild->is_guild_member(ob) )
		return notify_fail( chinese_mode?
			"���Ѿ��Ǳ�Э��Ļ�Ա�ˣ�\n":
			"You are already a member of this social guild!\n");

	// Check if the player is a wizard or didn't join other guilds yet.
	if( wizardp(ob) || !max_guild(ob) )
      return (int)this_social_guild->join_player(ob);
	else 
	  return notify_fail( chinese_mode?
		"���Ѿ�������̫��Э���ˣ��������˳�һЩЭ�ᣡ\n":
		"You have joined too many social guilds already!\n"
	  );
}

int do_verify()
{
	notify_fail( can_read_chinese()?
		"�Բ����㲻�����Э��Ļ�Ա��\n":
		"Sorry, but you are not out social guild member.\n" );
	return (int)this_social_guild->check_token( this_player() );
}

int do_help(string arg)
{
	int chinese_mode;

	chinese_mode = can_read_chinese();
	switch(arg) {
		case "guild": if(chinese_mode) write( @C_USAGE_GUILD
�����������ʹ�����µ�ָ�ÿһ��ָ��и��꾡��˵��( ���� "help <ָ��>" ):

	join     - �������Э�ᡣ
	verify   - ȷ����֣���ȡ����ʧ��Э�����

C_USAGE_GUILD
			); else write( @USAGE_GUILD
You can use the following commands in the guild, type 'help <command>' for
more information:

	join     - Join the social guild.
	verify   - Verify your membership and get a new social guild token if it is lost.
    
USAGE_GUILD
			); break;
		case "join": write( @USAGE_JOIN
Syntax: join

    This command enrolls you as a member of the guild. Different guilds
may have different features and rules, type 'info' to get informations
about the guild.
USAGE_JOIN
			); break;
		default:
			return 0;
	}
	return 1;
}
