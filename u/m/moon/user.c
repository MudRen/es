//#pragma save_binary

// File: /std/user.c
// The user body is from the TMI-2 lib. Part of the bodies project and
// implemented by Watcher@TMI-2 and Mobydick@TMI-2. The code contained
// in this object is heavily based on code found in the original user.c
//
// The relevant code headers follow:
// Original Authors: Sulam and Buddha @ The Mud Institute
// Many other people have added to this as well.
// This file has a long revision history dating back to the hideous
// mudlib.n and is now probably not at all the same.
// This file is part of the TMI distribution mudlib.
// Please keep this header with any code within.

// Users don't use this object as body directly. The actual bodies of
// different races are at /std/user_ob. By Annihilator Aug 17, 1994.
// This object is only inherited and provide common utilities.

#include <config.h>
#include <channels.h>
#include <login.h>
#include <commands.h>
#include <daemons.h>
#include <net/daemons.h>
#include <mudlib.h>
#include <flock.h>
#include <move.h>
#include <money.h>
#include <priv.h>
#include <uid.h>

// Some files are inherited by including user.h.
#include <user.h>
#include <player.h>
#include <logs.h>
#include <body.h>
#include <stats.h>
#include <guilds.h>
#include <conditions.h>

// This is the room where players go whe he/she dies
#define DEATH "/d/abyss/hell/monster/black_wuchang"

inherit LIVING;

int age;
static int hb_tick;

static int last_age_set;
static string *protect = ({ "catch_tell", "receive_message", "do_alias",
	"do_history", "do_nickname", "receive_snoop" });
string query_title(); 
static void complete_setup(string str);
static void die();
static int create_ghost();
//	int coins_carried();
int query_permission(string prop);
void init_setup();
void destroy_autoload_obj();
//	 int clean_up_attackers();

int receive_object(object ob)
{
	int weight ;
	string temp;
	// player can't obtain the object in /u/ or /open/ by Yueh
	if (!wizardp(this_object())){
//                if (geteuid(ob)==0) return 0;
		temp=explode(base_name(ob),"/")[0];
		if((temp== "u")||(temp=="open"))
			return 0;
	}
	weight = ob->query("weight") ;
	if ( weight + this_object()->query("load") >this_object()->query("max_load") )
		return 0;
	this_object()->add("load",weight);
	return 1;
}

//  Setup basic and command catch systems
void basic_commands()
{
	add_action("quit", "quit");
}

void init_commands()
{
	// updated by Kyoko, to differ cmds path between wizs and archwizs.	
	// cleaned up by Annihilator, removed all variable usage to speedup.
	PATH_D->assign_path( this_object() );

	add_action( "cmd_hook", "", 1 );
}

//	Setup standard user command hook system.  This system interfaces
//	with the cmd bin system, the environment's exits, and feeling entries.
nomask static int cmd_hook(string cmd)
{
	string file;
	string verb;
	int foo ;
	mapping before, after;

	if( query_temp("block_command") ) {
		quick_message( "( �������޷������������� )\n");
		return 1;
	}

	verb = query_verb();
	if ( !verb ) return 1;
	if( environment() && environment()->valid_exit(verb) ) {
		verb = "go";
		cmd = query_verb();
	}

	// Changed PATH to an array, to speed uo command hooking by Annihilator.
	file = (string)CMD_D->find_cmd(verb, query("PATH"));

	if( file && file != "" ) {
#ifdef PROFILING
		before = rusage() ;
#endif
		foo = (int)call_other(file, "cmd_" + verb, cmd);
#ifdef PROFILING
		after = rusage() ;
	 	"/adm/daemons/profile"->log_cmd(verb, before, after);
#endif
		return foo;
	}

//	if( environment() && environment()->query("quiet") ) return 0 ;
#ifdef PROFILING
	before = rusage();
#endif
	foo = (int)EMOTE_D->parse(verb, cmd);
	if (foo) {
#ifdef PROFILING
		after = rusage() ;
		"/adm/daemons/profile"->log_cmd(verb,before,after);
#endif
		return foo;
	}
#ifdef PROFILING
	before = rusage();
#endif
	foo = (int)CHANNELD_D->do_channel( this_object(),verb, cmd );
#ifdef PROFILING
	if( foo ) {
		after = rusage();
		"/adm/daemons/profile"->log_cmd( verb, before, after );
	}
#endif
	return foo;	
}

//	Setup standard user command hook system.  This system interfaces
//	with the cmd bin system, the environment's exits, and feeling entries.

