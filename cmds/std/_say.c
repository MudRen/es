//#pragma save_binary
#include <mudlib.h>
inherit DAEMON;

int cmd_say(string str)
{
	if (!str) {
	write("����������.\n");
	say( this_player()->query("c_name")+"��������Ĳ�֪����˵ʲ��.\n");
	return 1;
	}
	printf( "��˵����%s\n",str);
	say( this_player()->query("c_name") + "˵����" + str + "\n");

	return 1;
}
 
int help()
{
	write ( @HELP
ʹ�ø�ʽ: say <��Ϣ>

˵������������ͬһ�������˶�����������ʱ�ǽ��յ��ֶ�֮һ.
HELP
	);
	return 1 ;
}