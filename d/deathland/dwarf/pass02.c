
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("storage room","������");
  set_long(@Long
һ��ܴ�Ĵ�����,�������һ�������Ӱ˵Ķ���.��һ���ܳ�������(ladder)ͨ������
,��������һ�������ĵ�����
Long
);

set("c_item_desc",([
    "ladder":"һ���ܳ�������.\n",
   ]) );
set("exits",([
     "northdown":Deathland"/dwarf/pass01.c",
     ]) );
 ::reset();
}

void init()
{
 add_action("to_climb","climb");
}

int to_climb(string str)
{
  if(!str||str!="ladder") return 0;
  else {
    write("������������,������\�õ�ʱ�����������ǳ���������\n");
    say(this_player()->query("c_name")+"����������\n");
    this_player()->move_player(Deathland"/palace/pa_0b","SNEAK","");
    return 1;
  } 
}