/*
nomask static int stack_cmd_hook(string cmd)
{
	string file;
	string verb, arg;
	int foo ;
	mapping before, after;

	if( query_temp("block_command") ) {
		write( "( �������޷������������� )\n");
		return 1;
	}
	if (sscanf(cmd,"%s %s",verb,arg) != 2 ) {
		if( environment() && environment()->valid_exit(cmd) ) {
			foo = (int)call_other("/cmds/std/_go", "cmd_go", cmd);
			return foo;
		}
		else {
			verb = cmd;
			arg = 0;
		}
	}
	if ( arg == "" ) arg = 0;
	// Changed PATH to an array, to speed uo command hooking by Annihilator.
//	file = (string)CMD_D->find_cmd(verb, query("PATH"));

//	if( file && file != "" ) {
//		foo = (int)call_other(file, "cmd_" + verb, arg);
//		return foo;
//	}

	foo = (int)EMOTE_D->parse(verb, arg);
	if (foo) {
		return foo;
	}
	foo = (int)CHANNELD_D->do_channel( this_object(),verb, arg );
	if ( !foo )
		return command(cmd);
}
*/
//	This function protects the object from being shadowed for 
//	certain secure functions.
nomask int query_prevent_shadow(object ob)
{
	int loop;

	loop = sizeof(protect);
	while(loop--)
		if(function_exists(protect[loop], ob))  return 1;

	return 0;
}
 
/*
* Move the player to another room. Give the appropriate
* message to on-lookers.
* The optional message describes the message to give when the player
* leaves.
*/ 
varargs int move_player(mixed dest, mixed message, string dir)
{
	object prev,*usr;
	int res,n;
	
	prev = environment();
	if( res = move(dest) != MOVE_OK ) {
		tell_object(this_object(), "( ������ԭ��.... )\n");
		return res;
	}

	if( query_attackers() && clean_up_attackers() == 0) {
		set_temp("last_attack_skill", 0);
		quick_message("ս�������ˡ�\n");
	}

	if(message == "SLIENCE") return 0;
	if(message == "SNEAK") {
		call_other("/cmds/std/_look","cmd_look");
//		command("look");
		return 0;
	} 

	if( !query("invisible") && !query("player_invisible")) {
		if(message == 0 || message == "") {
			if(dir && dir != "") {
				tell_room(prev, 
					(string)this_object()->query_c_mout(dir) + "\n",
					this_object());
				tell_room(environment(), 
					(string)this_object()->query_c_min() + "\n",
					this_object());
			} else {
				tell_room(prev, 
					(string)this_object()->query_c_mmout() + "\n",
					this_object());
				tell_room(environment(), 
					(string)this_object()->query_c_mmin() + "\n",
					this_object());
			}
		} else {
			if( pointerp(message) ) {
				tell_room(prev, 
					sprintf(message[0], query("c_name")) , this_object() );
				tell_room(environment(), 
					sprintf(message[1], query("c_name")), this_object() );
			} else {
				tell_room(prev, message + "\n", this_object());
				tell_room(environment(), 
					(string)this_object()->query_c_min() + "\n",
					this_object() );
			}
		}
	} else if (query("player_invisible"))
	{
	usr=all_inventory(prev);
	usr = filter_array( usr, "filter_in_users", this_object() );
	for (n = sizeof(usr) ; n-- ; )
		if(message == 0 || message == "") {
			if(dir && dir != "") 
				tell_object(usr[n], 
					(string)this_object()->query_c_mout(dir) + "\n");
			else 
				tell_object(usr[n], 
					(string)this_object()->query_c_mmout() + "\n");
		} else {
			if( pointerp(message) ) 
				tell_object(usr[n], 
					sprintf(message[0], query("c_name")));
			else 
				tell_object(usr[n], message + "\n");
		}
	usr=all_inventory(environment());
	usr = filter_array( usr, "filter_in_users", this_object() );
	for (n = sizeof(usr) ; n-- ; )
		if(message == 0 || message == "") {
			if(dir && dir != "") 
				tell_object(usr[n], 
					(string)this_object()->query_c_min() + "\n");
			 else 
				tell_object(usr[n], 
					(string)this_object()->query_c_mmin() + "\n");
		} else {
			if( pointerp(message) ) 
				tell_object(usr[n], 
					sprintf(message[1], query("c_name")));
			 else 
				tell_object(usr[n], 
					(string)this_object()->query_c_min() + "\n" );
		}
	}
	set_temp("force_to_look",1);
		call_other("/cmds/std/_look","cmd_look");
//	command("look") ;
	set_temp("force_to_look",0);
	//	Follow/track mudlib support
/*
	if( !this_object()->query("no_follow") && environment() != prev && prev )
		all_inventory(prev)->follow_other(this_object(), environment(), dir);
*/ 
	return 0;
}

int filter_in_users( object plr )
{
	if (!living(plr)) return 0;
	if (!plr->query_temp("detect_invi")) return 0;
	if (plr == this_object()) return 0;
	return 1;
}

