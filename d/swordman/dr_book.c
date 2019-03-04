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
	set_name("The book of DragonSlayer", "��������");
	add( "id", ({ "book" }) );
	set("unit","��");
	set_short("��������");
	set_long( @LONG
�����������ɵĻ��������ķ������м�����һЩ�����������������ţ�
�������֪�������÷��������� help book ��
LONG
	);

	set( "weight", 10 );
	set( "extra_look", "$N����һ�����������ġ��������ס���\n");
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
			"Ŀǰ���� " + n  + " λ�������ɵ�ͬ�� :\n"
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
		write( "�ƺ�û���κ��������ɵĳ�Ա������....��\n");
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
	if( !arg ) return notify_fail("���������ͬ��˵ʲ�᣿\n");

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
