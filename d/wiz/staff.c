// staff.c: Annihilator's magical staff

#include <uid.h>
#include <mudlib.h>
#include <daemons.h>
#include <guilds.h>

inherit REF_D;
inherit GUILD_OB;
inherit WEAPON;

void create()
{
	seteuid( getuid(this_player()) );
	guild_ob::create();
	set_name("staff", "ħ��");
	add( "id", ({ "magical staff" }) );
	set_short("A wizard staff", "��ʦħ��");
	set_long(
		"This is a magical staff created by Annihilator. Type 'help staff'\n"
		"for more information.\n",
		"����һ�ѡ���ʦר�á�������ħ�ȣ��� help staff ��ʹ��˵����\n"
	);
	set_class_name("adventurer");
	set( "unit", "��" );
	set( "type", "blunt" );
	set( "weapon_class", 20 );
	set( "min_damage", 10 );
	set( "max_damage", 20 );
	set( "prevent_drop", 1 );
}

int query_auto_load()
{
	return 1;
}

void init()
{
	object owner;

	owner = environment();
	if( !wizardp(owner) ) remove();
	guild_ob::init();

	add_action("guild_line", "chat");
	add_action("list_guild_members", "fellows");
	add_action("change_guild", "join");
	
	add_action("help_staff", "help");
	add_action("make_room", "mkroom");
	add_action("make_npc", "mknpc");
	add_action("make_obj", "mkobj");
	add_action("call_set_room", "rset");
	add_action("call_add_room", "radd");
	add_action("save_room", "saveroom");
	add_action("connect_room", "connect");
}


int change_guild(string arg)
{
	if( file_size(GUILD_MASTER(arg)+".c")<0 )
		return notify_fail( can_read_chinese()?
			"û��������ᡣ\n": "No such guild.\n" );
	set_class_name(arg);
	// Cause init() to be called and everything set ok.
	move(this_player());
	write("Ok.\n");
	return 1;
}

// "connect" command connects an exit from the environment to specified room.
int connect_room(string arg)
{
	string dir, filename;
	object here;

	if( !arg || arg=="" || sscanf(arg, "%s to %s", dir, filename)!= 2 )
		return notify_fail( can_read_chinese()?
			"ָ���ʽ: connect <����> to <���䵵��>\n":
			"Usage: connect <direction> to <filename>\n");

	filename = resolv_path("cwd", filename);

	here = environment( this_player() );
	if( !here ) return notify_fail( can_read_chinese()?
		"�㲻����һƬ���������ӳ��ڡ�\n":
		"You can't do that in the void.\n");

	if( !((int)master()->check_access( base_name(here), this_player() ) & 2) )
		return notify_fail( can_read_chinese()?
			"��û���޸���������Ȩ����\n":
			"You have no WRITE access to this room.\n" );

	here->add( "exits", ([ dir:filename ]) );
	tell_room( here, ({
		this_player()->query("cap_name") + " opens a gateway with the magical staff.\n",
		this_player()->query("c_cap_name") + "����ʦħ�ȴ�һ��ͨ�����Ԫ��ͨ����\n"}),
		this_player() );
	write("Ok.\n");
	return 1;
}


// "mkroom" command creates a simple room.
int make_room(string arg)
{
	string header_file, filename, room;

	if( !arg || arg=="" ) return
		notify_fail( can_read_chinese()?
			"ָ���ʽ: mkroom <���䵵��>\n": "Usage: mkroom <filename>\n" );

	filename = resolv_path("cwd", arg) + ".c";
	if( file_size(filename)!=-1 )
		return notify_fail( can_read_chinese()?
			"���� "+filename+" �Ѿ������ˣ�\n": filename+" already exists!\n");

	write("Creating room ("+filename+") ...... ");
	header_file = user_path( this_player()->link_data("name") ) + ".room.h";
	if( file_size(header_file) > -1 )
		room = read_file(header_file);
	else {
		room  = "// "+filename+"\n";
		room += "\n#include <mudlib.h>\n";
		room += "\ninherit ROOM;\n";
	}
	room += "\nvoid create()\n{\n";
	room += "\t::create();\n";
	room += "\tset_short(\"A empty room\", \"�շ���\");\n";
	room += "\tset_long(\n";
	room += "\t\t\"This is a simple room created by roommaker.\\n\",\n";
	room += "\t\t\"����һ���÷���༭��������Ŀշ��䡣\\n\"\n";
	room += "\t);\n";
	room += "}\n";

	if( write_file(filename, room) ) {
		write("Ok.\n");
		return 1;
	} else
		return notify_fail( can_read_chinese()?
			"����д��ʧ�ܡ�\n": "Access denied.\n");
}

