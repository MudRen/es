#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("内城南门");
    set_long(@LONG
这里是树雷王家居住处－内城的南门，由这儿仰望都城的部份，心中不
由得为魔族的先进文明感到佩服不已。整座城是由数不尽的梁柱架构而成，
或斜插，或横伸，亦或直挺；虽然令人无法理解，却不会感到不协调，相反
的，还让人忍不住的想开口赞美呢！
LONG
            );
    set("light",1);
    set("exits",([
        "south":CITY"r6",
        "north":CITY"inway4"]) );
    
    set("objects",([
        "soldier#2":TMOB"warrior",
        "soldier#1":TMOB"warrior"]) );
  
    set("pre_exit_func",([
            "north":"do_say"]));
    set_outside("island");
    reset();
}

void init()
{ add_action("do_say","say"); }

int do_say(string arg)
{
   if( !present("warrior"))
   return 0; 
   
   if( !arg ){
   write("\n魔族战士伸手拦下你：喂！等一下，报上通行密码，不然不准过去！\n\n");
   return 1;}
   
   if( arg != "很久很久以前有一个老公公和一个老婆婆") {
   write(@ALONG
    战士生气的大吼骂道：不知道密码去问将军，不要在这里窃窃私语
，小心我海Ｋ你一顿哦！
ALONG
         );
   return 1; }
   
   if( !this_player()->query_explore("island#3") ) {
   write("\n战士凝望著你的眼睛，过了一会儿，说道：\n");
   write("\n不要以为随随便便打听到了密码就能混进去，还不快滚 !!\n");
   return 1;}
   
   write("\n战士和缓的说：嗯！！可以确定你不是武士堡或蜥蜴窝的奸细，好，进去吧！\n\n");
   tell_room( environment(this_player()),
     "战士招手示意"+this_player()->query("c_name")+"赶快通过！\n",
     this_player() );
   this_player()->move_player(CITY"inway4","SNEAK");
   tell_room( environment(this_player()),
     this_player()->query("c_name")+"畏畏缩缩的走了过来!\n",
     this_player() );
   return 1;
}   
   
    
