#include <mumar.h>
inherit ROOM;
 
int ent;
void create()
{
        ::create();
  set_short("牧马关教场");
  set_long( @CLong
你走到牧马关内的营地，这片空地上整齐地排列著难以数计的帐篷，而这儿就是
士兵们的家。在这弥漫著肃杀气息和震天杀声的广场上，你实在很难想像这些士兵怎
麽能睡得著。广场的北面靠墙的地方有个平台(platform)，东边是一间伙房，正传来
阵阵菜香。
CLong
);
set_outside("eastland");
 
set("c_item_desc",([
    "platform":"@@to_platform","door":"@@to_door"
     ]) );
 
set("search_desc",([
    "platform":"@@to_search_platform", "door":"@@to_search_door"
     ]) );
 
set("exits",([
               "south":MUMAR"square03",
               "east":MUMAR"kitchen",
               "west":MUMAR"square05",
             ]));
set("objects",([
               "soldier":MOB"old_soldier" ]) );
reset();
}
 
void init()
{
    add_action("to_enter","enter");
}
 
int to_enter()
{
   if (ent==1) {
     write("门是关著的，没有把手又没有钥匙孔，你实在想不到怎麽打开..\n");
     }
   else
     {
     write("你进入了门内..才突然发现你什麽也踩不到。\n");
     write("你整个人摔了下去，失声喊出...「哇!!.....」\n.\n.\n.\n.\n.\n.\n.\n");
     this_player()->move_player(MUMAR"secret01",({
      "",this_player()->query("c_short")+"进入了密门\n。",
      "",this_player()->query("c_short")+"从上面摔了下来，姿势乱难看的不说，叫得也比大声的。\n",
      }),"");
     }
   return 1;
}
 
string to_search_platform()
{
      return "当你仔细检查这座司令台时，发现在台下有道密门(door)...\n";
}
 
string to_search_door()
{
    if (ent==1) {
      ent=2;
      return "当你仔细检查这道门时，触动了门下的机关，密门突然隆隆地开了...\n";
      }
    else
      {
      ent=1;
      return "当你仔细检查这道门时，触动了门下的机关，密门突然隆隆地关上了...\n" ;
      }
}
 
string to_platform()
{
    return "一座司令台，站在上面可以看到整个牧马关内的活动情形。\n";
}
 
string to_door()
{
  if (ent==1)
    return "一道一次只能让一个人通过的小密门(door)。\n";
  else
    return  "一道一次只能让一个人通过的小密门(door)，它现在开著。\n";
}
 
void reset()
{
  ::reset();
  ent=1;
}
