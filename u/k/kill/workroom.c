#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        ::create();
      set_short( "���������" );
        set_long(
             "������������������������ݣ����￴�����ƺ����ң������\n"
             ""+HIW"��ʿ�ʹ�����"+NOR"���������ң����ԲŻ�...................\n"
             "������羭�����ڼң���������ֻ���õ��������Ҹ��ˡ�\n"NOR,
        );
        set( "light",1 );
        set( "exits", ([
    "west" : "u/b/boss/workroom.c",
    "north" : "/d/mage/tower/time.c",
    "healer" : "/d/healer/building/healer_guild.c",
    "knight" : "/d/knight/fortress/knight_guild.c",
    "thief" : "/d/thief/hall/thief_guild.c",
    "mage" : "/d/mage/tower/mage_guild.c",
    "monk" : "/d/monk/guild/monk_guild.c",    
    "scholar" : "/d/scholar/scholar/scholar_guild.c",

        ]) );
}