void create()
{
	if( user_exists(getuid()) ) return;

//	Until the user's name and id is set ... give it a temporary one.

	set("name", "noname", MASTER_ONLY);
	set("c_name", "İ����", MASTER_ONLY);
//	set("cap_name", capitalize(query("name")));
//	set("c_cap_name", query("c_name"));
	set("id", ({ "noname" }));

// We set EUID of 0 so that the login daemon can export the proper
// UID onto the player. If you are running without AUTO_SETEUID, then
// this has no effect, but under auto-EUID-setting it's important.
// Also it makes it mildly harder for people to get themselves into
// trouble by cloning user.c.

	seteuid(0);

//	The set_level()  is defined in /std/body/stats.c, which sets many
//	properties about the player's stats.

	set_level(1);

// there's some standard properties that need to be locked so that
// Joe Random Wizard can't break security by setting them on people
// who haven't used them yet.

	set("npc", 0, LOCKED);
	set("user", 1, MASTER_ONLY);

	set("snoopable", 0, MASTER_ONLY);
	set("invisible", 0);
	set("short", "@@query_short");
//	set("c_short", "@@query_c_short");
	set("title", query_title());
//	set("c_title", "@@query_c_title", MASTER_ONLY);

	set("linkdead", "@@query_linkdead");
	set("ghost", 0, MASTER_ONLY);
	set("shell", "none", MASTER_ONLY);
	set("vision", "@@query_vision");
//	set("harass", 0, OWNER_ONLY);
	set("critical_med_res", "@@query_critical_med_res");
	set("weight", USER_WEIGHT );
	init_aliases();

	//	Complete the standard user attribute settings.
//	set("channels", ([ "toggle": ({ "admin",}) ]), MASTER_ONLY);
	enable_commands();
}

void remove()
{
	string euid;
	mixed *inv;
	int loop;
 
	if( previous_object() ) {
		euid = geteuid(previous_object());
		if( (euid != ROOT_UID) && (euid != geteuid(this_object())) &&
			!member_group(euid, "admin") && !member_group(euid, "arch") ) {
			tell_object( previous_object(), 
				"�㲻������ݻ���ҵ����塣\n");
			return;
		}
	}

	// If this is an invisible wizard, we let the invisibility stay on: but
	// if it's a player who cast the invisibility spell, then we want him
	// to be visible when he reappears.
	if( !wizardp(this_object()) ) set("invis", 0);

	// do some command necessary.
	if( this_object()->query_temp("mounting") ) command("dismount");
	command("unsecure all");
	command("drop all");
        save_me();

	// Added master copy check to prevent flock daemon loading problem - Annihilator 12-05-93
	if( environment() ) free_locks(this_object());
	destroy_autoload_obj();
	inv = all_inventory(this_object());
	for( loop=0; loop<sizeof(inv); loop++ )
		if(inv[loop]->query("prevent_drop")) inv[loop]->remove();

	this_object()->tsh_cleanup();
	CMWHO_D->remove_user(this_object());
	if( link ) link->remove();
	living::remove();
}
 
static int in_de_quit_script;

int quit(string str)
{
	object *stuff, *inv;
	int i, j,loop;

	if( str ) 
		return notify_fail( "Ҫ�뿪��Ϸ���� quit �ͺ��ˡ�\n");
	if ( wizardp(this_object()) && !this_object()->query("ok_ip"))
		return notify_fail( "��Ϊ��ʦ��������� OKIP �� quit ��ȷ����ȫ !!\n");
// If the #define is on, then save their location for starting next time.

#ifdef REAPPEAR_AT_QUIT
	if (environment(this_player())) {
		set ("start_location", file_name(environment(this_player()))) ;
	} else {
		set ("start_location", START);
	}
#endif

	//	Get rid of any party memberships.
	PARTY_D->check_party(this_object()) ;

	if( wizardp( this_object() ) )	{
		string quit_script; // Pallando 93-02-1

		quit_script = user_path( query( "name" ) ) + ".quit";
		if( file_size( quit_script ) > 0 ) {
			if (in_de_quit_script++)
				write( "ι������ .quit ����� \"quit\" ָ����ӡ�\n");
			else
				call_other( this_object(), "tsh", quit_script );
			in_de_quit_script = 0;
		}
	}

#ifdef LOGOUT_MSG
	if( previous_object() == this_object() && this_player() )
		write( LOGOUT_MSG );
#endif

	if( link ) {
		link->set("last_on", time());
		link->set("ip", query_ip_name(this_object()));
	}
 
#ifdef QUIT_LOG
       if (wizardp(this_object()))
        "/adm/daemons/logind"->log_file1(QUIT_LOG, query("name") + ": quit from " +
                 query_ip_name(this_object()) + " [" +
                 extract(ctime(time()), 4, 15) + "]\n");
#endif
  
	//	Announce the departure of the user.
	if( this_object() && visible(this_object()) && environment() )
		tell_room( environment(), 
			query("c_name") + "������ʱ�뿪�������£��ص����µ���ʵ����ȥ�ˡ�\n"
			, this_object()
		);
 
	if( this_object() && interactive(this_object()) )
	ANNOUNCE->announce_user(this_object(), 1);
//  For speedy login message ;
// 	if ( !wizardp(this_object()) )
//	 	EVENT->add_online_user(0,capitalize((string)this_object()->query("name")));

//	Inform logoutd if this player is in open area, add by Iris
#ifdef OPEN_CHAT_ROOM
	LOGOUT_D->call_other_player();
#endif
	remove();
	return 1; 
}



