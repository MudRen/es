//#pragma save_binary

// File   :  /adm/daemons/logind.c
// Creator :  Sulam@TMI  (12-13-91)
// Updated :  Sulam@TMI  (3-29-92)  Added real_name prompting
//	 Sulam@TMI  (4-10-92)  Added game locking
//	 Buddha@TMI  (9-4-92)  Added news system and
//	  expanded the login process
//
// Overhauled by Buddha@TMI (12-92) to support a separate creation
// module and to serve as a login daemon
//
// Updated :  Watcher@TMI  (2-9-93)  Moved news display to nes
//	  news daemon, and inserted check for users stuck
//	  in login limbo
//	 Watcher@TMI  (2-22-93)  Added an optional userlist
//	  display during the welcome screen
//	 Watcher@TMI  (2-23-93)  Streamlined Guest login process,
//	  added banish name system, and upgraded a few other things.
//	 Watcher@TMI  (3-9-93)  Added login failure notification.
//	 Watcher@TMI  (4-7-93)  Added max players, WIZ_LOCK,
//	  ADMIN_LOCK, and shutdown entry check.
//	 Watcher@TMI  (4/15/93)  Added NO_REMOTE_LOGIN check option.
//	 Watcher@TMI  (4/29/93)  Added hibernation checks.
//	 Karathan  (7/13/93)  Tidied and moved updated banish code
//	  to the banish daemon.
//	 Karathan  (8/12/93)  Added email-registration command handler.
//   Kyoko     (6/9/94)   Added IRC channel checking.
//	 Annihilator (11/1/94)  Added configurable run-time options.
//	 Elon (01/06/95) added Chinese messages..
// Much of the login process can be customized to suit your
// specific variety of mud and its atmosphere.  These defines
// can be found, for the most part, in /include/login.h

#include <uid.h>
#include <priv.h>
#include <config.h>
#include <mudlib.h>
#include <login.h>
#include <daemons.h>
#include <login_macros.h>
#include <net/daemons.h>
#include <logs.h>

#define MANY_TRY "��Ǹ, ����̫�����.\n"

//  Prototyping
void logon(object ob);
string active_users(int irc);
protected void get_name(string str, object ob, int count);
protected void get_password(string pass, object ob, int count);
protected int check_password(string pass, object ob);
protected void choice(string choice, object ob, string name);
protected void register_site();
protected void exec_old_copy(string s, object ob);
protected void login_new_copy(object ob);
protected void enter_world(object ob);
protected void check_email(object user);

mapping options;
int IS_CHAT_ROOM, extra;
object NETDEAD;

void create()
{
    seteuid(ROOT_UID);
    IS_CHAT_ROOM=0;
    options = DEFAULT_LOGIN_OPTIONS;
        NETDEAD = find_object_or_load("/d/std/rooms/netdead");
}

void set_chat_room(int stat)
{
    IS_CHAT_ROOM=stat;
}

// This is called when a new user logs in.
void logon(object ob)
{
    string user_ip;

    if( base_name(previous_object()) != CONNECTION )
        return;

    cat(C_WELCOME);
    printf("\t\t���������Ѿ�����ִ���� %s ��\n\n", format_c_time(uptime(), 1));
    if ( uptime() < 43200 ) extra = options["EXTRA_USERS"] ;
        else extra = 0;
    if( options["USER_LIST"] ) write(wrap(active_users(0))+"\n");

    write(LOGIN_PROMPT);
#ifdef CONNECT_LOG
        log_file (CONNECT_LOG,query_ip_name(ob)+" try to connect at "+
                  ctime(time()) +" as "+file_name(ob)+"\n" );
#endif

    input_to("get_name", 2, ob, 1);
    return;
}

