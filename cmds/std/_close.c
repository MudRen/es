//#pragma save_binary

// _close.c
// Command to let players close doors.
// Written by Mobydick@TMI-2, 1-8-93.
// Based on an earlier version by Rusty@TMI-2.
// Closing containers is handled by an add_action in the container and not
// by this command.
// Help added by Pallando (93-02-14)
// Watcher improved the door handling a bit, 03-28-93.
// Watcher added vision checks, 04-13-93.

#include <mudlib.h>

inherit DAEMON ;

int cmd_close (string str)
{
	string dir, *tmp;
	object env ;
	mapping doors ;

	if (!str || str == "")
		return notify_fail("��Ҫ����ʲ�᣿\n");

	if( str != "door" && !(dir=environment(this_player())->query_door(str))
	&& sscanf(str, "%s door", dir) != 1 )
		return notify_fail( 
			"��Ҫ����ʲ�᣿\n");

	env = environment(this_player()) ;
	if (!env)
		return notify_fail( 
			"����ʲ��Ҳû�У���Ҫ����ʲ�᣿\n");

	doors = env->query("doors");
	if (!doors)
		return notify_fail( 
			"����û����....��\n");
 
	tmp = keys( doors );
 
	//  If the player can't see ... pick a random door. <grin>
	if(!this_player()->query("vision")) {
		write( 
			"���ںڰ�������������....��\n");
		dir = tmp[ random(sizeof(tmp)) ];
	}
 
	if(!dir) {
		if(sizeof(doors) > 1)
			return notify_fail(
				"������Ų�ֻһ������Ҫ����һ����\n");

		dir = tmp[0];
	}
	if (!doors[dir])
		notify_fail( 
			"�Ǹ�����û���š�\n");

	if (doors[dir]["status"]!="open")
		return notify_fail( 
			"���Ѿ��ǹ������ˡ�\n");

	env->set_status(dir,"closed");
	env->update_link(dir);
	write(
		"���" + doors[dir]["c_name"] + "���ϡ�\n");

	tell_room( env, 
		this_player()->query("c_name")+"��" + doors[dir]["c_name"] + "���ϡ�\n" ,
		this_player() );
	return 1 ;
}

int help()
{
  write( @HELP
ʹ�ø�ʽ: close <����> door

�ر�<����>����.
HELP
);
  return 1;
}
