//#pragma save_binary

#include <mudlib.h>
#include "scholar.h"

inherit GUILD_OB;
inherit OBJECT;

void create()
{
	seteuid( getuid() );
	guild_ob::create();
	set_class_name("scholar");
#include <compress_obj.h>
	set_name("jade mark", "玉符");
	add( "id", ({ "mark", "jade" }) );
	set_short("玉符");
	set_long( @LONG
这是一块晶莹剔透的美玉琢磨而成的玉符，自古以来的文人书生都喜欢
配戴一块美玉以代表自己高尚的人格，就像玉一样完美无暇，这块玉是
若岚城舞墨轩主人卞大夫的门下食客所配戴的，你可以用 help jade
得到有关书生公会的一些资料。
LONG
	);

	set( "unit", "块" );
	set( "weight", 1 );
	set( "extra_look", "$N看起来温文儒雅，颇有书卷气息，腰间配著一块晶莹剔透的美玉。\n");
}

void init()
{
	// Apply guild_ob checks
	guild_ob::init();

	add_action("help", "help");
	add_action("info", "info");
	add_action("do_scholars", "scholars");
	add_action("do_chat", "scholar");
}

int do_scholars()
{
	return guild_ob::list_guild_members();
}

// The guild channel
int do_chat(string arg)
{
	if( !arg )
		return notify_fail("你想对其它书生说什麽？\n");
	return guild_ob::guild_line(arg);
}

int info(string arg)
{
	switch(arg) {
		case "commands":cat( GUILD_DATA"c_scholar_commands" );
		    break;
		case "gonfus":cat( GUILD_DATA"c_scholar_gonfus" );
		    break;     		
                case "history":cat( GUILD_DATA"c_scholar_history" );
		    break;
		default: 
			cat( GUILD_DATA"c_topics" );
			break;
	}
	return 1;
}

int help(string arg)
{
	if( !arg || arg!="jade" ) return 0;
	cat(GUILD_DATA"c_jade_mark");

	return 1;
}