// "mknpc" command creates a simple monster.
int make_npc(string arg)
{
	string header_file, filename, room;

	if( !arg || arg=="" ) return
		notify_fail( can_read_chinese()?
			"ָ���ʽ: mknpc <���ﵵ��>\n": "Usage: mknpc <filename>\n" );

	filename = resolv_path("cwd", arg) + ".c";
	if( file_size(filename)!=-1 )
		return notify_fail( can_read_chinese()?
			"���� "+filename+" �Ѿ������ˣ�\n": filename+" already exists!\n");

	write("Creating NPC ("+filename+") ...... ");
	header_file = user_path( this_player()->link_data("name") ) + ".npc.h";
	if( file_size(header_file) > -1 )
		room = read_file(header_file);
	else {
		room  = "// "+filename+"\n";
		room += "\n#include <mudlib.h>\n";
		room += "\ninherit MONSTER;\n";
	}
	room += "\nvoid create()\n{\n";
	room += "\t::create();\n";
	room += "\tset_level(1);\n";
	room += "\tset_name(\"monster\", \"����\");\n";
	room += "\tset_short(\"A monster\", \"����\");\n";
	room += "\tset_long(\n";
	room += "\t\t\"This is a simple monster created by npc maker.\\n\",\n";
	room += "\t\t\"����һ���ù���༭��������Ĺ��\\n\"\n";
	room += "\t);\n";
	room += "}\n";

	if( write_file(filename, room) ) {
		write("Ok.\n");
		return 1;
	} else
		return notify_fail( can_read_chinese()?
			"����д��ʧ�ܡ�\n": "Access denied.\n");
}


// "mkobj" command creates a simple object.
int make_obj(string arg)
{
	string header_file, filename, room;

	if( !arg || arg=="" ) return
		notify_fail( can_read_chinese()?
			"ָ���ʽ: mkobj <���ﵵ��>\n": "Usage: mkobj <filename>\n" );

	filename = resolv_path("cwd", arg) + ".c";
	if( file_size(filename)!=-1 )
		return notify_fail( can_read_chinese()?
			"���� "+filename+" �Ѿ������ˣ�\n": filename+" already exists!\n");

	write("Creating NPC ("+filename+") ...... ");
	header_file = user_path( this_player()->link_data("name") ) + ".obj.h";
	if( file_size(header_file) > -1 )
		room = read_file(header_file);
	else {
		room  = "// "+filename+"\n";
		room += "\n#include <mudlib.h>\n";
		room += "\ninherit OBJECT;\n";
	}
	room += "\nvoid create()\n{\n";
	room += "\t::create();\n";
	room += "\tset_name(\"object\", \"���\");\n";
	room += "\tset_short(\"An object\", \"���\");\n";
	room += "\tset_long(\n";
	room += "\t\t\"This is a simple object created by object maker.\\n\",\n";
	room += "\t\t\"����һ��������༭��������������\\n\"\n";
	room += "\t);\n";
	room += "}\n";

	if( write_file(filename, room) ) {
		write("Ok.\n");
		return 1;
	} else
		return notify_fail( can_read_chinese()?
			"����д��ʧ�ܡ�\n": "Access denied.\n");
}


// "saveroom" command save the current room to a LPC program.
int save_room(string arg)
{
	int i, j;
	mixed key, tmp, str;
	object env;
	string header_file, filename, room, *list;
	mapping props;

	env = environment( this_player() );
	if( !env ) return notify_fail( can_read_chinese()?
		"�����ڲ�û�����κη����ڡ�\n": "Can't save void.\n");

	if( !arg || arg=="" ) {
		filename = base_name(env) + ".c";
	}
	else filename = resolv_path("cwd", arg) + ".c";

	write( can_read_chinese()?
		"�������Ϸ����� ...... ": "Saving room ("+filename+") ...... ");
	header_file = user_path( this_player()->link_data("name") ) + ".roommaker.h";
	if( file_size(header_file) > -1 )
		room = read_file(header_file);
	else {
		room  = "// File: "+filename+"\n";
		room += "// Generated by Roommaker "+ctime(time())+"\n";
		room += "\n#include <mudlib.h>\n";
		room += "\ninherit ROOM;\n";
	}
	room += "\nvoid create()\n{\n";
	room += "\t::create();\n";
	room += "\tset_short(\"" + env->query("short")
		+ "\", \"" + env->query("c_short") + "\");\n";
	room += "\tset_long( @LONG_DESCRIPTION\n";
	room += replace_string( env->query("long"), "\\", "\\\\" );
	room += "LONG_DESCRIPTION\n";
	room += "\t\t, @C_LONG_DESCRIPTION\n";
	room += replace_string( env->query("c_long"), "\\", "\\\\" );
	room += "C_LONG_DESCRIPTION\n";
	room += "\t);\n\n";
	
	if( !undefinedp( tmp= env->query("outside") ) )
		room += "\tset_outside( \"" + tmp + "\" );\n";

	props = env->query_ob_data();
	if( !props || !mapp(props) || sizeof(props)<1 )
		return notify_fail( can_read_chinese()?
			"�������϶�ȡʧ�ܡ�\n": "Failed to access the room data.");

	if( !undefinedp(props["light"]) && intp(props["light"]) )
		room += "\tset( \"light\", "+props["light"]+" );\n";

	list = keys(props);

	list -= ({ "short", "c_short", "long", "c_long", "load", "max_load",
		"outside", "light" });
	list = sort_array( list, "sort_prop", this_object() );

	for(i=0; i<sizeof(list); i++)
		room += "\tset( \""+list[i]+"\", "+identify(props[list[i]], 1)+" );\n";

	room += "\treset();\n";
	room += "}\n";

	if( file_size(filename)>-1 ) {
		write( can_read_chinese()?
			"�����Ѵ��ڣ�\n��Ҫȡ���ɵ�����[y/n] ":
			"File already exists!\nReplace it? [y/n] " );
		input_to( "save_room_file", 0, filename, room, can_read_chinese() );
		return 1;
	}

	if( write_file(filename, room) )
		write("Ok.\n");
	else
		write( can_read_chinese()?
			"����д��ʧ�ܡ�\n": "Access denied ("+filename+").\n");
	return 1;
}

