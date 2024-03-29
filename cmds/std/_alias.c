//#pragma save_binary

/*
 * alias user command
 * this is from portals
 * One of them wrote it, again.
 * In the course of time it grew into part of the TMI-2 mudlib, via the
 * old TMI mudlib. In any event, you should leave this header on. Moby
 * added it in 4-9-93.
 */

#include <alias.h>
#include <mudlib.h>
#include <body.h>

inherit DAEMON;

void print_aliases(mapping n, mapping x)
{
	int i;
	string *tmp;

	tmp = keys(n);
	if(sizeof(tmp)) {
		write( "您设定了 "+sizeof(tmp)+" 个替代指令:\n");
		tmp = sort_array(tmp, "sort_keys", this_object());

		for(i = 0; i < sizeof(tmp); i++)
			printf("  %-10s = %s\n", tmp[i], n[tmp[i]]);
	}
	tmp = keys(x);
	if(sizeof(tmp)) {
		write( "和 "+sizeof(tmp)+" 替代动词:\n");
		tmp = sort_array(tmp, "sort_keys", this_object());

		for(i = 0; i < sizeof(tmp); i++)
			printf("	%-15s %s\n",tmp[i],x[tmp[i]]);
	}
	else if( !sizeof(keys(n)) )
		write("您目前没有设定任何替代指令。\n");
}

int cmd_alias(string str)
{
	int i, sl;
	int index;
	string verb,cmd,*elements,tmp1,tmp2;
	mapping alias;
	object act_ob;

	act_ob = previous_object();

	if(str == "-global") {
		print_aliases((mapping)GA_SERVER->query_global_aliases(),
			(mapping)GA_SERVER->query_global_xaliases());
		return 1;
	}

	if(str == "-clear") {
		act_ob->clear_aliases();
		return 1;
	}

	alias = (mapping)act_ob->query_aliases();
	if(!alias) alias = ([]);
	// reset alias table if too many, added by Kyoko.
 	elements = keys(alias);
	if( sizeof(elements) > MAX_ALIAS_NUMBER ) {
		write( @SORRY
对不起, 为了增快 ES 的速度, alias 最多只能设定 40 个....
你 alias 的数目太多已经被 reset 了, 请重新设定。
SORRY
);
		act_ob->clear_aliases();
		return 1;
	}

	if(!str) {
		if(!elements || !sizeof(elements) )
			write("你目前没有定义任何替代指令。\n");
		else
			print_aliases((mapping)act_ob->query_nalias(),
						  (mapping)act_ob->query_xalias()
			);
		return 1;
	}

	//  Strip out the leading spaces in the command request
	while(str[0] == ' ') str = str[1..strlen(str)-1];
	if(sscanf(str,"%s %s", verb, cmd) == 2) {
		if (!verb || verb == "" || verb == " ")
			return notify_fail("你必须指定一个动词给替代指令。\n");

		if((verb=="alias") || (verb=="unalias") || (verb=="go") )
			return notify_fail (sprintf("你不能用 %s 这个字当动词。\n",verb));

		if((sscanf(cmd,"%s,"+verb+",%s",tmp1,tmp2)==2) ||
		   (sscanf(cmd,"do "+verb+",%s",tmp1)==1) ||
		   ((sscanf(cmd,"%s,"+verb+"%s",tmp1,tmp2)==2) && tmp2=="") )
			return notify_fail("你不能把相同的命令放到替代指令中 !!\n");

		if(environment(this_player())) { // it's probably not a new player
			// Players demand this .... by Annihilator@Eastern.Stories (12-26-93)
			if( strsrch(cmd, '$')==-1 ) cmd += " $*";
			if( !alias[verb] )
				// set Max alias number, added by Kyoko.
				if( sizeof(elements) < MAX_ALIAS_NUMBER )
				  write(
					"加入新的替代指令 "+verb+" ( 替代 "+cmd+" ) .... OK.\n");
				else {
				  write(
					"你已经设定太多的替代指令了, 请先杀掉一些。\n");
				  return 1;
				}
			else
			     if(strlen(cmd)>MAX_ALIAS_SIZE)
			       {  write("你的替代指令长度大於容许值,请试著改短一点。\n") ;
			          return 1;
			       }
			     else
				  write("修改旧有替代指令 "+verb+" ( 改为 "+cmd+" ) .... OK.\n");
		}
		act_ob->add_alias(verb,cmd);
		return 1;
	}

	if(!alias[str]) {
		write(
			"你并没有设定 \""+str+"\" 这个替代指令。\n");
		return 1;
	}

	printf("%-15s%s\n",str,alias[str]);
	return 1;
}

protected int sort_keys(string a, string b) {  return strcmp(a, b);  }

void help()
{
write(@HELP
一般参数: -clear  删除全部定义.

alias			查看全部定义.
alias <alias> <command>	定义<alias>是<command>.
alias <alias>		检查定义<alias>.
unalias <alias>		删除定义<alias>.

可替换的变量:
	$# - 替代数字或文字.
	$* - 替代任何事件.

HELP
);
}
