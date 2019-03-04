
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("well","�����ļ���");
  set_long(@Long
Long
,@CLong
һ���ǳ��ƾɵĵط�,������֩�����ͻҳ�,����ǽ�Ǳ���һ�߾޴�ĹǺ�(skeleton)
��һ������.�ƺ�����Ӧ���Ǹ�����.����һ�ߵ�ǽ����һ������(stair),�ƺ�����ͨ���
�ߵĵط����뿪����.
CLong
);

set("c_item_desc",([
    "stair":"һ������,ͨ���ϲ�ķ���.\n",
    "skeleton":"һ���޴�ĹǺ�,�ɴ�С���ж�Ӧ���Ǿ��˵ĹǺ�\n",       
    "wall" : "һƬ�������ǽ��,����������ֵ�����,�ƺ��Ǿ����������\n"       
           ]) );
set("search_desc",([
     "skeleton":"@@to_search_skeleton",     
          ]) );

set("exits",([
     "northeast":Deathland"/dwarf/well05",
     ]) );
 ::reset();
}

void init()
{
   add_action("to_climb","climb");
}

int to_climb(string str)
{
    if(!str||str!="stair") return 0;
    else {
      this_player()->move_player(Deathland"/dwarf/prison02","SNEAK","");
      return 1;
      }
}

string to_search_skeleton()
{
   return "�㷢����߹Ǻ����ֺ�����ǽ���ϻ�Щ����\n";
}
