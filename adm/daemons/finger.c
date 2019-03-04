//#pragma save_binary
 
// File : /adm/daemons/finger.c
//
// An improved interface to provide the information required by the "finger"
// command, as well as other essential information about the user, that may  
// not be available when they are not logged in.
// This version of the finger daemon was written by Buddha@TMI-2, with some
// existing code from the old finger daemon (most of which he also did).
// This is part of the TMI-2 distribution mudlib.
// Please retain this header.
//
// Bug - bad argument 1 to extract() line 133
// possibly caused by someone being half logged in
// Mobydick thinks he fixed this bug, hasn't had the chance to test it.
// 2-15-93.
// Watcher eliminated references to users when the user is inhabiting a
// monster body (3/22/93)
// Watcher added in wizard label to specific user finger (4/3/93)
// Made to respect invisible status by Spock @ TMI-2 4/4/93
// Watcher rewrote the invisible checks to use the visible() efun, added
// the checks to the finger_all function, and added an alphabetic sort on
// the general finger output, 4/25/93.
//
// @Eastern.Stories
// Someone (Probably Annihilator) make this display both English and Chinese.
// Kyoko add something, and limited the info displayed to the players.
// 12-23-94: Elon Take out English msg and make the code shorter.
 
#include <uid.h>
#include <config.h>
#include <mudlib.h>
#include <login_macros.h>
#include <daemons.h>
#include <stats.h>
#include <races.h>
 
inherit DAEMON;
 
void create()
{
	seteuid(ROOT_UID);
}
	
//  This function is called to restore the user's connection object that
//  holds the essential login information.  If the user in question is 
//  currently logged in, then their current connection object is returned,
//  otherwise it is restored.  You should probably call clean_up() on the
//  object when finished, and it will either self-destruct, if not interactive
//  or associated to a body, or save and wait for further information
//  requests, if it is. 
object restore_data(string name)
{
	object link;
 
	if( find_player(name) && interactive(find_player(name)) ) {
		return (object)find_player(name)->query_link();
	}
	link = new(CONNECTION);
	seteuid(name);
	export_uid(link);
	seteuid(ROOT_UID);
	link->set("name", name);
	if( link->restore() )
		return link;
	// If this fails, then let's clean up afterwards...
	link->remove();
	return 0;
}
 
