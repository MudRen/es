#include "../echobomber.h"

inherit ROOM;

int letter;
void create()
{
	::create();
  seteuid(getuid());
  set_short("well","�����ļ���");
  set_long(@Long
Long
,@CLong
һ���ǳ��ƾɵĵط�,������֩�����ͻҳ�,����ǽ�Ǳ���һ�߾޴�ĹǺ�(skeleton)
��������.....����һ�ߵ�ǽ����һ������(stair),�ƺ������뿪����.
CLong
);

set("c_item_desc",([
    "stair":"һ������,ͨ���²�ķ���.\n",
    "skeleton":"@@to_look_skeleton",
           ]) );
set("search_desc",([
     "skeleton":"@@to_search_skeleton",     
          ]) );

set("exits",([
     "down":Deathland"/dwarf/prison",
     ]) );
 ::reset();
}

void reset()
{
   ::reset();
   letter=0;
}

string to_look_skeleton()
{
   switch(letter) {
   case 0:
   return "һ���޴�ĹǺ�,�ɴ�С���ж�Ӧ���Ǿ��˵ĹǺ�,����������\n"
          "�ƺ�����һ������\n";
   case 1:
   return "һ���޴�ĹǺ�,�ɴ�С���ж�Ӧ���Ǿ��˵ĹǺ�\n";
   }
}

string to_search_skeleton()
{
   object ob1;
   switch(letter) {
   case 0:  
     letter=1;
     ob1=new(Object"/letter01");
     ob1->move(this_player());
     this_player()->set_explore( "deathland#4" );
     return "��ӹǺ������з�����һ���ƾɷ��Ƶ���ֽ\n";
   case 1:
     return "��һ����ϸ��������,��ֻ��ȷ�����Ǹ����˵ĹǺ�\n"; 
   }  
}
