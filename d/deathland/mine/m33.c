
#include "../echobomber.h"

inherit ROOM;

int be_digged;
void create()
{
	::create();
  set_short(" Drawf mine ","矮人矿坑");
  set_long(@Long
Long
,@CLong
这里是矿坑的深处.你能看到的是一个周围的岩壁充满著被挖掘的痕迹以及
用木头架设著以免塌陷的岩洞.在地上有铁轨铺设著.专供运矿车通行使用.然而
这里是铁轨的尽头,前面的路似乎被一堆塌陷的石块与木头挡住了去路.
CLong
);
set("c_item_desc",([
    "riprap":"@@to_search_riprap",
    "chest":"@@to_look_chest", 
     ]));
set("search_desc",([
    "riprap":"@@to_search_riprap",
    "here":"@@to_search_here",
    "chest":"@@to_look_chest",
    ]) );
set("direction","block");
set("exits",([
             "northeast":Mine"/m21",             ]));
reset();
}
string to_search_here()
{
     return "当你搜索这地方的时候,你的目光的焦点放在那堆堵住路的乱石(riprap)上\n";
}

string to_search_riprap()
{
    if (be_digged==0)
        return "一堆杂乱无章的石头,但是似乎在它的後面隐藏著一个秘密\n";
    else 
      return "一堆杂乱无章的石头.但是似乎有人曾挖掘过它\n"; 
}

int to_find_excavate(string str)
{
    object ob1;
    if ( str!="riprap" ) {
      tell_object(this_player(),"你想挖掘甚麽?\n" ); 
      return 1;
      }
    if ( be_digged!=0 ) { 
      tell_object(this_player(),"你挖了再挖,还是没有发现任何东西.\n"); 
      return 1;
      }
    else {
      tell_object(this_player(),
        // "you find a mystic chest in the underground,but seems no key to unlock it!\n " 
         "你发现了一个神秘的宝箱(chest),但是似乎被上锁了\n" 
          );
      be_digged++;   
      return 1;
      }
}
string to_look_chest()
{
    if ( be_digged==0 )
      return 0;
    else 
      return "一个很神秘的宝箱\n";
}
void reset()
{
  ::reset();
  be_digged=0;
}