// if st=1, fingeree has wizard status, else st=0, this is to filter
// out wizard only information while fingeree is a player.
// Elon 12-23-94
varargs string finger_user(string who, int st)
{
	object link, player;
	mixed tmp1, tmp2, tmp3, tmp4, tmp5;
   	string msg, race;
   	mapping mail_stat;
	int hibernate, age;
  
	link = restore_data(who);
	player = find_player(who); 
    if(!link) return "Finger: û����λʹ����.��\n";
		
    tmp1 = "ʹ��������:\t"+link->query("c_name")+"["+who+"]";
    tmp2 = "��ʵ����:\t";
  	if ( tmp3 = (string)link->RNAME) 
		tmp2 += extract(tmp3, 0, 22);
    else tmp2 += "(����)";
 
	msg = sprintf("%-40s%-30s\n", tmp1, tmp2);
 
	tmp1 = user_path(who);
    if(file_size(tmp1) == -1) tmp1 = "(û��)";
    msg += "˽��Ŀ¼:\t" + tmp1 + "\n";
 
	tmp4 = DOMAIN_D->query_domain(link);
	tmp5 = DOMAIN_D->query_domain_level(link);
    if ((tmp4==0) || (tmp4=="")) tmp4 = "û��";
    msg += "��������:\t" + tmp4 + " (" + to_chinese(tmp5) + ")\n";
 
    msg += "Ȩ�޵ȼ�:\t";
	if(member_group((string)link->query("name"), "admin"))
        msg += "��\n";
    else if(link->query("wizard"))  msg += "��ʦ\n";
    else msg += "���\n";
 
	tmp1 = (string)link->query("email");
    msg += "�����ʼ���ַ:\t" + tmp1 + "\n";
 
	tmp1 = find_player(who);
 
	hibernate = (int)link->query("hibernate");
 
	if( hibernate && time() < hibernate )
        msg += "\n\t[�ݼ��У���������: "+ctime(hibernate) + "]\n\n";
 
	if(tmp1) {
		if(!this_player() && tmp1->query("invisible"))  tmp1 = 0;
		else if(!visible(tmp1, this_player())) tmp1 = 0;
	}
 
	if( !link->query("last_on") )
        msg += (tmp1 ? "����ʱ��:\t" : "�ϴ�����ʱ��:\t") + "<����>\n";
	else
        msg += ((tmp1 && !tmp1->query("npc")) ? "����ʱ��:\t" : "�ϴ�����ʱ��:\t") +
        ctime((int)link->query("last_on"));
    if(st==1)
        msg += " (���� " + (string)link->query("ip") + " )\n";
    else
        msg += "\n";
//	if (tmp1) {
//		tmp1 = query_idle_string(tmp1, 1);
//		if (strlen(tmp1) > 0) msg += tmp1 + "\n";
//	}
    
	// add by Kyoko 4-9-94.
    if( player&&tmp1 ) {
      age = (int)player->query_age();
        msg += sprintf("����:\t\t%d�� %dСʱ %d�� %d��\n",
           age/86400, (age%86400)/3600, (age%3600)/60, age%60 );
 
/* This section comment out by Elon, 12-23-94. ת��, �����ƶȻ�û��
      race = player->query("race");
      if( race ) {
        age = RACE_MASTER(race)->query_natural_life();
        age -= (int)player->query("dead_count") * 2;
        age -= (int)player->query("natural_age");
        age -= (int)player->query_age() / 86400;
 
          msg += (age > 0) ? sprintf(" ���� %d ��ɻ\n", age ) :
                 " �����Ѿ���\n";
      }
*/
    }
         
	mail_stat = (mapping)MAILER_D->mail_status(who);
	if (mail_stat["unread"])
            msg += sprintf("\n�ż�:\t%d ��, ��δ��ȡ: %d ��\n",
			mail_stat["total"], mail_stat["unread"]);
    else msg += "\n[ û����δ��ȡ���ż� ]\n";
	tmp1 = user_path(who) + ".project";
    if(file_size( tmp1 ) >= 0) msg += "\nĿǰ�ƻ�:\t" + read_file(tmp1);
	tmp1 = user_path(who) + ".plan";
	if (file_size( tmp1 ) >= 0) {
        msg += "\nδ���ƻ�: \n" + read_file(tmp1);
	}
    else msg += "\n[ Ŀǰû������ƻ� ]\n";
	if (!find_player(who)) link->remove();
	return "\n" + msg + "\n";
}
 
varargs string finger_all(int st)
{
	object *who, link;
	int i, j;
	string msg;
 
	who = users(); 
	who = filter_array(who, "filter_users", this_object());
	who = sort_array(who, "sort_users", this_object());
 
	j = sizeof(who);
 
	msg =
"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    if (j == 0)
        msg += "[ ������������û���κ���������, ����һ�������� ]\n";
	else {
        msg += "[ �������� ] Ŀǰ�� " + j + " λʹ���� ( ʱ��: "+
               ctime(time()) + " )\n";
		msg += 
"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        msg += sprintf("%-15s%-15s%-15s%-8s%-6s%-16s","��������", "Ӣ������",
        "��ʵ����", (st == 1? "���":"    "), "����",
        (st == 1? "����λ��\n":"\n"));
		msg += 
"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
	}
	for (i=0; i < j; i++) {
		link = (object)who[i]->query_link();
		if(!link) continue;
		if (!link->RNAME) continue ;
            msg += sprintf( "%-15s%-15s%-15s%-8s%-6s%-20s\n",
			(string)link->query("c_name"),
            (string)link->query("name"),
            extract((string)link->RNAME, 0, 14),
            (st == 1 ? to_chinese((string)DOMAIN_D->query_domain_level(link)):""),
			query_idle_string(who[i], 0),
            (st == 1 ? extract(query_ip_name(who[i]), 0, 20 ):""));
	}
	return msg + 
"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
}
 
//  This function filters out any invisible and monster-inhabiting users.
 
int filter_users(object who) {
 
   if(!this_player() && who->query("invisible"))  return 0;
   else if(!visible(who, this_player()))  return 0;
 
return !((int)who->query("npc"));  }
 
 
//  This function sorts the users in alphabetical order.
 
int sort_users(object one, object two) {
   return strcmp((string)one->NAME, (string)two->NAME); }
 
