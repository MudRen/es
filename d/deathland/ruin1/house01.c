
// Deathland/ruin1/house01.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	 ::create();
     set_short("the council","���");
     set_long(@Long
Long
,@CLong
�������ż������ .һ���ܴ�Ľ���, ����Χ����һ���ŵ���λ, ���м�����ϯ̨
������ľ���Ƚ�����, ����ط��ƺ���һ������ĵط�, �ƺ�û���κ���ɱ������. 
CLong
);
     set("search_desc",([
         "here":"@@search_here",
         ]) );
     set("exits",([
         "out":Deathland"/ruin1/ruin11",
         ]) );
     set("crystal",1);
     reset();
}

string search_here()
{
    object item;
    if ( query("crystal") ) {
      item=new(Object"/crystal01");
      item->move(this_object());
      this_player()->set_explore("deathland#19");
      set("crystal",0);
      return "������ϸ�Ѳ������ʱ��, �㷢����һ����ɫ��ˮ��.\n";
      }  
    return "�ƺ��������Ѳ��������.\n";
}

void reset()
{
   ::reset();
   set("crystal",1);
}
