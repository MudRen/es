#include <mudlib.h>

inherit ROOM;

#include <ansi.h>
void create()
{
        ::create();
     set_short( "˯��" );
       set_long(
 "    ����ʥ�˵�˯����������ɾ����ˣ������м���ŵĲ���˵���Ǵ���\n"
 "û��ʲô�ر��,��ͷ����һ����Ƭ(picture)���ڴ����Ա߷���һ�Ż�\n"
 "ױ�������������ȫ������ʥ�˺�ϲ����������\n"
        );
     set( "light",1 );
     set("item_desc",([
              "picture" : "����ʥ�˺���δ���ŵ����ӵĺ��գ��������Ͽ�\n"
                          "���������Ƿǳ��Ҹ��ģ�����Ƭ���½ǣ��м���\n"
                          "С�֣�"RED"Ů��(qwe)����Ȼ�����Ҷ�ȥ������������\n"
                          "�����㣬��Ը�����һ��һ����"NOR"\n"
         ]));
     set( "objects", ([
          "knight" : "/u/s/sage/test/deathknight.c",
         ]) );
     set( "exits", ([
           "west"  : "/u/s/sage/workroom",
           "south" : "/u/s/sage/guild/gc.c",
        ]) );
}
