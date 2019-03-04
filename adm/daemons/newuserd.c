// File : /adm/daemons/newuserd.c
//
// This is the character creation module.
// This daemon is called from logind.c if a player enters and requests an
// unused name. It then sets up the new user as per the user's preferences.
// Begun by Buddha, sometime in September 1992.
//
// Mobydick added race, skills, and stats, 10-11-92.
// Extended by Buddha in December 1992 and January 1993
//
// Psyche@TMI-2 (93/01/27) added acceptance of first-letter input
//		when choosing gender and race.
//
// Streamlined and option addition added by Watcher@TMI (2/23/93)
//
// Watcher@TMI (4/15/93) added AUTO_WIZHOOD option.
//
// Languages added by Megadeath@TMI-2
//
// Mail registration added by Karathan (8/12/93)
//
// Added Chinese messages by Annihilator@Eastern.Stories (10/29/93)
//
// Elon (01/06/95) removed English message and add restriction to
//                 names with ( character...
 
#include <logs.h>
#include <uid.h>
#include <priv.h>
#include <mudlib.h>
#include <config.h>
#include <login.h>
#include <login_macros.h>
#include <language.h>
#include <daemons.h>
#include <guilds.h>
#include <stats.h>
#include <protects.h>
#include <races.h>
#include <ansi.h>

static void set_skills(object player);
static void set_stats(object player);
static void get_chinese_name(string rn, object user);

int chinese_mode;

string *races = ({
	"human",		"����",
	"elf",			"����",
	"dwarf",		"����",
	"orc",			"������",
	"gnome",		"�ؾ�",
	"halfling",		"������",
	"lizardman",	"������",
	"imp",			"����",
	"daemon",		"ħ��",
	"centaur",		"������",
	"drow",			"�ڰ�����",
	"beholder",		"��ħ",
	"vampire",		"��Ѫ��",
	"hawkman",		"����",
	"shapeshifter",	"���γ�"
});

void create()
{
	seteuid(ROOT_UID);
}

void create_new_user(object user, string pass)
{
	if (geteuid(previous_object()) != ROOT_UID) return;
	user->set_creating_phase(1);

    cat("/adm/news/nplayer_intro");

//  If EMAIL_REGISTRATION is defined in /include/login.h then check to see if
//  this is a registered name with a predefined password.
#ifdef EMAIL_REGISTRATION
	if( pass && stringp(pass) && pass != "") {
		write("Please enter the password sent to you with your\n" +
			 "registration acceptance: ");
		input_to("get_pass", 3, pass, user, 0);
		return;
	}
#endif  /* EMAIL_REGISTRATION */

	write("������������������(�� [enter] ��ʾͬӢ������): ");
	input_to("get_chinese_name",0, user);
	return;
}

/* comment out by Elon 01/06/95, cuz we don't need 'em anymore..
// Check if the new user want Chinese display. By Annihilator.
static void test_chinese(string reply, object user)
{
	if( !reply || reply=="" || reply[0]=='n' || reply[0]=='N' )
		chinese_mode = 0;
	else if( reply[0]=='y' || reply[0]=='Y' )
		chinese_mode = 1;
	else {
		write("Can you read Chinese like this: ��Ҫ��ʾ����ѶϢ��(y/n)? [n] ");
		input_to("test_chinese", 0, user);
		return;
	}

	if( chinese_mode ) {
		write("������������������(�� [enter] ��ʾͬӢ������): ");
		input_to("get_chinese_name", 0, user);
		return;
	}

	// Assume Chinese name is the same with English name.
	get_chinese_name( (string)user->NAME, user);
}
*/

static void get_chinese_name(string rn, object user)
{
	string tmp1, tmp2;
	if( !rn || rn == "" )  rn = capitalize((string)user->NAME);
	if( member_array(rn, PROTECT_C_NAME) != -1 ) {
		write( "�Բ�����Ϊĳ��ԭ���㲻��ʹ�������֣���������һ���ɡ�\n");
		write("������������������(�� [enter] ��ʾͬӢ������): ");
		input_to("get_chinese_name", 0, user);
		return;
	}
	if( sscanf(rn,"%s(%s",tmp1,tmp2)==2) {
		write("�Բ��������в��ܺ�������.��\n");
		write("����������һ��: ");
		input_to("get_chinese_name", 0, user);
		return;
	}
	if( strlen( rn ) > 14 ) {
		write("�Բ��������������̫���ˣ���������߸�����������.��\n");
		write("������������������(�� [enter] ��ʾͬӢ������): ");
		input_to("get_chinese_name", 0, user);
		return;
	}

	// if Chinese name starts with a letter, capitalize it.
	if( rn[0]>='a' && rn[0]<='z' ) rn = capitalize(rn);
     
     rn = replace_string(rn,ESC,"");
     
	user->set("c_name", rn);

	write("���趨��������: ");
	input_to("new_pass", 3, user, 0);
}


