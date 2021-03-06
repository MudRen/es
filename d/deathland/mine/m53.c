
#include "../echobomber.h"

inherit ROOM;

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
     ]));
set("search_desc",([
    "riprap":"@@to_search_riprap",
    "here":"@@to_search_here",
    ]) );
set("direction","block");
set("exits",([
             "north":Mine"/m47",
             ]));
reset();
}
string to_search_here()
{
     return "当你搜索这地方的时候,你的目光的焦点放在那堆堵住路的乱石(riprap)上\n";
}

string to_search_riprap()
{
    return "一堆杂乱无章的石头,但是似乎在它的後面隐藏著一个秘密\n";
}

int to_find_excavate(string str)
{
    object ob1;
    if ( str!="riprap" ) {
      tell_object(this_player(),"你想挖掘甚麽?\n" ); 
      return 1;
      }
    tell_object(this_player(),
             "这些石头在你的努力之下,终於有些松动了,但是你不能挖通这里,\n"
             "虽然一些声音断断续续由石头的後面传出,但是你只能呆呆地站在\n"
             "这里而束手无策,难道这些小石头能困住你吗?不行的,只是你没有\n"
             "使力点,如果能有一股大的力量来冲击它,\或\许\你可以发现隐藏於\n"
             "後的秘密.\n");
    this_player()->set_explore("deathland#7");
    return 1;
}
