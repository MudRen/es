#include "../echobomber.h"
//	#define BOARD "/u/e/echobomber/board/board"

inherit ROOM;

void create()
{
        ::create();
        set("light",1);
        set_short("死亡大地的码头");
        set_long(@Long_Description
这里是一个简单而老旧的码头.北边是一面高耸入云的悬崖(cliff),而南,西,东
三面皆是汪洋大海( ocean ).刺骨的冷风从海上吹来,以及腐烂的藤蔓( plants )所
传来的恶心味道,让你觉得离开这里将是最好的选择.
现在你已经踏上了死亡大地--------一处充满著死亡与财富的地方.这里除了友善的
矮人外,还有令人惧怕的山顶巨人 ,以及从来没人见过的骸骨人( Skeletons ).目前
黑暗的势力正控制著这块土地.除了祭祀邪神的矮人族外.
Long_Description

 );
set_outside( "deathland" );
 set("item_desc",(["cliff":@C_CLIFF
很高的悬崖.有很多的蔓□植物依附在上面,你可以试试是否能爬上去,但
是你不确定这蔓□是否能支撑你的重量.
C_CLIFF

,"plants":@C_PLANTS
当你注视那些腐烂的植物时,你发现有一些文字(writings)隐藏於後.
C_PLANTS

,"writings":@WRITINGS
当我将要远离这个危险的地方时,我很庆幸我仍活著.後来的冒险者呀,为了
让你能够避免我的错误,给你一些建议
 ----潜入(dive)水中,勿爬(climb)上山.------
     冒险家  亚默
WRITINGS

,"ocean":@C_OCEAN
一片汪洋大海
C_OCEAN
                               ]));

set("exits",([
    "northeast":Deathland"/main/p1",
      
   ]));

//	BOARD->frog();

}
void init()
{
     add_action("to_climb","climb");
     add_action("to_dive","dive");
     if( !find_object("/d/std/ocean/ship_death") )
     	"/d/std/ocean/ship_death"->frog();
     if( !find_object("/d/std/ocean/ship_ta_tong") )
     	"/d/std/ocean/ship_ta_tong"->frog();
}

int to_dive()
{
   write("你潜入海洋之中.\n");
   this_player()->set_explore( "deathland#0" );
   this_player()->move_player(Deathland"/main/d4.c",
         ({"%s潜入海中而消失。\n","%s从码头潜了下来。\n"}),"SNEAK");
   return 1;
}

int to_climb()
{
  if ((int)this_player()->query_skill("climb")>100) {
   write("凭著高超的攀登经验,你爬上了悬崖\n");
   this_player()->move_player(Deathland"/upper/a1","SNEAK","");
   }
   else {
   write("想想自己的技术,要爬上去简直是妄想.\n"
      "你只好另外寻找出路.\n");
   }
   return 1;
}
