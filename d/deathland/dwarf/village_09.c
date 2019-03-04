#include "../echobomber.h"

inherit ROOM;

void create()
{
  ::create();
  set_short("the stranger place","һ����ֵĵط�");
  set_long(@Long
Long
,@CLong
һ����ֵĵط�,���˼����Ȼ����һ��..........
һ����ֵĶ��ڳ����ھ��ڱ�,����Լ���������,\��\�ǽ�ȥ���ڿ�һ��.
����һ��а���Ӷ��ڷ���......
CLong
);
set( "c_item_desc",([
     "hole":"һ������ֵĶ�,�ƺ�Σ���������������������.\n"
     ]) );
  
set( "exits",([
             "down":Deathland"/dwarf/well01",
             ]));

}

void init()
{
   add_action("to_climb","climb");
   add_action("to_enter","enter");
}

int to_climb()
{
    this_player()->move_player(Deathland"/dwarf/village_07",({
      "%s����������.\n",
      "%s �Ӿ������˳���.\n",
      }) ); 
    return 1;
}

int to_enter(string str)
{
   if (!str||str!="hole") return 0;
    
   this_player()->set_explore( "deathland#16" ); 
   this_player()->move_player(Deathland"/dwarf/village_0a",({
      "%s�������Ǹ�а��Ķ���.\n",
      "%s���������.\n",
       }) );
    return 1;
    
} 
