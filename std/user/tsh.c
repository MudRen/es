//#pragma save_binary

/*
// tsh.c: TMI-shell or Tru-shell -- written by Truilkan@TMI 92/02/05
//        meant to be inherited by player.c
//
// Brutally hacked up and destroyed by Buddha to install something "better"
// on 3-7-92
//
// 1992/03/08 - hacked again by Truilkan@TMI to fix pushd and popd
//
// 1993/02/06 - Multiple command repeat capability by Watcher@TMI
//
// 1993/02/22 - Allowing silent queries to write_prompt() by Watcher@TMI
//
// 1993/03/30 -	Uses STACK not CSTACK (makes `dirs' cmd easier)
//		Uses tilde_path in prompt.
//		Cleaned up a bit. (Zak@tmi-2)
// 1993/08/05 Grendel@tmi-2 - Added test for files in ~/tsh/
*/

#include <adt_defs.h>
#include <commands.h>
#include <tsh.h>
#include <uid.h>
#include <ansi.h>

#define DEFAULT_PROMPT ""
#define MAX_HIST_SIZE  50
#define MIN_HIST_SIZE  20
#define MIN_PUSHD_SIZE 5
#define MAX_PUSHD_SIZE 50

#define MAX_CMD_STACK 32
/*
    STACK_ADT should be inherited from here so that this object can have
    its own  stack
*/
inherit STACK_ADT;       /* for pushd and popd */

nosave string tsh_prompt;
nosave int cmd_top, cmd_bottom ;
nosave string *cmd_stack ;
nosave int cur, hist_size, pushd_size, custom_prompt;

string do_nicknames(string arg);
string do_alias(string arg);
string do_substitution(string arg) ;
string handle_history(string arg);
// nomask mixed query( string label );

/* do_new: called by the "newstr" command */

void alloc_cmd_stack()
{
	cmd_stack = allocate(MAX_CMD_STACK);
	cmd_top = 0;
	cmd_bottom = 0;
}

int do_new()
{
	string d1, d2;

	tsh_prompt = (string)this_object()->getenv("prompt");
	tsh_prompt = !tsh_prompt ? DEFAULT_PROMPT : tsh_prompt + " ";
	custom_prompt = (tsh_prompt != DEFAULT_PROMPT);

	d1 = (string)this_object()->getenv("pushd");
	pushd_size = 0;
	if (d1)
	sscanf(d1,"%d",pushd_size);
	if (pushd_size > MAX_PUSHD_SIZE)
	pushd_size = MAX_PUSHD_SIZE;
	if (!pushd_size)
	pushd_size = MIN_PUSHD_SIZE;

	d1 = (string)this_object()->getenv("history");
	hist_size = 0;
	if (d1)
	sscanf(d1,"%d",hist_size);
	if (hist_size > MAX_HIST_SIZE)
	hist_size = MAX_HIST_SIZE;
	if (hist_size <= 0)
	hist_size = MIN_HIST_SIZE;
	return 1;
} // do_new


/* push current directory onto the stack and cd to dir named "arg" */
int pushd(string arg)
{
	string path;

	if (!arg && (string)this_object()->getenv("pushdtohome"))
	arg = "~";
	path = (string)this_object()->query("cwd");
	if (((int)CMD_CD->cmd_cd(arg)))
	{
	if (stack::push(path) == -1)
		write("dirstack full - try popd-ing some elements first\n");
	}
	return 1;
} // pushd


int popd()
{
	mixed dir;

	dir = stack::pop();
	if ((int)dir == -1)
	write("Directory stack is empty.\n");
	else
	CMD_CD->cmd_cd((string)dir);
	return 1;
} // popd


mixed *dirs()
{
	return stack::query_stack();
}


void initialize_tsh()
{
	string rcfile;

	do_new();
	if (pushd_size)
	stack::alloc(pushd_size);
	if (hist_size)
	history::alloc(hist_size);
	rcfile = user_path((string)this_object()->query("name")) + ".login";
	if( file_size(rcfile) > 0 )
	this_object()->tsh(rcfile);
	alloc_cmd_stack();
} // initialize_tsh

