#include <mumar.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("御风楼");
  set_long( @CLong
你走进了一间极为华丽的房间，四周的墙上挂满了镶满宝石的刀剑，地上则铺著
一件带著虎头的虎皮。一张纯金的座椅放置在北边的窗前，椅把上则放著一只象牙雕
的望远镜。高高的天花板上挂著一盏琉璃灯，照亮整个房间。角落有个梯子，可以通
往楼下。
CLong
);
set("light",1);
set( "pre_exit_func", ([ "east" : "check_button" ]) );
set("exits",([
               "east":MUMAR"stage07",
               "down":MUMAR"stage02"
             ]));
set("objects",([
               "general":MOB"lee"]) );
reset();
}
int check_button()
{
  if( wizardp(this_player()) || this_player()->query_temp("give_button") ) return 0;
  else {
        tell_object(this_player(),
                    "不知道这是什麽保全的设计，不过你就是走不过去。\n" );
        return 1;
       }
}
