// File: /std/ghost.c
// The ghost body from the TMI-2 lib. Part of the bodies project, conceived
// by Buddha@TMI-2 and implmented by Mobydick@TMI-2 and Watcher@TMI-2.
// The code contained in this object is heavily based on code found in the
// original user.c and living.c at TMI-2. The relevant code headers follow:
// Original Authors: Sulam and Buddha @ The Mud Institute
// Many other people have added to this as well.
// This file has a long revision history dating back to the
// hideous mudlib.n and is now probably not at all the same.
// This file is a part of the TMI distribution mudlib.
// Please keep this header with any code within.

#include <config.h>
#include <mudlib.h>
#include <daemons.h>
#include <net/daemons.h>
#include <move.h>
#include <priv.h>
#include <uid.h>
#include <body.h>
#include <logs.h>
#include <stats.h>

inherit BODY_BASE ;
inherit "/std/living/env";
 
static void complete_setup();
 
//	Basic and standard command sets 
//	.. Initiated from inhabitant setup

// add by Ruby@ES for new command-line 
string parse_arg(string arg) { return arg; }
 
void basic_commands()
{
	add_action("quit", "quit");
	add_action("_revive", "_revive");
}
 
static void init_commands()
{
	add_action("cmd_hook", "", 1);
}

//  Catch the heartbeat's continue_attack .. but since ghosts
//  can't fight, just ignore the call.
 
void continue_attack() {  return ;  }
 
//  This function revives the user to its standard body

varargs void revive(int skip)
{
	string *attrs;
	mapping skills;
	object body;
	mixed *names;
	int loop, attr;
 
	//	If the caller isn't this_object(), block the call.  It would
	//	mess up the resulting user body.  The caller must be this_object().
	if(this_player() != this_object()) return;
	if( !skip && wizardp(this_player()) ) skip = 1;
 
	if( !link || !link_data("dead") )  return;
	
	body = new( (string)link_data("body") );
	link->set("tmp_body", body);
	link->set("dead", 0);
 
	if( !link->switch_body() ) {
		write("��� !! ����ת����������������֪ͨ�����ʦ !!\n");
		return; 
	}

	body->init_setup();
	link = 0;
 
	//	All the player's skills are reduced to 90% of their current value.
	//  But if skip, then skip reduce func, added by Kyoko.
	STATS_D->revive( body, skip );

	body->move( environment() );
	body->consistency_check();
	body->delete("conditions/bleeding");
	body->delete("conditions/simple_poison");
	body->delete("conditions/confused");
	body->delete("conditions/sick");
//  Delete blind condition after revive, Added by Iris
    body->delete("blind");
	body->set("spell_points",1);
	body->set("talk_points",1);
//  Add action_points, by Iris	
	body->set("action_points",300);
	tell_object(body, 
		"�����һ����ѣ���о��Լ��ֻص�����Ϥ�������\n");
	tell_room( environment(), 
		(string)body->query("c_name") + "��Ӱ�����˼�������ú����ܵľ���һ��������\n" ,
		({ body }) );
	body->save_me();
	"/adm/daemons/backup"->user_backup(body);	
	remove();
}
 
/*
* Move the player to another room. Give the appropriate
* message to on-lookers.
* The optional message describes the message to give when the player
* leaves.
* Some of the arguments are ignored in the case of the ghost body.
*/
 
varargs int move_player(mixed dest, string message, string dir)
{
	object prev;
	int res;
	
	prev = environment( this_object() );
 
	if( res = move(dest) != MOVE_OK ) {
		tell_object(this_object(),"������ԭ�ء�\n");
		return res;
	}
 
	if(message == "SNEAK") {
		set_temp("force_to_look", 1);
		command("look");
		set_temp("force_to_look", 0);
		return MOVE_OK;
	}

	if(!dir || dir == "")  dir = "away";
 
	if(!query("invisible")) {
		if(message == 0 || message == "") {
			tell_room(prev, 
				query("c_name") + "�Ĺ��Ʈ��" + to_chinese(dir) + "����\n" ,
				({ this_object() }));
			tell_room( environment(), 
				query("c_name") + "�Ĺ��Ʈ�˹�����\n" ,
				({ this_object() }));
		} else {
                        if( pointerp(message) ) {
                                tell_room(prev, ({
					sprintf(message[0], query("cap_name")),
					sprintf(message[1], query("c_name")) }), this_object() );
                                tell_room(environment(), ({
					sprintf(message[2], query("cap_name")),
					sprintf(message[3], query("c_name")) }), this_object() );
			} else {
				tell_room(prev, message + "\n", ({ this_object() }));
				tell_room( environment(),
					  query("c_name") + "�Ĺ��Ʈ�˹�����\n" ,
					  ({ this_object() }));
			}

		}
		}

	 set_temp ("force_to_look", 1) ;
	 command("look") ;
	 set_temp("force_to_look", 0) ;
 
	 return MOVE_OK ;
}

