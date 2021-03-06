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
		write("你目前不会任何阵法。\n");
		return 1;
	}

	msg = "你目前所能使用的阵法有:\n" ;

	embat = keys(known);
	for( i=0; i<sizeof(embat); i++ ) {
          switch (embat[i]) {
          case "two" : str1="两仪微尘阵";
               break;
          case "three" : str1="天地人三才阵";
               break;
          case "four" : str1="四象璇玑阵";
               break;
          case "eight" : str1="八卦游龙阵";
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

这个指令可以把你所学过的阵法列出来。
See also: embattle.
HELP
	      );
	return 1;
}
