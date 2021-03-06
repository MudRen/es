#include "../echobomber.h"

inherit ROOM;

void create()
{
  ::create();
  set_short("the mystic altar","神秘祭坛");
  set_long(@Long
Long
,@CLong
一处已废弃多年的祭坛.但是仍然有祭祀的行动,某个人似乎利用这里来进行一种秘密
的祭典.祭坛上有著一团熊熊烈火(fire)在燃烧著.
CLong
);
  set( "light",1 );
  set( "c_item_desc",([
       "fire":"一团烈火,似乎永远不会熄灭的样子,你想试著去熄灭(extinguish)那团火吗? \n"
     ]) );
  
  set( "exits",([
             "south":Deathland"/dwarf/village_0a",
             ]));

  reset();
}

void init()
{
	add_action("to_extinguish","extinguish");
}

int to_extinguish(string str)
{
   object *items,who;
   int i,j;
   
   if (!str||str!="fire") return 0;
   who=this_player();
   items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if ( ( j=items[i]->query("quest_action/muse_filled") ) ) {
              if (j==3) { //红色
              write("你把你黑色瓶子的水倒下去, 此时火暂时地小了些, 於是你赶快地\n"
                    "把火中的书拿出来. 就在你拿出书的同时, 火又再度地大了起来. \n"
                    );
              items->set("quest_item/study_book",1);
              who->set_explore("deathland#17");
              }
              else 
              write("你把你黑色瓶子的水倒下去,但是火却一点也没有变小.\n");
              items->set("quest_action/muse_filled",0);
              return 1;
              }
  write(
  "当你尝试著去熄灭那一团火的时候, 你发现那团火中有一本厚厚的书籍, 但是由於火\n"
  "的温度实在太高了, 你无法拿出那本书来. \或\许\你应开去找水来把火弄熄, 但是一般\n"
  "的水应开没有办法浇熄它的. 你能找到能够弄熄这团熊熊烈火的水来吗? \n");
   
   return 1;
}

