//#pragma save_binary

// This command is for scholar only. It list all embattle now the scholar
// has learned. Created by Oldcat@Eastern.Stories.

#include <mudlib.h>

inherit DAEMON;

int help();

int cmd_embattles(string str)
{
	int i;
	string *embat, str1, msg;
	mapping known;

	known = (mapping)this_player()->query("embattle");
	if( !known || sizeof(known) == 0 ) {
		write("��Ŀǰ�����κ��󷨡�\n");
		return 1;
	}

	msg = "��Ŀǰ����ʹ�õ�����:\n" ;

	embat = keys(known);
	for( i=0; i<sizeof(embat); i++ ) {
          switch (embat[i]) {
          case "two" : str1="����΢����";
               break;
          case "three" : str1="�����������";
               break;
          case "four" : str1="���������";
               break;
          case "eight" : str1="����������";
               break;
          default :
               break;
          };
	  msg += sprintf("  %s(%s)\n", str1, embat[i]);
        }
	write(msg);
	return 1;
}

int help()
{
	write( @HELP
Usage: embattles

���ָ����԰�����ѧ�������г�����
See also: embattle.
HELP
	      );
	return 1;
}
