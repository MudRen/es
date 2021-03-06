#include "dgnisld.h"

inherit ROOM;


int cropps;
void create()
{
	::create();
	cropps = 0;
	set( "cropp",1);
	set( "outside" ,"dgnisld" ) ;
   set_short(
	           "龙岛的入口" ) ;
	set_long(
	    "这是龙岛的入口，你可以看到一个画有龙族符号的告示(sign)。\n"
	"北方似乎有一片大草原(campo)，有一条小径通往西北方的森林(forest)\n"
	"，东边则是一丛高耸浓密的草丛(brush)。\n"
        ) ;

	set( "item_desc", ([
	     "sign" : 
  "这张告示写著：\n"
  "——————————————————————————————————\n"
  "欢迎来到龙岛！\n"
  "  这岛乃由龙王巴哈姆特所管辖，不过却不曾有人看过它的真面目。岛上有\n"
  "草原、沼泽、湖泊、森林、火山等地形，到处充满了危险，也因此保留了一\n"
  "些原始生物。此处鲜为人烟，到处都是未开发地区，因而朦上了一层神秘的\n"
  "色彩。请小心那些凶暴的肉食性恐龙，它们可能在你能抵抗之前就把你一口\n"
  "吞掉。有一种种族——龙骑士居住在这里，他们是唯一可与龙族沟通的种族\n"
  "，不过他们根本不会理你，除非他们承认你是他们的一员。\n"
  "                                            一刻馆管理人  音无响子\n"
  "——————————————————————————————————\n",
           "brush" : "十分茂密的草丛，似乎这儿的雨水充足。\n",
           "forest": "很大的森林，看起来既阴森又恐怖。\n",
           "campo" : "一望无际的草原，到处杂草丛生。\n",
           ]) );
    set( "objects", ([
        "bahamut" : "/u/k/kyoko/FF-V/bahamut",   ]) );
	set( "exits", ([
	   "northwest"    : DGNISLD"forest1-10",
	       "north"    : DGNISLD"campo10-1",        ]) );
   reset();
}

void init()
{
        add_action("enter_hole","enter");
}

int to_find_cropp(string str)
{
      if ( !str || str!="brush" )
        write("You can't cropp it!\n");
      else {
        if (cropps==0) {
          cropps=1;
          add( "item_desc",([ 
                 "hole" : "一个小洞。不过它小到一次只能让一人通过，而且\n"
                          "看起来危危欲坠，好像随时都会崩坏。\n",              
                "brush" : "这草丛看起来毫无生气，它被砍得一蹋糊涂。\n",            
                         ]) );
          write(
            "当你割掉草丛时，很幸运地发现一个小洞(hole)。不过它小到只\n"
            "能让一人通过(enter) ，看起来危危欲坠，好像随时都会崩坏。\n");
          say(
            this_player()->query("c_cap_name")+"割了一些东西。\n");
        }
        else 
          write("They have been cropped!\n");
      }
      return 1;
}

int enter_hole(string str)
{        
         if ( !str || str=="" )
           write("enter what ?\n");
         else if ( str!="hole" )
           write("There are no "+str+" here!\n");
         else if (cropps==1){
           write("You climb into the hole and walk forward. The hole is\n"
                 "broken when you enter it. You enter a very dark place.\n"  );
           say( this_player()->query("cap_name")+
                " enter a hole and disappear.\n");
           cropps = 2;
           add( "item_desc",([
                "hole" : "当你探头往里面看，你发现这洞已经毁了！\n" ])  );
                                 
           this_player()->move_player(DGNISLD"hole1", "", "") ;
         }
         else if (cropps==2)
           write( !can_read_chinese() ? 
             "The hole has been broken!\n":"这洞已经毁了！\n");
         return 1;
}

int get_cropps()
{
         return cropps;
}
         
void reset()
{
    ::reset();
    cropps=0;
}
