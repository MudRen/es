// command.c

#include <body.h>
#include <commands.h>
#include <object.h>
#include <player.h>
#include <daemons.h>

// This function build up the command hook and makes this_object() a
// living with enable_commands()
void init_commands()
{
	enable_commands();

	// updated by Kyoko, to differ cmds path between wizs and archwizs.	
	// cleaned up by Annihilator, removed all variable usage to speedup.
	PATH_D->assign_path( this_object() );

	if( query("user") ) add_action("quit", "quit");

	add_action("cmd_hook", "", 1 );
}

//	Setup standard user command hook system.  This system interfaces
//	with the cmd bin system, the environment's exits, and feeling entries.
nomask static int cmd_hook(string cmd)
{
	string file;
	string verb;
	mapping before;

	if( query_temp("block_command") ) {
		receive( "�������޷�������������\n");
		return 1;
	}

	verb = query_verb();
	if ( !verb ) return 1;

	if( environment() && environment()->valid_exit(verb) ) {
		verb = "go";
		cmd = query_verb();
	}

#ifdef PROFILING
	if( userp(this_object()) ) before = rusage();
#endif

	// Changed PATH to an array, to speed uo command hooking by Annihilator.
	file = (string)CMD_D->find_cmd(verb, query("PATH"));

	if( file && call_other(file, "cmd_" + verb, cmd) );
	else if( EMOTE_D->parse(verb, cmd) );
	// else if( CHANNELS_D->parse_channel(verb, cmd ) );
	// This is the new channel daemon from es2.
	else if( "/adm/daemons/channeld"->do_channel(this_object(), verb, cmd ));
	else return 0;

#ifdef PROFILING
	if( userp(this_object()) )
		"/adm/daemons/profile"->log_cmd( verb, before, rusage() );
#endif

	return 1;
}

// The force hook.
int force_me(string cmd)
{
	string tmp, verb, *verbs;
	int res;
 
	tmp = geteuid(previous_object());
 
	if(tmp != ROOT_UID && tmp != geteuid(this_object()))
		return 0;

	//  Process command for aliases/nicknames/etc
	if(interactive(this_object()))
		cmd = (string)this_object()->process_input(cmd);

	verbs = explode(cmd, " ");
	if( sizeof(verbs) > 0 ) verb = verbs[0];
	else return 0;
	
	//	Check to make sure the force is not an illegal force. If so,
	//	block it and notify all the parties of the foul deed.
	if(BAD_FORCE_VERBS && member_array(verb, BAD_FORCE_VERBS) != -1) {
		tell_object(this_object(), (string)this_player()->query("cap_name") + 
			 " using " + identify(previous_object()) + " tried to force you to " +
			 cmd + ".\n");
		write("Illegal force attempt blocked and noted.\n");

#ifdef BAD_FORCE
		log_file(BAD_FORCE, wrap((string)this_player()->query("cap_name") +
			" using " + identify(previous_object()) + " tried to force " +
			(string)this_object()->query("cap_name") + " to " + cmd + " [" +
			extract(ctime(time()),4,15) + "]\n"));
#endif

		return 0;
	}
	res = command(cmd);
	return res;
}
 
void enable_me()
{
	if (geteuid(previous_object()) != ROOT_UID) return;
	enable_wizard();
}

nomask void disable_me()
{
	if (previous_object() == find_object(CMD_DEWIZ))
		disable_wizard();
}

string local_commands()
{
	mixed *cmds;
	int i;
	string result;
 
	if(geteuid(previous_object()) != ROOT_UID &&
		!member_group(geteuid(previous_object()), "admin"))
		return "You aren't authorized to check this information.\n";
 
	cmds = commands();
 	if (!sizeof(cmds)) return "No commands available";
 
	result = "";
	while (i < sizeof(cmds)) {
		result += (cmds[i][0] + " ");
		i++;
	}
 
	return result + "\n";
}

mixed *user_commands() { return commands(); }