static void new_pass(string pass, object user, int count)
{
	if (strlen(pass) < 5) {
		write("\n�ܱ�Ǹ����������Ҫ�����.��\n");
		if (count > 2) {
			write("\n���Ѿ���̫����ˣ��������������.��\n");
			user->remove_user();
			return;
		}
		write("���㻻һ������: ");
		input_to("new_pass", 3, user, count + 1);
		return;
	}
	write("\n��������һ�θոյ����룬��ȷ������: ");
	input_to("new_pass2", 3, pass, user, count);
}


static void new_pass2(string pass2, string pass, object user, int count)
{
	if (pass == pass2) {
		user->SET_PASS(crypt(pass2, 0));

		write( "\n\n������ѡ��������Ա�Ϊ����(male)��Ů��(female)������(neuter)��\n"
			"\n����������ѡ�� (m/f/n): ");
		input_to("new_gender", 2, user, 0);
		return;
	}
	write("\n�ף������������͸ոյĲ�һ��?��\n");
	if (count > 2) {
		write("\n��һ����̫���ˣ���Ϣһ��������.��\n");
		user->remove_user();
		return;
	}

	write("���������趨һ������: ");
	input_to("new_pass", 3, user, count + 1);
}

/* seem this section has no use.. comment out by Elon.
static void get_pass(string pass, string prev, object user, int count)
{
	if (crypt(pass, prev) != prev) {
		write("Sorry, that password is incorrect.\n");
		if (count > 2)
		  { write("\nYou have taken too many tries.\n");
			user->remove_user();
			return; }
		write("Please reenter your password: ");
		input_to("get_pass", 3, prev, user, count + 1);
		return; }
	user->SET_PASS(prev);
	write("\n\nYour gender can be male, female, neuter, or hermaphrodite." +
		  "\nPlease enter your gender: ");
	input_to("new_gender", 2, user, (object)user->BODY_OB, 0);
}
*/
void list_races()
{
	int i;
	string s;

	s = "�����ѡ�����¼��������е���һ��:\n";
	for(i=0; i*2<sizeof(races); i++) {
		s += sprintf( "    %20-s%s", 
			races[i*2+1] + "(" + races[i*2] + ")",
			(i%3==2? "\n": "" ));
	}
	if( (i%2) ) s += "\n";
	write(s);
}


static void view_race_list(string str, object user, object body, int count)
{
	list_races();
	write ("\n��ѡ����������(��Ӣ�ģ��� '? <������>' ����������˵��): ");
	input_to("new_race", user, body, count );
	return;
}

static void new_gender(string g, object user, int count)
{
	if (!g || member_array(g, ({"male", "female", "neuter", "m", "f", "n"})) == -1) {
		write( "\n�ܱ�Ǹ�������Ա�ֻ��������(male)��Ů��(female)������(neuter)��\n");
		if (count > 2) {
			write("\n��������Ա�������.��\n");
			user->remove_user();
			return;
		}
		write("�����������Ա� (m/f/n): ");
		input_to("new_gender", user, count + 1);
		return;
	}

// Psyche@TMI-2 (93/27/01): translates one-letter input to
//							corresponding full word

	switch(g) {
		case "m": g = "male";
				  break;
		case "f": g = "female";
				  break;
		case "n": g = "neuter";
				  break;
	}
	user->set("gender", g, READ_ONLY);
	list_races();
	write ("����������ѡ��(��Ӣ�ģ��� '? <������>' ����������˵��): ");
	input_to("new_race", user, 0);
	return ;
}