// This function determines if the user has anything droppable 
// when they quit the mud.
// Dunno if this is still required.  - Annihilator
static int inventory_check(object obj)
{
	if( obj->query_auto_load() ) return 0;
	if( !obj->query("short") || obj->query("prevent_drop") ) return 0;
	return 1;
}
 

// This procedure is called from the setup() function below.  It is
// basically here to check that existing users get whatever new settings
// they need to function in today's changing mudlib.
void consistency_check()
{
	// Right now this doesn't do anything, because all your characters
	// will be up to date with the mudlib.
	// if you change anything which requires changing the data of every
	// user, then you can put code to make the change here. It will be
	// called every time a use logs on. For example, if you have a "foo"
	// property and you want to change it to a "bar" property in all
	// users, you could do this:
	// if (query("foo")) {
	//	 set ("bar", query("foo"));
	//	 delete ("foo") ;
	// }
	// Thus, if any user who logged in had a "foo" property, it would be
	// copied into the "bar" proprety, then deleted.
	// Consistency check is used for Stuff Like That.
	
	// delete some properites.
	delete("attack_skill");
	delete("defense_skill");
//	delete("PATH");
// turn on below at 95/3/11 by Ruby
	delete("languages");
	delete("c_short");
	delete("c_title");
	delete("cap_name");
	delete("chinese");
	delete("harass");
	delete("last_kill");
	delete("last_location");
	delete("natural_gae");
	delete("wreply");
	delete("invis");
	delete("max_damage2");
	delete("min_damage2");
	delete("weapon2");
	delete("weapon_class2");
	if ( !wizardp(this_player())) {
		delete("wizard");
		delete("channels");
		delete("invisible");
	}	
	set("title",query_title());
//	to here :P)	
	// reset unleagel properites.

	if ( wizardp(this_object()) )
		set("PROMPT",this_object()->query_prompt() );
	else
		set("PROMPT", "> ");
	set("max_hp", "@@query_max_hp" );
	set("max_tp", "@@query_max_tp" );
	set("max_load", "@@query_max_load");
	set("critical_med_res", "@@query_critical_med_res");
	set("weight", USER_WEIGHT );
	if( !undefinedp( ob_data["max_sp"] ) ) set("max_sp", "@@query_max_sp");
	if( !undefinedp( ob_data["max_fp"] ) ) set("max_fp", "@@query_max_fp");

	// if the properity has been deleted, reset it back.
	if( undefinedp(ob_data["alignment"]) ) set("alignment", 0);
	if( undefinedp(ob_data["age"]) ) ob_data["age"] = "@@query_age";
	else if( intp(ob_data["age"]) ) {
		age = ob_data["age"];
		ob_data["age"]= "@@query_age";
	}

	// remove the herb apply and bandaged condition, by Kyoko.
	if( !undefinedp(ob_data["guild_levels"]) ) {
		set("spell_levels", ob_data["guild_levels"]);
		delete("guild_levels");
	}
	if( !undefinedp(ob_data["guild_experiences"]) ) {
		set("spell_exps", ob_data["guild_experiences"]);
		delete("guild_experiences");
	}
	HERB_APPLY->remove_effect(this_object());
	BANDAGED->remove_effect(this_object());
	return;
}

//  This function is called when the player enters the game. It handles
//  news displays, player positioning, and other initial user setups. 
void setup()
{
	string *news;
	int i;

	//	Check to see if the user body has a "name"
	if( !query("name") ) return;
	seteuid( getuid() );

	//	Initiate user shell setup protocal
	this_object()->init_setup();

	//	Display last logon and logon site
	if( link_data("last_on") )
		write( "\n�ϴ�����ʱ��:  " + ctime(link_data("last_on")) + " (�� " +
			link_data("ip") + ")\n\n");

	this_object()->consistency_check();  // A catch-all to upgrade old users

	if( query("inactive") ) delete("inactive");
	
	CHANNELS_D->initialize_user();
	
	if( !query("cwd") ) set("cwd", "/doc");

	//	Get the news from the news daemon and put it out line by line
	//	to avoid overloading one write output.
/*
	news = explode((string)MSG_D->display_news(), "\n");
	for( i=0; i<sizeof(news); i++ )
		write( news[i] + "\n" );
*/
	// fix new messager .. for more easy ... 
	cat("/adm/news/c_motd");
//#ifdef NO_LOGIN_PAUSE
	complete_setup("");
	return;
//#endif

	write( "[�밴 RETURN ������]  ");
	input_to("complete_setup",2);

	return;
}
 
