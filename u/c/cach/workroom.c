//sage �޸���  98-5-11 13:11
#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
      set_short( "��ի" );
        set_long(
             "����һ����˶���ķ��䣬�ڷ��м����һ�������������������£�\n"
     "���������鱾��\n"
        );
        set("exit_suppress",({"down"}));
        set( "light",1 );
        set( "exits", ([
    "down"    : "/u/s/sage/test/charch1.c",
    "up"      : "/d/wiz/wiz_hall",
    "east"    : "/u/s/sage/home/work.c",
    "healer"  : "/d/healer/building/healer_guild.c",
    "knight"  : "/d/knight/fortress/knight_guild.c",
    "mage"    : "/d/mage/tower/mage_guild.c",
    "monk"    : "/d/monk/guild/monk_guild.c",
    "scholar" : "/d/scholar/scholar/scholar_guild.c",
    "thief"   : "/d/thief/hall/thief_guild.c",
    "killer"  : "/d/killer/guild/killer_guild.c",
        ]) );
}
