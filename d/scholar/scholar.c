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
        "������С����",
        "�����е�������",
        "����������ѧ��",
        "С�н�������Ʒ����",
        "Ŭ���еĶ�Ʒ����",
        "���ϲ�¥��һƷ����",
        "�ճ�¯���¿ƽ�ʿ",
        "���µ������Ʒ̫ѧ��",
        "���Ƹ�ʫ�Ķ�Ʒ̫ѧ��",
        "��ī������һƷ̫ѧ��",
        "��ѧ�ḻ����ѧ����",
        "����ֱ�Ե���������",
        "һ��������������",
        "����֪���Ľ������",
        "ѧ��ר�����������",
        "�Ÿ߰˶���̽������",
        "ѧ���峵�İ�������",      
        "�������ڵ�״Ԫ����",
        "�������İ�������", 
        "ʵϰ��ʦ"              
});

string *c_titles_girl=({
        "��Ƥ��ŮС����",
        "�����е����Ů���",
        "����������Ůѧ��",
        "С�н�������ƷŮ����",
        "Ŭ���еĶ�ƷŮ����",
        "��Ҫ���õ�һƷŮ����",
        "�ճ�¯���¿�Ů��ʿ",
        "����ް�����ƷŮ̫ѧ��",
        "���Ƹ�ʫ�Ķ�ƷŮ̫ѧ��",
        "���������һƷŮ̫ѧ��",
        "��ı���˵���ѧŮ����",
        "һ�ʶ���ɽ������Ů����",
        "��˼Ȫӿ������Ů����",
        "�������˵Ľ��Ů����",
        "��Ϸ�˼�����Ů����",
        "������֪��̽��Ů����",
        "�ɲ�׿��İ���Ů����",
        "��ıԶ�ǵ�״ԪŮ����",
        "�ǹڹŽ�İ���Ů����",
        "ʵϰ��ʦ"
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
				"�����ϴ��Ķ���̫���ˣ��ò�������������\n");

		if( !(unit = obj->query("unit")) ) unit = "��";
		write( 
			"�������·�����һ" + unit + obj->query("short") + "��\n");
		return 1;
	}
	write( "���" + obj->query("short") + "��û����ʧ��\n");
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
//	"�Բ�����춹���Խ���������ʱֹͣ�Ա����Ჹ��������ֹͣ\n"
//	"������ͽ����ԭ�� !!\n");
//	return 1;
//
	race = (string)player->query("race");
	if( member_array(race, ({"orc", "lizardman", "centaur", "beholder", 
		"hawkman" }))!=-1 )
		return notify_fail("�Բ��𣬱����᲻�����ι�״�����塣\n");
	if( (int)player->query_perm_stat("int") < 5 )
		return notify_fail(
			"�Բ�������ǻ�̫���ˣ������ʸ�����������ᡣ\n");

	token = new( GUILD_TOKEN );
	if( token->move(player) != MOVE_OK )
		return notify_fail( 
			"�����ϴ��Ķ���̫���ˣ��ò�������������\n");
	write( @WELCOME
��ӭ�����������ᣬ����Ϊ����ͣ�����Լ�������Ϊ����Ϊ��������
֮ʿ��������������֮����ֻҪ�㲻�����۾��ѹ�֮�������������
���������ɳ��������̳ɵ����(jade mark) �Ǳ����͸�����ʳ�͵�
��������Ц�ɡ�
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
