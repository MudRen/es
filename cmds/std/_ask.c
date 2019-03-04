//#pragma save_binary

#include <mudlib.h>
inherit DAEMON;

int cmd_ask(string str)
{
	string mon_name, subject, func;
	object mon_obj;
	mapping cmd_map;

	if (!str)
		return notify_fail(
			"Ҫ�ʷ������������⣬���� \"ask <˭> about <�ؼ���>\"��\n");

	if (sscanf(str, "%s about %s", mon_name, subject) != 2)
		return notify_fail( 
			"Ҫ�ʷ������������⣬���� \"ask <˭> about <�ؼ���>\"��\n");

	mon_name = lower_case(mon_name);

	if( !(mon_obj= present(mon_name, environment(this_player()))) )
		return notify_fail( 
			"��Ҫ�ʵĶ��󲢲������\n");

	if (mon_obj->query("user")) {
		write( 
			"����"+ mon_obj->query("c_name") + "ѯ���й� "+subject+" ���¡�\n");

		tell_object( mon_obj,
			this_player()->query("c_name")+"����: ֪��֪���й� "+subject+" ����Ϣ��\n");
		return 1 ;
	}

	cmd_map = ([ ]);
	cmd_map = mon_obj->query("inquiry");

	if (sizeof(cmd_map)==0) {
		write( 
			mon_obj->query("c_name")+"���������û���κη�Ӧ....��\n");
		return 1 ;
	}
	if( undefinedp(cmd_map[subject]) ) {
		tell_room(environment(this_player()), 
			this_player()-> query("c_name") + "��" + mon_obj->query("c_name")
			+ "�����й� " + subject + " ����Ϣ��\n",
			this_player() );
		tell_room( environment(this_player()), 
			mon_obj->query("c_name") + "ҡҡͷ��˵��: " + "�Ҳ�֪��....��\n" );
	} else {
		tell_room(environment(this_player()), 
			this_player()-> query("c_name") + "��" + mon_obj->query("c_name")
			+ "�����й� " + subject + " ����Ϣ��\n",
			this_player() );
		if( stringp(cmd_map[subject]) && sscanf( cmd_map[subject], "@@%s", func )==1 )
			call_other( mon_obj, func, this_player() );
		else {
			if( pointerp(cmd_map[subject]) )
				tell_room(environment(this_player()), 
					mon_obj->query("c_name") + "˵��: " + cmd_map[subject][0] + "\n",
					mon_obj );
			else
				tell_room(environment(this_player()), 
					mon_obj->query("c_name") + "˵��: " + cmd_map[subject] + "\n",
					mon_obj );
		}
	}
	return 1;
}
int help()
{
	write(@HELP
ʹ�ø�ʽ: ask <������> about <����>

������npc��̸�����յı�׼ָ��.
������Щ������Ҫ����say��tellָ���npc˵�ؼ��ֲ��ܴ������.

HELP
);
	return 1;
}