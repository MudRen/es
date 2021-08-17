//#pragma save_binary

//
// the "set" command
// Part of the TMI distribution mudlib (and Portals too!)
//
// Zak, 930610: cleaned up a lot, added restrictions for players.
// Pallando, 930908: Allowed for non-string vals
//

#include <uid.h>
#include <mudlib.h>

inherit DAEMON;


#define PLAYER_VALID ({ \
    "mail_notification", "mail_entry_unread", "mail_no_cc" \
     "prompt", "vt100", "compact"\
})

nomask int valid_set(object who, string x)
{
    if ( wizardp(who) )
	return 1;
    return (member_array(x, PLAYER_VALID) + 1);	// returns +ve if in VALID_SET
						// 0 otherwise.
}

int cmd_set(string arg)
{
    int i;
    string * vars;
    mixed val;
    string var;
    object act_ob;

    act_ob = previous_object();
    if (!arg)
    {
	vars = (string *)act_ob->regexp_query_env(".*");
	if (!vars || !sizeof(vars))
	{
	    notify_fail ("No environment variables set.\n");
	    return 0;
	}
        vars = sort_array(vars, "sort_set", this_object());
	printf("Environment variables:\n");
	i = sizeof(vars);
	while (i--)
            if( !undefinedp( val = act_ob->query_env(vars[i]) ) )
            {
                if( stringp( val ) )
                    printf("%-15s\t%s\n",vars[i],val);
                else
                    printf("%-15s\t%O\n",vars[i],val);
            }
	return 1;
    }
    // tricky bits are to stop the %d from interpreting
    // "set title 2 down!" as "set title 2"
    if ( ( ( sscanf(arg,"%s %d",var,val) != 2 ) || ( arg != var+" "+val ) ) &&
         (sscanf(arg,"%s %s",var,val) != 2)    )
    {
	val = "";
	var = arg;
    }
    if (
//      geteuid(previous_object()) != ROOT_UID ||
	  !valid_set(act_ob, var)  )
    {
	printf("Sorry, you are not allowed to set the variable '%s'.\n",var);
	return 1;
    }
    i = act_ob->set_env(var,val);
    if (var=="prompt") this_player()->set("PROMPT",this_player()->query_prompt()) ;
    printf("Variable %s: %s\n", (i ? "updated" : "added"), var);
    return 1;
}

protected int sort_set(string one, string two)
{
    return strcmp(two, one);
}


void help()
{
    write( @HELP
Usage: set <����>

����ָ���������ĸ������.

һЩ�����õ�������:
prompt - ���������ʾ��.
vt100 - ������ʾ������ģʽ(��vt100Ϊ��׼)
LINES - ��������ʾ������(Ĭ�� 24).
TZONE - �������ʱ�� (one of EST, CST, MST, PST, BST, GMT, CET, EET, AST).

HELP
    );
    if( this_player()->link_data("wizard") ) {
	write ("PAGER - the file used to page files at you (default more).\n"+
"START - the room which you appear in when you log in.\n"+
"TITLE_COLOR - the color of your title, see /include/ansi.h for defined color.\n"+
"ENV_COLOR - the color of all your movement_message.\n"+
"home - the room where the home command takes you (default workroom.c)\n"+
"\n  There are also the movement messages: TITLE, MOUT, MIN, MMOUT, MMIN\n"+
"MDEST, MCLONE, MVIS, and MINVIS. Type \"help movement_messages\" for help\n"+
"with those.\n") ;
    }

}