int sort_prop(string a, string b)
{
	return strcmp(a, b);
}

void save_room_file(string yn, string filename, string room, int chinese_mode )
{
	if( !yn || yn=="" ) {
		write( chinese_mode?
			"Ҫ��Ҫȡ�� " + filename + " ? (���� \"y\" ��ʾҪ��\"n\" ��ʾ��Ҫ) ":
			"Replace "+filename+"? (type \"yes\" or \"no\") " );
		input_to( "save_room_file", 0, filename, room, chinese_mode );
		return;
	}

	if( yn[0]=='n' || yn[0]=='N' ) {
		write( chinese_mode?
			"���䴢����ֹ��\n": "Saveroom aborted.\n");
		return;
	} else if( yn[0]!='y' && yn[0]!='Y' ) {
		write( chinese_mode?
			"Ҫ��Ҫȡ�� " + filename + " ? (���� \"y\" ��ʾҪ��\"n\" ��ʾ��Ҫ) ":
			"Replace "+filename+"? (type \"yes\" or \"no\") " );
		input_to( "save_room_file", 0, filename, room );
		return;
	}

	if( rm(filename) && write_file(filename, room) )
		write("Ok.\n");
	else
		write( chinese_mode?
			"����д��ʧ�ܡ�\n": "Access denied("+filename+").\n");
}

int call_set_room(string arg)
{
	object env;
	string prop, str;

	env = environment(this_player());
	if( !env ) return notify_fail( can_read_chinese()?
		"�����ڲ�û�����κη����С�\n": "Can't set in void.\n");

	if( !((int)master()->check_access( base_name(env), this_player() ) & 2) )
		return notify_fail( can_read_chinese()?
			"��û���޸���������Ȩ����\n":
			"You have no WRITE access to this room.\n" );

	if( !arg || sscanf(arg, "%s %s", prop, str)!=2 )
		return notify_fail("Usage: rset <property> <value>\n");

	env->set( prop, resolv_str(str) );
	write( "Ok.\n");
	return 1;
}

int call_add_room(string arg)
{
	object env;
	string prop, str;

	env = environment(this_player());
	if( !env ) return notify_fail( can_read_chinese()?
		"�����ڲ�û�����κη����С�\n": "Can't set in void.\n");

	if( !((int)master()->check_access( base_name(env), this_player() ) & 2) )
		return notify_fail( can_read_chinese()?
			"��û���޸���������Ȩ����\n":
			"You have no WRITE access to this room.\n" );

	if( !arg || sscanf(arg, "%s %s", prop, str)!=2 )
		return notify_fail("Usage: rset <property> <value>\n");

	env->add( prop, resolv_str(str) );
	write( "Ok.\n");
	return 1;
}

// "help" command tells you how to use this staff
int help_staff(string arg)
{
	if( !arg || arg!="staff" ) return 0;
	if( can_read_chinese() )
		write( @C_HELP_STAFF
���ħ���ṩ���¼���ָ��:

    chat     - ���ù���Ƶ����������˵����
    fellows  - �г�Ŀǰ����ͬһ�������ҡ�
    join     - �ı���Ĺ��ᡣ

    mkroom   - �����һ���򵥷����ģ�͡�
    saveroom - �����������ڵķ��䳢���� LPC �ĳ�ʽд��һ��������
    rset     - �趨�������� properties��
    radd     - ������������ properties��
    connect  - ��ͨһ��ͨ����������ĳ��ڡ�
C_HELP_STAFF
	);
	else write( @HELP_STAFF
This staff applies these commands:
	
	chat     - talk in the guild channel.
	fellows  - list members of your guild.
	join     - change your current guild.

    mkroom   - create a new simple room.
    saveroom - save the current room.
    rset     - set properties of the room.
    radd     - add properties of the room.
    connect  - add an exit to other room.
HELP_STAFF
	);
	return 1;
}

