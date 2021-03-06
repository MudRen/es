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
		return notify_fail("你要关上什麽？\n");

	if( str != "door" && !(dir=environment(this_player())->query_door(str))
	&& sscanf(str, "%s door", dir) != 1 )
		return notify_fail( 
			"你要关上什麽？\n");

	env = environment(this_player()) ;
	if (!env)
		return notify_fail( 
			"这里什麽也没有，你要关上什麽？\n");

	doors = env->query("doors");
	if (!doors)
		return notify_fail( 
			"这里没有门....。\n");
 
	tmp = keys( doors );
 
	//  If the player can't see ... pick a random door. <grin>
	if(!this_player()->query("vision")) {
		write( 
			"你在黑暗中摸索，找门....。\n");
		dir = tmp[ random(sizeof(tmp)) ];
	}
 
	if(!dir) {
		if(sizeof(doors) > 1)
			return notify_fail(
				"这里的门不只一个，你要关哪一个？\n");

		dir = tmp[0];
	}
	if (!doors[dir])
		notify_fail( 
			"那个方向没有门。\n");

	if (doors[dir]["status"]!="open")
		return notify_fail( 
			"它已经是关著的了。\n");

	env->set_status(dir,"closed");
	env->update_link(dir);
	write(
		"你把" + doors[dir]["c_name"] + "关上。\n");

	tell_room( env, 
		this_player()->query("c_name")+"把" + doors[dir]["c_name"] + "关上。\n" ,
		this_player() );
	return 1 ;
}

int help()
{
  write( @HELP
使用格式: close <方向> door

关闭<方向>的门.
HELP
);
  return 1;
}