string query_prompt()
{
	string path, prompt, tmp;

	if ( wizardp(this_object()) ) {
		if ( !prompt = this_object()->getenv("prompt"))
			return "> ";
		prompt = replace_string(prompt,"$D",
			tilde_path((string)this_player()->query("cwd"), 0));
		prompt = replace_string(prompt, "\\n", "\n");
		prompt = replace_string(prompt, "$N", lower_case(mud_name()));
		prompt = replace_string(prompt, "$C", ""+(query_cmd_num() + 1));
	}
	if ( prompt )
		return prompt;
	else
		return "> ";
}
/*
string write_prompt(int silent)
{
	string path, prompt, tmp;

	if (wizardp(this_player()) && custom_prompt) {
		prompt = tsh_prompt;
		prompt = replace_string(prompt,"$D",
			tilde_path((string)this_player()->query("cwd"), 0));
		prompt = replace_string(prompt, "\\n", "\n");
		prompt = replace_string(prompt, "$N", lower_case(mud_name()));
		prompt = replace_string(prompt, "$C", ""+(query_cmd_num() + 1));
	} else
		prompt = DEFAULT_PROMPT;
	if(!silent)
		this_player()->quick_message(prompt);
	return prompt;
}
*/

int push_cmd(string arg)
{
	if ( strsrch(arg, "do ") != -1 )
		return command(arg);
	if ( (cmd_top+1) == cmd_bottom ) {
		write("你同时下太多命令, 停止执行 !!\n");
		cmd_top = 0;
		cmd_bottom = 0;
		return 0;
	}
	cmd_stack[cmd_top] = arg;
	cmd_top++;
	if ( cmd_top >= MAX_CMD_STACK )
		cmd_top = 0;
	return 1;
}
string parse_arg(string arg)
{
	arg = do_substitution(arg) ;
	arg = do_nicknames(arg);
	arg = do_alias(arg);
	arg = handle_history(arg);
	return arg;
}
nomask string process_input(string arg)
{
	int loop, num, macro;
	string *buf;

	if ( arg == "")
		return "";

	if( this_object()->query_temp("block_command") ) {
		write(
			"( 你现在无法做其他动作。 )\n" );
		return "";
	}

	// remove all ESC in the input
	arg = replace_string(arg,ESC,"");

	if ( !query_heart_beat() ) {
		cmd_top = 0;
		cmd_bottom = 0;
		set_heart_beat(1);
	}
	if ( !sizeof(cmd_stack) ) alloc_cmd_stack();
	if(sscanf(arg, "%d %s", num, arg) == 2)
		if ( num > 1 ) macro = 1;

	arg = parse_arg(arg);

	//	Allow multiple repeat actions like '5 north' as well as
	//	alias commands.   - Watcher  (02/05/93)

	if(macro && num && arg && arg != "" && !previous_object()) {
		if(num > 10) {
			write("重复指令次数不可以超过 10 次。\n");
			return "";
		}

		for(loop=0; loop<num; loop++)
			if ( !command(arg) ) break;
//			if ( !push_cmd(arg) ) break;

		return "";
	}

//	if ( cmd_buffer_mode )
		push_cmd(arg);
//	else
//		command(arg);

	return "";

} // process_input


int tsh(string file)
{
	string contents, euid, *lines;
	int j, len;

	euid = geteuid( previous_object() );
	// 93-02-12 pallando (_tsh wasn't working)
	if (  ( euid != geteuid( this_object() ) )
	   && ( euid != ROOT_UID )
	   && !member_group( euid, "admin" ) )
	return 0;

	if (!file) {
		notify_fail("usage: tsh filename\n");
		return 0;
	}

	contents = read_file( resolv_path( "cwd", file ) );
	if (!contents) {
		contents = read_file( resolv_path( "cwd", "~/tsh/"+file ) );
		if (!contents) {
			notify_fail("tsh: couldn't read " + file + "\n");
			return 0;
		}
	}
	lines = explode(contents,"\n");
	len = sizeof(lines);
	for (j = 0; j < len; j++) {
		if (lines[j][0] != '#' && !command(lines[j])) {
			write(file + ": terminated abnormally on line #" + (j+1) + "\n");
			write("while doing: " + lines[j] + "\n");
			break;
		}
	}
	return 1;
} // tsh

// This function allows for ^foo^bar substitutions.
string do_substitution (string arg)
{
	string pre,post,old,newstr,lastcom ;

	if (arg == "^^") {
		write ((lastcom = query_last_command()) + "\n");
		return lastcom;
	}

	if (sscanf(arg,"^%s^%s",old,newstr)!=2) {
		return arg ;
	}

	lastcom = query_last_command() ;
	if (!lastcom || lastcom=="") {
		write ("No previous command.\n") ;
		return "" ;
	}

	if (old == "") {
		// allow you to prepend last string
		write (newstr + lastcom + "\n");
		return newstr + lastcom ;
	}

	if (sscanf(lastcom, "%s" + old + "%s", pre,post) != 2) {
		write ("Failed substitution.\n") ;
		return "" ;
	}
	write (pre+newstr+post+"\n") ;
	return pre+newstr+post ;
}
void alloc(int size)
{
//	history::alloc(size);
//	stack::alloc(size);
}
