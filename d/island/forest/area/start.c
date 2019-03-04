#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("有明海");
    set_long(@LONG
这是个十分清澈乾净的湖(lake)，名字叫「有明海」是因为只要天上有
些许光线，这湖就会闪烁异样的光芒。湖畔长满了杨柳，垂挂在湖面上，映
著微波闪闪，身旁偶而吹过几阵使人心旷神怡的清风，不禁使你觉得心情畅
快；如果你觉得时间充裕的话，在这儿泡泡澡，游游泳倒也无妨！
LONG
            );
    set("light",1);
    set_outside("island");
    set("water_source",1);
    set("exits",([
        "west":"/d/island/11,7.island"]) );
    set("item_desc",([
         "lake":@LAKE
一个波光闪闪的小湖，你心想：在这儿游泳应当是一种享受！
LAKE
             ]) );
    set("objects",(["indi":TMOB"indi"]) );
    reset();
}
void init()
{
    add_action("do_swim","swim");
}
int do_swim(string str)
{
    write(@ALONG
    你迫不及待的一下子就往湖里头跳，突然暗潮将你吸到一个莫名其妙的怪地方...
ALONG
         );      
      tell_room( environment(this_player()),
      this_player()->query("c_name")+
      "连衣服都没脱就跳进湖中爽快去了，叫都没用，这个可恶的痞子..\n"
      , this_player() );
      this_player()->move_player(AREA"in","SNEAK");
     tell_room( environment(this_player()),
     "你看到"+this_player()->query("c_name")+"像死鱼般一动也不动的飘了过来...\n"
     ,this_player() );   
   return 1;
}                      
                      
    
