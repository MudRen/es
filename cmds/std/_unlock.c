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
		return notify_fail("��Ҫ��ʲ������\n");
 
	env = environment(this_player());
 
	if(!env) return 0;
 
	//	Get the door mapping from the environment.
	doors = env->query("doors");
 
	if(!doors)
		return notify_fail("����û���������š�\n");

	dir = env->query_door(str);
	if( !dir )
		return notify_fail("��Ҫ��ʲ������\n");

	all_keys = filter_array( all_inventory(this_player()), "find_keys", this_object());
	if( !all_keys || sizeof(all_keys) < 1 )
		return notify_fail("������û���κ�Կ�ס�\n");
	
	//	Get array of existing door directions.
	tmp = keys( doors );
 
	//  Check to see if the user can actually see.
	if(!this_player()->query("vision")) {
		write("���ںڰ��������ŵ�Կ�׿�....\n");
		dir = tmp[ random(sizeof(tmp)) ];
	}
 
	//	Check to see if the door actually has a unlock.
	if( !doors[dir]["lock"] || doors[dir]["lock"] == "none" )
		return notify_fail("�������沢û�з����κ�Կ�׿ס�\n");
 
	//	Now check and see if the door is actually locked.
	if(doors[dir]["status"] == "open" || doors[dir]["status"] == "closed")
		return notify_fail(doors[dir]["c_name"] + "��û��������\n");
 
	//	See if the key fits, or is a skeleton key.
	for( i=0; i<sizeof(all_keys); i++ )
		if( (string)all_keys[i]->query("to_lock") == doors[dir]["lock"] ) {
			key = all_keys[i];
			break;
		}

	if( !key )
		return notify_fail("���Թ��������е�Կ�ף�����Ȼ�򲻿���\n");
 
	//	Okay...unlock the door, and update its linked mirror lock.
	env->set_status(dir, "closed");
	env->update_link(dir);
 
	write( "����" + key->query("short") + "��" + doors[dir]["c_name"] + "�ϵ����򿪡�\n");
	tell_room( env, 
		(string)this_player()->query("c_name") + "��Կ�״�" + doors[dir]["c_name"] + "�ϵ�����\n",
		this_player() );
 
	return 1;
}
 
static int find_keys(object obj) {  return (int)obj->id("key");  }

int help() {
	write( @C_LONG
Syntax: unlock [object] with [optional desc] key

�����������������������ϵ�����Կ��ȥ�����ϵ�����������ע�⣬
�������е�Կ�׶��и�Կ�׿� ....
C_LONG
);
	return 1;
}
 
