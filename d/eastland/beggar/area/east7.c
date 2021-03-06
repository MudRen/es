#include "../dony.h"

inherit ROOM;

int corner_search,have_exit;

void create()
{
	::create();
        set_short( "east7", "村路" );
	set_long(@C_LONG
你现在正走在一条由碎石子铺成的村路上,村路延申到这里似乎已是尽头。村
路不很大,约可容纳一匹马行驶的宽度。在路旁长著一些奇形怪状的植物 ,那上面
更开著许多不知名的小花,小花闻起来有点淡淡的香味, 那味道说不出的使得你心
旷神怡。鸟语蛙呜, 顿时你烦恼尽失,站在这里真是有如仙境。你的东边是一间白
色的建筑物,原来是祠堂 ( church )。
C_LONG
	);
        set_outside("noden");
	set( "exits", ([
	           "south":DBEGGAR"east5.c"
	]) );
        set( "item_func", ([
                 "corner" : "exam_corner"
        ]) );
        set("c_item_desc",([
                 "church":"一间白色的老旧祠堂,你可以进去看看 ( enter )。\n"
        ]) );
        corner_search = 0;
     reset();
}
void init()
{
      add_action("do_touch","touch");
      add_action("do_search","search" );
      add_action("to_enter","enter");
}

int to_enter(string str)
{
    if (!str) return 0;
    if (str=="church") {
        this_player()->move_player(DBEGGAR"church",({
            "%s进入了一间老旧的祠堂。\n",
            "%s从外面走了进来.\n"}),"");
        return 1;
    }
    else {
        write("你想进入那里?\n");
        return 1;
    }
}

void exam_corner()
{
    if( !corner_search ) {
       write("你觉得这个角落怪怪的,可以找找看 ( search ) 是否有什麽?\n");
       return;
    }
    write("北边角落的泥土已经被弄松了,说不定墙会倒了下来。\n");                                                    
}

int do_touch(string arg)
{
    if ( !corner_search )
            return notify_fail("你要做什麽?\n");
    
    if ( !arg || arg != "corner" )
        return notify_fail("你要碰什麽东西？\n");
    
    if ( !query("exits/north") ) {
       write(@C_LONG
你伸出手触摸北边被弄松的角落，突然『碰』的一声, 北边的墙壁哗啦啦地倒塌
了,瞬间把你给压的扁扁的。唉呀!你隐隐觉得不对,好像中计了!!!
C_LONG
       );
    (DBEGGAR"east8")->set("exits/south",DBEGGAR"east7");
    if ( ( this_player() )->query_temp("jail_asked") ) {
       this_player()->receive_damage(15);
    } else { this_player()->receive_damage(100); }
    this_player()->set_temp("block_command",1);
    call_out("recover",15,this_player());
    tell_room(this_object(),this_player()->query("c_name")+
        "伸手摸摸北边的角落,突然『碰』的一声，北边的墙倒塌了把他给压扁了..\n",
         this_player() );
    set("exits/north",DBEGGAR"east8");
      return 1;
    }
    write("你摄手摄脚地拿著泥巴把北边的墙偷偷给封了起来......\n");
    corner_search=0;
    delete("exits/north");
    (DBEGGAR"east8")->delete("exits/south");
    return 1;
}                                        

void recover(object toucher)
{
   toucher->set_temp("block_command",0);
   tell_object(toucher,"你满身灰尘地爬了起来,甚是狼狈。\n");
}

int do_search(string arg)
{
   if( !arg || arg!= "corner" ) 
      return notify_fail("你要找什麽呢?\n");
   
   write( "你倒是没有找到什麽值钱的东西,反而北边角落的泥土被你弄松了。\n");
   corner_search=1;                        
   return 1;
}
void reset()
{
    (DBEGGAR"east8")->delete("exits/south");
    delete("exits/north");
    ::reset();
}
                                                                          