//#pragma save_binary

#include <config.h>
#include <mudlib.h>
#include <net/daemons.h>
#include <body.h>
#include <move.h>
#include <daemons.h>

inherit OBJECT;

inherit "/std/body/attack.c";
inherit "/std/body/alias.c";
inherit "/std/body/wild_card.c";
inherit "/std/body/link.c";
inherit "/std/body/more.c";
inherit "/std/body/message.c";
inherit "/std/body/command.c";

//  This function initializes the body shell prior to transfer
//  of the user connection.
varargs void setup(int silent)
{
	set_living_name( query("name") );
	seteuid( getuid(this_object()) );
	set_heart_beat(1);
	set( "id", ({ query("name") }) );
	set( "ip", query_ip_name(this_object()) );

	if( link_data("wizard")) {
		set("wizard", 1);
		enable_wizard();
	}
	else delete("wizard");

	//	Initialize the tsh system here so all bodies get it
	call_out("initialize_tsh", 0);

	//	Setup the message buffer system ... make sure its OWNER_ONLY
	set("message_buffer", "");
	set("buffer_flag", 0);
}

//  This function switchs the user from its present body to
//  that of a ghost when they "die".
protected object create_ghost()
{
	object ghost, old;
	string name;

	//	First confirm the body has a link
	if(!link)  return 0;

	ghost = new(GHOST);
	old = environment();

	link->set("dead", 1);
	link->set("tmp_body", ghost);

	if(!link->switch_body()) {
		write("Error in the ghost body transfer.  Please inform an Admin.\n");
		return 0;
	}
	if (!name = query("c_name")) name = link_data("c_name");

	ghost->set("name", link_data("name") );
	ghost->set("c_name", name );
	ghost->set("chinese", 1 );
	ghost->set("level", this_object()->query_level() );
	ghost->setup();
	link = 0;

	if( catch(call_other(GHOST_START_LOCATION, "???"))
	||	catch(ghost->move(GHOST_START_LOCATION) != MOVE_OK))
		ghost->move(START);

	tell_room( old,
		"�㿴��һ�ư�ɫ��Ӱ�Ӵ�" + (string)ghost->query("c_name")
		+ "�ġ�����Ʈ��\n" );

	if(environment(ghost) != old) {
		tell_room(old, "��Ӱ����Ʈ����գ�Ȼ����ʧ�ˡ�\n" );
		tell_room(environment(ghost), "�㿴��һ�ư�ɫ��Ӱ�Ӵӿ����г��֡�\n" ,	ghost );
	}

	return ghost;
}

// This is the driver apply that enables mudlib to process users' input
// lines before they are parsed. We can provide some useful features by
// hooking this to some utility modules.
nomask  string process_input(string cmdline)
{
	if( query_temp("block_command") ) {
		receive( "( �������޷������������� )\n" );
		return "";
	}
	if( query("user") ) {
		cmdline = this_object()->do_nicknames(cmdline);
		cmdline = this_object()->handle_history(cmdline);
	}
	cmdline = do_alias(cmdline);
	return cmdline;
}
