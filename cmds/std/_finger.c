// _finger.c
// Written by Huthar. (NOT! By Wayfarer actually!)
// Funny guys, aren't they? Apparently Wayfarer is the real author.
// Robocoder and Mobydick tweaked it on 3-24-93 so that commands of the
// form "finger mobydick robocoder" would finger each user.
// @Eastern.Stories
// Some people modified this file a bit. dunno when.
// 12-23-94: Elon edited this to reflect the changes made in finger daemon.////#pragma save_binary
 
#include <daemons.h>
#include <net/daemons.h>
#include <mudlib.h>
 
inherit DAEMON;
 
mapping requests;
 
void remote_finger(object me, string target, string mud);
 
int cmd_finger(string str)
{
    int wizard;
	object ob;
	string tmp1,tmp2,tmp3,tmp4;
 
    wizard = wizardp( this_player() );
	if(!str) {
	  if( wizard )
        write(FINGER_D->finger_all(1));
	  else 
        write(FINGER_D->finger_all(0));
	  return 1;
	}
  
	while (sscanf(str, "%s %s", tmp1, tmp2)) {
		if(sscanf(tmp1,"%s@%s",tmp3,tmp4)) {
			if (tmp4 == mud_name()) {
				if(!tmp3 || tmp3 == "")
				  if( wizard )
                    write(FINGER_D->finger_all(1));
			      else
                    write(FINGER_D->finger_all(0));
				else
				  if( wizard )
                    write((string)FINGER_D->finger_user(lower_case(tmp3),1));
			      else
                    write((string)FINGER_D->finger_user(lower_case(tmp3),0));
			} else {
				if (!tmp3) tmp3 = "" ;
				  FINGER_SERVER->remote_finger(this_player(), tmp3, tmp4);
			}
		} else if(tmp1 && tmp1 != "")
		  if( wizard )
            write((string)FINGER_D->finger_user(lower_case(tmp1),1));
		  else
            write((string)FINGER_D->finger_user(lower_case(tmp1),0));
		str = tmp2;
	}
	if (sscanf(str,"%s@%s",tmp3,tmp4)) {
		if(tmp4 == mud_name()) {
			if(!tmp3 || tmp3 =="")
			  if( wizard )
                write(FINGER_D->finger_all(1));
		      else
                write(FINGER_D->finger_all(0));
			else
			  if( wizard )
                write((string)FINGER_D->finger_user(lower_case(tmp3), 1));
			  else
                write((string)FINGER_D->finger_user(lower_case(tmp3), 0));
		} else {
			if (!tmp3) tmp3 = "" ;
			FINGER_SERVER->remote_finger(this_player(), tmp3, tmp4);
		}
	} else
	  if( wizard )
        write((string)FINGER_D->finger_user(lower_case(str), 1));
	  else
        write((string)FINGER_D->finger_user(lower_case(str), 0));
	return 1;
}
 
int help()
{
    write(@HELP
指令格式: finger [玩家]
 
您可以用这个指令来看一个玩家的一些资料。包括他的姓名，权限等级，Email帐号
与上线时间，年龄，邮件，计画和其他相关资料等等。
 
如果没有指定玩家姓名, 则会列出所有在线上玩家的中, 英文姓名及相关资料.
 
HELP
    );
    return 1;
}
 
void create()
{
	seteuid(getuid());
}
