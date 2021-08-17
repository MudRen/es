//#pragma save_binary

//	File		:  /cmds/std/_su.c
//	Creator		:  Sulam@TMI (1-21-92)
//	Updated		:  Huma@TMI (11-15-92) for conversion to mudlib 0.9
//
//	Completely overhauled by Watcher@TMI (2-18-93) for new connection
//	login system, and to improve a few of the su processes.
//
//	Updated by Watcher@TMI (03/92) to accomodated body transfers
//	into monsters by users.
//
//	Updated by Watcher@TMI (04/04/93) stripping away multiple user
//	capabilities to avoid confusion and fix a few other things.
//
//	Updated by Annihilator@Eastern.Stories (10/24/93) removed volume
//	and capacity system, changed to weight/load
//
//	This command allows wizards to refresh their player object, or
//	change into another user, if the correct password is known.
//	Admins are not required to enter the password.

#include <uid.h>
#include <priv.h>
#include <config.h>
#include <logs.h>
#include <mudlib.h>
#include <daemons.h>
#include <login.h>
#include <login_macros.h>

inherit DAEMON;

mapping active = ([]);
int chinese_mode;

protected int link_monster(string name);
protected void get_password(string pass);
protected void enter_world();
protected int check_password(string pass);
protected void try_again();
protected void switch_player();
protected void complete_entry(string str);

string old_body_data_file;
int KEEP_OLD_BODY_DATA;

void create()
{
	seteuid(getuid(this_object()));		// Set daemons permissions
}

int cmd_su(string name)
{
	object ob, me;
	string tmp;
	int TO_USERS_ONLY;

	chinese_mode = can_read_chinese();
	me = this_player();

	//	Setup the euid of the command to ROOT
	seteuid( getuid(this_object()) );

	//	If no name is given assume user's real (non-monster) name
	if(!name)  name = (string)me->link_data("name");

	//	Make sure user's name is lowercase
	name = lower_case(name);

	//	Check to see if anyone is using the su command.
	if( !undefinedp(active["new"]) )
		return notify_fail("Su: The su command is presently in use. Please try again.\n");

	//  Check if want keep old body's data. Added by Annihilator@ES (10/26/94)
	if( sscanf(name, "-f %s", tmp)==1 ) {
		name = tmp;
		KEEP_OLD_BODY_DATA = 1;
		old_body_data_file = user_data_file(me);
	}

	//	Check to see if a monster matches the requested id
	if( sscanf(name, "#%s", tmp) == 1 ) {
		name = tmp;
		TO_USERS_ONLY = 1;
	} else TO_USERS_ONLY = 0;

	// only admins can su to admins, added by Kyoko.
 	if( member_group(name, "admin") && !member_group(geteuid(me), "admin") )
 	    return notify_fail("Sorry, you can't su to admins.\n");

	if( !TO_USERS_ONLY && wizardp(me) && link_monster(name) ) return 1;

	//	Create new connection object to link
	ob = new(CONNECTION);

	//	Convert old format files into new login format
	CONVERTER_D->fix_user(name);

	//	Check to see if user actually exists in the database
	if( !file_exists(user_data_file(ob, name) + SAVE_EXTENSION) ) {
		if( wizardp(me) )
			write("Su: No such user or monster exists.\n");
		else
			write("Su: No such user exists.\n");
		ob->remove();
		return 1;
	}

	// Add user and connection object to su storage array
	active["old"] = me;
	active["new"] = ob;
	active["who"] = name;

	//	Set and pass permissions
	seteuid( name );
	export_uid(ob);
	seteuid(getuid());

	//	Name connection object and attempt to restore user's data
	ob->SET_NAME(name);

	if( !ob->restore() ) {
		write("Su: Could not restore requested user.\n");
		ob->remove();
		active = ([]);
		return 1;
	}

	if( !wizardp(me) && !ob->query("wizard") &&
		name != (string)me->link_data("name")) {
		write("Su: Players may only su to themselves or a wizard character.\n");
		ob->remove();
		active = ([]);
		return 1;
	}

	//	If user is an admin, and target isn't an admin
	if( member_group(me->link_data("name"), "admin") &&
		!member_group(name, "admin")) {
		active["same"] = 0;
		switch_player();
	} else
	//	Switching to a new user ... ask for password
	if( (string)me->link_data("name") != name ) {
		active["same"] = 0;
		input_to("get_password", 1);
		write("Password: ");
	} else
	//	Same player ... so don't ask password
	{
		active["same"] = 1;
		switch_player();
	}
	return 1;
}

protected int get_password(string pass)
{
	write("\n");

	// Check to see if inputed password is correct
	if( !check_password(pass) ) {
		write("Su: Incorrect password.\n");
		active = ([]);
		return 0;
	}

	// If correct, change into the new shell
	switch_player();
	return 1;
}

protected int check_password(string pass)
{
	string password;

	// Get stored character password from connection object
	password = (string)active["new"]->PASS;

	// Compared inputed password with stored character password
	if(password != crypt(pass, password))  return 0;
	return 1;
}

protected void switch_player()
{
	//	Switch interactive between old and new shells
	if( exec(active["new"], active["old"]) ) {
		enter_world();
	} else {
		write("Su: Login attempt failed.\n");
		active["new"]->remove();
		active = ([]);
		return;
	}
}