protected void get_name(string str, object ob, int count)
{
    string tmp, tmp1, tmp2, tmp3, tmp4;
    int bad_name, loop, i, sd_time;
    int now_clock, is_max;
    object *urs;

    // Check for IRC channel, original by Kyoko, cleaned up by Annihilator.
//	if( options["IRC_CHANNEL"] && str[0]=='#' && str!="#guest" ) {
//		str = extract(str,1);
//		IS_IRC = 1;
//	}

    // Did they supply anything?
    if( !str || str=="" ) {
        write( "\n������Ҫ����һ�㶫��...\n\n" );
        write( LOGIN_PROMPT );
        if( count>2 ) {
            write( MANY_TRY );
            ob->remove_user();
            return;
        }
        input_to( "get_name", 2, ob, count+1 );
        return;
    }

    if( options["ADMIN_LOCK"] && !member_group(str, "admin") ) {
        write("\n��������������ʱ����ֻ�С�ϵͳ�����ߡ����ϵ�ʹ���߲��ܽ��롣\n");
        ob->remove_user();
        return;
    }

    if( options["ARCH_LOCK"] && !member_group(str, "admin") && !member_group(str, "arch") ) {
        write("\n��������������ʱ����ֻ�С�����ʦ�����ϵ�ʹ���߲��ܽ��롣\n");
        ob->remove_user();
        return;
    }

    if( options["WIZ_LOCK"] && !member_group(str, "admin") &&
        (file_size(user_path(str))!=-2) ) {
//		!PROMOTION_D->in_wiz_list(str) ) {
        write("\n��������������ʱ����ֻ�С���ʦ�����ϵ�ʹ���߲��ܽ��롣\n");
        ob->remove_user();
        return;
    }

    if( options["MAX_USERS"] && !member_group(str, "admin") &&
       (file_size(user_path(str))!=-2) && !find_player(str) ) {
//		!PROMOTION_D->in_wiz_list(str) && str != "testchar"
//	   && !find_player(str) ) {
//  This stuff cause a trick: linkdead->login new char->reconnect
//  Comment out by Annihilator.
        NETDEAD = find_object_or_load("/d/std/rooms/netdead");
        urs = filter_array(users()+all_inventory(NETDEAD), "check_players", this_object());
#ifndef OPEN_CHAT_ROOM
        if( (sizeof(urs)>=options["MAX_USERS"]+extra) ) {
            write("\n\n\t��Ǹ�...  �����������ڿ���."+
            "\n\n\t��Ȼ�����, ��ȥ�������! \n\n");
            ob->remove_user();
            return;
        }
#else
                  if( (sizeof(urs)>=options["MAX_USERS"]+extra) ) {
            IS_CHAT_ROOM = 1;
        }
#endif
    }

    if( strlen(str) > 12 ) {
        write("���Ӣ�����ֲ��ܳ��� 12 ����ĸ.\n");
        write(LOGIN_PROMPT);
        if( count>2 ) {
            write( MANY_TRY );
            ob->remove_user();
            return;
        }
        input_to("get_name", 2, ob, count+1);
        return;
    }

    str = lower_case(str);
    for(i = 0; i < strlen(str); i++) {
        if( str[i] < 'a' || str[i] > 'z' ) {
            write("�������ֻ���� a-z ֮���Ӣ����ĸ.\n" +
                "����������һ��: ");
            if( count>2 ) {
                write( MANY_TRY );
                ob->remove_user();
                return;
            }
            input_to("get_name", 2, ob, count+1);
            return;
        }
    }

    //  Does the user even currently exist? If not, check for correct name.
    if( !file_exists(user_data_file(ob, str) + SAVE_EXTENSION) ) {
        // Could be a new player, confirm it!
        if (IS_CHAT_ROOM) {
            write("\n�����ɫ������.\n���ES������ʱ���������½�ɫ.\n");
            ob->remove_user();
            return;
        } else {
            write("\n\"" + capitalize(str) + "\" �����ɫ������.\n" +
                "��ȷ��Ҫ���������? (y/n) [y] ");
            input_to("choice", 2, ob, str);
            return;
        }
    }

    seteuid(str);
    export_uid(ob);
    seteuid(getuid());
    ob->SET_NAME(str);

    // If it is the Guest character, no password is asked for.
    if( str=="guest" ) {
        get_password("", ob, 1);
        return;
    }

    input_to("get_password", 3, ob, 1);
    write(PASSWORD_PROMPT);
    return;
}

protected void remove_copy(object ob)
{
    if( ob ) ob->remove();
}

