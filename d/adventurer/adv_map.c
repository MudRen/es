//#pragma save_binary

#include <mudlib.h>
#include "adventurer.h"

inherit GUILD_OB;
inherit MAP;
inherit OBJECT;

void create()
{
	guild_ob::create();
	seteuid(getuid());
	set_class_name("adventurer");
	set_size( 7, 7 );
#include <compress_obj.h>
	set_name("map", "��ͼ");
	set_short("ð��ר�õ�ͼ");
	set_long(@LONG
����һ��ʮ��������ð����ר�õ�ͼ����һλ���귢��ͨ���������
��ΰ��ð���������ƶ��ɡ��������ð���߿����ṩ�ܴ�İ�������
����\ help map �Ի�ý�һ����˵����
LONG
	);

	set( "unit", "��" );
	set( "weight", 5 );
	set( "extra_look", "$N����ð����ר�õ�ħ����ͼ��\n");
}

void init()
{
	// Apply guild_ob checks
	guild_ob::init();

	// Apply map functions
	std_map::init();
	
	add_action("help", "help");
	add_action("info", "info");
	add_action("do_check", "check" );
	add_action("do_fellows", "fellows");
	add_action("do_chat", "adv");
}

int do_check(string str)
{
	object dest;
	int my_level, dest_level;

	if( !str || str=="" || !(dest= present(str, environment(this_player()))) )
		return notify_fail("ָ���ʽ: check <����>\n");
	my_level = (int)this_player()->query_level();
	dest_level = (int)dest->query_level();
	if( my_level < dest_level ) write("�Է��ĵȼ�����ߡ�\n");
	if( my_level == dest_level ) write("�Է�����ͬ�ȼ���\n");
	if( my_level > dest_level ) write("�Է��ĵȼ�����͡�\n");
	return 1;
}

int do_fellows()
{
	return guild_ob::list_guild_members();
}

// The guild channel
int do_chat(string arg)
{
	if( !arg )
		return notify_fail("���������ð����˵ʲ�᣿\n");
	return guild_ob::guild_line(arg);
}

int info(string arg)
{
	switch(arg) {
		case "history": cat( GUILD_DATA+"c_adv_history" );
			break;
	    case "commands": cat( GUILD_DATA+"c_adv_commands" );
			break;
		case "topics":
		default: 
write( @C_TOPICS
ð���߹�����һ����������˵Ĺ��ᣬ������� info ָ��ȡ���й������������
Ѷ:
    history    - �й�ð���߹������ʷ��
    commands   - �й�ð������ʹ�õ�����ָ�
    
C_TOPICS
			);
			break;
	}
	return 1;
}

int help(string arg)
{
	if( !arg || arg!="map" ) return 0;
	cat(GUILD_DATA+"c_adv_map");
	return 1;
}
