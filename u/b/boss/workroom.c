#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        ::create();
      set_short( "��ʿ�ı���" );
        set_long(
             "����һ����������ķ��䣬û��һ��ҳ���������\n"
             ""+HIW"��ʿŮ��"+NOR"���������ԭ�ʰ�!\n"NOR,
        );
        set( "light",1 );
        set( "exits", ([
    "up"      : "/d/wiz/wiz_hall",
    "healer"  : "/d/healer/building/healer_guild.c",
    "knight"  : "/d/knight/fortress/knight_guild.c",
    "mage"    : "/d/mage/tower/mage_guild.c",
    "monk"    : "/d/monk/guild/monk_guild.c",
    "scholar" : "/d/scholar/scholar/scholar_guild.c",
    "thief"   : "/d/thief/hall/thief_guild.c",
        ]) );
}
