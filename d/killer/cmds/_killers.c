//#pragma save_binary

// This command is for monk only. It list all gonfus now the monk
// has learned. Created by Angel, almost rewriten by Kyoko@Eastern.Stories.

#include <mudlib.h>
#include "../killer.h"

inherit DAEMON;

int cmd_killers()
{
        seteuid(getuid());
        ORG_OBJ->list_guild_members() ;
        return 1;
}

int help()
{
        write( @HELP
�÷� : killers
���ָ����г�Ŀǰ���ϵ�ɱ�֡�

�ο�: killer
HELP
              );
        return 1;
}
