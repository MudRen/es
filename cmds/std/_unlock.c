//#pragma save_binary

//	File	:  /cmds/std/_unlock.c
//	Creator	:  Mobydick@TMI (probably)
//	Rewrite	:  Watcher@TMI  (4/13/93)
//
//	This is the standard open command for doors. The object open
//	command is handled by the objects themselves.

#include <mudlib.h>

inherit DAEMON ;

int cmd_unlock (string str)
{
	mapping doors;
	mixed *all_keys;
	object key, env;
	string *tmp, dir, key_name;
	int i;

	if( !str || str == "")
		return notify_fail("你要开什麽锁？\n");

	env = environment(this_player());

	if(!env) return 0;

	//	Get the door mapping from the environment.
	doors = env->query("doors");

	if(!doors)
		return notify_fail("这里没有上锁的门。\n");

	dir = env->query_door(str);
	if( !dir )
		return notify_fail("你要开什麽锁？\n");

	all_keys = filter_array( all_inventory(this_player()), "find_keys", this_object());
	if( !all_keys || sizeof(all_keys) < 1 )
		return notify_fail("你身上没有任何钥匙。\n");

	//	Get array of existing door directions.
	tmp = keys( doors );

	//  Check to see if the user can actually see.
	if(!this_player()->query("vision")) {
		write("你在黑暗中摸索门的钥匙孔....\n");
		dir = tmp[ random(sizeof(tmp)) ];
	}

	//	Check to see if the door actually has a unlock.
	if( !doors[dir]["lock"] || doors[dir]["lock"] == "none" )
		return notify_fail("你在上面并没有发现任何钥匙孔。\n");

	//	Now check and see if the door is actually locked.
	if(doors[dir]["status"] == "open" || doors[dir]["status"] == "closed")
		return notify_fail(doors[dir]["c_name"] + "并没有锁著。\n");

	//	See if the key fits, or is a skeleton key.
	for( i=0; i<sizeof(all_keys); i++ )
		if( (string)all_keys[i]->query("to_lock") == doors[dir]["lock"] ) {
			key = all_keys[i];
			break;
		}

	if( !key )
		return notify_fail("你试过身上所有的钥匙，但仍然打不开。\n");

	//	Okay...unlock the door, and update its linked mirror lock.
	env->set_status(dir, "closed");
	env->update_link(dir);

	write( "你用" + key->query("short") + "把" + doors[dir]["c_name"] + "上的锁打开。\n");
	tell_room( env,
		(string)this_player()->query("c_name") + "用钥匙打开" + doors[dir]["c_name"] + "上的锁。\n",
		this_player() );

	return 1;
}

protected int find_keys(object obj) {  return (int)obj->id("key");  }

int help() {
	write( @C_LONG
Syntax: unlock [object] with [optional desc] key

这个命令可以让你试著用身上的所有钥匙去试门上的锁。但是请注意，
不是所有的钥匙都有个钥匙孔 ....
C_LONG
);
	return 1;
}
