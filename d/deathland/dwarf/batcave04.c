
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("bat cave","����");
  set_long(@Long
Long
,@CLong
���Ѿ�����������ľ�ͷ.��������Ϣ�Լ����ܵ�ζ�����˾��úܲ����.����ط�
�ƺ������˼�,��Ϊ���������㹻�ĵ�����������������.
CLong
);

set("search_desc",([
    "here":"@@to_search_here"
    ]) );
set("exits",([
     "south":Deathland"/dwarf/batcave03",
     ]) );
set("beast",0);
reset();
}

string to_search_here()
{
   object monster;
   if ( !present("beast") && !query("beast")) {
     monster=new(Monster"/beast01");
     monster->move(this_object());
     set("beast",1);
     this_player()->set_explore("deathland#14");
     return "һֻ�Ӵ�ľ��޺�Ȼ�����������ǰ.\n";
     }
   return "ûʲ���·���.\n";  
}

void reset()
{
   ::reset();
   set("beast",0);
}
