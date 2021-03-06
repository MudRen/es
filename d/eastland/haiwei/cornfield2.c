
#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("稻田");
        set_long( @C_LONG_DESCRIPTION
你现在正走在海威镇的南方的稻田里，此处现今是一片绿油油的稻草，风一吹来
草随风四处摇曳，不过此刻田中一片泥泞，走在此处你要万分小心以免溅的满身泥拧
不过田的中央有一个小洞(hole)。
C_LONG_DESCRIPTION
        );
        set("layuter_hole",1);
    set("item_desc",([
        "hole":"这是一个又深又窄的洞穴，由此望去底下一片漆黑，你想或许\可以爬下去(climb down)。\n"]));
        set_outside( "haiwei" );
        set( "light", 1 );
        set( "exits", ([ 
                "south" : "/d/eastland/haiwei/cornfield4",
            "east" :  "/d/eastland/haiwei/cornfield"
           ]) );
        set("objects",([
            "fox1":"/d/eastland/haiwei/monster/fox",
            "fox2":"/d/eastland/haiwei/monster/fox"]));   
        reset();
}

void init()
{
 add_action("do_climb","climb");   
}

int do_climb(string arg)
{
  if (!arg || arg!="down") return 0;
     write("这洞太深了你无法爬下去，你也许\需要某些物品才有可能爬下去。\n");
     return 1;
    
 }
