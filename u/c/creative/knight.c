//#pragma save_binary

#include <move.h>
#include <daemons.h>
#include "knight.h"

mapping stat_max = ([
	"str" : 25,
	"int" : 15,
	"dex" : 20,
	"con" : 25,
	"pie" : 20,
	"kar" : 15
]);

mapping skill_list = ([
	"two-weapon" : ({ 180, 100 }),
	"longblade"  : ({ 100, 100 }),
	"shortblade" : ({ 150, 100 }),
	"thrusting"  : ({ 150, 100 }),
	"polearm"    : ({ 100, 100 }),
	"jousting"   : ({  80, 100 }),
	"blunt"      : ({ 250,  80 }),
	"dagger"     : ({ 250,  80 }),
	"axe"        : ({ 150,  90 }),
	"parry"      : ({ 180, 100 }),
	"block"      : ({ 150, 100 }),
	"tactic"     : ({ 250, 100 }),
	"defend"     : ({ 100, 100 }),
	"riding"     : ({ 100, 100 })
]);
/*
string *titles = ({
	"the Novice Squire",
	"the Regular Squire",
	"the Noble Squire",
	"the Spare Fighter",
	"the Volunteer Fighter",
	"the Regular Fighter",
	"the Elite Fighter",
	"the Novice Swoarman",
	"the Regular Swordman",
	"the Elite Swordman",
	"the High Swordman",
	"the Novice Knight",
	"the Regular Knight",
	"the Frontier Knight",
	"the Elite Knight",
	"the Royal Knight",
	"the Master Knight",
	"the Grand Knight",
	"the Knight Marshal",
	"the Apprentice Wizard"
});
*/
string *c_titles = ({
	"��ϰ�±� ",
	"�����С�� ",
	"�����̴� ",
	"����սʿ ",
	"���¾�սʿ ",
	"�����սʿ ",
	"����սʿ ",
	"������ʿ ",
	"�������ʿ ",
	"����ʿ ",
	"�߼���ʿ ",
	"��ϰ��ʿ ",
	"�������ʿ ",
	"�ȷ���ʿ ",
	"������ʿ ",
	"�ʼ���ʿ ",
	"��ʿ�� ",
	"����ʿ�� ",
	"��ʿ���� ",
	"��ϰ��ʦ "
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
	if( (string)obj->query("class") != "knight" ) return 0;
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
				"�����ϴ��Ķ���̫���ˣ��ò�������������\n");
		if( !(unit = obj->query("unit")) ) unit = "��";
		write( 
			"�������·�����һ" + unit + obj->query("short") + "��\n");
		return 1;
	}
	write( "���" + obj->query("short") + "��û����ʧ��\n");
	return 1;
}

// This function is called when a player want join the guild in /std/guild.c
// The guild check if the player is a wizard or didn't join any guild first
// and call this function to enroll player. You can put extra check here, and
// return 0 if failed.
int join_player(object player)
{
	object token;
	string race;

	race = (string)player->query("race");
	if( member_array(race, ({"imp", "beholder", "vampire" }))!=-1 )
		return notify_fail( 
			"�Բ��𣬱����᲻����������ħ����Ѫ��\n");
	token = new( GUILD_TOKEN );
	if( token->move(player) != MOVE_OK )
		return notify_fail( 
			"�����ϴ��Ķ���̫���ˣ��ò�������������\n");

	write( @WELCOME
��ӭ������ʿ���ᣬ��Ϊһ�����������������������ʿ�������������
ӵ��һ��ֻ����ʿ����ӵ�еĻƽ��䵶(sabre) ��ϣ��������ϧ����䵶
��������������塣
WELCOME
	);
	return 1;
}
/*
string query_title(object player)
{
	string kni, str;
	int level;
	
	level = player->query_level();
	if( level < 1 ) level = 1;
	if( level > 20 ) level = 20;
	str = player->query("cap_name") + " " + titles[level-1];
	if( kni = player->query("knighthood") )
		str = capitalize(kni) + " of Noden Kingdom " + str;
	return str;
}
*/
string query_c_title(object player)
{
	int level;
	string kni, str;
	
	level = player->query_level();
	if( level < 1 ) level = 1;
	if( level > 20 ) level = 20;
	str = c_titles[level-1] + player->query("c_name");
	if( kni = player->query("knighthood") )
		str += " " + to_chinese(kni);
	return str;
}
string query_title(object player)
{
	return query_c_title(player);
}
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
