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
		write(sprintf("%s(%s) ռ %d bytes .\n",
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
			write("����û�н��� "+str+" �Ķ�����\n");
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

    ������������������Ʒ���ĵ��ļ����壬ÿ����ʦ��������Ʒ֮�ᣬ
��Ӧ����ϸ��飬�Ա�������������ɱ�֡��������ֻ���Լ����Ϻ�ͬһ��
���ڵ���Ʒ��Ч��

    ��׼�ļ��������������� :
	1. ���� :	1 K ���ҡ�
	2. ��� :	1 K ���¡�
	3. ���� :	2-3 K ��

HELP
	       );
	return 1 ;
}
