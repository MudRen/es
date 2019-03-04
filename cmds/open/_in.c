//#pragma save_binary
// This is part of the TMI distribution mudlib.
// Please retain this header if you use this code.
// Written by Buddha (5-3-92)
// Updated by Alexus Mel Lynn (2-9-93) (Added exits as valid arguments)

#include <move.h>
#include <mudlib.h>

inherit DAEMON ;

void help() {

	write("\tUsage:\tin <room> <command>\n" +
	"Executes the command given in the room you have specified.\n" +
	"If the room isn't there, or cannot be entered, then it won't work.\n");
}

int cmd_in(string str) {
	string room, cmd;
        mapping exits;
	object prev, act_ob,env;
	int s;

	if (!str || sscanf(str, "%s %s", room, cmd) != 2) {
		notify_fail("Usage:\tin <room|exit> <command>\n");
		return 0;
	}
	env = environment(this_player());
	act_ob = previous_object();
        if (env)
                exits = env->query("exits");
	if(!mapp(exits) || member_array(room,keys(exits)) == -1) {
	room = resolv_path((string)act_ob->query("cwd"), room);
	if (!room || ((s = strlen(room)) >= 2 &&
	      file_size( (room[s-2..s-1] == ".c") ? room : room + ".c") <= 0))
	    return 0;
	} else room = exits[room];
	prev = environment(act_ob);
	if(act_ob->move(room) == MOVE_OK) {
		act_ob->force_me(cmd);
		act_ob->move(prev);
		return 1;
	}
	write("in: could not move to target.\n");
	return 1;
}


