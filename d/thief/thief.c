//#pragma save_binary

#include <move.h>
#include <daemons.h>
#include "thief.h"

mapping stat_max = ([
	"str" : 16,
	"int" : 20,
	"dex" : 27,
	"con" : 18,
	"pie" : 14,
	"kar" : 25
]);

mapping skill_list = ([
	"dagger"     : ({ 150,  80 }),
	"shortblade" : ({ 300,  60 }),
	"hide"       : ({ 150, 100 }),
	"sneak"      : ({ 150, 100 }),
	"steal"		 : ({  70, 100 }),
	"peep"		 : ({  70, 100 }),
	"backstab"   : ({ 200, 100 }),
	"dodge"		 : ({ 200,  100 }),
	"anatomlogy" : ({ 200,  50 }),
	"tactic"     : ({ 250,  60 }),
	"throw-dagger" : ({200,80}),
	"bandage"    : ({ 250,  50 }),
//	"artifice"	 : ({ 250,  80 }),
	"trick"		 : ({ 200,  100 }),
	"trading"    : ({  70,  80 }),
	"swimming"	 : ({  70, 100 }),
	"climbing"	 : ({  70, 100 }),
	"identify"   : ({  50, 100 }),
	"consider"	 : ({  50, 100 })
]);

string *c_titles = ({
	"�������µĻ�� ",
	"�ǻ���ͷ������ ",
	"���Ҷ��ֵ�С͵ ",
	"ǿ���� ",
	"��·ǿ�� ",
	"�о����ǿ�� ",
	"ǿ��ͷͷ ",
	"�½����� ",
	"����Ǳ���� ",
	"����ר�� ",
	"����ḻ�Ĺ��� ",
	"��ͷ�ϴ�ġ��� ",
	"��ͷ�ϴ� ",
	"���е��鱦ר�� ",
	"�������� ",
	"�ڰ���Ӫ�� ",
	"ΰ��Ľ�ͷ�ϴ� ",
	"��Ŵ�� ",
	"�����𾴵Ĵ��� ",
	"��ϰ��ʦ"
});
string *c_titles_girl = ({
	"�������µ���ü ",
	"�ǻ���ͷ��̫�� ",
	"��ͷ���� ",
	"���Ҷ��ֵ�С͵ ",
	"ǿ���� ",
	"��·Ůǿ�� ",
	"������ ",
	"ǿ�����ͷ ",
	"�½�Ů���� ",
	"����Ǳ���� ",
	"����Ůר�� ",
	"����ḻ��Ů���� ",
	"��ͷ�ϴ��Ů���� ",
	"��ͷŮ�ϴ� ",
	"�鱦ר�� ",
	"����Ů���� ",
	"ΰ��Ľ�ͷ��� ",
	"�籩Ů�� ",
	"����Ů���� ",
	"��ϰ��ʦ"
});
/*
 * TO DESIGN A GUILD:
 *    You must define the following functions in the guild object that
 * can be called in /std/guild.c or other place. These function should
 * do certain check to make sure its argument are correct.
 */

/************************** INTERFACE *****************************/
int is_guild_member(object obj);
int query_stat_max(string stat);
string *query_skill_list();
int query_skill_exp_cost(string sk_name, int sk_level);
int query_skill_max(string skill);
int query_skill_cost(string skill);
string *query_guild_master();
/************************** INTERFACE *****************************/

void create()
{
	seteuid( getuid() );
}

// This function judge if a player is a member of this guild. Return 1
// means yes, and 0 for no.
int is_guild_member(object obj)
{
	if( !living(obj) || !obj->query("user") ) return 0;
	if( (string)obj->query("class") != "thief" ) return 0;
	return 1;
}

string query_guild_room()
{
	return GUILD_LOCATION;
}

int query_stat_max(string stat)
{
	if( !stat || !stringp(stat) ) return 0;
	if( strlen(stat) > 3 ) stat = stat[0..2];
	if( undefinedp(stat_max[stat]) ) return 0;
	return stat_max[stat];
}

// The following founctions maintains the skill experience system of this
// guild. You MUST define them in the guild object. These functions are
// called in /std/guild.c to determinate if a player can raise his/her
// skills by training.
string *query_skill_list()
{
	return keys(skill_list);
}

int query_skill_exp_cost(string sk_name, int sk_level)
{
	if( undefinedp( skill_list[sk_name] ) ) return 0;
	if( sk_level < 0 || sk_level >= skill_list[sk_name][1] ) return 0;
	return (int)STATS_D->query_skill_exp(sk_level) * skill_list[sk_name][0] / 100;
}

int query_skill_cost(string skill)
{
	if( undefinedp( skill_list[skill] ) ) return 0;
	return (int)skill_list[skill][0];
}

int query_skill_max(string skill)
{
	if( undefinedp( skill_list[skill] ) ) return 0;
	return (int)skill_list[skill][1];
}

string *query_guild_master()
{
	return GUILD_MASTER;
}

int check_token(object player)
{
	object obj;
	string unit;

	if( (string)player->query("class") != "thief" )
		return 0;
	obj = new( GUILD_TOKEN );
	if( obj->move(player) != MOVE_OK )
		return notify_fail( 
			"�����ϴ��Ķ���̫���ˣ��ò�������������\n");

	if( !(unit = obj->query("unit")) ) unit = "��";
	write(
		"�������·�����һ" + unit + obj->query("short") + "��\n");

	return 1;
}

// This function is called when a player want join the guild in /std/guild.c
// The guild check if the player is a wizard or didn't join any guild first
// and call this function to enroll player. You can put extra check here, and
// return 0 if failed.
int join_player(object player)
{
	object token;

	token = new( GUILD_TOKEN );
	if( token->move(player) != MOVE_OK )
		return notify_fail( 
			"�����ϴ��Ķ���̫���ˣ��ò�������������\n");

	write( @WELCOME
��ӭ����С͵���ᣬ������ help dagger �鿴�������ṩ���һЩ��\��
����Ѷ��С͵����Ĵ�����ԶΪ���������ӭ���ܿɿ�����ⷰ顣
WELCOME
	);
	return 1;
}

string query_title(object player)
{
	int level;

	level = player->query_level();
	if( level < 1 ) level = 1;
	if( level > 20 ) level = 20;
	if ((string)player->query("gender") != "female")
        return c_titles[level-1] + player->query("c_name");
    else
        return c_titles_girl[level-1] + player->query("c_name");    
}

string query_c_title(object player)
{
	return query_title(player);
}
string *query_titles()
{
	return c_titles;
}

string *query_c_titles()
{
	return c_titles;
}
// The funnction decide equip level when a adventurer wear armor
int equip_level(object armor)
{
	string material;
	
	material = armor->query("material");
	if( !material ) return 2;
	if( member_array(material, ALLOWED_MATERIAL) != -1 ) return 0;
	else if( member_array(material, SECOND_MATERIAL) != -1 ) return 1;
	else return 2;
}
