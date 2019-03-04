//#pragma save_binary

// File: /cmds/std/_go.c
// Code to move a player from one room to another.
// This code used to be in the player object, which was wasteful because
// it meant the code was duplicated in each player. By adding the "go" verb
// to the movement command, it is possible to stick the code into a normal
// command, saving mucho RAM. It is wise to alias "n" to "go north", etc,
// for compatibility with people's expectations, and in fact this is done
// in the standard distribution.
// Written by Buddha in October 1992, probably. The lame-o didn't put a
// header on. This header was added by Mobydick on 11-11-92.

#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;

int cmd_go(string dir)
{
	mapping exits, tmp, doors;     
	object env, ob,ob1, *obs;
	int i, sz, flag;
	string tstr, *dirs;

	ob = this_player();
//	if(!ob) ob = previous_object();
	env = environment(ob);
	if (ob->query_temp("hidding")) {
		ob->set_temp("hidding",0);
		ob->set_temp("hide_score",0);
	}
	if( !env ) { 
		write("��������������Ʈ��䣬��֪��ȥ�δӡ�\n");
		return 1;
	}
	
	exits = env->query("exits");
	if( !mapp(exits) || !dirs = keys(exits) )
		return notify_fail("����û���κγ�·��\n");

	if( ob->query("confused") || ob->query_temp("confused") ) {
		tell_object( ob,"�������һ�Ż���, �޷�ȷʵ�Ŀ�������!!\n");
		dir = dirs[random(sizeof(dirs))];
	}

	if( member_array(dir, keys(exits)) == -1 )
		return notify_fail("����û���κγ�·��\n");

	if( ob->query_temp("block_command") )
		return notify_fail( "( ��Ŀǰ�޷��ƶ��� )\n");

  // Modify to fix that foe be block_attack but still be block
  // Indra 95.5.29
	if( obs=ob->query_attackers() ) {
		if( (int)ob->query("stop_attack") > 1 )
			return notify_fail( 
				"( ����һ��������û����ɣ��޷��ƶ���)\n");
				
		i = (int)ob->query_stat( "kar" );
		sz= sizeof(obs) ;
		// only when ob1 exist need to check..  
		// or sometimes will have bug
		// add by Iris. 95.5.30 
		if (ob1 = ob->query_current_attacker()) {
		  if(( random( i + sz + 2 ) > i )&&
		       !ob1->query("stop_attack") ) {
			  ob->block_attack(2);
			  return notify_fail( 
				  "( �㱻���˵�ס�ˣ��޷��ƶ���)\n");
		  }
		}  
	}
	
	// Check to see if there is a door in that exit, and if so, is it closed
	// or locked. If it is, don't permit the move.
	doors = env->query("doors");
	if( doors && doors[dir] ) {
		if( doors[dir]["status"] == "closed" ||
			doors[dir]["status"] == "locked")
			return notify_fail(
			sprintf("��...�Ǳߵ�%s�ǹ����ġ�\n",doors[dir]["c_name"]));
	}

	// Now check if the room allows monster to enter. by Annihilator (1-7-94)
	if( !userp(ob) && exits[dir]->query("no_monster") ) {
		write( "( ���ﲻ׼����������� )\n");
		return 0;
	}
	
	// let's see if it's ok to move -- is there a pre-exit function to call?
	// if the preexit function returns 1, then the exit will be prevented!
	// otherwise the preexit function can be void or return 0, and the exit 
	// will occur after it's called.
	tmp = env->query("pre_exit_func");
	if( tmp && tmp[dir] && call_other(env, tmp[dir]) ) return 1;

	// Now we find out if there's a special message to use when they leave.
	// if there is, we'll use it instead of the default.
	tmp = env->query("exit_msg");
	if( tmp && mapp(tmp) && tmp[dir] ) {
		tstr = substr(tmp[dir], "$N", 
			(string)ob->query("c_name") );
		ob->move_player(exits[dir], tstr);
	} else
		ob->move_player(exits[dir], "", dir);

	// We check for a post-exit function. Note that the player is no longer
	// in the room, and this is also our last chance to do anything before
	// our control of the player is lost. It doesn't matter what the
	// post-exit function returns.
	tmp = env->query("post_exit_func");
	if( tmp && mapp(tmp) && tmp[dir] ) call_other(env, tmp[dir]);
	
	// Now we check for party members and move them. The call_out will give
	// the effect of party members following their leader.
	if( (string)ob->query_temp("leader") &&
		((string)ob->query_temp("leader")) == ((string)ob->query("name"))) {
		obs = PARTY_D->query_members(ob);
		sz = sizeof(obs);
		flag = 1;
		for( i=0; i<sz; i++ ) {
			if(!obs[i] || obs[i]==ob )
				continue;
				
            if( environment(obs[i])==env && !obs[i]->query_temp("block_command")) 
				  obs[i]->force_me( "go "+dir );
				  
            if( environment(obs[i])!=environment(ob) ) {
                  tell_object(obs[i], "�����Ķ�����ɢ��.\n");
  	              tell_object(ob,
                    sprintf("��Ķ��� : %s û����.\n",obs[i]->query("c_name")) );
 			} else flag++;
		}
		if( sz > 1 && flag== sz ) write("��Ķ��Ѹ������߹���.\n");
	}
	
	// Finally we are finished.
	return 1;
}

int help()
{
	write(@HELP
SYNTAX: go <direction>

The go command will move you in the directionspecified, 
ie \"go west\" will move you throughthe room's west exit.
You can also type \"west\" and that will work. For the 
standard directions, \"w\" or other one-letter abbreviations
will also work.
HELP
);
	return 1;
}
