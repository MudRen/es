//#pragma save_binary

// monk_book.c
// The guild token of the monk's guild.
// Sub Usage: The spell book of mages, containing most spells one can find
//            in the mud. But not all spells it can remember.
// Created by Kyoko Autinashi Nov 9 '93.
// use by angel for monk_guild

#include <mudlib.h>
#include "monk.h"    

inherit GUILD_OB;
inherit OBJECT;
mapping levels = ([]);

void create()
{
	guild_ob::create();
	seteuid( getuid() );
	set_class_name("monk");
#include <compress_obj.h>
	set_name("monk_book", "��");
	set_short("��");
	set_long( @LONG
����һ�����Ƶķ𾭡����ֹ�Ȼ�кų����³�ʤ�������ɵ�������Ҳӵ��Ц�����ֵ�
��ѧ���䣬����ϣ����ɮ�����Դ�Ϊ��... ǿ������ǿ���֣�����ϣ����Ҷ����ϰ
�𾭣����ճ��������ǿ��ʤ������... �������֪���Ȿ�𾭵����ϼ�ʹ�ã�����
\"help monk_book\" ָ�
LONG
	);

	set( "weight", 10 );
	set( "unit", "��" );
        
	set( "allow_material", ({ "cloth", "leather","wood","stone", }));
	set( "second_material", ({ "element", }));

	set( "extra_look", "$N�������һ���ƾɷ��Ƶķ𾭣������ÿ���д�������֡���\n");
}

void init()
{
	// Apply guild_ob checks
	guild_ob::init();

	add_action("help", "help");
	add_action("info", "info");
	add_action("do_comrades","monks");
	add_action("do_chat", "monk");
}

int do_comrades()
{
        object *usr, temp;
        int i, j;

        usr = filter_array( users(), "filter_monk", this_object() );
        usr = sort_array( usr, "sort_usrs", this_object() );
        if ( sizeof(usr) ) {
           i = sizeof(usr);
           write( 
             "Ŀǰ���� " + i + " λ������ɮ������:\n"
			 "==================================================\n");
           while(i--) {
                printf( "[ %2d ] %s (%s)\n", usr[i]->query_level(),
                  usr[i]->query("short"), capitalize(usr[i]->query("name")) );
           }
        } else 
           write("�ƺ�û���κ���ɮ������....��\n");
        return 1;
}

int sort_usrs( object u1, object u2 )
{
        return (int)levels[u1] - (int)levels[u2];
}

int filter_monk( object plr )
{        
        string name;
        if( (string)plr->query("class")=="monk" && visible(plr,this_player()) ) {
          levels[plr] = (int)plr->query_level();
          if( !levels[plr] || levels[plr] == 0 ) return 0;
          return 1;
        }
        return 0;
}

int do_chat(string arg)
{
        object *usr;
        int chinese_mode, i;
        chinese_mode = can_read_chinese();
        
        if( !arg ) return notify_fail(
          "�����������������ɮ˵ʲ�᣿\n");
        return guild_ob::guild_line(arg);
}

int info(string arg)
{
        
	switch(arg) {
		case "history":
		          cat( GUILD_DATA"c_monk_history" );
			break;
	    case "init":
	              cat( GUILD_DATA"c_monk_init" );
	        break;
	    case "skills":
	              cat( GUILD_DATA"c_monk_skills" );
	        break;
	    case "gonfu":
	            cat( GUILD_DATA"c_monk_gonfu" );
	        break;
	    case "commands":
	            cat( GUILD_DATA"c_monk_commands" );
	        break;
		case "topic":
		case "topics" :
		default : 
			cat( GUILD_DATA"c_topics");
			  break;
	}
	return 1;
}

int help( string arg )
{
    if( !arg || !id(arg) ) return 0;
	cat( GUILD_DATA"c_monkbook");
	return 1;
}