protected void get_password(string pass, object ob, int count)
{
    object body;
    int hibernate,i;

//  If BANISHED_SITES has been defined in /include/login.h, check with
//  the banish daemon for use of a banished site.
#ifdef BANISHED_SITES
    //  Site banning code is from Dainia@DreamShadow
    //  Updated 7/13/93 by Karathan
    i = BANISH_D->check_banned_site(query_ip_name());
    if (i < 0) {
            write( IP_FAIL ) ;
            ob->remove_user();
            return;
        }
        if (i > 0) {
            write( BANISH_REPORT ) ;
            ob->remove_user();
            return;
        }
#endif /* BANISHED_SITES */


    if ( !pass ) pass = "";
    if ( !ob ) return;
    write("\n");
    if( !check_password(pass, ob) && (string)ob->query("name") != "guest" ) {
        write("��Ǹ, �������.\n");
        if( count > 2 ) {
            write("\n"+MANY_TRY);
            ob->set("passwd_fail", ({ query_ip_name(ob), time() }) );
            ob->remove_user();
            return;
        }
        write("�����������������: ");
        input_to("get_password", 3, ob, count + 1);
        return;
    }

    // This code checks to see if the user is in hibernation.
    hibernate = ob->query("hibernate");
    if( hibernate && time() < hibernate ) {
        write("\n\n\t�� ? �㲻�Ƿ���˵ҪŬ���ù�, �� " + ctime(hibernate) +
              " ֮ǰ\n\t���� LOGIN �� ?? �� !! ��ȥ���顣\n\n");
        ob->remove_user();
        return;
    }
    else if( hibernate )
        ob->set("hibernate", 0);

    body = find_player((string)ob->NAME);

    // If user is stuck in login limbo ... dest old copy
    if( body && !environment(body))
        body->remove();

    // There's already a body exists, do further check.
    if( body ) {
        ob->SET_BODY_OB(body);
        if(interactive(body)) {

//  If ONE_GUEST is defined in /include/login.h, only permit one guest login.
#ifdef ONE_GUEST
            if ((string)ob->query("name") == "guest") {
                write("��Ǹ, �����Ѿ���һ�� Guest ��.\n" +
                    "���������, �������½���һ����ɫ." +
                    "\n\n");
                call_out("remove_copy",1, this_player());
                return;
            }
#else /* ONE_GUEST */
            if ((string)ob->query("name") == "guest") {
                exec_old_copy("n", ob);
                return;
            }
#endif /* ONE_GUEST */

            write("\n��һ���㻹����Ϸ��. ");
            write("��Ҫ�����߳�ȥ��?? (y/n): ");
            input_to("exec_old_copy", 2, ob);
            return;
        }

//  If EXEC_COPY is defined in /include/login.h, log the exec copy call.
#ifdef EXEC_COPY
        log_file(EXEC_COPY, capitalize((string)ob->NAME) +
            " :\texec copy from " + query_ip_address(ob) + " [" +
             extract(ctime(time()),4,15) + "]\n");
#endif /* EXEC_COPY */

         // When we comes here, the existing body is net-dead, reconnect it.
        if( ob->connect() ) {
            body->restart_heart();
            body->set("ip",query_ip_name(ob));
            ENTER_D->check_okip(body);
        }
        else {
            write("��������ʧ��...\n");
            ob->remove();
        }
        return;
    }
    // There's no existing body, login a new copy.
    login_new_copy(ob);
}

void login_new_copy(object ob)
{
    object body,*urs;
    if ( (file_size(user_path(ob->query("name")))!=-2) ) {
        urs = filter_array(users()+all_inventory(NETDEAD), "check_players", this_object());
        if( (sizeof(urs)>=options["MAX_USERS"]+extra) ) {
#ifndef OPEN_CHAT_ROOM
            write(FULL_MSG);
            ob->remove();
            return;
#else
               IS_CHAT_ROOM=1;
#endif
//		    if( (sizeof(all_inventory(IRC))>options["MAX_IRC_USERS"])&&!wizardp(ob))
//                {  write(FULL_MSG);
//			    ob->remove();
//			    return; }
        }
    }
    // Try restore our body object, reference to restore_body() in connection.c
    if( !ob->restore_body() ) {
        write(@TEXT

��ΪĳЩԭ��ϵͳ�޷���������������ϣ����� Email ֪ͨ��ʦ��

TEXT
        );
        ob->remove();
        return;
    }

    if( ob->connect() ) {
        body = ob->BODY_OB;

        body->delete("stop_heal");
        enter_world(ob);
    } else {
        write("��������ʧ��.....\n");
        ob->remove();
    }
}

