#include <mumar.h>
inherit ROOM;
 
int ent;
void create()
{
        ::create();
  set_short("李□的收藏室");
  set_long( @CLong
走进这个房间，你几乎怀疑自己是不是身处於一个军事基地之中。这儿华丽的陈
设不说，收藏的更都是各地的珍奇物品和古玩。耀眼的珠宝(gems)和瓷器(china) 以
外，这儿还有些有趣的盔甲(plates)与武器。你觉得若是能拥有这房间里十分之一的
财富，大概下半辈子都不用辛苦赚钱了。
CLong
);
set("light",1);
set("c_item_desc",([
    "gems":"@@to_gems","china":"@@to_china",
    "plates":"@@to_plates","mirror":"@@to_mirror"
     ]) );
 
set("exits",([
               "west":MUMAR"stage06"
             ]));
}
 
void init()
{
    add_action("to_polish","polish");
    add_action("to_touch","touch");
}
 
int to_polish(string arg)
{
 if( !arg || arg != "plates" ) return 0;
   write("你小心翼翼地地轻轻擦拭著盔甲，却还是一个不小心差点把一具战甲弄倒。\n");
   write("当你试图扶起那战甲时你才发现盔甲後面的角落里放著一座大镜子(mirror)。\n");
 this_player()->set_temp("look_mirror",1);
 return 1;
}
 
int to_touch(string arg)
{
   if( !arg || arg != "mirror" ) return 0;
   else  {
      if (this_player()->query_temp("mirror_ok") || ent==2){
        ent=2;
        write("在你摸著镜子的同时，你感到一股强大的吸引力把你拉进了镜内。\n");
        this_player()->move_player(MUMAR"m_stage",({
        "",this_player()->query("c_short")+"被吸入了镜子\n。",
        "",this_player()->query("c_short")+"进入了这个镜中世界。\n",
        }),"");
        }
      else {
        ent=1;
        write("你轻轻地摸著镜子，结果摸了一手的灰...\n");
            }
        }
   return 1;
}
 
string to_gems()
{ return "一些红宝石、猫眼石、翡翠、珊瑚之类的，让你眼花撩乱。\n"; }
 
string to_china()
{ return "这些瓷器都是官窑正品，色泽和造型都是上上之选。\n"; }
 
string to_plates()
{ return "这儿有著东方岛国的武士战甲、诺顿大陆的骑士装备、默尔斯人的战袍、\n"
         "前代将军染著敌人鲜血的盔甲。这些来自不同时空的盔甲只有一个共同的\n"
         "特色，那就是都被擦拭(polish)得一尘不染，闪著亮丽的金属色泽。\n"; }
 
string to_mirror()
{
  if (this_player()->query_temp("mirror_ok"))
   {return "这面镜子闪耀著一种奇异的光芒，深深地吸引著你去摸(touch)它。\n";
   ent=2;}
  else{
   return "这面镜子似乎是这房间中最不起眼的玩意儿了。而且这镜子还缺了一角。\n";
      }
}
 
void reset()
{
  ::reset();
  ent=1;
}
