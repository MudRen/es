#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "厨房" );
	set_long(
	"这是梁山泊内的大众厨房，提供免费的食物，锅子(pot)内正煮著食物，冒\n"
	"著阵阵的白烟，但那股奇怪的味道却让人不敢恭维。地上散布著各种食物的\n"
	"残渣，看起来这里的主人十分不注重卫生。\n"
	);
	set( "light",1 );
        set( "exits", ([
                "north"  : TROOM"path4",    
        ]) );
        set( "c_item_desc", ([
                "pot" : @POT
你探头往锅中看去，这一锅黏不拉叽的东西不知道是什麽，看起来令人作呕。
再向前仔细一看，你发现一件很奇怪的事，锅子里都是些青菜萝卜和黄豆，打
碎混合的东西，难道梁山泊的人都吃素?
POT
]));              
        set( "objects",([
             "cooker" : TMONSTER"fat"
             ]));
        reset();
}
void init()
{
   object obj;

   add_action("do_sweep","sweep");
   add_action("do_consider","consider");
   add_action("do_suggest","suggest");
   if ((int)this_player()->query_temp("fat_quest/fish")==2 && present("cooker")) {
   obj = new("/d/noden/asterism/item/tea01");
   write(
   "肥东说道: 辛苦你了，边说边倒了杯青草茶给你.......\n");
   this_player()->set_temp("fat_quest/fish",3);
   write(
   "刚才你出去的时候，张顺头领派人送来了一些鱼虾，我就试著做了一些料理\n"
   "你要不要试试看................\n\n"
   "於是你从料理台上挑出几样食物送入口中，嚼嚼嚼嚼.........\n\n"
   "说实话，味道实在不是很好，看来肥东的烹饪技术(skill)有待加强。\n");
   obj->move(this_object());
}
}
int do_sweep()
{
   if ( present("broom",this_player()) )
     {
      write(
      "你一边哼著小毛驴，一边把厨房打扫的乾乾净净....\n\n");
     
      tell_room(this_object(),
      "你看到"+this_player()->query( "c_name")+"拿著扫把，努力的清理这间厨房。\n",this_player());
   if (present("cooker")) 
     {
      write(
      "肥东感激的说道:谢谢你帮我打扫厨房，可是......\n"
      "唉.................\n\n"
      "一声叹息之後肥东继续说道：其实我也是很爱乾净的，可是我这麽胖，根本不能\n"
      "弯下腰去打扫，现在虽然你打扫得很乾净，但我想过不了多久这□还是会变得跟\n"
      "以前一样那麽脏，难道你要天天帮我扫吗？所以我想这不是一个治本的好办法吧\n"
      "。不过尽管如此，我还是非常的谢谢你。\n"
      "说完这些话，肥东继续哀声叹气的做今天的菜。\n\n");
     
     
      this_player()->set_temp("fat_quest",(["ask":0,
                                            "diet":0,
                                            "meat":0,
                                            "fish":0,
                                            "cook":0,
                                           ]));
      call_out("recover",10,this_player());
     return 1;
     }
  else return 1;
    }
  else  {
    write(
    "你确定要用手来打扫吗?\n");
    return 1;    
        }
}
int recover()
  { 
   write(
   "肥东抬头看了你一眼後说：看你这样的热心助人，不知道你愿不愿意帮助\n"
   "我解决我的苦恼(trouble)呢?\n");
   this_player()->set_temp("fat_quest/ask",1);
   }   
int do_consider(string arg)
{
  if ( !arg || arg != "meat")
  return notify_fail(
  "讨论什麽?\n"  );
  if ((int)this_player()->query_temp("fat_quest/meat")==2 && present("cooker")) {
  write(
  "肥东说道: 原来如此，可是像我们这种公营事业，经费是不能随便乱用的.....\n"
  "说完，肥东又开始长嘘短叹........\n"
  "你想，这实在是一个困难的任务，凭你的智慧是很难处理的。或许\应\该\找\个\聪明\n"
  "人一同来参详\n");
  this_player()->set_temp("fat_quest/ask",2);
  return 1;
  }
  else return 0;
  }
 int do_suggest(string arg)
 {
 if (!arg || arg != "fish" )
 return notify_fail(
 "建议什麽?\n" );
 if ((int)this_player()->query_temp("fat_quest/fish")==1 && present("cooker"))  {
 write(
 "肥东说道: 用鱼去作料理，听来像是个好主意，但是我从来没有试过，也许你可\n"
 "以先去把材料拿回来看看。\n");
 return 1;
 }
 else { write(
 "你想要干什麽?\n");
 return 1;
}}
int clean_up() { return 0; }