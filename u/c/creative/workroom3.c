#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        ::create();
 set_short( ""+HIW"���ñ���"+NOR"" );
        set_long("����ȫ�ܵ�"+HIR"��"+NOR"--ȫ�ܴ����ߵı����������������
     ������̩ͨ��������Ķ��������û����,����һ�����ҿ��ܻ��д��ջ�!\n");
        set( "light",1 );
        set( "exits", ([
      "guild" : "/d/wiz/wiz_hall",
       ]) );
}
