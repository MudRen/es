#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("津鸣城南门");
    set_long(@LONG
这里是魔族的皇城－津鸣城的南门，由这儿仰望都城的部份，心中不由
得为魔族的先进文明感到佩服不已。整座城是由数不尽的梁柱架构而成，或
斜插，或横伸，亦或直挺；虽然令人无法理解，却不会感到不协调，相反的
，还让人忍不住的想开口赞美呢！
LONG
            );
    set("light",1);
    set("exits",([
        "south":AREA"way13",
        "north":CITY"r4"]) );
    
    set("objects",([
        "soldier#2":TMOB"soldier",
        "soldier#1":TMOB"soldier"]) );
  
    set("pre_exit_func",([
            "north":"do_say"]));
    set_outside("island");
    reset();
}

void init()
{ add_action("do_say","say"); }

int do_say(string arg)
{
   if( !present("soldier"))
   return 0; 
   
   if( !arg ){
   write("\n魔族士兵伸手拦下你：喂！等一下，报上通行密码，不然不准过去！\n\n");
   return 1;}
   
   if( arg != "芋头蕃薯") {
   write("\n士兵生气的大吼骂道：喂！这里除了密码之外严禁窃窃私语！\n\n");
   return 1; }
 
   if( !this_player()->query_explore("island#2") ) {
   write("\n士兵恶狠狠地瞪你一眼，说道：不要以为我不知道你密码是骗来的 !\n");
   write("士兵大喊道：再不走的话我要砍人喽 !!\n");
   return 1;}
            
   write("\n士兵和缓的说：嗯！！可以确定你不是武士堡或蜥蜴窝的奸细，好，进去吧！\n\n");
   tell_room( environment(this_player()),
     "士兵点了点头，要"+this_player()->query("c_name")+"赶快通过！\n",
     this_player() );
   this_player()->move_player(CITY"r4","SNEAK");
   tell_room( environment(this_player()),
     this_player()->query("c_name")+"瞪著眼睛，边吱呜边走了过来！\n",
     this_player() );
   return 1;
}   
   
    
