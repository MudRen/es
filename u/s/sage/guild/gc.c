//�����ſڵĹ㳡
#include <mudlib.h>

inherit ROOM;
inherit DOORS;

void create()
{
        ::create();
     set_short( "�㳡" );
        set_long(
       "һ��Ư������ˮ�������ڹ㳡����,Ȫˮ�������������㳡�ϲ������ӣ�\n"
  "���ǻ�վ�������򿴻�ι�����ֳ�һƬ��ƽ�ľ���\n"
          );
     set( "light",1 );
     set( "exits", ([
          "north" : "/u/s/sage/home/work.c",
        "south" : "/u/s/sage/guild/killer_guild.c",
        ]) );
     create_door("south", "north", ([
                "keyword"       : ({ "tree door", "door" }),
                "name"          : "tree door",
                "c_name"        : "ľ��",
                "c_desc"        : "һ�����õ�ľ��",
                "status"        : "closed",
        ]) );

}
