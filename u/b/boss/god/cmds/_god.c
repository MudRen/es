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
用法 : god message
这个指令用来同目前线上的魔神通信。

参考: god
HELP
              );
        return 1;
}
