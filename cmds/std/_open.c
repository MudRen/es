//#pragma save_binary

// open.c
// Lets players open doors.
// Written by Mobydick@TMI-2, 1-8-93.
// Based on an earlier version by Rusty@TMI-2.
// Opening containers is handled by an add_action in the container, not by
// this command.
// Updated by Watcher@TMI-2 (03/28/93) to handle "open door".
// Watcher@TMI added vision checks (04/13/93).

#include <mudlib.h>

inherit DAEMON ;

int cmd_open (string str)
{
	string dir, *tmp;
	object env ;
	mapping doors ;

	if(!str || ( str!="door" && !(dir=environment(this_player())->query_door(str)) 
	&& sscanf(str,"%s door", dir) != 1))
		return notify_fail( 
			"��Ҫ�����ᶫ����\n");

	env = environment(this_player());
	if (!env)
		return notify_fail( 
			"��������Ҳû�У���Ҫ�����ᶫ����\n");

	doors = env->query("doors") ;
 
	if (!doors)
		return notify_fail( 
			"����û����....��\n");
 
	tmp = keys( doors );
 
	if(str == "door") {
		if(sizeof(doors) > 1)
			return notify_fail( 
				"������Ų�ֻһ������Ҫ����һ����\n");

		dir = tmp[0];
	}
 
	//  If the user can't see ... then pick a random door. <grin>
	if(!this_player()->query("vision"))  {
		write( 
			"���ںڰ�������������....��\n");
		dir = tmp[ random(sizeof(tmp)) ];
	}
 
	if (!doors[dir])
		return notify_fail(
			"�������û����....��\n");

	if (doors[dir]["status"]=="open")
		return notify_fail( 
			"���Ѿ������ˡ�\n");

	if (doors[dir]["status"]=="locked")
		return notify_fail( 
			"��....�򲻿����������ס�ˡ�\n");

	env->set_status(dir, "open");
	env->update_link(dir);
	printf( "���%s�򿪡�\n", doors[dir]["c_name"] );

	tell_room( env, 
		this_player()->query("c_name")+"����"+ doors[dir]["c_name"] + ".\n" ,
		this_player()
	);
	return 1 ;
}

int help() {
	write (@HELP
ʹ�ø�ʽ: open <����> door  -or-  open <����>

���ָ����Դ򿪹رյ��Ż�����������������û�����ϵ�.

���ָ��: get, put, close, lock, unlock.
HELP
	) ;
	return 1 ;
}
