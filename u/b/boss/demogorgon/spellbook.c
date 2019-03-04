//#pragma save_binary

// spellbook.c
// The guild token of the mage's guild.
// Sub Usage: The spell book of mages, containing most spells one can find
//            in the mud. But not all spells it can remember.
// Created by Kyoko Autinashi Nov 9 '93.

#include <mudlib.h>
#include "mage.h"

inherit GUILD_OB;
inherit OBJECT;
mapping levels = ([]);

void create()
{
	guild_ob::create();
	seteuid( getuid() );
	set_class_name("mage");
#include <compress_obj.h>
	set_name("spellbook", "ħ����");
//	add( "id", ({ "book" }) );
	set("unit","��");
	set_short("ħ����");
	set_long( @LONG
����ħ��ʦ�������ഫ��ħ���飬��������˴�ǰ��λΰ��ħ��ʦ������
������֪ʶ�뷨�����������֪�������й�ħ��������ϣ�����
	"help spellbook" ָ�
LONG
	);

	set( "weight", 10 );
	set( "extra_look", "$N����һ��ħ��ʦ�Ƕ��е�ħ���顣\n");
}

void init()
{
	// Apply guild_ob checks
	guild_ob::init();

	add_action("help", "help");
	add_action("info", "info");
	add_action("do_comrades","mages");
	add_action("do_read", "read");
	add_action("do_chat", "mage");
}

int do_comrades()
{
	object *usr, temp;
	int chinese_mode, i,n;
    
	usr = filter_array( users(), "filter_mages", this_object() );
	usr = sort_array( usr, "sort_mages", this_object() );
	n = sizeof(usr);
	if( n ) {
		write( sprintf("Ŀǰ���� %d λħ��ʦ������:\n==================================\n",n));
		for( i=0; i<n; i++ )
				printf( "[ %2d | %2d ] %s (%s)\n", usr[i]->query_level(),
					usr[i]->query("spell_levels/guild"),
					usr[i]->query("short"), capitalize(usr[i]->query("name"))
				);
	} else
		write( "�ƺ�û���κ�ħ��ʦ����ĳ�Ա������....��\n");
	return 1;
}

int sort_mages( object u1, object u2 )
{
	return (int)levels[u2] - (int)levels[u1];
}

int filter_mages( object plr )
{        
	if( (string)plr->query("class")=="mage" && visible(plr,this_player()) ) {
		levels[plr] = (int)plr->query_level();
		if( !levels[plr] || levels[plr] == 0 ) return 0;
		return 1;
	}
	return 0;
}

int do_chat(string arg)
{
	if( !arg ) return notify_fail("���������ħ��ʦ˵ʲ�᣿\n");

	return guild_ob::guild_line(arg);
}

int do_read(string arg)
{
	object me;
	string *types;
	int i, lvl, exp;

	if( !id(arg) ) return 0;
	me = this_player();
		printf("     ħ������     �����ȼ�            ħ������\n");
		for( i=0; i<sizeof(MAGIC_TYPES); i++ )
			printf("     %8s        %2d        %15d\n",
				to_chinese(MAGIC_TYPES[i]),
				me->query("spell_levels/"+MAGIC_TYPES[i]),
				me->query("spell_exps/"+MAGIC_TYPES[i])
			);
		printf("�ۺ�(ƽ��)ħ���ȼ� : %2d\n", me->query("spell_levels/guild"));

	return 1;
}

int info(string arg)
{
        
	switch(arg) {
		case "history":
		          cat( GUILD_DATA"c_history" );
			break;
	    case "skills":
	              cat( GUILD_DATA"c_skills" );
	        break;
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
	    case "commands":
	              cat( GUILD_DATA"c_commands" );
	        break;
	    case "slist":
	              cat( GUILD_DATA"c_spell_list" );
	        break;
	    case "magic-level":
	              cat( GUILD_DATA"c_magic-level" );
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
	cat ( GUILD_DATA"c_spellbook");
	return 1;
}