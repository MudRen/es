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
		write( "���趨�� "+sizeof(tmp)+" �����ָ��:\n");
		tmp = sort_array(tmp, "sort_keys", this_object());
 
		for(i = 0; i < sizeof(tmp); i++)
			printf("  %-10s = %s\n", tmp[i], n[tmp[i]]);
	} 
	tmp = keys(x);
	if(sizeof(tmp)) {
		write( "�� "+sizeof(tmp)+" �������:\n");
		tmp = sort_array(tmp, "sort_keys", this_object());
 
		for(i = 0; i < sizeof(tmp); i++)
			printf("	%-15s %s\n",tmp[i],x[tmp[i]]);
	}
	else if( !sizeof(keys(n)) )  
		write("��Ŀǰû���趨�κ����ָ�\n");
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
�Բ���, Ϊ������ ES ���ٶ�, alias ���ֻ���趨 40 ��....
�� alias ����Ŀ̫���Ѿ��� reset ��, �������趨��
SORRY
);
		act_ob->clear_aliases();
		return 1;
	}
	
	if(!str) {
		if(!elements || !sizeof(elements) )
			write("��Ŀǰû�ж����κ����ָ�\n");
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
			return notify_fail("�����ָ��һ�����ʸ����ָ�\n");

		if((verb=="alias") || (verb=="unalias") || (verb=="go") )
			return notify_fail (sprintf("�㲻���� %s ����ֵ����ʡ�\n",verb));

		if((sscanf(cmd,"%s,"+verb+",%s",tmp1,tmp2)==2) ||
		   (sscanf(cmd,"do "+verb+",%s",tmp1)==1) ||
		   ((sscanf(cmd,"%s,"+verb+"%s",tmp1,tmp2)==2) && tmp2=="") )
			return notify_fail("�㲻�ܰ���ͬ������ŵ����ָ���� !!\n");

		if(environment(this_player())) { // it's probably not a new player
			// Players demand this .... by Annihilator@Eastern.Stories (12-26-93)
			if( strsrch(cmd, '$')==-1 ) cmd += " $*";
			if( !alias[verb] )
				// set Max alias number, added by Kyoko.
				if( sizeof(elements) < MAX_ALIAS_NUMBER ) 
				  write( 
					"�����µ����ָ�� "+verb+" ( ��� "+cmd+" ) .... OK.\n");
				else {
				  write( 
					"���Ѿ��趨̫������ָ����, ����ɱ��һЩ��\n");
				  return 1;
				}
			else
			     if(strlen(cmd)>MAX_ALIAS_SIZE)
			       {  write("������ָ��ȴ������ֵ,�������Ķ�һ�㡣\n") ;
			          return 1;
			       }
			     else
				  write("�޸ľ������ָ�� "+verb+" ( ��Ϊ "+cmd+" ) .... OK.\n");
		}
		act_ob->add_alias(verb,cmd);
		return 1;
	}

	if(!alias[str]) {
		write(
			"�㲢û���趨 \""+str+"\" ������ָ�\n");
		return 1;
	}

	printf("%-15s%s\n",str,alias[str]);
	return 1;
}

static int sort_keys(string a, string b) {  return strcmp(a, b);  }

void help()
{
write(@HELP
һ�����: -clear  ɾ��ȫ������.

alias			�鿴ȫ������.
alias <alias> <command>	����<alias>��<command>.
alias <alias>		��鶨��<alias>.
unalias <alias>		ɾ������<alias>.

���滻�ı���:
	$# - ������ֻ�����.
	$* - ����κ��¼�.

HELP
);
}