//	Complete remainder of character setup after NEWS 
//	has been read by the entering player
static void complete_setup (string str)
{
       int timetemp,timetemp1;
	object ghost;
	string class, start_room, student_time;
/*
This is here to permit an admin to shut down the game from the
"Press ENTER to continue" prompt. Sometimes this is helpful if there
is an object that is interfering with commands or otherwise wedging
the game, but will go away if the game is reset. It's not a security
problem because only admins can use it, and they could just log in
and use the shutdown command anyway... ;)
*/

#ifdef SAFETY_SHUTDOWN
	if( member_group(getuid(this_object()),"admin") )
		if( str=="shutdown" )
			CMD_SHUTDOWN->cmd_shutdown("0 because safety shutdown invoked.") ;
#endif
	write("\n");

        // Added by yueh for file checking
        if ((!wizardp(this_player()))&&(!query_temp("newuser"))){
             timetemp=stat(user_data_file(this_player())+".o",0)[1];
	timetemp1=query("last_save");
	if (!timetemp1){
           tell_object(this_object(),"������������Ѿ��𻵣�������������֪ͨ�������ʦ !!\n");
             ANNOUNCE->log_file1("BAD_MODIFY",query("name")+" be modified from "+link->query("ip")
               +" ["+extract(ctime(timetemp),4,15)+"] no save time\n");
	link->set("hibernate", (time() +259200));
	link->save_data();
                remove();
               return;
	}
             if (timetemp > (timetemp1+20)){
           tell_object(this_object(),"������������Ѿ��𻵣�������������֪ͨ�������ʦ !!\n");
             ANNOUNCE->log_file1("BAD_MODIFY",query("name")+" be modified from "+link->query("ip")
               +" ["+extract(ctime(timetemp),4,15)+"] save ["+extract(ctime(timetemp1),4,15)+"]\n");
	link->set("hibernate", (time() +259200));
	link->save_data();
                remove();
               return;
             }
           }

	link->set("last_on", time());
	link->set("ip", query_ip_name(this_object())) ;

	set("reply", 0);
//	set("wreply", 0);

	if( this_object()->query_temp("chat_user"))
		start_room = "/d/std/IRC/lobby";
	else
		start_room = getenv("START");

	if( !start_room || !stringp(start_room) ){
		class = this_object()->query("class");
		if ( member_array( class, CLASS_NAMES ) == -1 ) {
			tell_object(this_object(),"������������Ѿ��𻵣�������������֪ͨ�������ʦ !!\n");
			remove();
			return;
		}
		start_room = call_other( GUILD_MASTER(class), "query_guild_room" );
	}
	if( !(start_room && stringp(start_room) && move(start_room) == MOVE_OK) ) {
#ifdef REAPPEAR_AT_QUIT
		start_room = query("start_location");
		if(!(start_room && stringp(start_room) && move(start_room) == MOVE_OK))
			move(START);
#else
		move(START);
#endif
	}

	call_out("save_me", 1);

	ANNOUNCE->announce_user(this_object(), 0);

#if 0
This is commented out because of a problem with socket handling
by some versions of UNIX. Basically, if you make the call to USERID_D,
then the driver will call back to the user's host machine and ask for
the user's account name. Under some OS's (Ultrix and HP_UX to name two,
but there may be more) if the query returns "Host is unreachable", eg if
there is a firewall machine between the driver and the user's machine,
then the driver will break the user's connection, and anyone from that machine
will be unable to play the MUD.
You can undefine this at your own risk, but you'll be cutting off anyone
from a protected site, which means most .com addresses and a fair
smattering of other hosts, if your OS behaves this way. TMI-2's host
runs Ultrix, so we leave it commented out. A good 90% of hosts don't
support the user name query protocol anyway, so we're not losing that
much. It's your decision if you want to get the names of the other 10%
of users, or leave it commented out...
	USERID_D->query_userid();
#endif

	if( link_data("dead") || ((int)this_object()->query("hit_points")<1)) {
		ghost = create_ghost();
		this_object()->move(START);
		ghost->force_me("look");
		tell_object(ghost,
			"\n��ͻȻ���� ... ����ǰ���Ѿ����ˡ�\n");
		tell_room(environment(ghost), 
			  "һ��ԩ�����߽����˶������¡�\n", ghost );
		remove();
		return;
	}

	if( visible(this_object()) )
		tell_room( environment(),
			   (string)this_object()->query("c_name") + "���߽����˶������¡�\n",
			  this_object() );
 
#ifdef LOGIN_LOG
       if (wizardp(this_player()))
        "/adm/daemons/logind"->log_file1(LOGIN_LOG, query("name") + ": logged in from " +
		query_ip_name(this_object()) + " [" +
		extract(ctime(time()), 4, 15) + "]\n");
#endif

		call_other("/cmds/std/_look","cmd_look");
		hb_tick = random(20);
//	command("look");

/*
	student_time = STUDENT_D->query_time_left(query("name"));

	if(student_time != -1) {
		if(!student_time)
			write(blink("\n [WARNING:  Your time period as a student has " +
				"ended]") + "\n\n");
		else 
			write("\n [You have " + bold(format_time(student_time, 1)) + " left " +
				"as a student]\n\n");
	}
*/
}

