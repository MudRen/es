//#pragma save_binary

//	File	:  /cmds/std/_lock.c
//	Creator	:  Mobydick@TMI (probably)
//	Rewrite	:  Watcher@TMI  (4/13/93)
//
//	This is the standard open command for doors. The object open
//	command is handled by the objects themselves.

#include <mudlib.h>

inherit DAEMON ;

int cmd_lock (string str)
{
	mapping doors;
	mixed *all_keys;
	object key, env;
	string *tmp, dir, key_name;
	int i;

	if( !str || str == "" )
		return notify_fail( "你要锁上哪一个门？\n");

	env = environment(this_player());

	if(!env) return 0;
	dir = env->query_door(str);
	if( !dir ) return notify_fail("你要锁上哪一个门？\n");

	//	Get the door mapping from the environment.
	doors = env->query("doors");

	if(!doors)
		return notify_fail("这里没有门可以锁....\n");

	//	Check to see if we have the key.
	all_keys = filter_array(all_inventory(this_player()), "find_keys",
		this_object());

	if( !all_keys || sizeof(all_keys) < 1 )
		return notify_fail("你身上没有任何钥匙。\n");

	//	Get array of existing door directions.
	tmp = keys( doors );

	//  Check to see if the user can actually see.
	if(!this_player()->query("vision")) {
		write("你在黑暗中摸索找钥匙孔....\n");
		dir = tmp[ random(sizeof(tmp)) ];
	}

	if(!doors[dir])
		return notify_fail("你要锁上哪一个门？\n");

	//	Check to see if the door actually has a lock.
	if(!doors[dir]["lock"] || doors[dir]["lock"] == "none")
		return notify_fail(doors[dir]["c_name"] + "上没有钥匙孔。\n");

	//	Now check and see if the door is actually unlocked.
	if(doors[dir]["status"] == "locked")
		return notify_fail(doors[dir]["c_name"] + "已经锁上了。\n");

	//	Hmmm...make sure the door is closed, too.

	if(doors[dir]["status"] == "open")
		return notify_fail("你必须先将" + doors[dir]["c_name"] + "关上。\n");

	//	See if the key fits.
	for( i=0; i<sizeof(all_keys); i++ )
		if( (string)all_keys[i]->query("to_lock") == doors[dir]["lock"] ) {
			key = all_keys[i];
			break;
		}

	if( !key )
		return notify_fail(
			"你试过身上所有的钥匙，但是没有一把能将" + doors[dir]["c_name"] + "锁上。\n");

	//	Okay...lock the door, and update its linked mirror lock.

	env->set_status(dir, "locked");
	env->update_link(dir);

	write("你用" + key->query("short") + "把" + doors[dir]["c_name"] + "锁上。\n");
	tell_room( env,
		(string)this_player()->query("c_name") + "把" + doors[dir]["name"] + "锁上。\n",
		this_player() );

	return 1;
}

protected int find_keys(object obj) {  return (int)obj->id("key");  }

int help() {

	write( @C_HELP
Syntax: lock [object] with [optional desc] key

这个命令可以让你用特定的钥匙把门锁上，当然，你必须先找到钥匙。
C_HELP
);
return 1; }
