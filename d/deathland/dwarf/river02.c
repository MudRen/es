
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("???","�ӱ�");
  set_long(@Long
Long
,@CLong
������һ�����ټ���ĺӴ�, ��ʹ��վ�ںӱ���һ���ܸ��ܵ������ٶ�.
CLong
);

set("c_item_desc",([
    "river":"һ�����ټ���ĺӴ�.\n",
           ]) );

set("exits",([
     "east":Deathland"/dwarf/river03",
     "west":Deathland"/dwarf/river01",
     ]) );
 ::reset();
}

void init()
{
   add_action("to_swim","swim");
}

int to_swim()
{
    write("���ˮ������̫������,����������º�ȥ�Ļ�,\��\��\�����ֱ����\n"
          "������������ǰ.\n");
    return 1;      
} 