protected void enter_world()
{
	object *inv;
	int i, load;
	string tmp;

	//	Save present user configuration
 	active["old"]->save_data();

	//	Setup new user object and move inventory to new host
	if(!(KEEP_OLD_BODY_DATA?
		active["new"]->restore_body_file(old_body_data_file):
		active["new"]->restore_body())
	|| !active["new"]->connect()
	|| !active["new"]->BODY_OB->query("name")) {
		write("Su: Could not restore new user body.\n");
		exec(active["old"], active["new"]);
		active["new"]->BODY_OB->remove();
		active["new"]->remove();
		active = ([]);
		return;
	}

	//	Move the inventory..etc.. if old isn't a monster.
	if(!active["old"]->query("npc") && !active["new"]->query("npc")) {
		for(inv=all_inventory(active["old"]); i<sizeof(inv); i++)
			if(!inv[i]->query_auto_load())
				inv[i]->move( active["new"]->BODY_OB );

	}

#ifdef SU_USER_LOG
	seteuid(ROOT_UID);
	if( !member_group(this_player()->query("name"), "admin") ) {
		log_file(SU_USER_LOG, active["old"]->query("name")+": sued into "+
			active["new"]->query("name")+" from "+
			query_ip_name(this_player())+" ["+
			extract(ctime(time()), 4, 15)+"]\n");
		inv = users();
		tmp = sprintf("[ %s(%s) ����� %s(%s) .]\n",
								active["old"]->query("c_name"),
								capitalize(active["old"]->query("name")),
								active["new"]->query("c_name"),
								capitalize(active["new"]->query("name")));
		for ( i = 0; i < sizeof(inv) ; i ++ ) {
			if ( !wizardp(inv[i]) || !visible(inv[i],active["old"]) )
				continue ;
			tell_object(inv[i],tmp);
		}
	}
#endif /* SU_USER_LOG */

	if( active["old"]->query("npc") ) {
		write("Reappear in the same location? [y/n] ");
		input_to("complete_entry", 0);
		return;
	}

	complete_entry("yes");
	return;
}

protected void complete_entry(string str)
{
	if(!str || member_array(str, ({ "y", "yes", "n", "no" })) == -1) {
		write("Reappear in the same location? [y/n] ");
		input_to("complete_entry", 0);
		return;
	}
	if(str == "no" || str == "n")
		active["new"]->BODY_OB->move( START );
	else
		active["new"]->BODY_OB->move( environment(active["old"]) );
	if( active["old"]->query("npc")) {
		active["old"]->clear_monster();
		active["old"]->reset_monster();
	}

	if(active["same"]) {
		write(chinese_mode?"���������ϡ�\n":"Transfer complete.\n");
		if(!active["old"]->query("npc"))
			write((string)this_player()->write_prompt(1));
		active["new"]->BODY_OB->init_setup();
	} else {
			write("������" +
			  active["new"]->BODY_OB->query("c_name") + "��\n");
		say(active["old"]->query("c_name") + "�����" +
			active["new"]->query("c_name") + ".\n",
			({ active["old"], active["new"] }));
		active["new"]->BODY_OB->init_setup();
	}

	//	Announce the departure of the old char if different from new

	if(!active["same"] && !active["old"]->query("npc"))
		ANNOUNCE->announce_user( active["old"], 1 );

	active["new"]->BODY_OB->fix_load();
	if(!active["old"]->query("npc")) {
		active["old"]->save_data();
		active["old"]->remove();
	}
	active = ([]);
}

//	This function handles the user transfers into monster shells
protected int link_monster(string name)
{
	object ob, old;
	int ret;

	old = this_player();
	ob = get_object( name );

	//	Check to see if a monster matches the requested id
	if( !ob || !ob->query("npc") || !environment(ob) || old == ob )
		return 0;

	if( interactive(ob) ) {
		write("Su: That monster body is presently inhabited.\n");
		return 1;
	}

	old->query_link()->set("tmp_body", ob);
	ret = old->query_link()->switch_body();

	if( !ret ) {
		write("Su: Could not transfer into " + name + ".\n");
		return 1;
	}

#ifdef SU_MONSTER_LOG
	seteuid(ROOT_UID);
	if( !member_group(old->query("name"), "admin") )
		log_file(SU_MONSTER_LOG, old->query("name")+": sued into "+
			ob->query("name")+"(monster) from "+
			query_ip_name(this_player())+" ["+
			extract(ctime(time()), 4, 15)+"]\n");
#endif /* SU_MONSTER_LOG */

	ob->clear_monster();
	seteuid( (string)old->link_data("name") );
	export_uid(ob);
	seteuid(getuid());

	ob->init_setup();
	old->set_link(0);
	old->quit();

	write("Transfer complete.\n> ");
	return 1;
}

mapping query_active() {  return active;  }

int help()
{
	write("Usage: su <#>[user]\n\n" +
	  "The su command allows a user to change from their present character\n" +
	  "to another, either a fresh version of the present character or a new\n" +
	  "version of another character (provided you know the password). It is\n" +
	  "equivalent to logging out and back in again, but quicker. With an\n" +
	  "argument, su prompts you for the requested user's password, and if\n" +
	  "answered correctly, you will be polymorphed into that user. Without\n" +
	  "an argument, or if you pass your own character's name as an argument,\n"+
	  "you will be transfered into a new copy of your present character.\n"
	  "If you want su a user not a monster, please add '#' before user name.\n"
	);
	return 1;
}
