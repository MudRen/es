#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        ::create();
      set_short( "�������޳�" );
set_long(
"�ö�"+HIB"ħ��սʿ"NOR"������ȥ����Ҷ���Ŭ���Ľ����Լ���\n"
"ϣ����Ϊ���յ�"+HIC"ǿ��"+NOR"��\n"
  NOR
        );
        set( "light",1 );
        set( "exits", ([
    "east" : "/u/b/boss/god/guild/god_guild.c",
        ]) );
}
