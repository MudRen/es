//#pragma save_binary

#include <mudlib.h>
#include <gonfu.h>

inherit DAEMON;

int help();

int cmd_force(string str)
{
	if( !str ) return help();
	if( !this_player()->query("max_fp") )
		return notify_fail("���������� ?\n");

	if( str == "on" ) {
		this_player()->set_temp("enable_inner_force", 1);
		write("�������ս������������������ս��������\n");
		return 1;
	}   

	if( str == "off" ) {
		this_player()->delete_temp("enable_inner_force");
		write("�������ս���в�ʹ�������Խ�ʡ����������ġ�\n");
		return 1;
	}
	return help();
}

int help()
{
write( @C_HELP
		
ָ���ʽ: force [on|off]
 
���ָ�����������趨��ս�����Ƿ���������������ս��������

C_HELP
		);
    return 1;
}
