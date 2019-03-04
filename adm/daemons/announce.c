//  Mud user login/logout Announcer Daemon
//  Created by Glenn Ferguson (Watcher@TMI) 09/26/92
//  Visibility check added by Pallando, 93-08-19
//  Autobow/Autowave hack added by Robocoder, 94.08.27
//
//  Must have connecting hooks within the mudlib system to inform
//  the daemon when a user has enter/left the mud.
//
//  Type 0  :   entered     Type 1  :   left
//  Type 2  :   re-entered  Type 3  :   net-dead
//  
//  Elon@ES took out autowave, autobow (they are silly). let all
//  (01-15-95)  wiz can see player login IP.. translate to Chinese.


#include <mudlib.h>
#include <uid.h>
#include <daemons.h>
#include <logs.h>
 
inherit DAEMON;
inherit OBJECT;
 
void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "ʹ���߱䶯");
}
 
int announce_user(object who, int type)
{
	mixed *list, *ann;
	string name, what, c_name, tmp;
	int loop, s, member;
	object ob;

	if(!who)  return 0;
	if(name = (string)who->query("name"))
		name = capitalize(name);
	else
		name = "NONAME";
	if (!(c_name = (string)who->query("c_name")))
	c_name = "����";
   
	tmp = c_name + "(" + name + ") ";

	switch (type) {
		case 0:
			CHANNELD_D->do_channel(this_object(), "sys",
				tmp + "�� " + query_ip_name(who) + " ���߽��붫�����¡�");
#ifdef LOGIN_LOG
       if (wizardp(this_player()))
        log_file(LOGIN_LOG,this_player()->query("name") + ": logged in from " +
                query_ip_name(this_player()) + " [" +
		extract(ctime(time()), 4, 15) + "]\n");
#endif
			break;
		case 1:
			CHANNELD_D->do_channel(this_object(), "sys",
				tmp + "�뿪�˶������¡�");
#ifdef QUIT_LOG
      if (this_player())
       if (wizardp(this_player()))
        log_file(QUIT_LOG,this_player()->query("name") + ": quit from " +
                 query_ip_name(this_player()) + " [" +
		 extract(ctime(time()), 4, 15) + "]\n");
#endif
			break;
		case 2:
			CHANNELD_D->do_channel(this_object(), "sys",
				tmp + "�� " + query_ip_name(who) + " �������߽��롡");
#ifdef NETDEAD_LOG
        log_file(NETDEAD_LOG, tmp + ": reconnected from " +
                 query_ip_name(who) + " [" +
                 extract(ctime(time()), 4, 15) + "]\n");
#endif
			break;
		case 3:
			CHANNELD_D->do_channel(this_object(), "sys",	tmp + "�����ˡ�");
#ifdef NETDEAD_LOG
        log_file(NETDEAD_LOG, tmp + ": disconnected from " +
                 query_ip_name(who) + " [" +
                 extract(ctime(time()), 4, 15) + "]\n");
#endif
			break;
	}
 
	return 1;
}

void log_file1(string file, string message)
{
 log_file(file,message);
}
