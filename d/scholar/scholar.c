//#pragma save_binary

#include <move.h>
#include <daemons.h>
#include <conditions.h>
#include "scholar.h"

mapping stat_max = ([
	"str" : 17,
	"int" : 25,
	"dex" : 25,
	"con" : 18,
	"pie" : 17,
	"kar" : 18
]);

mapping skill_list = ([
	"longblade"    : ({ 250,  70 }),
	"shortblade"   : ({ 200,  85 }),
//	"dagger"       : ({ 300,  80 }),
	"parry"        : ({ 300,  70 }),
	"dodge"        : ({ 300,  60 }),
	"tactic"       : ({ 250,  60 }),
	"inner-force"  : ({ 150,  70 }),
//	"anatomlogy"   : ({ 200,  60 }),
	"polemic"      : ({ 100, 100 }),
	"yinyanglogy"  : ({ 150,  60 }),
//	"soothsaying"  : ({ 150,  60 }),
	"chutan"       : ({ 200,  70 }),
	"ethics"       : ({ 100, 100 }),
//	"thrusting"    : ({ 250,  50 }),
        "embattle"     : ({ 100,  95 }),
        "brood"        : ({ 150,  70 }),
        "palaeography" : ({  50,  80 }),
]);
/*
string *titles=({
        "Apprentice of Knowledge",
        "Exam Reject",
        "Impecunious Tutor",
        "Junior Student",
        "Student",
        "Senior Student",
        "Baccalaureate",
        "Junior Licentiate",
        "Licentiate",
        "Senior Licentiate",
        "Privat Docent",
        "Ferrum Fellow",
        "Argentum Fellow",
        "Aurum Fellow",
        "Wizadry Fellow",
        "Dean of Flos",
        "Council of Oculus",
        "Chanceller of Knowledge",
        "Lord of Erudition",
        "Apprentice Wizard",
});
*/
string *c_titles=({
        "笨笨的小书僮",
        "加油中的落第秀才",
        "不折腰的穷学究",
        "小有进步的三品举人",
        "努力中的二品举人",
        "更上层楼的一品举人",
        "刚出炉的新科进士",
        "办事得体的三品太学生",
        "饮酒赋诗的二品太学生",
        "舞墨长吟的一品太学生",
        "杂学丰富的游学书生",
        "仗义直言的铁笔书生",
        "一字万金的银笔书生",
        "天下知名的金笔书生",
        "学有专精的神笔书生",
        "才高八斗的探花书生",
        "学富五车的榜眼书生",      
        "满腹经纶的状元书生",
        "天机神算的百晓书生", 
        "实习巫师"              
});

string *c_titles_girl=({
        "顽皮的女小书僮",
        "加油中的落第女秀才",
        "不折腰的穷女学究",
        "小有进步的三品女举人",
        "努力中的二品女举人",
        "好要更好的一品女举人",
        "刚出炉的新科女进士",
        "辨才无碍的三品女太学生",
        "饮酒赋诗的二品女太学生",
        "侠骨柔情的一品女太学生",
        "智谋超人的游学女书生",
        "一笔定江山的铁笔女书生",
        "文思泉涌的银笔女书生",
        "聪明好运的金笔女书生",
        "游戏人间的神笔女书生",
        "无所不知的探花女书生",
        "仙才卓茔的榜眼女书生",
        "深谋远虑的状元女书生",
        "智冠古今的百晓女书生",
        "实习巫师"
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
	if( (string)obj->query("class") != "scholar" ) return 0;
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
	if( !(obj= player->query("guild")) ) {
		obj = new( GUILD_TOKEN );
		if( obj->move(player) != MOVE_OK )
			return notify_fail( 
				"你身上带的东西太重了，拿不动本公会的信物。\n");

		if( !(unit = obj->query("unit")) ) unit = "个";
		write( 
			"公会重新发给你一" + unit + obj->query("short") + "。\n");
		return 1;
	}
	write( "你的" + obj->query("short") + "并没有遗失。\n");
	return 1;
}

void check_quest(object player)
{
  if ((int)player->query_quest_level("Tenshin's herb")==1)
    player->set("demand/grass",1);
  if ((int)player->query_quest_level("Ohio's_brother")==1)
    player->set("demand/wood",1);
  return;
}

// This function is called when a player want join the guild in /std/guild.c
// The guild check if the player is a wizard or didn't join any guild first
// and call this function to enroll player. You can put extra check here, and
// return 0 if failed.
int join_player(object player)
{
	object token;
	int level;
	string race;

// close guild for reconstructure at 94/11/8 by Ruby@Eastern.Stories
//	tell_object(this_player(),
//	"对不起，由於国库吃紧，皇上暂时停止对本公会补助，所以停止\n"
//	"招收门徒，请原谅 !!\n");
//	return 1;
//
	race = (string)player->query("race");
	if( member_array(race, ({"orc", "lizardman", "centaur", "beholder", 
		"hawkman" }))!=-1 )
		return notify_fail("对不起，本公会不收奇形怪状的种族。\n");
	if( (int)player->query_perm_stat("int") < 5 )
		return notify_fail(
			"对不起，你的智慧太低了，不够资格加入书生公会。\n");

	token = new( GUILD_TOKEN );
	if( token->move(player) != MOVE_OK )
		return notify_fail( 
			"你身上带的东西太重了，拿不动本公会的信物。\n");
	write( @WELCOME
欢迎加入书生公会，卞大夫为人随和，并不约束你的行为，因为特立独行
之士往往有其他过人之处，只要你不犯下欺君叛国之罪，卞大夫仍是以礼
相待，这块由城内名匠刻成的玉符(jade mark) 是卞大夫送给门下食客的
见面礼，请笑纳。
WELCOME
	);
	player->set("max_fp", "@@query_max_fp");   /* maybe need delete...*/
        player->set("max_sp", "@@query_max_sp");
        player->set("spell_points",(int)player->query("max_sp"));
        HEAL_SP->apply_effect(player);
        check_quest(player);
	return 1;
}

string query_title(object player)
{
        int level;

        level = player->query_level();
        if( level < 1 ) level = 1;
        if( level > 20 ) level = 20;
        if ((string)player->query("gender") != "female")
          return c_titles[level-1] + " " + player->query("c_name");
        else
          return c_titles_girl[level-1] + " " + player->query("c_name");
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

// the function decide the equip level when a scholar wear armor.
int equip_level(object armor)
{
	string material;
	
	material = armor->query("material");
	if( !material ) return 2;
	if( member_array(material, ALLOWED_MATERIAL) != -1 ) return 0;
	else if( member_array(material, SECOND_MATERIAL) != -1 ) return 1;
	else return 2;
}
