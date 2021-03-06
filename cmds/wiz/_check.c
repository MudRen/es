//#pragma save_binary
// command for check object's memory size.
// Ruby@Eastern.Stories add it for mudlib 0.9 in '94/12/17.

#include <mudlib.h>

inherit DAEMON ;

int help();

int output(object *inv)
{
	int i ;
	for ( i = 0 ; i < sizeof(inv) ; i ++ ) {
		if ( ! inv[i] ) continue ;
		write(sprintf("%s(%s) 占 %d bytes .\n",
			inv[i]->query("short"),inv[i]->query("name"),
			memory_info(inv[i]))
		      );
	}
	return 1;
}

int cmd_check(string str) 
{ 
	int i;
	object *inv,ob,ob2;

	if ( !str ) return help();

	inv = ({ });

	if ( str == "here" ) 
		inv = ({ environment(this_player()) });
	else if ( str == "me" ) 
		inv = ({ this_player() });

	if ( sizeof(inv) ) return output(inv); 

	if ( str != "all" ) {
		if ( !(ob = present(str,environment(this_player()))) &&
		     !(ob2 = present(str,this_player())) ) {
			write("这里没有叫做 "+str+" 的东西。\n");
			return 1;
		}
		else {
			inv = ({ ob }) + ({ ob2 }) ;
			return output(inv);
		}
	}
	inv = all_inventory(this_player())+all_inventory(environment(this_player()));
		return output(inv);
}

int help() {
	write (@HELP
Usage : check <object name> , me ,here , all

    这个命令是用来检查物品所耗掉的记忆体，每个巫师在制作物品之後，
都应该详细检查，以避免做出记忆体杀手。这个命令只对自己身上和同一房
间内的物品有效。

    标准的记忆体耗用情况如下 :
	1. 房间 :	1 K 左右。
	2. 物件 :	1 K 以下。
	3. 生物 :	2-3 K 。

HELP
	       );
	return 1 ;
}
