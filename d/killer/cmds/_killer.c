#include "../killer.h"

inherit DAEMON;

int cmd_killer(string arg)
{
        seteuid(getuid());
        ORG_OBJ->guild_line(arg);
        return 1;
}

int help()
{
        write( @HELP
�÷� : killer message
���ָ������ͬĿǰ���ϵ�ɱ��ͨ�š�

�ο�: killer
HELP
              );
        return 1;
}
