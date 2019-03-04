//#pragma save_binary

// wizcall.c
// This command will send a message to all logged-in wizards. Invisible
// wizards will be notified: hidden ones will not.
// This command is intended to allow players to call for wizard assistance
// if they are caught in dead-end traps or other situations they aren't
// expected to cope with themselves. Any other use is misuse, and admins
// should be clear about that in the help files.
// Written by Mobydick@TMI-2, 11-14-92

#include <mudlib.h>

inherit DAEMON ;

int help() ;
int cmd_wizcall(string str) {

	object *usrs ;
	int i, flag ;
	string message ;

	if (wizardp(this_player())) {
		notify_fail ("Players only, please.\n") ;
		return 0 ;
	}
	if (!str) {
		return help() ;
	}
	message = capitalize((string)this_player()->query("name"))+" calls: "+str+"\n" ;
	usrs = users() ;
	for (i=0;i<sizeof(usrs);i++) {
		if (!wizardp(usrs[i])) continue ;
		tell_object(usrs[i],message) ;
		flag = 1 ;
	}
	if (flag==0) {
		write ("There are no wizards logged on at the moment.\n") ;
 	}
	return 1 ;
}
int
help() {
  write(@HELP
ָ���ʽ: wizcall <��Ϣ>

����ָ��������㷢��һ����Ϣ��ȫ�����ߵ�wiz��
����bug�������������ô�ָ������ô�ָ����wiz�ʲ���bug������.

HELP
);
  return 1;
}