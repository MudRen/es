#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        ::create();
      set_short( ""+HIW"PK�᳡"+NOR"" );
set_long(
"�������ר�õ�PK���أ��������"+HIR"��Ѫ"+NOR"��"+HIW"ʬ��"+NOR"��\n"NOR,
"һ����������������������������ֲ���ͻȻ��\n"
""+HIB"����"+NOR"����а��һЦ��\n"NOR,
        );
        set( "light",1 );
        set( "exits", ([
    "east" : "/u/b/boss/demogorgon/demogorgon.c",
        ]) );
}
