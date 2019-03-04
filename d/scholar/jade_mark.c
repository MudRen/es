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
	set_name("jade mark", "���");
	add( "id", ({ "mark", "jade" }) );
	set_short("���");
	set_long( @LONG
����һ�龧Ө��͸��������ĥ���ɵ�������Թ�����������������ϲ��
���һ�������Դ����Լ����е��˸񣬾�����һ��������Ͼ���������
��ᰳ���ī�����˱��������ʳ��������ģ�������� help jade
�õ��й����������һЩ���ϡ�
LONG
	);

	set( "unit", "��" );
	set( "weight", 1 );
	set( "extra_look", "$N�������������ţ����������Ϣ����������һ�龧Ө��͸������\n");
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
		return notify_fail("�������������˵ʲ�᣿\n");
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
