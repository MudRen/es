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
""HIG"����"+NOR"����а��һЦ��\n"NOR,
        );
        set( "light",1 );
        set( "exits", ([
    "west" : "/u/b/boss/god/guild/god_guild.c",
        ]) );
}