//  This function is called cyclically to save the user data
//  periodically, if AUTOSAVE is defined.
/*
static void autosave_user()
{
//	remove_call_out("autosave_user");
//	call_out("autosave_user", AUTOSAVE);

	if( !wizardp(this_object()) )
		tell_object(this_object(), "�Զ��浵....��ϡ�\n");
	save_me();
}
*/

void run_cmds()
{
//	cmd_buffer_mode = 1;
	cmd_bottom++ ;
	command(cmd_stack[cmd_bottom-1]);

	if ( cmd_bottom >= 32 ) cmd_bottom = 0;
	if ( cmd_top == cmd_bottom ) receive(query("PROMPT"));
	return;
} 
//	This is called every system tick, and 'speed' should be the focus
//	when modifying this function.

void heart_beat()
{
	int idle_dump;

	if (hb_tick< MAX_TICK) {
		hb_tick++;
		if ( cmd_top != cmd_bottom ) 
			run_cmds();
		//else
		//	cmd_buffer_mode = 0;
		// run 2 cmds in 1 heart beat, add by Iris	
//		if ( cmd_top != cmd_bottom ) 
//			run_cmds();
//		else
//			cmd_buffer_mode = 0;
		return;
	} else hb_tick = 0;
	continue_attack();
	unblock_attack();
	heal_up();

#ifdef USE_IDLE_DUMP
	if( member_group(this_object()->query("name"), "admin") )
		idle_dump = ADM_IDLE_DUMP;
	else if( wizardp(this_object()) )
		idle_dump = WIZ_IDLE_DUMP;
	else
		idle_dump = IDLE_DUMP;
	if( interactive(this_object()) && query_idle(this_object()) > idle_dump )
		this_object()->call_user_dump("idle");
#endif

	//	Add to the user's online age total.
	if( !last_age_set )  
		last_age_set = time();
 
	age += (time() - last_age_set);
	last_age_set = time();
}


// Use this function to query age, query("age") is obsolete
int query_age()
{
	return age;
}

// This function returns whether the user is linkdead or not.
nomask int query_linkdead()
{
	return !interactive(this_object());
}

// Called by MudOS driver when player goes linkdead .
void net_dead()
{
	object env, statue;
	int dump_delay;
	
	save_data();
	env = environment();
	if( env )
		tell_room( env, 
			this_object()->query("c_name")+
			"����ʵ����������ƺ���Щ���� .... �����ˡ�\n"
			, this_object());

        PARTY_D->check_party(this_object());
        ANNOUNCE->announce_user(this_object(), 3);
        CMWHO_D->remove_user(this_object());
//      if net_dead in chat room , net dead == quit
//                                     Add by Iris
	if (query_temp("chat_user")) {
		this_object()->quit();
		return;
	}	
	

	// Create a statue in the room where the player was in.
	statue = new( NEW_STATUE );
	statue->assign( this_object() );
	this_object()->set("statue", statue);
	if( env ) {
		this_object()->set("linkdead_room", env);
		statue->move( env );
	} else
		statue->remove();

        set_heart_beat(0);
        set("inactive", 1);
//	netdead user remove herb_apply .. for punish the 
//	users use netdead k mobs
	"/std/conditions/herb_apply"->remove_effect(this_object());
	// Move this idle user to a safe room.
	this_object()->move_player(LINKDEAD_ROOM, "SLIENCE");

#ifdef USE_LINKDEAD_DUMP
	if( member_group(this_object()->query("name"), "admin") )
		dump_delay = ADM_LINKDEAD_DUMP;
	else if( wizardp(this_object()) )
		dump_delay = WIZ_LINKDEAD_DUMP;
	else
		dump_delay = LINKDEAD_DUMP;
	call_out("call_user_dump", dump_delay, "linkdead", this_object());
#endif

#ifdef NETDEAD_LOG
	log_file(NETDEAD_LOG, link_data("name") + ": net-dead from " +
		 query_ip_name(this_object()) + " [" +
		 extract(ctime(time()), 4, 15) + "]\n");
#endif
	if( link ) link->remove();
}
 
