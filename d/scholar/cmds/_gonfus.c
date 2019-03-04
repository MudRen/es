//#pragma save_binary

// This command is for scholar only. It list all gonfus now the scholar
// has learned. Created by Kyoko@Eastern.Stories.

#include <mudlib.h>

inherit DAEMON;

int cmd_gonfus(string str)
{
	int i;
	string *gonfu, msg;
	mapping known,exp;

	known = (mapping)this_player()->query("scholar_gonfu");
        exp = (mapping)this_player()->query("gonfus_exp");
	if( !known || sizeof(known) == 0 ) {
		write("��Ŀǰ�����κι�\��\n");
		return 1;
	}

	msg = "��Ŀǰ����ʹ�õĹ�\����:\n" ;

	gonfu = keys(known);
	for( i=0; i<sizeof(gonfu); i++ )
		msg += sprintf(" %s(%s) [%d] (��������ֵ%d)\n", to_chinese(gonfu[i]),
		gonfu[i], known[gonfu[i]], (exp ? exp[gonfu[i]]:0) );
	write(msg);
	return 1;
}

int help()
{
	write( @HELP
Usage: gonfus

The gonfus command will list the names of all the gonfus you know.
See also: enhant.
HELP
	      );
	return 1;
}
