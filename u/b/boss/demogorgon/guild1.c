#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        ::create();
      set_short( "�������޳�" );
set_long(
"�ö�"+HIB"ħ��սʿ"NOR"������ȥ����Ҷ���Ŭ���Ľ����Լ���\n"
"ϣ����Ϊ���յ�"+HIR"ǿ��"+NOR"��\n"
  NOR
        );
        set( "light",1 );
        set( "exits", ([
    "west" : "/u/b/boss/demogorgon/demogorgon.c",
        ]) );
}