void restart_heart()
{
	object linkroom, statue;
	
	tell_room( environment(), 
		query("c_name")+"�������ߴ���ʱ���Ž���ð�����硣\n"
		, this_object()
	);

	statue = (object)this_object()->query("statue");
	if( statue )
		statue->remove();

	linkroom = (object)this_object()->query("linkdead_room");
	if( linkroom ) {
		this_object()->move_player( linkroom, "SNEAK" );
		tell_room( linkroom, 
			"һ�ŷ�������岻֪�Ӻδ����ֲ��ɽ�"+
			query("c_name")+"�ĵ����ڡ�\n"
			, this_object());
	}

	this_object()->delete("linkdead_room");
	this_object()->delete("statue");
	write( "����������ϡ�\n");
	ANNOUNCE->announce_user(this_object(), 2);
	USERID_D->query_userid();
	set_heart_beat(1);
	set("inactive", 0);
	remove_call_out("call_user_dump");
 
#ifdef RECONNECT_LOG
	log_file(RECONNECT_LOG, query("name") + ": reconnected from " +
		 query_ip_name(this_object()) + " [ " +
		 extract(ctime(time()), 4, 15) + "]\n");
#endif
 
}
 
varargs call_user_dump(string type, object player)
{
	object statue, user;
	
	if( player && objectp(player) ) user = player;
	else user = this_object();

	tell_object(user, "");  		//  Beep'em
	tell_object(user, 
		"�ܱ�Ǹ�����Ѿ�����̫���ˣ���ӭ�´�������\n");
		
	statue = (object)user->query("statue");
	if( objectp(statue) && type == "linkdead" ) {
		if( environment(statue) )
			tell_room( environment( statue ), 
				user->query("c_name")+
				"����̫�ã��������ϵ����������һ��߻���ʵ���硣\n"
				"����������¡��һ������֪�δ�����һ�������"+statue->query("short")+
				"��Ϊ�ҽ���\n"
				, statue
			);
			statue->remove();
	} else 
		tell_room(environment(), 
			user->query("c_name")+
			"����̫���ˣ��������ϵ����������һ��߻���ʵ���硣\n"
			, user
		);
	user->quit();
}

