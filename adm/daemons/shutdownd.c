//#pragma save_binary

/*
// File:     shutdownd.c
// Purpose:  Does mudlibby things before calling the shutdown() efun.
// Credits:
// 92-09-26  Truilkan @ Basis wrote the original version.
// 93-01-04  Pallando @ TMI-2 added in the delay option and Apocalypse bits.
// 93-01-14  Pallando moved the emotes to a seperate file
// Comments: (makes it easier for other muds to create their own emote files)
// 93-04-02  Pallando added stop_shutdown()
// 93-05-22  Watcher @ TMI-2 Changed shout()s to message()s
// Comments: ensures the emotes are labeled and this_player() get them.
// 93-07-08  Pallando ensured delay to shutdown isn't messaged twice.
// 93-07-08  Grendel@tmi-2 stoped two shutdowns happening at once
*/

#include <config.h>
#include <uid.h>
#include <daemons.h>
#include <net/daemons.h>

#define log( x )
#define EMOTE_FILE    "/adm/etc/shutdown_message"
#define C_EMOTE_FILE  "/adm/etc/c_shutdown_message"

string *emotes, *c_emotes;
int num_emot, c_num_emot; // The number of shutdown messages.
int s_sec; //	The time() the shutdown is due at, in seconds.
void count_down(int how);

int query_shutdown()
{
	return s_sec;
}

varargs mixed query_emotes(int chinese)
{
	return (chinese? c_emotes : emotes);
}

void save_daemons()
{
	EMOTE_D->save_data();
	CMWHO_D->halt();

	// save some daemons's data.
	CHINESE_D->save_data();
	EXPLORE_D->save_data();
//	PROMOTION_D->save_data();
	QUEST_D->save_data();
	"/adm/daemons/npc_kills"->save_data();

	// save all users data on line.
      users()->save_me();
//         users()->quit();
}

void do_shutdown(int how)
{   
    if(previous_object() )
	if( geteuid( previous_object() ) != ROOT_UID ) return;
	save_daemons();
	shutdown(how);
}

varargs int start_shutdown(int how, int delay, string who)
{
	object *user, act_ob;
	int i;
	string msg, c_msg, name, c_name;

	act_ob = previous_object();
	if( geteuid( act_ob ) != ROOT_UID ) return s_sec;
	if( delay < 0 ) return s_sec;
	if( this_player() && member_group(geteuid(this_player()), "admin") ) {
		name = (string)this_player()->query("name");
		c_name = (string)this_player()->query("c_name");
	} else {
		name = "God of Eastern Stories";
		c_name = "�������µ�����";
	}

	switch( name ) {
		case "Kyoko":
//			msg = sprintf("\n%s cackles: The end of the world is nigh."+
//	    		" Prepare to meet thy DOOM!\n\n", name);
			c_msg = sprintf("\n����ͻȻ�����ȱ������񡪡�%s���������: "+
				"������ҵ������Ѿ���ʼҪ�����ˣ����׼��׼����!!\n\n", c_name);
			break;
		default:
//			msg = sprintf("\n%s cackles: The end of the world is nigh."+
//				" Prepare to meet thy DOOM!\n\n", name);
			c_msg = sprintf("\n����ͻȻ�����ȱ������񡪡�%s���������: "+
				"������ҵ������Ѿ���ʼҪ�����ˣ����׼��׼����!!\n\n", c_name);
			break;
	}
	user = users();
	for( i=sizeof(user)-1; i>=0; i-- )
		message("shutdown", set_color(
			c_msg, "HIY", user[i]), user[i] );

	if( !delay ) {
		do_shutdown( how );
		return time();
	}

	// if there is another shutdown on the way then cancel it
	if( s_sec ) remove_call_out("count_down");

	s_sec = time() + ( delay * 60 );
	count_down(how);
	return s_sec;
}

varargs string get_emote(int delay, int chinese)
{
//	if( !emotes ) {
//		emotes = explode(read_file(EMOTE_FILE), "###\n");
//		num_emot = sizeof(emotes) - 1;
//	}
	if( !c_emotes ) {
		c_emotes = explode(read_file(C_EMOTE_FILE), "###\n");
		c_num_emot = sizeof(c_emotes) - 1;
	}

	// 1st in shutdown message is not used.
	if( delay < c_num_emot )
		return c_emotes[(c_num_emot-delay)];
//	else if( !chinese && delay < num_emot )
//		return emotes[(num_emot-delay)];
	return "\n"; // No message except the time until shutdown, done by count_down()
}

// Make this function static to prevent calls to this function outside the
// shutdownd.                                             - Annihilator
void count_down(int how)
{
	int delay, i;
	string msg, c_msg;
	object *user;

	delay = ( s_sec - time() ) / 60;
	if( delay > 0 ) {
//		msg = sprintf("%s\nEastern Stories will reboot after %d mins.\n\n",
//			get_emote(delay, 0), delay);
		c_msg = sprintf("%s\n��������ĩ�ջ��� %d ���ӡ�\n\n",
			get_emote(delay, 1), delay);
		user = users();
		for( i=sizeof(user)-1; i>=0; i-- )
			message("shutdown", set_color(
				c_msg ,"HIR", user[i]), user[i]);
	} else {
		do_shutdown( how );
		return;
	}
	call_out("count_down", 60, how);
}

int stop_shutdown()
{
	object *user, act_ob;
	int i;
	string msg, c_msg, name, c_name;

	act_ob = previous_object();
	if( geteuid(act_ob) != ROOT_UID ) return 0;
	s_sec = 0;
	remove_call_out("count_down");
	if( this_player() && member_group(geteuid(this_player()), "admin") ) {
		name = (string)this_player()->query("name");
		c_name = (string)this_player()->query("c_name");
	} else {
		name = "Gods in Eastern Stories";
		c_name = "�������µ�����";
	}

	switch( name ) {
		case "Kyoko":
//			msg = sprintf("\nThe Mighty %s intervenes to save the world.\n\n", name);
			c_msg = sprintf("\n����ͻȻ�����ȱ������񡪡�%s���������: "+
				"���Ѿ���ʱ��ֹ������Ļ������Ұ��ĵ���!!\n\n", c_name);
			break;
		default:
//			msg = sprintf("\nThe Mighty %s intervenes to save the world.\n\n", name);
			c_msg = sprintf("\n����ͻȻ�����ȱ������񡪡�%s���������: "+ 
                                "���Ѿ���ʱ��ֹ������Ļ������Ұ��ĵ���!!\n\n",c_name);
			break;
	}
	user = users();
	for( i=sizeof(user)-1; i>=0; i-- )
		message("shutdown", set_color(
			c_msg, "HIC", user[i]), user[i] );
	return 1;
}

void guild_data_log()
{
	string temp;

	temp =ctime(time())+"\n";
	temp+=(string)find_object_or_load("/d/knight/data/topknights")->get_list(0);
	write_file("/d/knight/data/knights.log",temp);

	temp =ctime(time())+"\n";
	temp+=(string)find_object_or_load("/d/mage/tower/obj/topmages")->get_list(0);
	write_file("/d/mage/data/magedata.log",temp);

	temp =ctime(time())+"\n";
	temp+=(string)find_object_or_load("/d/thief/data/topthieves")->get_list(0);
	write_file("/d/thief/data/thieves.log",temp);
        temp=ctime(time())+"\n";
         temp+=(string)find_object_or_load("/d/monk/guild/misc/topmonks")->get_list();
         write_file("/d/monk/data/monks.log",temp);
        temp =ctime(time())+"\n";
}

