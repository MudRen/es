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
"pray" : "/d/noden/farwind/charch",
"mage" : "d/mage/tower/mage_guild",
"knight" : "d/knight/fortress/knight_guild",
      "guild" : "/d/wiz/wiz_hall",
       ]) );
}
