//#pragma save_binary

#include <mudlib.h>
#include "swordman.h"

inherit GUILD_OB;
inherit OBJECT;
mapping levels = ([]);

void create()
{
	guild_ob::create();
	seteuid( getuid() );
	set_class_name("swordman");
#include <compress_obj.h>
	set_name("The book of DragonSlayer", "屠龙剑谱");
	add( "id", ({ "book" }) );
	set("unit","本");
	set_short("屠龙剑谱");
	set_long( @LONG
这是屠龙剑派的基本入门心法，其中记载了一些基本剑术和炼气法门，
如果你想知道它的用法，可以用 help book 。
LONG
	);

	set( "weight", 10 );
	set( "extra_look", "$N带著一本练剑养气的「屠龙剑谱」。\n");
}

void init()
{
	// Apply guild_ob checks
	guild_ob::init();

	add_action("help", "help");
	add_action("info", "info");
	add_action("do_comrades","swordmans");
//	add_action("do_read", "read");
	add_action("do_chat", "swordman");
}

int do_comrades()
{
	object *usr, temp;
	int chinese_mode, i,n;
    
	usr = filter_array( users(), "filter_swordmans", this_object() );
	usr = sort_array( usr, "sort_swordmans", this_object() );
	n = sizeof(usr);
	if( n ) {
		write( 
			"目前共有 " + n  + " 位屠龙剑派的同门 :\n"
			"==================================\n");
		for( i=0; i<n; i++ )
/*
				printf( "[ %2d | %2d ] %s (%s)\n", usr[i]->query_level(),
					usr[i]->query("spell_levels/guild"),
*/
				printf( "[ %2d ] %s (%s)\n", usr[i]->query_level(),
					usr[i]->query("short"), capitalize(usr[i]->query("name"))
				);
	} else
		write( "似乎没有任何屠龙剑派的成员在线上....。\n");
	return 1;
}

int sort_swordmans( object u1, object u2 )
{
	return (int)levels[u2] - (int)levels[u1];
}

int filter_swordmans( object plr )
{        
	if( (string)plr->query("class")=="swordman" && visible(plr,this_player()) ) {
		levels[plr] = (int)plr->query_level();
		if( !levels[plr] || levels[plr] == 0 ) return 0;
		return 1;
	}
	return 0;
}

int do_chat(string arg)
{
	if( !arg ) return notify_fail("你想对其它同门说什麽？\n");

	return guild_ob::guild_line(arg);
}
/*
int do_read(string arg)
{
	object me;
	string *types;
	int i, lvl, exp;

	if( !id(arg) ) return 0;
	me = this_player();
		printf("     魔法种类     熟练等级            魔法经验\n");
		for( i=0; i<sizeof(MAGIC_TYPES); i++ )
			printf("     %8s        %2d        %15d\n",
				to_chinese(MAGIC_TYPES[i]),
				me->query("spell_levels/"+MAGIC_TYPES[i]),
				me->query("spell_exps/"+MAGIC_TYPES[i])
			);
		printf("综合(平均)魔法等级 : %2d\n", me->query("spell_levels/guild"));

	return 1;
}
*/
int info(string arg)
{
        
	switch(arg) {
		case "history":
		          cat( GUILD_DATA"c_history" );
			break;
	    case "skills":
	              cat( GUILD_DATA"c_skills" );
	        break;
/*
	    case "titles":
	              cat( GUILD_DATA"c_titles" );
	        break;
	    case "elemental":
	            cat( GUILD_DATA"c_elemental" );
	        break;
	    case "black-magic":
	            cat( GUILD_DATA"c_black-magic" );
	        break;
	    case "misc":
	            cat( GUILD_DATA"c_misc" );
	        break;
	    case "slist":
	              cat( GUILD_DATA"c_spell_list" );
	        break;
	    case "magic-level":
	              cat( GUILD_DATA"c_magic-level" );
	        break;
*/
	    case "commands":
	              cat( GUILD_DATA"c_commands" );
	        break;
		case "topic":
		default : 
			cat( GUILD_DATA"c_topics" );
			  break;
	}
	return 1;
}

int help( string arg )
{
    if( !arg || !id(arg) ) return 0;
	cat ( GUILD_DATA"c_book");
	return 1;
}