void exec_old_copy(string s, object user)
{
    object tmp, link;

    if( member_array(s, ({ "y", "Y", "Yes", "yes" }) ) == -1 ) {

        // If not a wizard and neither a guest, login new copy
        if( !wizardp((object)user->BODY_OB) &&
            (string)user->query("name") != "guest") {
            write("�Ǿ�.... �´�������!\n");
            user->remove();
            return;
        }

//  If NEW_COPY is defined in /include/login.h, log the new copy entry.
#ifdef NEW_COPY
        log_file(NEW_COPY, capitalize((string)user->NAME) +
            " :\tNew copy from " + query_ip_name(user) + " [" +
            extract(ctime(time()),4,15) + "]\n");
#endif /* NEW_COPY */

        login_new_copy(user);
        return;
    }

    //  Old connection object
    if ( !user ) return ;
    link = user->BODY_OB->query_link();
    user->BODY_OB->set("ip",query_ip_name(user));

//  If FORCE_EXEC is defined in /include/login.h, log the new copy force.
#ifdef FORCE_EXEC
    log_file(FORCE_EXEC, capitalize((string)user->NAME) + " :\tForce exec " +
        "from " + query_ip_name(user) + " [ " +
        extract(ctime(time()),4,15) + "]\n");
#endif /* FORCE_EXEC */

    tell_object(user->BODY_OB,
        "\n���˴� " +
        query_ip_name(user) + " ȡ�����������.\n");
    tmp = new(OBJECT);

    //  Exec them into any old object
    exec(tmp, (object)user->BODY_OB);

    tmp->remove();

    if( user->connect() ) {
        write("�����������\n");
        ENTER_D->check_okip(user->BODY_OB);
    }
    else
        write("��������ʧ��.\n");

    link->remove();
    return;
}

protected void enter_world(object user)
{
    mixed *bad_pass, *bad_ip;
    string name;
    object player;

    seteuid(geteuid(user));
    player = user->BODY_OB;
    export_uid(player);
    seteuid(getuid());

    // if login failure by wrong passwd, Warn user.
    bad_pass = (mixed *)user->query("passwd_fail");
    if( bad_pass ) {
        tell_object( player,
            "\nWARNING: ����� " + ctime(bad_pass[1]) + " �� " + bad_pass[0] + " ��������ʧ�ܡ�\n");
        user->set("passwd_fail",0);
    }

    // if login failure by wrong IP, Warn user.
    bad_ip = (mixed *)player->query("okip_fail");
    if( bad_ip ) {
        tell_object(this_player(), "\nWARNING: Login failure " +
            ctime(bad_ip[1]) + " by OKIP check from\n" +
            "          IP address <" + bad_ip[0] + ">.\n\n");
        player->delete("okip_fail");
    } else tell_object(player, "\n");

    check_email(user);
    if (IS_CHAT_ROOM) {
        player->set_temp("chat_user",time());
        player->set_temp("be_sucked",1);
        player->set_temp("be_clawed",1);
        player->set_temp("be_hoofed",1);
    }
    player->setup();

    // Do some thing before enter ES, added by Kyoko.
    ENTER_D->check_okip(player);
    // Check for player wear mask or shapeshift , add by Ruby
    ENTER_D->check_make_up(player);
    // Check spouse to encourage couples group , add by Indra
    ENTER_D->check_spouse(player) ;
    // check consistency, added by Elon
    ENTER_D->check_stats(player);
    // Check for top player list, added by Annihilator.
    TOPPLAYER_D->log_player(player);
    write( "ĿǰȨ�ޣ�" + DOMAIN_D->query_domain_level(player) + "\n");

/*
    log_file("log_rec",extract(ctime(time()), 4, 18) +" : "+ player->query("name") +
         " as "+file_name(player)+"\n   �� " + query_ip_name(player)+
         " ���߽��붫������. \n\n");
*/
}

protected int check_password(string pass, object ob)
{
    string password;

    // Try to restore our connection object from saved file.
    if (!ob->restore()) {
        write("�޷������������ԭ.\n");
        ob->remove();
        return 0;
    }

    password = ob->PASS;
    if(password == crypt(pass, password))
        return 1;

    return 0;
}

