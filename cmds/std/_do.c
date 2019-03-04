//#pragma save_binary
 
//	File	:  /cmds/std/_do.c
//	Creator	:  Watcher@TMI  (02/07/93)
//
//	This command allows command line parsing to use multiple
//	commands separated by the preset command separator.
 
#include <mudlib.h>
 
inherit DAEMON; 
 
#define DIVIDER	","
#define SYNTAX	"Syntax: do [cmd1" + DIVIDER + "cmd2" + DIVIDER + \
		"...]\n"
 
int cmd_do(string str) {
   string *cmds, what;
   int loop, num, count,brief;
	object me;
 
   notify_fail( SYNTAX );
 
   if(!str || str == "")  return 0;
 
   //	Remove all space from the command line
 
   str = replace_string(str, DIVIDER + " ", DIVIDER);
 
   //	Parse the command line into its individual commands
	me =this_player();
   cmds = explode(str, DIVIDER);

   //	Loop through and initiate the commands in order
   for(loop=0; loop<sizeof(cmds); loop++) {
   //	If multiple single commands are requested... ie: 5 smile
 
        if ((strsrch(cmds[loop],"!!",0)!=-1)||(strsrch(cmds[loop],"!d",0)!=-1)){
            tell_object(me,"do �ﲻ����!! or !d ��\n");
             return 1;
        }
	if(sscanf(cmds[loop], "%d %s", num, what) == 2) {
		if ( num > 10 ) {
			tell_object(me,"�ظ�ָ����������Գ��� 10 ��.\n");
			return 1;
		}
		what = me->parse_arg(what);

   		for(count=0; count<num; count++) 
			if ( !me->push_cmd(what)) return 1;

   	} else  //	Else do the single command portion
		me->push_cmd( me->parse_arg(cmds[loop]) );
   }
	return 1; 
}
int
help() {
  write(@HELP
ָ���ʽ: do <����ָ��>

����ָ������������ͬһʱ��ִ�ж���ָ��.

����do get sword,wield sword,kill balrog
    (������װ����kill brlrog)

HELP
);
  return 1;
}
