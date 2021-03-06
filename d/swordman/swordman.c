//#pragma save_binary

#include <move.h>
#include <daemons.h>
#include "swordman.h"

mapping stat_max = ([
	"str" : 20,
	"int" : 18,
	"dex" : 25,
	"con" : 20,
	"pie" : 19,
	"kar" : 18
]);

mapping skill_list = ([
	"dodge"	     : ({ 200, 80 }),
	"sword_skills"   : ({ 150, 100}),
	"longblade"  : ({ 100, 95 }),
	"shortblade" : ({ 150, 80 }),
	"thrusting"  : ({ 150, 80 }),
	"polearm"    : ({ 100, 80 }),
	"blunt"      : ({ 250, 80 }),
	"dagger"     : ({ 250, 70 }),
	"axe"        : ({ 150, 70 }),
	"parry"      : ({ 180, 80 }),
	"defend"     : ({ 150, 80 }),
]);

string *c_titles = ({
	"屠龙剑侍 "
	"试剑锋 ",
	"扬青芒 ",
	"执剑舞 ",
	"敌不归 ",
	"七步剑斩蛟 ",
	"三尺剑断浪 ",
	"尝饮剑锋血 ",
	"惯夺剑下魂 ",
	"横剑一笑敌丧胆 ",
	"睥睨众生敌茫茫 ",
	"万剑影渺锋芒灭 ",
	"一剑飞仙斩龙王 ",
	"抱剑煞 ",
	"求剑痴 ",
	"好剑成迷 ",
	"因剑而狂 ",
	"号剑中圣 ",
	"称剑之王 ",
	"见习巫师 "
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
int equip_level(object armor);
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
	if( (string)obj->query("class") != "swordman" ) return 0;
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

	if( !is_guild_member( player ) ) return 0;
	if( !(obj= player->query("guild")) ) {
		obj = new( GUILD_TOKEN );
		if( obj->move(player) != MOVE_OK )
			return notify_fail( 
				"你身上带的东西太重了，拿不动本帮的信物。\n");
		if( !(unit = obj->query("unit")) ) unit = "个";
		write( 
			"帮里执事重新发给你一" + unit + obj->query("short") + "。\n");
		return 1;
	}
	write( "你的" + obj->query("short") + "并没有遗失。\n");
	return 1;
}

// This function is called when a player want join the guild in /std/guild.c
// The guild check if the player is a wizard or didn't join any guild first
// and call this function to enroll player. You can put extra check here, and
// return 0 if failed.
int join_player(object player)
{
	object token;
	string class1;

	class1 = (string)player->query("class");
	if( member_array(class1, ({"knight", "mage" }))==-1 )
		return notify_fail( 
			"对不起，本帮只欢迎对战斗和精神方面下过苦功的人。\n");
	if ( player->query_level() < 15 ) 
		return notify_fail("对不起 !! 你的等级还不够 !!\n");
	token = new( GUILD_TOKEN );
	if( token->move(player) != MOVE_OK )
		return notify_fail( 
			"你身上带的东西太重了，拿不动本帮的信物。\n");

	write( @WELCOME
欢迎加入屠龙帮，为了成为一个有能力斩蛟屠龙的强者，除了战斗与精神
的修炼外，这本屠龙剑谱(book)可以帮助你修炼剑法，希望你能勤加修习
磨练，使你的技艺日有进益。
WELCOME
	);
	return 1;
}

string query_c_title(object player)
{
	int level;
	string kni, str;
	
	level = player->query_level();
	if( level < 1 ) level = 1;
	if( level > 20 ) level = 20;
	str = c_titles[level-1] + player->query("c_name");
	return str;
}
/*
string query_title(object player)
{
	return query_c_title(player);
}
*/
string *query_titles()
{
	return c_titles;
}

string *query_c_titles()
{
	return c_titles;
}

// The funnction decide equip level when a knight wear armor
int equip_level(object armor)
{
	string material;
	
	material = armor->query("material");
	if( !material ) return 2;
	if( member_array(material, ALLOWED_MATERIAL) != -1 ) return 0;
	else if( member_array(material, SECOND_MATERIAL) != -1 ) return 1;
	else return 2;
}