static void new_race(string r, object user, int count)
{
	string race;
	object body;

	if( !r || member_array(r, races)==-1 ) {
		if (count > 2) {
			write("\n��һ����̫���ˣ���������������ɡ�\n");
			user->remove_user();
			return;
		}
		if( sscanf(r, "? %s", race)==1 ) {
			if( file_size( "/doc/help/" + "c_" + race )>0 )
				cat( "/doc/help/" + "c_" + race );
			write( "\n[�� ENTER ������]");
			input_to( "view_race_list", user, count );
			return;
		}
		list_races();
		write ("��ѡ����������(��Ӣ��): ");
		input_to("new_race", user, count + 1);
		return;
	}
	user->set("body", "/std/user_ob/"+r);
	body = new( "/std/user_ob/"+r);
	if(!body) {
		write("���������޸�����������ĵ���, ���������.\n");
		user->remove_user();
		return;
	}
        body->set_temp("newuser",1);
	body->set_name( user->query("name"), user->query("c_name") );
	body->set("gender", user->query("gender") );
	body->set("class","adventurer");
	//body->query_title(body);
	body->set("max_sp","qyery_max_sp");
	body->set("race",r );
	body->set("natural_age", RACE_MASTER(r)->query_natural_age() );
//	body->set("chinese", chinese_mode );
	body->set("snoopable",1);
	body->set("max_ap",3000);
	user->SET_BODY_OB(body);
	write("���������� email address ( user@host �� \"$\" ��ʾû�� )");
	input_to("new_email", user, body, 0);
}


static void new_email(string e, object user, object body, int count)
{
	string id, host;

	if (e!="$" && (sscanf(e, "%s@%s", id, host) != 2 || id == "" || host == "") ) {
		write("�Բ������� user@host ��ʽ���룬�� \"$\"��\n");
		if (count > 2) {
			write("\n������벻������������������\n");
			user->remove_user();
			return;
		}
		write("�������������� email address: ");
		input_to("new_email", user, body, count + 1);
		return;
	}
	e = replace_string(e,ESC,"");
	user->SET_EMAIL(e);
	write("����������ʵ������(Ӣ��): ");
	input_to("get_real_name", user, body);
}


static void get_real_name(string rn, object user, object body)
{
	object guild_obj;

	if (!rn || rn == "")  rn = "???";
	rn = replace_string(rn,ESC,"");
	user->SET_RNAME(rn);

	// Ok, that's all we need to know from them... let's get them connected.
	// the stats could be rolled, etc, but that's not my job to code -- buddha
 
	seteuid(user->query("name"));
	export_uid(body);
	seteuid(getuid());
	user->connect();
	user->set_creating_phase(0);
 
//	cat(NPLAYER_NEWS);
    cat("/adm/news/nplayer_news");
//  If NEW_USER is defined in /include/logs.h then log the creation time.
#ifdef NEW_USER
	log_file(NEW_USER, capitalize((string)user->NAME) + " was created on " +
			 extract(ctime(time()), 4, 15) + " from " + query_ip_name() + ".\n");
#endif /* NEW_USER */
 
//  If AUTO_WIZHOOD is defined in /include/config.h then any newly created
//  users will automatically be granted wizard status, and given the PATH
//  given by the define. This would be handy on places like TMI where
//  wizard bits are freely given.
//ȡ��by cach
//#ifdef AUTO_WIZHOOD
//	user->set("wizard", 1);
//	body->set("PATH", AUTO_WIZHOOD);
//	write("\t[You have been granted automatic wizard status]\n");
//#endif /* AUTO_WIZHOOD */
 
	body->setup();

	guild_obj = new(NEW_PLAYER_GUILD_OBJ);
	guild_obj->move(body);

	set_stats(body);

	user->save_data();
	body->save_data();
//  If EMAIL_REGISTRATION is defined in /include/login.h then check to see if
//  this is a registered name that now can be removed from the file.
#ifdef EMAIL_REGISTRATION
	(void)BANISH_D->remove_mailreg_name(user->NAME);
#endif /* EMAIL_REGISTRATION */
}


int clean_up()
{
	destruct(this_object()); 
	return 1;
}


static void set_stats(object player)
{
//	mapping languages ;

//	languages = ([ (string)player->query("race") : 100, "common" : 100 ]);
//	player->set("languages", languages);

	player->set("class","adventurer");
	player->set_level(1);
	return ;
}

