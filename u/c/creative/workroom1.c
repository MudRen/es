#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        ::create();
        set_short( "���ñ���" );
        set_long("     ����ȫ���ܵ���--ȫ�ܴ����ߵı����������������
        ������̩ͨ��������Ķ��������û����,����һ�����ҿ���\n
        ���д��ջ�!\n");
        set( "light",1 );
        set( "exits", ([
      "guild" : "/d/wiz/wiz_hall",
       ]) );
}
