
// Deathland/ruin1/down03.c

#include "../echobomber.h"

inherit DOORS;
inherit ROOM;

void create()
{
	 ::create();
     set_short("the ruin","�ż����´�����");
     set_long(@Long
Long
,@CLong
�������ż��ĵ��´����� ,�ƺ�������������ˮ��ʳ��ĵط� .����ĵ�����ǰ
��ĵط���ͬ ,ʮ��Ǭ�� .\��\��\��ط��Ǵ����Ұ� .��������ط�ȴ��һ������ë��
�Ȼ�ĸо� .
CLong
);
     set("objects",([
         "wight":Monster"/wight02",
         ]) );
     
     set("exits",([
         "north":Deathland"/ruin1/down02",
         ]) );
     create_door("north","south",([
             "name":"stone door",
             "c_name":"ʯ��",
             "keyword":({"stone door","door",}),
             "c_desc":"ʯ��",
             "status":"closed",
             "desc":"a stone door",
                     ]) );    
     ::reset();
}

void init()
{
    this_player()->set_explore("deathland#18");
}
