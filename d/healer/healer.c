////#pragma save_binary

#include <move.h>
#include <daemons.h>
#include "healer.h"

mapping stat_max = ([
	"str" : 15,
	"int" : 25,
	"dex" : 15,
	"con" : 20,
	"pie" : 25,
	"kar" : 20
]);

mapping skill_list = ([
	"blunt"       : ({ 400,  80 }),
	"dagger"      : ({ 300,  90 }),
	"diagnose"    : ({ 100, 100 }),
	"depoison"    : ({ 100, 100 }),
	"anatomlogy"  : ({ 100, 100 }),
//	"venomlogy"   : ({ 100, 100 }),
	"bandage"     : ({  50, 100 }),
	"herbs"       : ({ 100, 100 }),
	"acupuncture" : ({ 100, 100 }),
	"medical"     : ({ 100, 100 }),
	"clotting"    : ({ 100, 100 }),
	"first-aid"   : ({ 100, 100 }),
	"dodge"       : ({ 250,  60 }),
//	"white-magic" : ({ 150, 100 }),
	"operation"   : ({ 100, 100 }),
	"concentrate" : ({ 150, 100 })
]);

string *titles = ({
	"the Novice Watcher",
	"the Learning Watcher",
	"the Qualified Watcher",
	"the Outstanding Watcher",
	"the Apprentice of Herblist",
	"the Novice Herbalist",
	"the Qualified Herbalist",
	"the Experienced Herbalist",
	"the Novice Healer",
	"the Learning Healer",
	"the Qualified Healer",
	"the Experienced Healer",
	"the Novice Surgeon",
	"the Qualified Surgeon",
	"the Experienced Surgeon",
	"the Famous Surgeon",
	"the Master Surgeon",
	"the Luminary of Healers",
	"the Mortal Asclepius",
	"the Apprentice Wizard"
});

string *c_titles = ({
	"�ݰ������� ",
	"ѧϰ�еĿ����� ",
	"�ϸ�Ŀ����� ",
	"�������õĿ����� ",
	"ҩʦѧͽ ",
	"ʵϰҩʦ ",
	"�ϸ��ҩʦ ",
	"�о����ҩʦ ",
	"����é®����ҽ�� ",
	"ѧϰ�е���ҽ�� ",
	"�ϸ����ҽ�� ",
	"����ḻ����ҽ�� ",
	"����é®�Ĵ�� ",
	"�ϸ�Ĵ�� ",
	"�о���Ĵ�� ",
	"�����Ĵ�� ",
	"Ȩ���Ĵ�� ",
	"������ҽ ",
	"һ����ҽ ",
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

string query_guild_room()
{
	return GUILD_LOCATION;
}

// This function judge if a player is a member of this guild. Return 1
// means yes, and 0 for no.
int is_guild_member(object obj)
{
	if( !living(obj) || !obj->query("user") ) return 0;
	if( (string)obj->query("class") != "healer" ) return 0;
	return 1;
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
	obj = new( GUILD_TOKEN );
	if( obj->move(player) != MOVE_OK )
		return notify_fail( 
			"�����ϴ��Ķ���̫���ˣ��ò�������������\n"
	);
	if( !(unit = obj->query("unit")) ) unit = "��";
	write("���ᷢ����һ" + unit + "�µ�" + obj->query("short")+"��\n") ;
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
	if( member_array(race, ({"orc", "lizardman", "vampire","beholder" }))!=-1 )
		return notify_fail(
			"�Բ��𣬱����᲻�հ����ˡ������ˡ���Ѫ������ħ��\n"
			);
	if( (int)player->query("alignment") < -100 )
		//return notify_fail(
		//	"�����᲻��Ϊ���������ˣ�����ذɡ�\n"
		//	);
		write("������һƬ���ģ�Ů������˵��������������߽������������ˣ�\n");
		
	token = new( GUILD_TOKEN );
	if( token->move(player) != MOVE_OK )
		return notify_fail(
			"�����ϴ��Ķ���̫���ˣ��ò�������������\n"
		);
	write( 
		"��ӭ������ҽ�߹��ᣬ��һ����ҽ�߱���ר����о�ҽ�����ҩ����\n"
		"�����гԿ������׼������ҽ�ߵ������ǡ��˲����ҡ��Ҳ����ˡ���\n"
		"�����������ģ����������Ȼֵ���˶���Ǯ������ϣ������������\n"
		"�츣��Ⱥ��\n"
	);
	return 1;
}

// decide the title of guild members.
string query_title(object player)
{
	int level;

	level = player->query_level();
	if( level < 1 ) level = 1;
	if( level > 20 ) level = 20;
	return player->query("cap_name") + " " + titles[level-1];
}

string query_c_title(object player)
{
	int level;

	level = player->query_level();
	if( level < 1 ) level = 1;
	if( level > 20 ) level = 20;
	return c_titles[level-1] + player->query("c_name");
}

string *query_titles()
{
	return titles;
}

string *query_c_titles()
{
	return c_titles;
}

// The function decide equip level when a healer equip armor.
int equip_level(object armor)
{
	string material;
	
	material = armor->query("material");
	if( !material ) return 2;
	if( member_array(material, ALLOWED_MATERIAL) != -1 ) return 0;
	else if( member_array(material, SECOND_MATERIAL) != -1 ) return 1;
	else return 2;
}