static void die()
{
	object killer, ghost, corpse, env, coins, *stuff;
	mapping wealth;
	string *names, name;
	int i, res;

	//	Set the user's killer variable
	killer = query("last_attacker");
	if (!killer) killer = previous_object() ;

	// The monster kill top-list stuff.
	if( !wizardp(this_object()) && killer->query("npc") )
		"/adm/daemons/npc_kills"->add_kills( base_name(killer) );
	
	// If a high lv killed a low lv (lv < 5) player, let him die!
        if( this_object()->query_level()<5 && userp(killer) && query("last_attacker") ) {
		tell_room(killer,"�������µ����񷢳�һ��ŭ��:�ɶ��"+
			killer->query("c_name")+"����PK�͵ȼ����, ȥ����!\n");
		killer->receive_damage(1000);
	}

	//	If the wizard has themself set to "immortal", then
	//	they cannot die ... stop death call.
	if( wizardp(this_object()) && query("immortal")) {
		write("( �����ʦ��ݼ������ħ��ʹ����������� )\n");
		set("hit_points", (int)query("max_hp"));
		return;
	}

	//	If the user is already dead ... stop death call.
	if( link_data("dead") )  return;

	//	If PK in PK zone won't die  .. add by Ruby
	if( (env = environment(this_object())) && env->query("PK_ZONE") 
		&& killer)	{
	   if ( !killer->query("npc") && !this_object()->query("npc") ) {
		this_object()->set("hit_points",1);
		write( "��������ľ������ⳡս������ܡ�\n"); 

        tell_room( env, 
		sprintf("%s�������ľ��������ⳡս����\n",(string)this_object()->query("c_name")) ,
        	this_object()
        );
		return;
	}
	}
    // Bail out of any parties they may be involved in.
    PARTY_D->check_party(this_object());

	// Count how many times we had been dying.
	add( "dead_count", 1 );

	//	Announce the user's death
	write( "�����ˡ�\n");
	COMBAT_D->report_death();

	
//	init_attack();

	//	Setup corpse with user's specifics
	corpse = clone_object("/obj/corpse");

	corpse->set_name(query("name"), query("c_name")) ;
        corpse->set("user_corpse");

	i = query("weight");
	if( i>0 ) corpse->set("weight", i);
	else corpse->set("weight", 600 );

	i = query("max_load");
	if (i>0) corpse->set("max_load", i);
	else corpse->set("max_load", 1000 );

	corpse->move(environment(this_object()));

	stuff = all_inventory(this_object());

	for(i=0; i<sizeof(stuff); i++)
		if(!stuff[i]->query("prevent_drop") && !stuff[i]->query_auto_load()) {
			// Remove stuff silently, Added by Annihilator@Eastern.Stories
			if( stuff[i]->query( "wielded" ) )
				stuff[i]->unwield(1);
			else if( stuff[i]->query( "equipped" ) )
				stuff[i]->unequip(1);
			stuff[i]->move(corpse);
		}
	corpse->add("weight",corpse->query("load"));
 	// Move all coins into corpse
	wealth = query("wealth");
	if( wealth ) {
		names=keys(wealth);
		for( i=0; i<sizeof(names); i++ ) {
			if( member_array(names[i], COIN_TYPES) == -1 || 
				!wealth[names[i]] ) continue;
			coins = new(COINS);
			if( coins ) {
				coins->set_type(names[i]);
				coins->set_number(wealth[names[i]]);
//				debit( names[i], wealth[names[i]] );
				coins->move(corpse);
			}
		}
	}
	set( "wealth", ([]) );

	if( killer ) name = (string)killer->query("name");

// open KILL log to check unknow killers
// by Ruby@ES 96/6/20
//	#ifdef KILLS
	if(killer)
        ANNOUNCE->log_file1("KILLS", query("name") + " was killed by " +
		 (name ? name + " " : "") + "(" + file_name(killer) +
				") [" + extract(ctime(time()), 4, 15) + "]\n");
	else
        ANNOUNCE->log_file1("KILLS", query("name") + " was killed by something [" +
		 extract(ctime(time()), 4, 15) + "]\n");
//	#endif

	//	Switch user to ghost body

	if ( DEATH->check_life_end(this_object()) ) return;

	ghost = create_ghost();

	if(!ghost)  return;

	tell_object(ghost, 
		"\n��������ֵĸо�....��ƮƮ��....\n\n�㿴�����Լ��������������ڵ���....��\n\n");

	if( killer ) {
		ghost->set("killer_ob", killer);
		ghost->set("killer_name", (string)killer->query("name"));
		if ( !killer->query("npc") && killer->query("make-up") ) {
			tell_object(ghost,set_color(sprintf("\n��ͻȻ����,ɱ�������%s(%s) !!\n\n\n",
				killer->query("c_org_name"),
				capitalize(killer->query("org_name") ) ),"HIR",this_object()));
		}
	}

	//  Use a call_out to make sure all the above calls have 
	//  completed their required processing (so we don't lose
	//  this_object() before everything is done).
	DEATH->start_death(ghost);
	call_out("remove", 0);
}

string query_short()
{
	object ob;
	
	if( query("name") == "noname" )  return "������";

	if( !interactive(this_object()) )  
		return (query("title") + " [������...]");

	if( query("inactive") )
		return query("title") + " [ֹͣ�]";
/*
	if( this_player() && attackers && sizeof(attackers) && attackers[0]
		&& environment(this_player()) == environment(this_object()) )
		return query("title") + " [���ں�" +
			(string)attackers[0]->query("c_name") + "ս��]";
*/
	if( query_temp("meditating") )
		return query("title") + " [ڤ˼��...]";

	if( query_temp("exercising") )
		return query("title") + " [�����˹�\��...]";

	if( ob=query_temp("mounting") )
		return query("title") + " [����һ" + 
			ob->query("unit") + ob->query("c_name") + "��]";

	return query("title");
}
string query_title()
{
	string str, foo, fii, name, color;
 	
	name = this_object()->query("c_name");
	color = getenv("TITLE_COLOR");
					
	if( wizardp(this_object()) && str=getenv( "C_TITLE" ) ) {
		if( sscanf(str, "%s$N%s", foo, fii) != 2 )
			return set_color(str+" "+name, color);
		else return set_color(substr(str,"$N",name), color);
	} else if( !undefinedp(ob_data["class"]) ) 
	{
		if( !undefinedp(ob_data["organization"]) ) 
                {
                   str=GUILD_MASTER(ob_data["organization"]);
                   if(file_size(str+".c")>0)
                       return str->query_c_title(this_object());
                }
                return GUILD_MASTER(ob_data["class"])->query_c_title(this_object());
         }
	else
		return name;
}
nomask void catch_msg(object source, string *msg)
{
	int i;
	for( i=0; i<sizeof(msg); i++ ) 
		receive(msg[i]);
}

void hide(int i)
{
	set_hide(i);
}

int move_ok()
{
	return this_object()->valid_mount(previous_object());
}
/* EOF */