void create()
{
	set("weight", 0);
	set("max_load", 0);
	set_name("ghost","ĳ�˵Ĺ��");
	set("short", "@@query_short");
	set("vision", "@@query_vision") ;
	set("ghost", 1);
	set("_revive", 0, MASTER_ONLY);
	enable_commands();
}

void remove()
{
	CMWHO_D->remove_user(this_object());
	if (query_link()) query_link()->remove();
	body::remove() ;
}

int quit(string str) {

	int i, j ;
	object *stuff ;

	if (str) return notify_fail("Quit what?\n");

	if( wizardp( this_object() ) )	{
		string quit_script; // Pallando 93-02-11

		quit_script = user_path( query( "name" ) ) + ".quit";
		if( file_size( quit_script ) > 0 )
			call_other( this_object(), "tsh", quit_script );
	}
 
#ifdef LOGOUT_MSG
	write( LOGOUT_MSG );
#endif
    EVENT->add_online_user(0,capitalize((string)this_object()->query("name")) );	
	set("last_on", time());
	ANNOUNCE->announce_user(this_object(), 1);
	say(query("c_name") + " �뿪 ES �ص��п����ʵ��.\n");
 
#ifdef QUIT_LOG
	log_file(QUIT_LOG, query("name") +": quit\t\t" +
		ctime(time()) + " from " + query_ip_name(this_object()) + "\n");
#endif
 
	remove();
 
	return 1;
}

string process_input (string arg)
{
	arg = do_alias(arg) ;
	return arg ;
}

//	This function is used to check if the user is able to 
//	see anything around it.		 Watcher  (01/29/93)
//
// Ghosts can see anything at all times. If players find this advantageous
// enough to die for, then cheerio for them :)
 
int query_vision() {
 
	//	If there is no environment, you obviously can't see anything. :)
	if (!environment(this_object())) return 0 ;
 
	//	Otherwise, you can.
	return 1 ;
 
}

// Basic recognition function.

int query_ghost()
{
	return 1 ;
}
 
//  The ghost's short description
string query_short()
{
	if(!link) return "һ��ģ���İ�Ӱ";
	if(!link->query("c_name"))  return "һ��ģ���İ�Ӱ";

	if(interactive(this_object()))
		return link->query("c_name") + "�Ĺ��";
	else return link->query("c_name") + "�Ĺ�� [������...]";
}

void setup_ghost() {
 
	if(!query("name") || query("name") != geteuid(link))  return;

	set("cap_name", link->query("name"));
	set("c_name", link->query("c_name"));
	set("id", ({ "ghost", "mist", link->query("name"), query("cap_name") }) );
	set("long", sprintf("���ģ����Ӱ�ӿ���������%s�Ĺ�ꡣ\n",link->query("c_name")));
}

nomask static int cmd_hook(string cmd)
{
	string file;
	string verb;

	verb = query_verb();
	if (environment() && environment()->valid_exit(verb)) {
		verb = "go";
		cmd = query_verb();
	}

	file = (string)CMD_D->find_cmd(verb, ({ "/cmds/ghost" }) ) ;
 
	if(file && file != "")
		return (int)call_other(file, "cmd_" + verb, cmd);
 
	return 0 ;
}

 
int _revive()
{
	if(!query("_revive"))  return 0;

	set("_revive", 0);
	revive();
	return 1;
}

//  This is needed as a catch for the non-existant save system in
//  the ghost body, as compared to the user system. Without this 
//  catch, the ghost body can error at certain function calls when
//  save is called.  Watcher  (7/93)
 
int save_data() {  return 1;  }

// This is need to enable players see ghost players on the who list.

int query_level() { return query("level"); } 
/* EOF */
