#include <uid.h>
#include <config.h>
#include <daemons.h>
#include <net/daemons.h>
#include <commands.h>
#include <mudlib.h>
inherit OBJECT;
void create() { seteuid( getuid() ); }
mixed eval()
{
"/d/m/moon/_who.c"->cmd_who("-l");
}
