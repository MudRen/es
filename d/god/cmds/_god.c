#include "../god.h"

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
�÷� : god message
���ָ������ͬĿǰ���ϵ�ħ��ͨ�š�

�ο�: god
HELP
              );
        return 1;
}