// This function is called when a nnew name is entered, to confirm if a new
// character will be created.
protected void choice(string choice, object user, string name)
{
    int i;
    string pass;

    write("\n");

    if( !choice || choice=="" ) choice = "y";

    if( choice[0]=='N' || choice[0]=='n') {
        write("������������Ľ�ɫ����: ");
        input_to("get_name", 2, user);
        return;
    }

    if ( choice[0]!='y' && choice[0]!='Y' ) {
        write("������ \"y\" �� \"n\":[y] ");
        input_to("choice", user, name);
        return;
    }

//  If EMAIL_REGISTRATION has been defined in /include/login.h, check with
//  the banish daemon for a pre-registered name and password.
#ifdef EMAIL_REGISTRATION
    pass = BANISH_D->check_mailreg_name(name);
#else
    pass = "";
#endif

//  If REGISTER_MSG has been defined in /include/login.h, no new logins are
//  possible at this stage. REGISTER_MSG should be defined as the printed
//  message explaining why no unregistered users are being permitted.
#ifdef REGISTER_MSG
    if (!pass || !stringp(pass) || pass == "") {
        write(REGISTER_MSG);
        call_out("remove_copy", 1, user);
        return;
    }
#endif /* REGISTER_MSG */

//
//  move BANISH SITE to the first check when login
//

//  If BANISHED_NAMES has been defined in /include/login.h, check with
//  the banish daemon for use of a banished name.
#ifdef BANISHED_NAMES
    if( BANISH_D->check_banned_name(name) ) {
        write("��ΪĳЩԭ��, �㲻��ʹ���������\n\n" +
            LOGIN_PROMPT);
        input_to("get_name", 2, user);
        return;
    }
#endif /* BANISHED_NAMES */

#ifdef BANISHED_SITES
    //  Site banning code is from Dainia@DreamShadow
    //  Updated 7/13/93 by Karathan
    i = BANISH_D->check_banned_site(query_ip_name());
    if (i < 0) {
            write( IP_FAIL ) ;
            user->remove_user();
            return;
        }
        if (i > 0) {
            write( BANISH_REPORT ) ;
            user->remove_user();
            return;
        }
#endif /* BANISHED_SITES */


    seteuid(name);
    export_uid(user);
    seteuid(getuid());
    user->SET_NAME(name);
    NEWUSER_D->create_new_user(user, pass);
    return;
}

//  Check the user's email for new entries.
void check_email(object user)
{
    mapping mail_stat;
    int toread;

    mail_stat = (mapping) MAILER_D->mail_status(user->NAME);
    toread = mail_stat["unread"];
    if (toread)
        printf("\n���� %d ��δ�����ż�.\n\n", toread);
}

//  If online user display is selected, this function displays
//  all online, visible users to those in the login process.
string active_users(int irc)
{
    mixed *who;
    string output;
    int loop;
    NETDEAD = find_object_or_load("/d/std/rooms/netdead") ;
    who = filter_array(users()+all_inventory(NETDEAD), irc? "check_IRC_users":"check_players",
        this_object());
    who = filter_array(who, "filter_invis", this_object());

    if( !who || !sizeof(who) )
        return (!irc? "������������û��." : "����������û��.");

    who = map_array(who, "switch_name", this_object());
    who = uniq_array(who);
    if( sizeof(who) == 1 )
        output = who[0] + ".";
    else
        output = implode(who[0..sizeof(who)-2], ", ") + ", and " +
            who[sizeof(who)-1] + ".";

    if( !irc )
      return "Ŀǰ�����ϵ����: " + output + "\n����: " + sizeof(who) + " �����.  (���� : "+(options["MAX_USERS"]+extra)+" ��)";
    else
      return "Ŀǰ�������ҵ���: " + output + "\n����: " + sizeof(who) + " �����.";
}

protected int filter_invis(object who)
{
    if (!who || !environment(who))
        return 0;

    if ((int)who->query("npc"))
        return 0;

    return visible(who);
}

//  Switch user object pointer for name of user
protected string switch_name(object who)
{
    return capitalize((string)who->query("name"));
}

int check_players(object user)
{
    if ( !user->query("user") ) return 0;
    if( !environment(user)
    || user->query_temp("IRC_USER")
    || wizardp(user))
        return 0;
    return 1;
}

int check_IRC_users(object user)
{
    if( !environment(user)
    ||  !interactive(user)
    ||  !user->query_temp("IRC_USER"))
        return 0;
    return 1;
}

mixed query_options(string term)
{
    return options[term];
}
